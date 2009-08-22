/*
    一个例子模块，简单的将http请求的内容返输出
    V4 版本： 
        使用upstream来实现的版本
        需要设置的参数出了 echov4_times 之外， 
        还有echov4_pass :指明echo服务的upstream地址
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
static ngx_int_t ngx_http_echo_filter_init(ngx_conf_t* cf);
static ngx_int_t ngx_http_echo_header_filter(ngx_http_request_t* r);
static ngx_int_t ngx_http_echo_body_filter(ngx_http_request_t* r, ngx_chain_t* in);

/*
  upstream 相关的callback
 */

static ngx_int_t ngx_http_echo_create_request(ngx_http_request_t *r);
static ngx_int_t ngx_http_echo_reinit_request(ngx_http_request_t *r);
static ngx_int_t ngx_http_echo_process_header(ngx_http_request_t *r);
static void ngx_http_echo_abort_request(ngx_http_request_t *r);
static void ngx_http_echo_finalize_request(ngx_http_request_t *r, ngx_int_t rc);


/*
 必须要包含的两个变量
*/
static ngx_http_output_header_filter_pt  ngx_http_next_header_filter;
static ngx_http_output_body_filter_pt    ngx_http_next_body_filter;

/*
    定义一个loc的上下文结构体，保存配置信息等
*/
typedef struct ngx_http_echov4_loc_conf_s {
    ngx_int_t  echo_times;      /* echo要被显示的次数 */
    ngx_http_upstream_conf_t upstream; 
} ngx_http_echov4_loc_conf_t;

/*
    定义一个request life cycle的结构体，用来保存per request的运行时状态等信息
    保存在 r->ctx[index of our module] 中
*/
typedef struct ngx_http_echov4_request_ctx_s {
    ngx_int_t       current_echo_times; /* 已经被显示的次数 */
    ngx_str_t*      post_content;       /* 要发送的内容       */
} ngx_http_echov4_request_ctx_t ;

void ngx_http_echov4_request_post_handler (ngx_http_request_t *r)
{ }

/* 
    定义echo的conf文件指令集 
*/
static ngx_command_t ngx_http_echo_commands[] = {
    { ngx_string("echov4_pass"),      /* 设定echo的handler */
      NGX_HTTP_LOC_CONF|NGX_HTTP_LIF_CONF|NGX_CONF_TAKE1,
      &ngx_conf_set_echo,
      NGX_HTTP_LOC_CONF_OFFSET,
      0,
      NULL },
    { ngx_string("echov4_times"), /* 设置echo的次数 */
      NGX_HTTP_LOC_CONF|NGX_CONF_TAKE1,
      ngx_conf_set_num_slot,
      NGX_HTTP_LOC_CONF_OFFSET,
      offsetof(ngx_http_echov4_loc_conf_t, echo_times),
      NULL },
    ngx_null_command
};

/*
    echo 指令的处理，主要是进行handler的注册 
*/
static char* 
ngx_conf_set_echo(ngx_conf_t *cf, ngx_command_t *cmd, void* conf)
{
    ngx_http_core_loc_conf_t*   clcf;
    ngx_str_t                  *value;
    ngx_url_t                   u;
    ngx_http_echov4_loc_conf_t* elcf = (ngx_http_echov4_loc_conf_t*) conf; 

    ngx_log_debug0(NGX_LOG_DEBUG_HTTP, cf->log, 0, "ngx_conf_set_echo called - [rainx]");
    clcf = ngx_http_conf_get_module_loc_conf(cf, ngx_http_core_module);
    clcf->handler = ngx_http_echo_handler;

    value = cf->args->elts;

    u.url = value[1];
    u.no_resolve = 1;
    elcf->upstream.upstream = ngx_http_upstream_add(cf, &u, 0);
    if (elcf->upstream.upstream == NULL){
        return NGX_CONF_ERROR;
    }
    
    return NGX_CONF_OK;
}



