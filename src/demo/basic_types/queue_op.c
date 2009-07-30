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

	// 找到位于队列中间(若队列有奇数个元素就是正中间，若有偶数个元素则为后半部分的首个元素)的元素输出
	{
		ngx_queue_t *m = ngx_queue_middle(&yahoo->queue);
		guy = ngx_queue_data(m, yahoo_guy_t, queue);
		printf("Middle man: ID: %d, Name: %s\n", guy->id, guy->name);
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
    
	// 找到位于队列中间(若队列有奇数个元素就是正中间，若有偶数个元素则为后半部分的首个元素)的元素输出
	{
		ngx_queue_t *m = ngx_queue_middle(&yahoo->queue);
		guy = ngx_queue_data(m, yahoo_guy_t, queue);
		printf("Middle man: ID: %d, Name: %s\n", guy->id, guy->name);
	}
	
    ngx_destroy_pool(pool);
    return 0;
}
