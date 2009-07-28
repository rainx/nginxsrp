#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

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

int main()
{
	// 创建内存池
	ngx_pool_t *p = ngx_create_pool(128, NULL);

	int fd = open("test.dat", O_WRONLY|O_CREAT, 0644);
	
	// 新增注册资源清理项，分配一个文件清理结构
	ngx_pool_cleanup_t *cp = ngx_pool_cleanup_add(p, sizeof(ngx_pool_cleanup_file_t));
	cp->handler = ngx_pool_cleanup_file;	// 使用默认的文件清理回调函数，仅关闭文件描述符
	// 设置分配到的文件清理结构
	ngx_pool_cleanup_file_t *cfp = (ngx_pool_cleanup_file_t *)(cp->data);
	cfp->fd = fd;	// 注册待清理的文件描述符
	cfp->name = NULL;
	cfp->log = NULL;

	// 既可等待内存池销毁时自动启动文件清理过程，也可以在这里强行启动针对特定文件描述符的清理过程
	ngx_pool_run_cleanup_file(p, fd);

	// 这里文件描述符已经被关闭
	printf("write() rc: %d (Expect failed)\n", write(fd, "c", 1));
	printf("error msg: %s (Expect EBADF)\n", strerror(errno));

	ngx_pool_run_cleanup_file(p, fd);	// 一次清理完毕后对应资源清理项的回调函数指针就被清空，因此连续多次调用没有作用！

	// 重新打开文件描述符
	fd = open("test.dat", O_WRONLY|O_CREAT, 0644);

	// 新增注册资源清理项，分配一个文件清理结构
	cp = ngx_pool_cleanup_add(p, sizeof(ngx_pool_cleanup_file_t));
	cp->handler = ngx_pool_delete_file;	// 使用默认的文件删除回调函数，删除文件清理结构中设置的文件，并关闭设置的文件描述符
	// 设置分配到的文件清理结构
	cfp = (ngx_pool_cleanup_file_t *)(cp->data);
	cfp->fd = fd;
	cfp->name = (u_char*)"./test.dat";	// 待删除的文件路径
	cfp->log = NULL;

	// 文件删除过程只能在内存池销毁时启动，这里无法强制启动
	ngx_pool_run_cleanup_file(p, fd);

	// 因此这里的文件描述符仍然可用
	printf("write() rc: %d (Expect success)\n", write(fd, "c", 1));

	printf("About to destroy pool...\n");

	// 销毁内存池，释放所有资源
	// 此时文件删除过程启动
	ngx_destroy_pool(p);

	return 0;
}

