分段反向代理是一种特殊形式的反向代理，因此其主要功能还是转发HTTP请求到指定的后端服务并将后端响应结果解析处理后响应给客户端。需要识别的分段协议是在反向代理和后端服务之间使用的，交互过程对客户端连接是不透明的，因此客户端应无法辨别响应结果是否是反向代理做出的。

为了简化实现，对于后端委托处理的外部请求目前仅实现单次请求逻辑，即一次中间响应结果只能委托反向代理进行一次外部请求；后期若有性能要求再增强为支持在一次中间响应结果中委托反向代理进行多个并发外部请求。但单次请求和多并发请求应使用一致的协议。

**分段交互协议如下：**

1. 若后端响应结果中包含 X-Staged-Next 头，则认为当前响应是一个中间响应结果。X-Staged-Next 的格式如下：
```
X-Staged-Next: <backend-path-to-request-next>
```
这里 `<backend-path-to-request-next>` 为再次向后端请求下一阶段结果时的请求路径。不管客户端原本的 HTTP 请求方法如何，当分段反向代理发起下一阶段请求时总是使用 POST 方式进行。本次响应头中所有不是分段交互协议一部分的字段都会被丢弃。

为保证 HTTP/1.1 的虚拟主机功能可用，并提供切换到不同后端服务的能力，可以增加如下格式的可选头：
```
X-Staged-Next-Host: <virtual host name>
X-Staged-Next-Server: <addr>:<port> | <unix socket path>
```
X-Staged-Next-Host 头若存在，则发起下一阶段 HTTP POST 请求时就会将其内容作为 Host 请求头的新值；否则下一阶段 HTTP POST 请求头中的 Host 取值维持初始客户端请求中的 Host 值不变。X-Staged-Next-Server 头若存在，则下一阶段 HTTP POST 请求的目标服务器会切换到指定的位置上；否则下一阶段 HTTP POST 请求的目标服务器维持原有的后端服务器不变。

响应体可能包含 2 部分内容：上下文传递数据和外部请求数据。其中上下文传递数据会暂存在反向代理内，待发起下一阶段请求时整合在请求体数据中，代理本身不对其做任何解析修改；若响应头中包含外部连接请求头，则反向代理会解析外部请求数据部分，否则直接将这部分数据丢弃。响应体具体格式规定如下：
```
<response body> ::= <data block>*
<data block> ::= <context data block> | <extern request data block>
<context data block> ::= 'T' <4-bytes length> <data content>
<extern request data block> ::= 'E' <4-bytes request id> <4-bytes length> <data content>
```
其中 `<request id>` 为该外部请求的唯一整数标识，其对应的外部请求数据则交给各自的外部请求协议处理器自行解释，若不存在对应 id 的外部请求头时对应的数据块会被丢弃。下面是外部请求协议对应的 `<data content>` 格式：
```
<data content> ::= <http schema data content> | ...

<http schema data content> ::= <1-byte http method> 'd' (<header key> <header val>)* 'e' <body content>
<header key> ::= <2-bytes length> <key content>
<header val> ::= <2-bytes length> <val content>
<http method> ::= 0 (GET) | 1 (POST)
```
出现类型未知的数据块或数据块长度有误时都视为有效数据结束，剩余数据全部丢弃。

2. 若后端响应结果中包含 X-Staged-Request 头，则意味着需要发起外部连接请求。X-Staged-Request 的格式如下：
```
X-Staged-Request: <uri-with-schema>[; id=<request id>]
```
这里 `<uri-with-schema>` 是带有请求协议 schema 的标准外部 URI；`<request id>` 为十进制文本表示的请求 id，可在出现多个 X-Staged-Request 头并发进行多个外部请求时通过 id 子域(若忽略则默认为 0)指明每个请求的唯一标识，标识相同的头会被后来者覆盖；每个外部请求所需的数据(对于HTTP协议请求来说就是请求方式、请求头和请求体数据；对于其他协议的请求则可能不同)在对应 id 的外部请求数据块中以指定格式保存。

当所有外部连接请求均结束时，若之前后端的响应结果中包含 X-Staged-Next 头，则以如下格式将外部请求响应结果和上下文传递数据合并起来作为发起下一段 POST 请求的请求体：
```
<request body> ::= <data block>*
<data block> ::= <context data block> | <extern response data block>
<context data block> ::= 'T' <4-bytes length> <data content>
<extern response data block> ::= 'E' <4-bytes request id> <4-bytes length> <data content>
```
若之前后端的响应结果中没有 X-Staged-Next 头，则以 `<request id>` 最小的外部连接请求响应结果作为客户端连接的最终响应结果，具体的响应头和响应体的内容如何是由该请求的协议处理器自行决定的。

若在后端的最终响应结果中以 HTTP 外部请求作为响应给客户端的内容，则 HTTP 协议处理器应支持用后端响应结果中的某些 Header 覆盖外部请求响应结果中对应 Header 内容的功能。允许被后端响应头覆盖的 Header 为：
```
Content-Type
Content-Disposition
Accept-Ranges
Set-Cookie
Cache-Control
Expires
```
3. 为了完成特定的客户端请求所进行的分段操作总数有上限，后端每产生一个分段中间响应结果，同其对应的客户端连接上关联的分段操作计数器就增加 1，当计数器当前值超过上限时，分段反向代理将不再继续处理逻辑，直接向客户端响应 500 Internal Error 内部错误。

4. 为了避免客户端有意无意地直接请求中间处理阶段的代码，分段反向代理会在客户端首次发起连接时产生一个随机串，在处理该连接过程中每次向后端发起的 HTTP 请求中用 X-Staged-Crumb 头(必选)带上该随机串：
```
X-Staged-Crumb: <random string>
```
后端返回中间响应结果时，用只有后端服务自己知道的密钥同分段反向代理传入的随机串合并后进行 SHA1 签名，并将签名结果保存在上下文传递数据中；下一阶段的代码获取到上下文传递数据后，会从中提取出签名串，并同本次请求中反向代理发送的随机串的签名进行比对，只有二者匹配时才允许继续处理。

后端对 X-Staged-Crumb 串的签名算法可表述为：
```
sign(key, crumb) ::= SHA1(crumb . key)
```
其中 SHA1() 产生的是 16 进制文本字符串，crumb 和 key 之间的小数点表示字符串拼接。