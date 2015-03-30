

# 概述 #

```
Nginx  ("engine x") 是一个高性能的 HTTP 和 反向代理 服务器，也是一个 IMAP/POP3/SMTP 代理服务器 。
 Nginx 是由 Igor Sysoev 为俄罗斯访问量第二的Rambler.ru 站点开发的，它已经在该站点运行超过四年多了。
Igor 将源代码以类BSD许可证的形式发布。自Nginx 发布四年来，Nginx 已经因为它的稳定性、丰富的功能集
、示例配置文件和低系统资源的消耗而闻名了。目前国内各大门户网站已经部署了Nginx，
如新浪、网易、腾讯等；国内几个重要的视频分享网站也部署了Nginx，如六房间、酷6等。
新近发现Nginx 技术在国内日趋火热，越来越多的网站开始部署Nginx。 
```
- from http://wiki.nginx.org/NginxChs

我们研究nginx的源代码的动机是为了完成分段反向代理项目的开发，由于分段反向代理的需求要求对web server的并发性很强，并且是给予http协议的基础上进行的， 所以我们选择了使用Nginx的模块的形式进行开发。

我们发现目前学习nginx的例子很少，主要是emiller的模块开发介绍这篇文章， 但是单独研究这篇文章发现很多晦涩难懂的地方，而目前还没有其他更好的文章来对这些地方做解释， 有些东西必须要通过源代码的研读才可以了解的更加清楚，所以我们决定开始进行代码研究计划，以便于更好的完成开发任务

根据目前的状况，我们决定使用最新的稳定版本进行研究，故而选择 0.7.61 版作为调研对象。

http://sysoev.ru/nginx/nginx-0.7.61.tar.gz




# 研究计划 #

下面是王晓哲帮助制定的调研计划

  * 学习emiller的文章
  * 熟悉nginx的基本数据结构 1w
  * 了解nginx的core module 的结构和运行机制， 同时参考 event 和 os module 的实现 1w
  * 了解nginx的http core module 的结构和运行机制 1w
  * 学习handler 类型module的编写 2d
  * 学习filter 类型module的编写 2d
  * upstream类型module的编写 1w

# 参与人员 #

