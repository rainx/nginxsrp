#include <stdio.h>
#include "ngx_config.h"
#include "ngx_conf_file.h"
#include "nginx.h"
#include "ngx_core.h"
#include "ngx_string.h"
#include "ngx_palloc.h"
#include "ngx_shmem.h"

volatile ngx_cycle_t  *ngx_cycle;

void ngx_log_error_core(ngx_uint_t level, ngx_log_t *log, ngx_err_t err, const char *fmt, ...) { } 


int main()
{
    ngx_shm_t shm;
    ngx_int_t  ret;
    // shm.name = ngx_string("shm_test");
    shm.name.len = sizeof("shm_test");
    shm.name.data = (u_char*) ("shm_test");
    shm.size = 1024;
    shm.log  = NULL;

    ret = ngx_shm_alloc(&shm);
    printf("ret is %d\n", ret);
    ngx_shm_free(&shm);
    return 0;
}