/*
    create conf for loc 
*/
static void* 
ngx_http_echo_create_loc_conf(ngx_conf_t *cf)
{
    ngx_http_echov4_loc_conf_t *conf;
    ngx_log_debug0(NGX_LOG_DEBUG_HTTP, cf->log, 0, "ngx_http_echo_create_loc_conf called - [rainx]");
    conf = ngx_pcalloc(cf->pool, sizeof(ngx_http_echov4_loc_conf_t));
    if (conf == NULL) {
        return NGX_CONF_ERROR;
    }
    /* from memcached module */
    conf->upstream.connect_timeout = NGX_CONF_UNSET_MSEC;
    conf->upstream.send_timeout = NGX_CONF_UNSET_MSEC;
    conf->upstream.read_timeout = NGX_CONF_UNSET_MSEC;

    conf->upstream.buffer_size = NGX_CONF_UNSET_SIZE;

    /* the hardcoded values */
    conf->upstream.cyclic_temp_file = 0;
    conf->upstream.buffering = 0;
    conf->upstream.ignore_client_abort = 0;
    conf->upstream.send_lowat = 0;
    conf->upstream.bufs.num = 0;
    conf->upstream.busy_buffers_size = 0;
    conf->upstream.max_temp_file_size = 0;
    conf->upstream.temp_file_write_size = 0;
    conf->upstream.intercept_errors = 1;
    conf->upstream.intercept_404 = 1;
    conf->upstream.pass_request_headers = 0;
    conf->upstream.pass_request_body = 0;


    conf->echo_times = NGX_CONF_UNSET;

    return conf;
}

/*
    merge conf for loc
*/
static char* 
ngx_http_echo_merge_loc_conf(ngx_conf_t* cf, void* parent, void* child)
{
    ngx_http_echov4_loc_conf_t* prev = parent;
    ngx_http_echov4_loc_conf_t* conf = child;
    ngx_log_debug0(NGX_LOG_DEBUG_HTTP, cf->log, 0, "ngx_http_echo_merge_loc_conf called - [rainx]");
    
    if (conf->echo_times == NGX_CONF_UNSET) {
        conf->echo_times = prev->echo_times;
    }

    /* from memcached */
    ngx_conf_merge_msec_value(conf->upstream.connect_timeout,
            prev->upstream.connect_timeout, 60000);

    ngx_conf_merge_msec_value(conf->upstream.send_timeout,
            prev->upstream.send_timeout, 60000);

    ngx_conf_merge_msec_value(conf->upstream.read_timeout,
            prev->upstream.read_timeout, 60000);

    ngx_conf_merge_size_value(conf->upstream.buffer_size,
            prev->upstream.buffer_size,
            (size_t) ngx_pagesize);

    ngx_conf_merge_bitmask_value(conf->upstream.next_upstream,
            prev->upstream.next_upstream,
            (NGX_CONF_BITMASK_SET
             |NGX_HTTP_UPSTREAM_FT_ERROR
             |NGX_HTTP_UPSTREAM_FT_TIMEOUT));

    if (conf->upstream.next_upstream & NGX_HTTP_UPSTREAM_FT_OFF) {
        conf->upstream.next_upstream = NGX_CONF_BITMASK_SET
            |NGX_HTTP_UPSTREAM_FT_OFF;
    }

    if (conf->upstream.upstream == NULL) {
        conf->upstream.upstream = prev->upstream.upstream;
    }


    return NGX_CONF_OK;
}

/*
    HTTP 上下文 
*/
 