徐景([rainx](http://rainx.cn)), 王晓哲(chaoslawful)

# 研究文档 #

## 学习emiller的文章 ##

http://www.evanmiller.org/nginx-modules-guide.html

## 熟悉nginx的基本数据结构 ##

### nginx 代码的目录结构 ###

解开nginx的代码后，在src目录下发现有如下的几个目录

```
core  event  http  mail  misc  os
```

其中 ：

  * **core** : 该目录存放core module的代码，也是nginx服务的入口
  * **http** : http core module 的代码，nginx作为web/http proxy server运行时的核心模块
  * **mail** : mail core module 的代码，nginx作为pop3/imap/smtp proxy server运行时的核心模块 ( 不在我们本次研究范围内 )
  * **event** : nginx 自身对事件处理逻辑的封装
  * **os** : nginx对各个平台抽象逻辑的封装
  * **misc** : nginx 的一些utils,定义了test和profiler的一些外围模块的逻辑


为了方便了解整个结构， 我们在src目录下建立了一个子目录，叫做demo,然后根据每个章节内容的不同，分别在demo下建立子目录，存放一些学习时使用的代码,如我们目前的章节是学习基本的数据类型，所以建立basic\_types子目录

```
rainx@rainx-laptop:~/land/nginx-0.7.61/src$ mkdir -p demo/basic_types/
```


### nginx简单的数据类型的表示 ###

在 core/ngx\_config.h 目录里面定义了基本的数据类型的映射，大部分都映射到c语言自身的数据类型

```
typedef intptr_t        ngx_int_t;
typedef uintptr_t       ngx_uint_t;
typedef intptr_t        ngx_flag_t;
```

其中 ngx\_int\_t, nginx\_flag\_t, 都映射为 intptr\_t； ngx\_uint\_t映射为 uintptr\_t

这两个类型在/usr/include/stdint.h的定义为：

```
/* Types for `void *' pointers.  */
#if __WORDSIZE == 64
# ifndef __intptr_t_defined
typedef long int		intptr_t;
#  define __intptr_t_defined
# endif
typedef unsigned long int	uintptr_t;
#else
# ifndef __intptr_t_defined
typedef int			intptr_t;
#  define __intptr_t_defined
# endif
typedef unsigned int		uintptr_t;
#endif
```

所以基本的操作和整形/指针类型的操作类似

建立文件
```
#include <stdio.h>
#include "../../core/ngx_config.h"

int main()
{
    ngx_uint_t a;
    ngx_int_t b;
    a = 1000;
    b = -1000;
    printf ("%d + %d = %d\n", a, b, a+b);
    return 0;
}
```
编译测试
```
gcc -I ../../../objs/ -I ../../os/unix/ basic_types_int.c -o basic_types_int
./basic_types_int
1000 + -1000 = 0
```

### nginx字符串的数据类型的表示 ###

nginx对c语言的字符串类型进行了简单的封装， **core/ngx\_string.h/c** 里面包含这些封装的内容

其中定义了 ngx\_str\_t ，ngx\_keyval\_t， ngx\_variable\_value\_t

这几个基础类型的定义如下

```
typedef struct {
    size_t      len;
    u_char     *data;
} ngx_str_t;


typedef struct {
    ngx_str_t   key;
    ngx_str_t   value;
} ngx_keyval_t;


typedef struct {
    unsigned    len:28;

    unsigned    valid:1;
    unsigned    no_cacheable:1;
    unsigned    not_found:1;
    unsigned    escape:1;

    u_char     *data;
} ngx_variable_value_t;
```

可以看出 ngx\_str\_t 在原有的`uchar*` 的基础上加入的字符串长度的附加信息， 初始化使用ngx\_string宏进行，他的定义为：
```
#define ngx_string(str)     { sizeof(str) - 1, (u_char *) str }
```

测试字符串的代码
demo/basic\_types/basic\_types\_str.c
```
#include <stdio.h>
#include "ngx_config.h"
#include "ngx_conf_file.h"
#include "nginx.h"
#include "ngx_core.h"
#include "ngx_string.h"
#include "ngx_string.h"

volatile ngx_cycle_t  *ngx_cycle;

void
ngx_log_error_core(ngx_uint_t level, ngx_log_t *log, ngx_err_t err,
            const char *fmt, ...)
{
}

int main()
{
    u_char* p = NULL;
    ngx_uint_t size;
    ngx_str_t dst;
    ngx_str_t mystr = ngx_string("hello, world !");
    ngx_keyval_t pair = {ngx_string("url"), ngx_string("http://rainx.cn/index.php?test=1")};
    int dst_len  =ngx_base64_encoded_length(mystr.len);
    printf("source length is %d, destination length is %d\n", mystr.len, dst_len );
    p = malloc( ngx_base64_encoded_length(mystr.len) + 1);
    dst.data = p;
    ngx_encode_base64(&dst, &mystr);
    printf("source str is %s\ndestination str is %s\n", mystr.data, dst.data);
    free(p);
    size = pair.value.len + 2 * ngx_escape_uri(NULL, pair.value.data, pair.value.len, NGX_ESCAPE_URI);
    p = malloc (size * sizeof(u_char));
    ngx_escape_uri(p, pair.value.data, pair.value.len, NGX_ESCAPE_URI);
    printf("escaped %s is : %s (%d)\noriginal url size is %d\n", pair.key.data, p, size, pair.value.len);
    free(p);
    return 0;

}

```

编译运行
```
gcc  -c -O -pipe  -O -W -Wall -Wpointer-arith -Wno-unused-parameter -Wunused-function -Wunused-variable -Wunused-value -Werror -g -I ../../../objs/ -I ../../os/unix/ basic_types_str.c -I../../core/ -I../../event/ -I../../os/ -o basic_types_str.o
gcc -o basic_types_str basic_types_str.o ../../../objs/src/core/ngx_{string,palloc}.o ../../../objs/src/os/unix/ngx_alloc.o -lcrypt -lpcre -lcrypto -lz
rainx@rainx-laptop:~/land/nginx-0.7.61/src/demo/basic_types$ ./basic_types_str 
source length is 14, destination length is 20
source str is hello, world !
destination str is aGVsbG8sIHdvcmxkICE=
escaped url is : http://rainx.cn/index.php%3ftest=1 (34)
original url size is 32
```

**core/ngx\_string.h/c** 中同时也封装了一批字符／字符串处理的函数和宏，他们的使用大多数情况下和c标准库中的类似，只是在内存分配相关的函数中有一定的区别。

比如 `u_char *ngx_pstrdup(ngx_pool_t *pool, ngx_str_t *src);` 除了源字符串驻外，还要传入ngx\_pool\_t的指针作为参数，使用nginx自己的内存分配方式进行内存的分配。

除了标准的字符串操作外， nginx还实现了例如：

```
// base64 编码／解码函数和宏

#define ngx_base64_encoded_length(len)  (((len + 2) / 3) * 4)
#define ngx_base64_decoded_length(len)  (((len + 3) / 4) * 3)

void ngx_encode_base64(ngx_str_t *dst, ngx_str_t *src);
ngx_int_t ngx_decode_base64(ngx_str_t *dst, ngx_str_t *src);

//utf-8 编码／解码相关函数

uint32_t ngx_utf8_decode(u_char **p, size_t n);
size_t ngx_utf8_length(u_char *p, size_t n);
u_char *ngx_utf8_cpystrn(u_char *dst, u_char *src, size_t n, size_t len);

// urlencode和html实体的编码解码
uintptr_t ngx_escape_uri(u_char *dst, u_char *src, size_t size,
    ngx_uint_t type);
void ngx_unescape_uri(u_char **dst, u_char **src, size_t size, ngx_uint_t type);
uintptr_t ngx_escape_html(u_char *dst, u_char *src, size_t size);

```
等对于http服务有帮助的宏和函数

### 内存分配相关 ###

#### 系统功能封装 ####

内存相关的操作主要在 os/unix/ngx\_alloc.{h,c} 和  core/ngx\_palloc.{h,c} 下

其中 os/unix/ngx\_alloc.{h,c} 封装了最基本的内存分配函数，是对c原有的malloc/free/memalign 等原有的函数的封装,对应的函数为：

  * ngx\_alloc 使用malloc分配内存空间
  * ngx\_calloc 使用malloc分配内存空间，并且将空间内容初始化为0
  * ngx\_memalign 返回基于一个指定的alignment大小的数值为对齐基数的空间
  * ngx\_free 对内存的释放操作

#### ngx的内存池 ####


为了方便系统模块对内存的使用，方便内存的管理，nginx自己实现了进程池的机制来进行内存的分配和释放， 首先nginx会在特定的生命周期帮你统一建立内存池，当需要进行内存分配的时候统一通过内存池中的内存进行分配，最后nginx会在适当的时候释放内存池的资源，开发者只要在需要的时候对内存进行申请即可，不用过多考虑内存的释放等问题，大大提高了开发的效率。

内存池的主要结构为：
```
//ngx_palloc.h
struct ngx_pool_s {
    ngx_pool_data_t       d;
    size_t                max;
    ngx_pool_t           *current;
    ngx_chain_t          *chain;
    ngx_pool_large_t     *large;
    ngx_pool_cleanup_t   *cleanup;
    ngx_log_t            *log;
};

//ngx_core.h
typedef struct ngx_pool_s        ngx_pool_t;
typedef struct ngx_chain_s       ngx_chain_t;
```

下面是我简单画的一个图来描述这个结构：

![http://img02.taobaocdn.com/tps/i2/T1m1JRXnRcXXXXXXXX-991-634.png](http://img02.taobaocdn.com/tps/i2/T1m1JRXnRcXXXXXXXX-991-634.png)

link : http://www.flickr.com/photos/rainx/3765612584/sizes/o/

下面解释一下主要的几个操作：

```
// 创建内存池
ngx_pool_t *ngx_create_pool(size_t size, ngx_log_t *log);
```

大致的过程是创建使用 ngx\_alloc 分配一个size大小的空间, 然后将 `ngx_pool_t*` 指向这个空间， 并且初始化里面的成员, 其中
```
p->d.last = (u_char *) p + sizeof(ngx_pool_t); // 初始指向 ngx_pool_t 结构体后面
p->d.end = (u_char *) p + size; // 整个结构的结尾后面
p->max = (size < NGX_MAX_ALLOC_FROM_POOL) ? size : NGX_MAX_ALLOC_FROM_POOL; // 最大不超过 NGX_MAX_ALLOC_FROM_POOL,也就是getpagesize()-1 大小
```
其他大都设置为null或者0

```
// 销毁内存池
void ngx_destroy_pool(ngx_pool_t *pool);
```
遍历链表，所有释放内存，其中如果注册了clenup(也是一个链表结构）， 会一次调用clenup 的 handler 进行清理。

```
// 重置内存池
void ngx_reset_pool(ngx_pool_t *pool);
```
释放所有large段内存， 并且将d->last指针重新指向 ngx\_pool\_t 结构之后（和创建时一样）

```
// 从内存池里分配内存
void *ngx_palloc(ngx_pool_t *pool, size_t size);
void *ngx_pnalloc(ngx_pool_t *pool, size_t size);
void *ngx_pcalloc(ngx_pool_t *pool, size_t size);
void *ngx_pmemalign(ngx_pool_t *pool, size_t size, size_t alignment);
```

ngx\_palloc的过程一般为，首先判断待分配的内存是否大于 pool->max的大小，如果大于则使用 ngx\_palloc\_large 在 large 链表里分配一段内存并返回， 如果小于测尝试从链表的 pool->current 开始遍历链表，尝试找出一个可以分配的内存，当链表里的任何一个节点都无法分配内存的时候，就调用 ngx\_palloc\_block 生成链表里一个新的节点， 并在新的节点里分配内存并返回， 同时， 还会将pool->current 指针指向新的位置（从链表里面pool->d.failed小于等于4的节点里找出） ，其他几个函数也基本上为 ngx\_palloc 的变种，实现方式大同小异

```
// 释放指定的内存
ngx_int_t ngx_pfree(ngx_pool_t *pool, void *p);
```
这个操作只有在内存在large链表里注册的内存在会被真正释放，如果分配的是普通的内存，则会在destory\_pool的时候统一释放.
```
// 注册cleanup回叫函数（结构体）
ngx_pool_cleanup_t *ngx_pool_cleanup_add(ngx_pool_t *p, size_t size);
```
这个过程和我们之前经常使用的有些区别， 他首先在传入的内存池中分配这个结构的空间（包括data段）， 然后将为结构体分配的空间返回， 通过操作返回的ngx\_pool\_cleanup\_t结构来添加回叫的实现。 (**这个过程在nginx里面出现的比较多，也就是 xxxx\_add 操作通常不是实际的添加操作，而是分配空间并返回一个指针，后续我们还要通过操作指针指向的空间来实现所谓的add**)

下面是内存操作的一些例子
demo/basic\_types/mem\_op.c
```
#include <stdio.h>
#include "ngx_config.h"
#include "ngx_conf_file.h"
#include "nginx.h"
#include "ngx_core.h"
#include "ngx_string.h"
#include "ngx_palloc.h"

volatile ngx_cycle_t  *ngx_cycle;

void
ngx_log_error_core(ngx_uint_t level, ngx_log_t *log, ngx_err_t err,
            const char *fmt, ...)
{
}

typedef struct example_s {
    int a;
    char* b;
} example_t;

int main()
{
    ngx_pool_t *pool;
    example_t* exp;
    char* s;

    pool = ngx_create_pool(5000, NULL);
    printf("available pool regular pool free size is %d now\n", (ngx_uint_t) (pool->d.end - pool->d.last));
    exp = ngx_palloc(pool, sizeof(example_t)) ;
    s = ngx_palloc(pool, sizeof("hello,world"));
    printf("available pool regular pool free size is %d now\n", (ngx_uint_t) (pool->d.end - pool->d.last));
    exp->a = 1;
    exp->b = s;
    strcpy(s, "hello,world");
    printf("pool max is %d\n", pool->max);
    printf("exp->a is %d, exp->b is %s\n", exp->a, exp->b);
    ngx_destroy_pool(pool);
    return 0;
}
```

编译运行结果
```
gcc  -c -O -pipe  -O -W -Wall -Wpointer-arith -Wno-unused-parameter -Wunused-function -Wunused-variable -Wunused-value -Werror -g -I ../../../objs/ -I ../../os/unix/ mem_op.c -I../../core/ -I../../event/ -I../../os/ -o mem_op.o
 gcc -o mem_op mem_op.o ../../../objs/src/core/ngx_{string,palloc}.o ../../../objs/src/os/unix/ngx_alloc.o -lcrypt -lpcre -lcrypto -lz
rainx@rainx-laptop:~/land/nginx-0.7.61/src/demo/basic_types$ ./mem_op 
available pool regular pool free size is 4960 now
available pool regular pool free size is 4940 now
pool max is 4960
exp->a is 1, exp->b is hello,world
```


### ngx的基本容器 ###

#### ngx\_array ####

对应的文件为 core/ngx\_array.{c|h}

ngx\_array是nginx内部封装的使用 ngx\_pool\_t对内存池进行分配的数组容器，其中的数据是在一整片内存区中连续存放的。更新数组时只能在尾部压入1个或多个元素。

数组的实现结构为
```
struct ngx_array_s {
    void        *elts;
    ngx_uint_t   nelts;
    size_t       size;
    ngx_uint_t   nalloc;
    ngx_pool_t  *pool;
};
```

其中 elts 为具体的数据区域的指针， nelts 为数组实际包含的元素数量， size为数组单个元素的大小， nalloc为数组容器预先（或者重新）分配的内存大小， pool 为分配基于的内存池

常用的操作有
```
// 创建一个新的数组容器
ngx_array_t *ngx_array_create(ngx_pool_t *p, ngx_uint_t n, size_t size);
```

```
// 销毁数组容器
void ngx_array_destroy(ngx_array_t *a);
```

```
// 将新的元素加入数组容器
void *ngx_array_push(ngx_array_t *a);
void *ngx_array_push_n(ngx_array_t *a, ngx_uint_t n);　//返回ｎ个元素的指针
```
这里需要注意的是，和之前的ngx\_pool\_cleanup\_add一样， ngx\_array\_push只是进行内存分配的操作，我们需要对返回的指针指向的地址进行赋值等操作来实现实际数组值的添加。

具体一点的push操作的实现为，

  1. 首先判断　nalloc是否和nelts相等，即数组预先分配的空间已经满了，如果没满则计算地址直接返回指针
  1. 如果已经满了则先判断是否我们的pool中的当前链表节点还有剩余的空间，如果有则直接在当前的pool链表节点中分配内存，并返回
  1. 如果当前链表节点没有足够的空间则使用ngx\_palloc重新分配一个2倍于之前数组空间大小的数组，然后将数据转移过来，并返回新地址的指针

下面是一个array的例子:

demo/basic\_types/array\_and\_hash.c
```
#include <stdio.h>
#include "ngx_config.h"
#include "ngx_conf_file.h"
#include "nginx.h"
#include "ngx_core.h"
#include "ngx_string.h"
#include "ngx_palloc.h"
#include "ngx_array.h"

volatile ngx_cycle_t  *ngx_cycle;

void
ngx_log_error_core(ngx_uint_t level, ngx_log_t *log, ngx_err_t err,
            const char *fmt, ...)
{
}

int main()
{
   ngx_pool_t* pool;
   ngx_array_t* arr;
   int n;
   int* ele;
   pool = ngx_create_pool(4000, NULL);
   arr = ngx_array_create(pool, 10, sizeof(ngx_uint_t));
   for (n=0; n < 5; n++) {
      ele = (int*) ngx_array_push(arr);
      *ele = n;
      printf("new element %d added\n", n);
   }

   printf("arr->nelts is %d, arr->nalloc = %d\n", arr->nelts, arr->nalloc);

   for (n=5; n < 15; n++) {
      ele = (int*) ngx_array_push(arr);
      *ele = n;
      printf("new element %d added\n", n);
   }
   printf("arr->nelts is %d, arr->nalloc = %d\n", arr->nelts, arr->nalloc);

   ngx_array_destroy(arr);
   ngx_destroy_pool(pool);
   return 0;
}
```

编译运行

```
gcc  -c -O -pipe  -O -W -Wall -Wpointer-arith -Wno-unused-parameter -Wunused-function -Wunused-variable -Wunused-value -Werror -g -I ../../../objs/ -I ../../os/unix array_and_hash.c -I../../core/ -I../../event/ -I../../os/ -o array_and_hash.o
gcc -o array_and_hash array_and_hash.o ../../../objs/src/core/ngx_{string,palloc,array}.o ../../../objs/src/os/unix/ngx_alloc.o -lcrypt -lpcre -lcrypto -lz
rainx@rainx-laptop:~/land/nginx-0.7.61/src/demo/basic_types$ ./array_and_hash 
new element 0 added
new element 1 added
new element 2 added
new element 3 added
new element 4 added
arr->nelts is 5, arr->nalloc = 10
new element 5 added
new element 6 added
new element 7 added
new element 8 added
new element 9 added
new element 10 added
new element 11 added
new element 12 added
new element 13 added
new element 14 added
arr->nelts is 15, arr->nalloc = 15
```

#### ngx\_queue ####

ngx\_queue.{c,h} 实现了一个队列的操作逻辑，队列的基本结构为一个双向队列

基础的数据结构为
```
typedef struct ngx_queue_s  ngx_queue_t;

struct ngx_queue_s {
    ngx_queue_t  *prev;
    ngx_queue_t  *next;
};
```

注意nginx的队列操作和结构只进行指针的操作，不负责节点内容空间的分配和保存，所以在定义自己的队列节点的时候，需要自己定义数据结构以及分配空间， 并包含一个ngx\_queue\_t类型的成员, 需要获得原始的数据节点的时候需要使用ngx\_queue\_data宏

```
#define ngx_queue_data(q, type, link)                                         \
    (type *) ((u_char *) q - offsetof(type, link))
```

另外，整个queue结构中包含一个 sentinel（哨兵） 节点， 他指向队列的头和尾

![http://img04.taobaocdn.com/tps/i4/T1WeBRXaxeXXXXXXXX-503-409.png](http://img04.taobaocdn.com/tps/i4/T1WeBRXaxeXXXXXXXX-503-409.png)

下面是一个queue操作的例子

```
#include <stdio.h>
#include "ngx_config.h"
#include "ngx_conf_file.h"
#include "nginx.h"
#include "ngx_core.h"
#include "ngx_string.h"
#include "ngx_palloc.h"
#include "ngx_queue.h"

volatile ngx_cycle_t  *ngx_cycle;
void ngx_log_error_core(ngx_uint_t level, ngx_log_t *log, ngx_err_t err, const char *fmt, ...) { }

// 用雅虎的成员列表作为一个简单的例子
typedef struct yahoo_s {
    ngx_queue_t   queue;
} yahoo_t;

typedef struct yahoo_guy_s {
    ngx_uint_t    id;
    u_char*       name;
    ngx_queue_t   queue;
} yahoo_guy_t;

// 排序使用的比较函数, 按照id的大小排序，id大放到到前面
ngx_int_t yahoo_no_cmp(const ngx_queue_t* p, const ngx_queue_t* n)
{
    yahoo_guy_t *pre, *next;
    pre  = (yahoo_guy_t*) ngx_queue_data(p, yahoo_guy_t, queue);
    next = (yahoo_guy_t*) ngx_queue_data(n, yahoo_guy_t, queue);
    return ((pre->id > next->id) ? 1:0);
}

int main()
{
    ngx_pool_t*     pool;
    yahoo_guy_t*    guy;
    ngx_queue_t*    q;
    yahoo_t*        yahoo;
    pool            = ngx_create_pool(1024*10, NULL); //初始化内存池
    int             i;
    // 构建队列
    const ngx_str_t   names[] = {
        ngx_string("rainx"), ngx_string("xiaozhe"), ngx_string("zhoujian")
    } ;
    const int       ids[]   = {4611, 8322, 6111};

    yahoo = ngx_palloc(pool, sizeof(yahoo_t));
    ngx_queue_init(&yahoo->queue); //初始化queue

    for(i = 0; i < 3; i++)
    {
      guy = (yahoo_guy_t*) ngx_palloc(pool, sizeof(yahoo_guy_t));
      guy->id   = ids[i];
      //guy->name = (char*) ngx_palloc(pool, (size_t) (strlen(names[i]) + 1) );
      guy->name = (u_char*) ngx_pstrdup(pool, (ngx_str_t*) &(names[i]) );

      ngx_queue_init(&guy->queue);
      // 从头部进入队列
      ngx_queue_insert_head(&yahoo->queue, &guy->queue);
    }

    // 从尾部遍历输出
    for(q = ngx_queue_last(&yahoo->queue);
        q != ngx_queue_sentinel(&yahoo->queue);
        q = ngx_queue_prev(q) ) {

        guy = ngx_queue_data(q, yahoo_guy_t, queue);
        printf("No. %d guy in yahoo is %s \n", guy->id, guy->name);
    }

    // 排序从头部输出
    ngx_queue_sort(&yahoo->queue, yahoo_no_cmp);
    printf("sorting....\n");
    for(q = ngx_queue_prev(&yahoo->queue);
        q != ngx_queue_sentinel(&yahoo->queue);
        q = ngx_queue_last(q) ) {

        guy = ngx_queue_data(q, yahoo_guy_t, queue);
        printf("No. %d guy in yahoo is %s \n", guy->id, guy->name);
    }

    ngx_destroy_pool(pool);
    return 0;
}

```

运行结果为
```
rainx@rainx-laptop:~/land/nginxsrp/src/demo/basic_types$ ./queue_op 
No. 4611 guy in yahoo is rainx 
No. 8322 guy in yahoo is xiaozhe 
No. 6111 guy in yahoo is zhoujian 
sorting....
No. 8322 guy in yahoo is xiaozhe 
No. 6111 guy in yahoo is zhoujian 
No. 4611 guy in yahoo is rainx 
```

#### ngx\_hash ####

ngx\_hash.{c|h} 实现了nginx里面比较重要的一个hash结构， 这个在模块配置解析里经常被用到。该 hash 结构是只读的，即仅在初始创建时可以给出保存在其中的 key-val 对，其后就只能查询而不能进行增删改操作了。

下面是简单 hash 结构的内存布局：

![http://img01.taobaocdn.com/tps/i1/T1GuRRXjXaXXXXXXXX-1019-777.png](http://img01.taobaocdn.com/tps/i1/T1GuRRXjXaXXXXXXXX-1019-777.png)

link: http://www.flickr.com/photos/chaoslawful/3780810336/sizes/o/

虽然代码理解起来比较混乱，但是使用还是比较简单的，常用的有创建 hash 和在 hash 中进行查找两个操作，对于创建hash的操作,过程一般为：

  1. 构造一个 ngx\_hash\_key\_t 为成员的数组， 包含 key, value 和 使用key计算出的一个hash值
  1. 构建一个 ngx\_hash\_init\_t结构体的变量， 其中包含了ngx\_hash\_t 的成员， 为hash的结构体， 还包括一些其他初始设置，如bucket的大小，内存池等
  1. 调用 ngx\_hash\_init 传入 ngx\_hash\_init\_t 结构， ngx\_hash\_key\_t 的数组，和数组的长度， 进行初始化，这样 ngx\_hash\_init\_t的hash成员就是我们要的hash结构

查找的过程很简单

  1. 计算 key 的hash值
  1. 使用 ngx\_hash\_find 进行查找，需要同时传入 hash值和key ,返回的就是value的指针

需要注意的是，nginx 的 hash 在查找时使用的是分桶后线性查找法，因此当分桶数确定时查找效率同其中的总 key-val 对数量成反比。

下面是一些demo代码(可以从svn中找到)
```
#include <stdio.h>
#include "ngx_config.h"
#include "ngx_conf_file.h"
#include "nginx.h"
#include "ngx_core.h"
#include "ngx_string.h"
#include "ngx_palloc.h"
#include "ngx_array.h"
#include "ngx_hash.h"
volatile ngx_cycle_t  *ngx_cycle;
void ngx_log_error_core(ngx_uint_t level, ngx_log_t *log, ngx_err_t err, const char *fmt, ...) { }


static ngx_str_t names[] = {ngx_string("rainx"),
                            ngx_string("xiaozhe"),
                            ngx_string("zhoujian")};
static char* descs[] = {"rainx's id is 1","xiaozhe's id is 2","zhoujian's id is 3"};

// hash table的一些基本操作
int main()
{
    ngx_uint_t          k; //, p, h;
    ngx_pool_t*         pool;
    ngx_hash_init_t     hash_init;
    ngx_hash_t*         hash;
    ngx_array_t*        elements;
    ngx_hash_key_t*     arr_node;
    char*               find;
    int                 i;

    ngx_cacheline_size = 32;
    // hash key cal start
    ngx_str_t str       = ngx_string("hello, world");
    k                   = ngx_hash_key_lc( str.data, str.len);
    pool                = ngx_create_pool(1024*10, NULL);
    printf("caculated key is %u \n", k);
    // hask key cal end
    //
    hash = (ngx_hash_t*) ngx_pcalloc(pool, sizeof(hash));
    hash_init.hash      = hash;                      // hash结构
    hash_init.key       = &ngx_hash_key_lc;          // hash算法函数
    hash_init.max_size  = 1024*10;                   // max_size
    hash_init.bucket_size = 64; // ngx_align(64, ngx_cacheline_size);
    hash_init.name      = "yahoo_guy_hash";          // 在log里会用到
    hash_init.pool           = pool;                 // 内存池
    hash_init.temp_pool      = NULL;

    // 创建数组

    elements = ngx_array_create(pool, 32, sizeof(ngx_hash_key_t));
    for(i = 0; i < 3; i++) {
        arr_node            = (ngx_hash_key_t*) ngx_array_push(elements);
        arr_node->key       = (names[i]);
        arr_node->key_hash  = ngx_hash_key_lc(arr_node->key.data, arr_node->key.len);
        arr_node->value     = (void*) descs[i];
        // 
        printf("key: %s , key_hash: %u\n", arr_node->key.data, arr_node->key_hash);
    }

    if (ngx_hash_init(&hash_init, (ngx_hash_key_t*) elements->elts, elements->nelts)!=NGX_OK){
        return 1;
    }

    // 查找
    k    = ngx_hash_key_lc(names[0].data, names[0].len);
    printf("%s key is %d\n", names[0].data, k);
    find = (char*)
        ngx_hash_find(hash, k, (u_char*) names[0].data, names[0].len);

    if (find) {
        printf("get desc of rainx: %s\n", (char*) find);
    }

    ngx_array_destroy(elements);
    ngx_destroy_pool(pool);

    return 0;
}
```

运行结果
```
rainx@rainx-laptop:~/land/nginxsrp/src/demo/basic_types$ ./hash_op 
caculated key is 3654358412 
key: rainx , key_hash: 108275556
key: xiaozhe , key_hash: 2225329080
key: zhoujian , key_hash: 3269715264
rainx key is 108275556
get desc of rainx: rainx's id is 1

```


#### ngx\_list ####

ngx\_list 的结构并不复杂，ngx为我们封装了ngx\_list\_create, ngx\_list\_init, 和 ngx\_list\_push等(建立，初始化，添加）操作， 但是对于我们来说最常用的是遍历操作， 下面是nginx的注释里面提到的遍历的例子

```
   part = &list.part;
   data = part->elts;
 
   for (i = 0 ;; i++) {
 
       if (i >= part->nelts) {
           if (part->next == NULL) {
               break;
           }
 
           part = part->next;
           data = part->elts;
           i = 0;
       }
 
       ...  data[i] ...
 
   }
```


## 了解nginx的core module 的结构和运行机制 ##

### 参考资料 ###

在开始这个task的学习的时候，经过搜索发现了langwan同学之前对nginx的源代码研究资料，很有参考意义，所以大量节省了我们的工作，我觉得对于本章的进行比较有用的是，下面这几个文章

  1. nginx源代码分析 http://hi.baidu.com/langwan/blog/item/6b18ef24cd859e064c088d28.html
  1. nginx 缓冲区构造 http://hi.baidu.com/langwan/blog/item/822b758d5d1d9a1ab31bbaf8.html
  1. Nginx源代码分析 - 日志处理 http://hi.baidu.com/langwan/blog/item/7e7db51978e04e4d43a9ad32.html

### Debug信息的输出 ###

为了方便研究，将nginx的debug 信息打开，重新编译

```
rainx@rainx-laptop:~/land/nginx-0.7.61$ ./configure --prefix=/home/rainx/land/test --with-debug
```

然后修改nginx.conf

```
worker_processes  2; 
error_log  logs/error.log  debug;
```

打开debug信息的支持，并使用2个worker进程，通过查看 log 信息来了解 nginx 运行的情况

基于上面的配置信息，结合一个简单的http访问操作，我这里记录了一个 [log日志的例子 ](NginxCodeReviewErrorLogDemo.md)

### ngx\_init\_cycle ###

其中一个比较重要的函数调用是，  ngx\_init\_cycle, 这个是使用kscope输出的他的调用关系，他被main,  ngx\_master\_process\_cycle,ngx\_single\_process\_cycle 调用， 其中后两者是在reconfigure的时候被调用的

![http://img03.taobaocdn.com/tps/i3/T1AuBRXeNeXXXXXXXX-608-117.png](http://img03.taobaocdn.com/tps/i3/T1AuBRXeNeXXXXXXXX-608-117.png)

他主要做了如下几件事情:

```
初始化cycle是基于旧有的cycle进行的，比如这里的 init_cycle，会继承old cycle的很多属性， 比如log等， 但是同时会对很多资源重新分配,比如pool, shared mem, file handler, listening socket 等，同时清除旧有的cycle的资源 
```

另外，ngx\_master/single\_process\_cycle 里面会对init\_process进行调用，  并且循环调用 ngx\_process\_events\_and\_timers ， 其中里面会调用ngx\_process\_events(cycle, timer, flags); 对事件循环进行polliing  时间一般默认为 500 ms

## 了解nginx的http [core](core.md) module 的结构和运行机制 ##

HTTP相关的Module都在 src/http 目录和其子目录下， 其中 src/http 下的文件为http模块的核心文件，  src/http/modules 下的文件为http模块的扩展模块。

其中：

### ngx\_http.[c|h] ###

ngx\_http.c 中，注册了 http 这个指令的处理模块，对应ngx\_http\_block函数
```
static ngx_command_t  ngx_http_commands[] = {

    { ngx_string("http"),
      NGX_MAIN_CONF|NGX_CONF_BLOCK|NGX_CONF_NOARGS,
      ngx_http_block,
      0,
      0,
      NULL },

      ngx_null_command
};
```

这个函数里面会进行一些conf资源分配/Merge，配置文件解析等工作。 这里面有个一比较重要的工作是注册了nginx http 的 phase handler

```
    if (ngx_http_init_phase_handlers(cf, cmcf) != NGX_OK) {
        return NGX_CONF_ERROR;
    }
```

phase handler的类型在 ngx\_http\_core\_module 这里定义:
```
typedef enum {
    NGX_HTTP_POST_READ_PHASE = 0,

    NGX_HTTP_SERVER_REWRITE_PHASE,

    NGX_HTTP_FIND_CONFIG_PHASE,
    NGX_HTTP_REWRITE_PHASE,
    NGX_HTTP_POST_REWRITE_PHASE,

    NGX_HTTP_PREACCESS_PHASE,

    NGX_HTTP_ACCESS_PHASE,
    NGX_HTTP_POST_ACCESS_PHASE,

    NGX_HTTP_TRY_FILES_PHASE,
    NGX_HTTP_CONTENT_PHASE,

    NGX_HTTP_LOG_PHASE
} ngx_http_phases;
```

每一个phase的handlers 都是一个数组，里面可以包含多个元素，通过 ngx\_array\_push 添加新的handler

其中每个phase的处理大都包含了对ngx\_request\_t 的 write 或者 read event的改写，其中

在 ngx\_http\_core\_content\_phase 里面， 有对location handler的调用， 其中的 r->content\_handler 就是运行时刻从location handler中注册的，
```
    if (r->content_handler) {
        r->write_event_handler = ngx_http_request_empty_handler;
        ngx_http_finalize_request(r, r->content_handler(r)); /*实际的请求发送处理*/
        return NGX_OK;
    }
```

其中， 在各个phase的结束阶段，一般都是调用
```
    r->phase_handler++;
    return NGX_AGAIN;
```
移动request 中 phase\_handler的指针，并且示意主程序继续进行。

这里，无论是phase handler,还是 location handler，我们都是可以在程序里进行注册的。

另外， ngx\_http\_block 里面调用了 ngx\_http\_optimize\_servers ，这个函数对listening和connection相关的变量进行了初始化和调优，并最终在 ngx\_http\_add\_listening （被ngx\_http\_add\_listening调用） 中注册了listening 的 handler 为 ngx\_http\_init\_connection

```
    ls->handler = ngx_http_init_connection;
```

ngx\_http\_init\_connection 在 ngx\_http\_request.c中定义，后续会进行详细的介绍


### ngx\_http\_request.[c|h] ###

这里面，ngx\_http\_init\_connection 注册了connection事件的读操作的回叫函数， 并将写操作设置为空函数
```
    rev = c->read;
    rev->handler = ngx_http_init_request;
    c->write->handler = ngx_http_empty_handler;
```

当新的连接进入的时候，就执行到 ngx\_http\_init\_request, 开始对后面的流程进行处理，主要是将rev的handler 设置为ngx\_http\_process\_request\_line ， 然后ngx\_http\_process\_request\_line 会先后有调度到 ngx\_http\_process\_request\_headers 和  ngx\_http\_process\_request 函数对读取过来的event进行处理，其中， ngx\_http\_process\_request\_headers  里面会对http的请求头进行解析，ngx\_http\_process\_request 设置event handler 到ngx\_http\_request\_handler ，ngx\_http\_request\_handler 中会根据事件可能是读取还是写入的操作分别调用 request 的 read\_event\_handler 和 write\_event\_handler ,所以后续程序对 request 的 [read/write]_event\_handler 调整 本质上类似对 rev 和 wev的handler的调整，只是回叫函数的参数变更为了 ngx\_request\_t 而不是之前的ngx\_event\_t_

```
    c->read->handler = ngx_http_request_handler;
    c->write->handler = ngx_http_request_handler;
    r->read_event_handler = ngx_http_block_reading;
```

根据上面代码可以看出， 模块开始使用 ngx\_http\_block\_reading 这个handler对后续的读请求进行处理

在注册完事件后， ngx\_http\_process\_request 会分别调用下面的两个函数

```
    ngx_http_handler(r);
    ngx_http_run_posted_requests(c);
```

其中， ngx\_http\_handler 在ngx\_http\_core\_module中定义，处理程序的主请求，  ngx\_http\_run\_posted\_requests 在ngx\_http\_request.c 里定义，处理所有提交的子请求数据的输出。


### ngx\_http\_core\_module.[c|h] ###

对于 ngx\_http\_core\_module 是http 模块中比较重要的模块， 他本身是一个 NGX\_HTTP\_MODULE （不同于ngx\_http\_module, ngx\_http\_module本质上是一个 NGX\_CORE\_MODULE

这里面对http block下面的一些指令进行了处理， 比如 server, location 等， 同时， 上面提到的 ngx\_http\_handler 也在这里面

ngx\_http\_handler 所作的最核心的工作就是在最后调用 并将 write event 设置为 ngx\_http\_core\_run\_phases， 开始依次处理各个阶段的 handler

当handler处理完成后，http的处理流程也就基本上完成了..

```
    while (ph[r->phase_handler].checker) {

        rc = ph[r->phase_handler].checker(r, &ph[r->phase_handler]);

        if (rc == NGX_OK) {
            return;
        }
    }
```

run\_phases 的过程实际上非常简单， 一次的运行每一个handler, 当任意一个handler返回ok或者所有handler执行完成后，整个流程结束。

这里需要注意的是， ph的下标变化是根据 r->phase\_handler 变量决定的， 所以在每个handler内部，如果想要让主程序继续处理下一个 handler,需要手动的 r->phase\_handler++ ,将phase handler数组的下标转移到下一个成员。

### 关于subrequest ###

在 ngx\_http\_core\_module 里面，我们可以看到一些subrequest的函数，根据evan miller 的文章，我们知道 subrequest是在主请求的基础上发起的子请求，subrequest返回的内容会被附加到自请求上面，他的实现方法就是调用 ngx\_http\_subrequest 函数，subrequest函数的圆形是
```
ngx_int_t
ngx_http_subrequest(ngx_http_request_t *r,
    ngx_str_t *uri, ngx_str_t *args, ngx_http_request_t **psr,
    ngx_http_post_subrequest_t *ps, ngx_uint_t flags)
```

在里面，在这个函数里，他会1)创建新的request变量，根据 主request的值去填充这个变量2）注册新的变量的write event handler

```
    sr->read_event_handler = ngx_http_request_empty_handler;
    sr->write_event_handler = ngx_http_handler;
```

3) 并且把subrequet 的request 注册到主request的 posted\_requests 变量里
```
    for (p = &r->main->posted_requests; *p; p = &(*p)->next) { /* void */ }
```

也就是说，一但调用了 ngx\_http\_subrequest 只后，subrequest已经已经注册到了nginx的事件循环中，和主循环并行进行处理，所以根据evan miller的文章里我们也可以看到，subrequest的串行处理是比较困难的。


### 关于 internal redirect ###

nginx的 internal redirect 有两种方式， 一个是调用 ngx\_http\_internal\_redirect 命令， 一个是使用 X-Accel-Redirect 头，其中X-Accel-Redirect 头是交由upstream模块进行的， 在ngx\_http\_upstream\_process\_headers函数中，我们可以看到

```
   if (u->headers_in.x_accel_redirect
        && !(u->conf->ignore_headers & NGX_HTTP_UPSTREAM_IGN_XA_REDIRECT))
   {
        .....
        .....
        ngx_http_internal_redirect(r, uri, &args);
        return NGX_DONE;
    }
```

也就是说，本质上，这两种方法都是通过 ngx\_http\_internal\_redirect 的函数实现的，而ngx\_http\_internal\_redirect 函数又做了些什么呢？

```
    r->internal = 1;

    ngx_http_handler(r);

    return NGX_DONE;
```

可以看到，其实它只是简单的修改request结构体，并通过 ngx\_http\_handler 重新进行http处理流程而已。

关于internal redirect 和 subrequest,他们有类似的地方，都是在最后调用 ngx\_http\_handler 重新开始对request的处理，但是不同的地方我想主要是 subrequest会新建立一个request结构，原来的request处理并不会结束，而 internal redirect会结束当前的请求处理，使用嗯但前的request结构体来发起请求。

### 关于upstream ###

upstream是nginx里面非常重要的一种处理模式，nginx的很多模块都是使用他来完成的， upstream和普通的handler有很大的不同，比如nginx的location handler 和phase handler, 他们的处理模式非常类似apache的handler,就是获取后同步的进行处理，但是对于有些场合，比如proxy或者fastcgi, nginx进程需要和上游的服务(http,或者php-cgi）进行交互，并且将结果返回给客户端，在交互的过程中，由于后端服务的响应时间各异，如果后端服务的响应时间过长，nginx等待后端服务响应的过程一之同步阻塞在这里是不现实的，所以nginx采用了异步的方案，每当上游服务器有响应的时候才进行处理，并将处理结果返回给前端，这样nginx在处理上游请求的时候，可以同时注册多个io时间，使用epoll\_wait(linux下默认) 也就是nginx的主事件循环进行处理，大大提高了nginx的并发能里，每个进程可以处理多个连接 ，不会因为一个上游连接阻塞整个nginx进程， 当然这也有依赖于你程序的实现方式。

关于upstream的使用方式， evan miller的文章里已经说的很清楚了，就是可以在location handler里（或者其它插入点中） 注册upstream的一些callback


```
    u->conf = &plcf->upstream;

/* attach the callback functions */
    u->create_request = ngx_http_proxy_create_request;
    u->reinit_request = ngx_http_proxy_reinit_request;
    u->process_header = ngx_http_proxy_process_status_line;
    u->abort_request = ngx_http_proxy_abort_request;
    u->finalize_request = ngx_http_proxy_finalize_request;

    r->upstream = u;

```

并且最后在调用 ngx\_http\_read\_client\_request\_body 中传入 ngx\_http\_upstream\_init 作为callback function 参数初始化 upstream流程, 在 ngx\_http\_upsteam\_init 里面，会调用 ngx\_http\_upstream\_connect建立连接，并注册读写的event handler

```
	/* event handler 最终会根据读／或者写的请求调用 write_event_handler和 read_event_handler ，也就是  ngx_http_upstream_send_request_handler和
	ngx_http_upstream_process_header */
    c->write->handler = ngx_http_upstream_handler;
    c->read->handler = ngx_http_upstream_handler;

    u->write_event_handler = ngx_http_upstream_send_request_handler;
    u->read_event_handler = ngx_http_upstream_process_header;
```

这里需要注意的是，在处理上游请求的时候，由于是异步的事件，所以每次上游服务器在调用callback的时候并不一定返回的是全部数据，process\_header 函数必须根据判断每次返回的数据包是否完成，如果没有处理完成则返回 NGX\_AGAIN,来指示nginx需要重新进入process\_header函数进行处理，并知道处理完成的时候返回NGX\_OK 来指示nginx完成处理。 具体的例子可以参考 fastcgi 模块的ngx\_http\_fastcgi\_process\_header函数

另外， nginx可以针对上游服务的响应body进行处理， 通过注册 u->pipe->input\_filter 这个回叫来实现，同样可以参考fastcgi模块，下面是例子

```
    /* 这里注册对于响应体的处理 */
    u->pipe->input_filter = ngx_http_fastcgi_input_filter;
    u->pipe->input_ctx = r;
```

通常在处理的过程中需要自己创建状态机来处理请求的不同状态，对于一些请求相关的信息，可以自己创建结构体，通过

```
#define ngx_http_get_module_ctx(r, module)  (r)->ctx[module.ctx_index]
#define ngx_http_set_ctx(r, c, module)      r->ctx[module.ctx_index] = c;
```

这两个宏进行读取和存储。