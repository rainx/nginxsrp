/*
    一个例子模块，简单的将http请求的内容返输出
    by RainX
*/

#include <ngx_config.h>
#include <ngx_core.h>
#include <ngx_http.h>

/*
    函数的声明
*/
static ngx_int_t ngx_http_echo_handler(ngx_http_request_t* r);
static char* ngx_conf_set_echo(ngx_conf_t *cf, ngx_command_t* cmd, void* conf);
static void* ngx_http_echo_create_loc_conf(ngx_conf_t *cf);
static char* ngx_http_echo_merge_loc_conf(ngx_conf_t* cf, void* parent, void* child);
static size_t ngx_http_dump_request_body(ngx_http_request_t* r, void** post_content_ptr);
static void ngx_http_dump_request_headers(ngx_http_request_t* r);

/*
    定义一个loc的上下文结构体，保存配置信息等
*/
typedef struct ngx_http_echo_loc_conf_s {
    ngx_int_t  echo_times;   /* echo要被显示的次数 */
} ngx_http_echo_loc_conf_t;


void ngx_http_echo_request_post_handler (ngx_http_request_t *r)
{ }

/* 
    定义echo的conf文件指令集 
*/
static ngx_command_t ngx_http_echo_commands[] = {
    { ngx_string("echo"),      /* 设定echo的handler */
      NGX_HTTP_LOC_CONF|NGX_CONF_NOARGS,
      &ngx_conf_set_echo,
      NGX_HTTP_LOC_CONF_OFFSET,
      0,
      NULL },
    { ngx_string("echo_times"), /* 设置echo的次数 */
      NGX_HTTP_LOC_CONF|NGX_CONF_TAKE1,
      ngx_conf_set_num_slot,
      NGX_HTTP_LOC_CONF_OFFSET,
      offsetof(ngx_http_echo_loc_conf_t, echo_times),
      NULL },
    ngx_null_command
};

/*
    echo 指令的处理，主要是进行handler的注册 
*/
static char* 
ngx_conf_set_echo(ngx_conf_t *cf, ngx_command_t *cmd, void* conf)
{
    ngx_http_core_loc_conf_t* clcf;
    ngx_log_debug0(NGX_LOG_DEBUG_HTTP, cf->log, 0, "ngx_conf_set_echo called - [rainx]");
    clcf = ngx_http_conf_get_module_loc_conf(cf, ngx_http_core_module);
    clcf->handler = ngx_http_echo_handler;
    
    return NGX_CONF_OK;
}



/*
    create conf for loc 
*/
static void* 
ngx_http_echo_create_loc_conf(ngx_conf_t *cf)
{
    ngx_http_echo_loc_conf_t *conf;
    ngx_log_debug0(NGX_LOG_DEBUG_HTTP, cf->log, 0, "ngx_http_echo_create_loc_conf called - [rainx]");
    conf = ngx_pcalloc(cf->pool, sizeof(ngx_http_echo_loc_conf_t));
    if (conf == NULL) {
        return NGX_CONF_ERROR;
    }

    conf->echo_times = NGX_CONF_UNSET;

    return conf;
}

/*
    merge conf for loc
*/
static char* 
ngx_http_echo_merge_loc_conf(ngx_conf_t* cf, void* parent, void* child)
{
    ngx_http_echo_loc_conf_t* prev = parent;
    ngx_http_echo_loc_conf_t* conf = child;
    ngx_log_debug0(NGX_LOG_DEBUG_HTTP, cf->log, 0, "ngx_http_echo_merge_loc_conf called - [rainx]");
    
    if (conf->echo_times == NGX_CONF_UNSET) {
        conf->echo_times = prev->echo_times;
    }

    return NGX_CONF_OK;
}

/*
    HTTP 上下文 
*/
 
static ngx_http_module_t ngx_http_echo_module_ctx = {  
    NULL,                       /* preconfiguration */
    NULL,                       /* postconfiguration */
    NULL,                       /* create main configuration */
    NULL,                       /* init main configuration */
    
    NULL,                       /* create server configuration */
    NULL,                       /* merge server configuration */

    ngx_http_echo_create_loc_conf, /* create location configuration */
    ngx_http_echo_merge_loc_conf   /* merge location configuration */
};


/* 
 定义模块 
*/
ngx_module_t ngx_http_echo_module = {
    NGX_MODULE_V1,
    &ngx_http_echo_module_ctx,      /* 模块的上下文 */ 
    ngx_http_echo_commands,        /* 模块的指令 */
    NGX_HTTP_MODULE,                /* 模块的类型 */
    NULL,                           /* 初始化master */
    NULL,                           /* 初始化模块 */
    NULL,                           /* 初始化process*/
    NULL,                           /* 初始化线程 */
    NULL,                           /* 退出线程 */
    NULL,                           /* 退出process */
    NULL,                           /* 退出master */
    NGX_MODULE_V1_PADDING
};


