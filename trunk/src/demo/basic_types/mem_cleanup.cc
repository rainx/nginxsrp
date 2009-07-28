#include <stdio.h>

extern "C" {

#include "ngx_config.h"
#include "nginx.h"
#include "ngx_core.h"
#include "ngx_string.h"
#include "ngx_palloc.h"

	// 避免加载整个NginX日志子系统而定义的空日志核心函数
	void ngx_log_error_core(ngx_uint_t level, ngx_log_t *log, ngx_err_t err, const char *fmt, ...)
	{
	}

}

// 自定义资源清理回调函数
void do_nothing_cleanup(void *data)
{
	printf("Customized resource cleanup callback called!\n");
}

class A {
public:
	A() { printf("A ctor called!\n"); }
	~A() { printf("A dtor called!\n"); }
};

void object_A_cleanup(void *data)
{
	A *p = reinterpret_cast<A *>(data);
	delete p;
}

int main()
{
	// 创建内存池
	ngx_pool_t *p = ngx_create_pool(1234, NULL);

	// 计算内存池可用空间大小
	ngx_uint_t free_size = p->d.end - p->d.last;

	printf("pool free: %d bytes, total: %d bytes\n",
			free_size,
			free_size + sizeof(ngx_pool_t));

	// 新增注册资源清理项，同时从内存池中分配指定大小的内存块
	ngx_pool_cleanup_t *cp = ngx_pool_cleanup_add(p, 456);
	cp->handler = do_nothing_cleanup;	// 由于内存块是从内存池中分配的，因此这里注册的资源清理函数无须进行释放工作
	// 使用分配到的内存块
	char *mem = (char *)(cp->data);
	for(int i = 0; i < 456; ++ i) {
		mem[i] = i;
	}

	ngx_uint_t nfree_size = p->d.end - p->d.last;
	printf("pool free: %d bytes, diff: %d bytes\n", nfree_size, free_size - 456 - sizeof(ngx_pool_cleanup_t));

	// 这次仅仅新增注册资源清理项，不分配内存资源
	cp = ngx_pool_cleanup_add(p, 0);
	cp->data = new A();	// 将外部资源委托给资源清理项管理
	cp->handler = object_A_cleanup;	// 注册对应的资源清理函数，此时该函数需要负责清理外部资源

	printf("About to destroy pool...\n");

	// 销毁内存池，释放所有资源
	ngx_destroy_pool(p);

	return 0;
}

