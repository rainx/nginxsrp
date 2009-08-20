#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#include <iostream>
#include <string>
#include <cassert>

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

	volatile ngx_cycle_t  *ngx_cycle;
}

using namespace ::std;

template<class T>
void dump_list(ngx_list_t *l)
{
	if(!l) {
		cerr << "Given single-linked list is null!\n";
		return;
	}

	ngx_list_part_t *part = &(l->part);	// 指向单链表首个数据块
	T *data = (T*)(part->elts);	// 指向首个数据块的数据区
	int block_count = 0;	// 链表数据块计数

	// 开始遍历单链表
	for(size_t i = 0; ; ++i) {
		if(i >= part->nelts) {	// 当前数据块中元素遍历完毕
			if(part->next == NULL) {
				// 没有后续数据块，链表遍历结束
				break;
			}

			// 跳到后续数据块
			part = part->next;
			data = (T*)(part->elts);
			i = 0;
			++block_count;
		}

		// 输出当前元素
		cout << "Data Block " << block_count << " (Index " << i << "): " << data[i] << endl;
	}
}

int main()
{
	// 创建内存池
	ngx_pool_t *p = ngx_create_pool(10240, NULL);
	assert(p);

	// 创建新的单链表，其中每个链表数据块最多容纳12个大小为sizeof(int)的元素
	ngx_list_t *l = ngx_list_create(p, 12, sizeof(int));
	assert(l);

	// 在单链表末尾插入元素
	int *q;
	for(int i = 0; i < 20; ++i) {
		q = (int *)ngx_list_push(l);
		assert(q);
		*q = i;
	}

	// 输出单链表内容
	cout << "Dump single-linked list l:\n";
	dump_list<int>(l);
	cout << endl;

	// 初始化给定的单链表结构，其中每个链表数据块最多容纳5个大小为sizeof(char*)的元素
	ngx_list_t ll;
	if(ngx_list_init(&ll, p, 5, sizeof(char*)) != NGX_OK) {
		cerr << "Failed to allocate memory for the single-linked list!\n";
		exit(1);
	}

	// 在单链表末尾插入元素
	const char *s = "hello, world! that's all, folks!";
	char **sp;
	for(int i = 0; i < 20; ++i) {
		sp = (char **)ngx_list_push(&ll);
		assert(sp);
		*sp = (char*)(s+i);
	}

	// 输出单链表内容
	cout << "Dump single-linked list ll:\n";
	dump_list<const char*>(&ll);
	cout << endl;

	// 销毁内存池，释放所有资源
	ngx_destroy_pool(p);

	return 0;
}

