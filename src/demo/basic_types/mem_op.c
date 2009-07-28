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
    printf("NGX_MAX_ALLOC_FROM_POOL is %d\n", NGX_MAX_ALLOC_FROM_POOL);
    ngx_destroy_pool(pool);
    return 0;
}
