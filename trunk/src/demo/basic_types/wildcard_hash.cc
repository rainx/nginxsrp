#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#include <string>

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

void dump_ngx_wildcard_hash(ngx_hash_t*,string);

void dump_hash_bucket(ngx_hash_elt_t *bucket, string indent)
{
	printf("%s{\n",indent.c_str());
	while(bucket->value) {
		string key((char*)(bucket->name), bucket->len);
		void *val = (void*)(((uintptr_t)(bucket->value))&((uintptr_t)~3));

		switch(((uintptr_t)(bucket->value))&0x3) {
			case 0:	// normal value
				printf("%s\t'%s'=>%p(flag=0, void *s): s='%s',\n", indent.c_str(), key.c_str(), val, (char*)val);
				break;
			case 1:	// normal value, but original key ends with '.'
				printf("%s\t'%s'=>%p(flag=1, void *s): s='%s',\n", indent.c_str(), key.c_str(), val, (char*)val);
				break;
			case 2:	// ngx_hash_wildcard_t* value, the original key doesn't contains '.'
				{
					ngx_hash_wildcard_t *wh=(ngx_hash_wildcard_t*)val;
					printf("%s\t'%s'=>%p(flag=2, ngx_hash_wildcard_t *h): h->value=%p:'%s'\n", indent.c_str(), key.c_str(), wh, wh->value, wh->value?(char*)(wh->value):NULL);
					dump_ngx_wildcard_hash(&(wh->hash),indent+"\t");
					printf(",\n");
				}
				break;
			case 3:	// ngx_hash_wildcard_t* value, the original key contains '.'
				{
					ngx_hash_wildcard_t *wh=(ngx_hash_wildcard_t*)val;
					printf("%s\t'%s'=>%p(flag=3, ngx_hash_wildcard_t *h): h->value=%p:'%s'\n", indent.c_str(), key.c_str(), wh, wh->value, wh->value?(char*)(wh->value):NULL);
					dump_ngx_wildcard_hash(&(wh->hash),indent+"\t");
					printf(",\n");
				}
				break;
		}
		bucket = (ngx_hash_elt_t*)ngx_align_ptr(&(bucket->name) + bucket->len, sizeof(void*));
	}

	printf("%s}",indent.c_str());
}

void dump_ngx_wildcard_hash(ngx_hash_t *h, string indent)
{
	unsigned long bucket_size = h->size;
	ngx_hash_elt_t **buckets = h->buckets;
	
	if(bucket_size == 0) {
		printf("%s\t(empty hash)",indent.c_str());
		return;
	}

	for(unsigned long i = 0; i < bucket_size; ++i) {
		printf("%s\tbucket%4ld:\n",indent.c_str(),i);
		dump_hash_bucket(buckets[i],indent + "\t");
		printf("\n");
	}
}

int main()
{
	// 创建内存池
	ngx_pool_t *p = ngx_create_pool(10240, NULL);

	// 手工初始化 cacheline 大小
	ngx_cacheline_size = 32;

	const char* str[] = {
		"hello",
		"world",
		"foo",
		"bar"
	};

	// 初始化用键值对，注意用于初始化 ngx_hash_wildcard_t 散列表的 value 指针必须是至少对齐在 4 字节边界上的
	// 否则使用时可能产生错误。因为 ngx_hash_wildcard_init() 会将 value 指针值的最低 2 位用作标志位。
	// 另外初始化的 key 必须是按字符串增序排序的，因为 ngx_hash_wildcard_init() 是从前向后顺序扫描层级关系的。
	// key 中除了小数点'.'字符作为层级分隔符之外，其他字符都作为普通字符看待。
	ngx_hash_key_t props[] = {
		{ngx_string("a"), 0, NULL},
		{ngx_string("a.b*"), 0, NULL},
		{ngx_string("a.c.d.e"), 0, NULL},
		{ngx_string("b."), 0, NULL},
		{ngx_string("c*."), 0, NULL},
		{ngx_string("c*.a."), 0, NULL}
	};
	props[0].value = ngx_pcalloc(p, (strlen(str[0])+1)); ngx_memcpy(props[0].value, str[0], strlen(str[0]));
	props[1].value = ngx_pcalloc(p, (strlen(str[1])+1)); ngx_memcpy(props[1].value, str[1], strlen(str[1]));
	props[2].value = ngx_pcalloc(p, (strlen(str[2])+1)); ngx_memcpy(props[2].value, str[2], strlen(str[2]));
	props[3].value = ngx_pcalloc(p, (strlen(str[3])+1)); ngx_memcpy(props[3].value, str[3], strlen(str[3]));
	props[4].value = ngx_pcalloc(p, (strlen(str[3])+1)); ngx_memcpy(props[4].value, str[3], strlen(str[3]));
	props[5].value = ngx_pcalloc(p, (strlen(str[3])+1)); ngx_memcpy(props[5].value, str[3], strlen(str[3]));

	for(size_t i = 0; i < sizeof(props)/sizeof(props[0]); ++i) {
		char buf[255] = {0};
		ngx_sprintf((u_char*)buf, "%V", &(props[i].key));
		printf("%s => %s\n",buf, (char*)(props[i].value));
	}

	ngx_hash_init_t hinit;

	hinit.hash = NULL;
	hinit.pool = p;
	hinit.temp_pool = p;
	hinit.key = ngx_hash_key_lc;
	hinit.max_size = 16;
	hinit.bucket_size = 16;
	hinit.name = (char*)"wildcard hash";

	if(ngx_hash_wildcard_init(&hinit, props, sizeof(props)/sizeof(props[0])) == NGX_OK) {
		// 初始化成功
		printf("wildcard hash init succeeded!\n");
		dump_ngx_wildcard_hash(hinit.hash,"");
	} else {
		// 初始化失败
		printf("failed to do wildcard hash init!\n");
	}

	// 销毁内存池，释放所有资源
	ngx_destroy_pool(p);

	return 0;
}