/* 
    echo 处理handler
*/
static ngx_int_t 
ngx_http_echo_handler(ngx_http_request_t* r)
{
    ngx_http_echo_loc_conf_t*       echo_conf;
    ngx_chain_t                     out;
    ngx_int_t                       rc;
    ngx_buf_t*                      b;
    u_char*                         post_content = NULL;
    size_t                          post_content_len = 0;
    ngx_log_debug0(NGX_LOG_DEBUG_HTTP, r->connection->log, 0, "ngx_http_echo_handler called - [rainx]");
    echo_conf = ngx_http_get_module_loc_conf(r, ngx_http_echo_module);
    
    rc = ngx_http_read_client_request_body(r, ngx_http_echo_request_post_handler);

    if (rc >= NGX_HTTP_SPECIAL_RESPONSE) {
        return rc;
    }

    ngx_http_dump_request_headers(r);
    post_content_len = ngx_http_dump_request_body(r, /* out */(void*) &post_content);

    if (!(r->method &(NGX_HTTP_POST))) {
        return NGX_HTTP_NOT_ALLOWED;
    }

    // 获取post data 

    ngx_log_debug1(NGX_LOG_DEBUG_HTTP, r->connection->log, 0, "POST CONTENT LEN IS %d, DATA: %p - [rainx]",
            post_content_len, post_content);
    //输出头
    r->headers_out.content_type_len = sizeof("text/plain") - 1;
    r->headers_out.content_type.len = sizeof("text/plain") - 1;
    r->headers_out.content_type.data = (u_char *) "text/plain";
    r->headers_out.status = NGX_HTTP_OK;
    r->headers_out.content_length_n = post_content_len;
    
    rc = ngx_http_send_header(r);

    if (rc == NGX_ERROR || rc > NGX_OK || r->header_only) {
        return rc;
    }

    // 输出内容：

    b = ngx_pcalloc(r->pool, sizeof(ngx_buf_t));
    if (b == NULL) {
        return NGX_HTTP_INTERNAL_SERVER_ERROR;
    }

    out.buf = b;
    out.next = NULL;
    b->pos = post_content;
    b->last = post_content + post_content_len;
    b->memory = 1;
    b->last_buf = 1;

    return ngx_http_output_filter(r, &out);
}


// 将request body 的数据打印出来
static size_t
ngx_http_dump_request_body(ngx_http_request_t* r, void** post_content_ptr)
{
    ngx_http_request_body_t*            rb;
    u_char*                             post_content = NULL;
    rb = r->request_body; 
    ngx_log_debug0(NGX_LOG_DEBUG_HTTP, r->connection->log, 0, "ngx_http_dump_request_body entried - [rainx]");
    if (!rb) { 
        ngx_log_debug0(NGX_LOG_DEBUG_HTTP, r->connection->log, 0, "request body is empty - [rainx]");
        return 0;
    }

    // check a bit

    ngx_log_debug7(NGX_LOG_DEBUG_HTTP, r->connection->log, 0, 
            "\nParameters dump is :   [ rb->temp_file = %p ]\n"
            "                       [ rb->bufs      = %p ]\n"
            "                       [ rb->bufs->buf = %p ]\n"
            "                       [ rb->buf       = %p ]\n"
            "                       [ rb->rest      = %d ]\n"
            "                       [ rb->to_write  = %d ]\n"
            "                       [ buf size      = %d ]\n",
            "                       [ buf pos       = %d ]\n",
            "                       [ buf last      = %d ]\n",
            rb->temp_file,
            rb->bufs,
            rb->bufs->buf,
            rb->buf,
            rb->rest,
            rb->to_write,
            rb->buf->end - rb->buf->start
            );
    ngx_log_debug2(NGX_LOG_DEBUG_HTTP, r->connection->log, 0, 
            "\n                       [ buf pos       = %p ]\n"
            "                       [ buf last      = %p ]\n",
            rb->buf->pos,
            rb->buf->last
            );
    post_content = ngx_palloc(r->pool, rb->buf->last-rb->buf->pos + 1);
    ngx_cpystrn(post_content, rb->buf->pos, rb->buf->last-rb->buf->pos);
    ngx_log_debug1(NGX_LOG_DEBUG_HTTP, r->connection->log, 0, 
            "\n                       [ buf pos data  = %s ]",
            post_content
            );
    *post_content_ptr = post_content;
    return rb->buf->last-rb->buf->pos;
}

static void ngx_http_dump_request_headers(ngx_http_request_t* r)
{
    //    ngx_http_headers_in_t       h; 
    // dump some data
    ngx_log_debug1(NGX_LOG_DEBUG_HTTP, r->connection->log, 0, "[rainx] request_line is : %V",  &r->request_line);
    ngx_log_debug1(NGX_LOG_DEBUG_HTTP, r->connection->log, 0, "[rainx] uri is : %V",  &r->uri);
    ngx_log_debug1(NGX_LOG_DEBUG_HTTP, r->connection->log, 0, "[rainx] args is : %V",  &r->args);
    ngx_log_debug1(NGX_LOG_DEBUG_HTTP, r->connection->log, 0, "[rainx] exten is : %V",  &r->exten);
    ngx_log_debug1(NGX_LOG_DEBUG_HTTP, r->connection->log, 0, "[rainx] unparsed_uri is : %V",  &r->unparsed_uri);
    ngx_log_debug1(NGX_LOG_DEBUG_HTTP, r->connection->log, 0, "[rainx] method_name is : %V",  &r->method_name);
    ngx_log_debug1(NGX_LOG_DEBUG_HTTP, r->connection->log, 0, "[rainx] http_protocol is : %V",  &r->http_protocol);

    return ;
}
