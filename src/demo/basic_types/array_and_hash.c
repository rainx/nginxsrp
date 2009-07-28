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