static ngx_http_module_t ngx_http_echo_module_ctx = {  
    NULL,                       /* preconfiguration */
    ngx_http_echo_filter_init,                       /* postconfiguration */
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
ngx_module_t ngx_http_echov4_module = {
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
    ngx_http_echov4_loc_conf_t*     echo_conf;
    ngx_int_t                       rc;
    u_char*                         post_content = NULL;
    size_t                          post_content_len = 0;
    ngx_http_echov4_request_ctx_t*  echo_ctx;
    ngx_http_upstream_t*            u;

    echo_conf = ngx_http_get_module_loc_conf(r, ngx_http_echov4_module);
    // 我们模块运行时的上下文，如果没有的话，我们将进行初始化工作
    echo_ctx  = (ngx_http_echov4_request_ctx_t*) ngx_http_get_module_ctx(r, ngx_http_echov4_module);
    if (!echo_ctx){ //初始化
        echo_ctx = ngx_pcalloc(r->pool, sizeof(ngx_http_echov4_request_ctx_t)); 
        /*
            实际上calloc 已经把结构体里的数值设置为0 
        */
        echo_ctx->current_echo_times = 0;
        echo_ctx->post_content = ngx_pcalloc(r->pool, sizeof(ngx_str_t));

        ngx_http_set_ctx(r, echo_ctx, ngx_http_echov4_module);
    }
 
    rc = ngx_http_read_client_request_body(r, ngx_http_echov4_request_post_handler);
    if (rc >= NGX_HTTP_SPECIAL_RESPONSE) {
        return rc;
    }

    if (!(r->method &(NGX_HTTP_POST))) {
        return NGX_HTTP_NOT_ALLOWED;
    }

    ngx_http_dump_request_headers(r);
    // 将post_content的数值赋值给结构体
    post_content_len = ngx_http_dump_request_body(r, /* out */(void*) &post_content);
    echo_ctx->post_content->len = post_content_len;
    echo_ctx->post_content->data = post_content;     

    u = ngx_pcalloc(r->pool, sizeof(ngx_http_upstream_t));
    if (u == NULL) {
        return NGX_HTTP_INTERNAL_SERVER_ERROR;
    }

    u->schema.len = sizeof("echo://") - 1;
    u->schema.data = (u_char *) "echo://";

    u->peer.log = r->connection->log;
    u->peer.log_error = NGX_ERROR_ERR;
#if (NGX_THREADS)
    u->peer.lock = &r->connection->lock;
#endif

    u->output.tag = (ngx_buf_tag_t) &ngx_http_echov4_module;

    u->conf = &echo_conf->upstream;

    u->create_request = ngx_http_echo_create_request;
    u->reinit_request = ngx_http_echo_reinit_request;
    u->process_header = ngx_http_echo_process_header;
    u->abort_request = ngx_http_echo_abort_request;
    u->finalize_request = ngx_http_echo_finalize_request;
    r->upstream = u;

    ngx_http_upstream_init(r);

    return NGX_DONE;
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
    post_content = ngx_palloc(r->pool, rb->buf->last - rb->buf->pos + 1);
    ngx_cpystrn(post_content, rb->buf->pos, rb->buf->last - rb->buf->pos + 1);	// ngx_cpystrn()长度参数应为实际数据长度+1，是其for循环编写有误所致……
    ngx_log_debug1(NGX_LOG_DEBUG_HTTP, r->connection->log, 0, 
            "\n                       [ buf pos data  = %s ]\n"
			"                         [ data length = %d ]\n",
            post_content,
			rb->buf->last - rb->buf->pos
            );
    *post_content_ptr = post_content;
    return rb->buf->last - rb->buf->pos;
}

static void ngx_http_dump_request_headers(ngx_http_request_t* r)
{
    // ngx_http_headers_in_t       h; 
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


// 注册filter
static ngx_int_t 
ngx_http_echo_filter_init(ngx_conf_t* cf)
{
    ngx_http_next_header_filter     = ngx_http_top_header_filter;
    ngx_http_top_header_filter      = ngx_http_echo_header_filter;
    ngx_http_next_body_filter       = ngx_http_top_body_filter;
    ngx_http_top_body_filter        = ngx_http_echo_body_filter;
    
    return NGX_OK;
}

// 修改header头的size
static ngx_int_t
ngx_http_echo_header_filter(ngx_http_request_t* r)
{
    /* 获取echo_times和current_echo_times */ 
    ngx_http_echov4_loc_conf_t*     echo_conf;
    ngx_http_echov4_request_ctx_t*  echo_ctx;
    echo_conf = ngx_http_get_module_loc_conf(r, ngx_http_echov4_module);
    // 我们模块运行时的上下文，如果没有的话，我们将不进行处理
    echo_ctx  = (ngx_http_echov4_request_ctx_t*) ngx_http_get_module_ctx(r, ngx_http_echov4_module);
    ngx_log_debug0(NGX_LOG_DEBUG_HTTP, r->connection->log, 0, "ngx_echo_header_filter called - [rainx]");
    // 如果当前的输出次数已经比设定的大
    if (!echo_ctx || echo_ctx->current_echo_times >= echo_conf->echo_times){ 
        return ngx_http_next_header_filter(r);
    }
    // 将content_length的数值设定为原来的长度乘以 echo_times;    
    if (r->headers_out.content_length_n)
        r->headers_out.content_length_n = r->headers_out.content_length_n * echo_conf->echo_times;

    return ngx_http_next_header_filter(r);
}

static ngx_int_t
ngx_http_echo_body_filter(ngx_http_request_t* r, ngx_chain_t* in)
{
    /* 获取echo_times和current_echo_times */ 
    ngx_http_echov4_loc_conf_t*     echo_conf;
    ngx_chain_t*                    chain_link;
    ngx_chain_t*                    new_link;
    ngx_buf_t*                      new_buf;
    ngx_http_echov4_request_ctx_t*  echo_ctx;
    int                             i;
    ngx_log_debug0(NGX_LOG_DEBUG_HTTP, r->connection->log, 0, "ngx_echo_body_filter called - [rainx]");
    echo_conf = ngx_http_get_module_loc_conf(r, ngx_http_echov4_module);
    // 我们模块运行时的上下文，如果没有的话，我们将不进行处理
    echo_ctx  = (ngx_http_echov4_request_ctx_t*) ngx_http_get_module_ctx(r, ngx_http_echov4_module);
    if (!echo_ctx || echo_ctx->current_echo_times >= echo_conf->echo_times){ 
        return ngx_http_next_body_filter(r, in);
    }
    ngx_log_debug2(NGX_LOG_DEBUG_HTTP, r->connection->log, 0, 
            "ngx_http_echo_handler called[v2] - [rainx]\n"
            "Dump of ngx_http_echov4_loc_ctx_t current_echo_times=[%d]\n"
            "Dump of ngx_http_echov4_loc_conf_t echo_times=[%d]",
            echo_ctx->current_echo_times,
            echo_conf->echo_times
            );

    chain_link = in;

    for ( i = 0 ; 
          i < echo_conf->echo_times - echo_ctx->current_echo_times;
          i++) {
        new_link = ngx_alloc_chain_link(r->pool);
        new_buf  = ngx_calloc_buf(r->pool);
        // 创建buffer并赋值
        new_buf->pos        = echo_ctx->post_content->data;
        new_buf->last       = echo_ctx->post_content->data + echo_ctx->post_content->len;
        new_buf->memory     = 1;
        new_buf->last_buf   = 1;
        new_link->buf       = new_buf;
        
        // 修改chain_link,将,新增的chain放到chain link的最前面
        new_link->next      = chain_link;
        chain_link          = new_link;
    }

    echo_ctx->current_echo_times = echo_conf->echo_times;
      
    return ngx_http_next_body_filter(r, chain_link);
}


static ngx_int_t
ngx_http_echo_create_request(ngx_http_request_t* r)
{
    ngx_http_echov4_loc_conf_t*         elcf;
    ngx_http_echov4_request_ctx_t*      ctx;
    ngx_buf_t*                          b;
    ngx_chain_t*                        cl;
    elcf        = ngx_http_get_module_loc_conf(r, ngx_http_echov4_module);
    ctx         = ngx_http_get_module_ctx(r, ngx_http_echov4_module);

    b = ngx_create_temp_buf(r->pool, ctx->post_content->len);
    if (b == NULL) {
        return NGX_ERROR;
    }

    cl = ngx_alloc_chain_link(r->pool);
    if (cl == NULL) {
        return NGX_ERROR;
    }

    cl->buf = b;
    cl->next = NULL;

    r->upstream->request_bufs = cl;

    b->last = ngx_copy(b->last, ctx->post_content->data, ctx->post_content->len + 1);	// 复制末尾的'\0'以保证process_header正常完成
    
    return NGX_OK;
}

static ngx_int_t
ngx_http_echo_reinit_request(ngx_http_request_t* r)
{
    return NGX_OK;
}

static ngx_int_t
ngx_http_echo_process_header(ngx_http_request_t* r)
{
    u_char                    *p;
    ngx_http_upstream_t       *u;

    u = r->upstream;
    for (p = u->buffer.pos; p < u->buffer.last; p++) {
        if (*p == LF || *p == '\0') {
            goto found;
        }
    }

    return NGX_AGAIN;

found: 
    *p = '\0'; 
    
    r->headers_out.content_length_n = p - u->buffer.pos;
    u->headers_in.status_n = 200;
    u->state->status = 200;

    return NGX_OK;
}

static void
ngx_http_echo_abort_request(ngx_http_request_t* r)
{
    return;
}

static void
ngx_http_echo_finalize_request(ngx_http_request_t* r, ngx_int_t rc)
{
    return ;
}
