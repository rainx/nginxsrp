TARGETS := mem_cleanup \
			basic_types_int \
			basic_types_str \
			mem_op \
			array_and_hash \
			file_cleanup \
			queue_op \
			hash_op \
			shmem_op \
			wildcard_hash
NGX_ROOT := ../../nginx-0.7.61
CC := gcc
CXX := g++
CFLAGS := -g3 -O0 -Wall -Werror
CXXFLAGS := -g3 -O0 -Wall -Werror
INCS := -I. \
		-I$(NGX_ROOT)/src/core \
		-I$(NGX_ROOT)/src/event \
		-I$(NGX_ROOT)/src/event/modules \
		-I$(NGX_ROOT)/src/os/unix \
		-I$(NGX_ROOT)/objs \
		-I$(NGX_ROOT)/src/http \
		-I$(NGX_ROOT)/src/http/modules
LDFLAGS :=
LIBS := -lcrypt -lpcre -lcrypto -lz

all: $(TARGETS)

valgrind: $(TARGETS)
	for prog in $(TARGETS); do \
		valgrind --tool=memcheck --leak-check=full ./$$prog; \
	done

clean:
	rm -f $(TARGETS) *.o

.PHONY: all clean valgrind

mem_cleanup: mem_cleanup.cc
	$(CXX) -c $(CFLAGS) $(INCS) $^
	$(CC) $(patsubst %.cc,%.o,$^) \
		$(NGX_ROOT)/objs/src/core/ngx_palloc.o \
		$(NGX_ROOT)/objs/src/os/unix/ngx_alloc.o \
		-o $@ $(LDFLAGS) $(LIBS) -lstdc++

file_cleanup: file_cleanup.cc
	$(CXX) -c $(CFLAGS) $(INCS) $^
	$(CC) $(patsubst %.cc,%.o,$^) \
		$(NGX_ROOT)/objs/src/core/ngx_palloc.o \
		$(NGX_ROOT)/objs/src/os/unix/ngx_alloc.o \
		-o $@ $(LDFLAGS) $(LIBS) -lstdc++

wildcard_hash: wildcard_hash.cc
	$(CXX) -c $(CFLAGS) $(INCS) $^
	$(CC) $(patsubst %.cc,%.o,$^) \
		$(NGX_ROOT)/objs/src/core/ngx_palloc.o \
		$(NGX_ROOT)/objs/src/core/ngx_string.o \
		$(NGX_ROOT)/objs/src/core/ngx_hash.o \
		$(NGX_ROOT)/objs/src/core/ngx_array.o \
		$(NGX_ROOT)/objs/src/os/unix/ngx_alloc.o \
		-o $@ $(LDFLAGS) $(LIBS) -lstdc++

basic_types_int: basic_types_int.c
	$(CC) $(CFLAGS) $(INCS) $^ -o $@ $(LDFLAGS) $(LIBS)

basic_types_str: basic_types_str.c
	$(CC) $(CFLAGS) $(INCS) $^ \
		$(NGX_ROOT)/objs/src/core/ngx_palloc.o \
		$(NGX_ROOT)/objs/src/core/ngx_string.o \
		$(NGX_ROOT)/objs/src/os/unix/ngx_alloc.o \
		-o $@ $(LDFLAGS) $(LIBS)

mem_op: mem_op.c
	$(CC) $(CFLAGS) $(INCS) $^ \
		$(NGX_ROOT)/objs/src/core/ngx_palloc.o \
		$(NGX_ROOT)/objs/src/core/ngx_string.o \
		$(NGX_ROOT)/objs/src/os/unix/ngx_alloc.o \
		-o $@ $(LDFLAGS) $(LIBS)

array_and_hash: array_and_hash.c
	$(CC) $(CFLAGS) $(INCS) $^ \
		$(NGX_ROOT)/objs/src/core/ngx_palloc.o \
		$(NGX_ROOT)/objs/src/core/ngx_string.o \
		$(NGX_ROOT)/objs/src/core/ngx_array.o \
		$(NGX_ROOT)/objs/src/os/unix/ngx_alloc.o \
		-o $@ $(LDFLAGS) $(LIBS)

queue_op: queue_op.c
	$(CC) $(CFLAGS) $(INCS) $^ \
		$(NGX_ROOT)/objs/src/core/ngx_palloc.o \
		$(NGX_ROOT)/objs/src/core/ngx_string.o \
		$(NGX_ROOT)/objs/src/core/ngx_queue.o \
		$(NGX_ROOT)/objs/src/os/unix/ngx_alloc.o \
		-o $@ $(LDFLAGS) $(LIBS)

hash_op: hash_op.c
	$(CC) $(CFLAGS) $(INCS) $^ \
		$(NGX_ROOT)/objs/src/core/ngx_palloc.o \
		$(NGX_ROOT)/objs/src/core/ngx_string.o \
		$(NGX_ROOT)/objs/src/core/ngx_hash.o \
		$(NGX_ROOT)/objs/src/core/ngx_array.o \
		$(NGX_ROOT)/objs/src/os/unix/ngx_alloc.o \
		-o $@ $(LDFLAGS) $(LIBS)

shmem_op: shmem_op.c
	$(CC) $(CFLAGS) $(INCS) $^ \
		$(NGX_ROOT)/objs/src/core/ngx_string.o \
		$(NGX_ROOT)/objs/src/core/ngx_palloc.o \
		$(NGX_ROOT)/objs/src/os/unix/ngx_alloc.o \
		$(NGX_ROOT)/objs/src/os/unix/ngx_shmem.o \
		-o $@ $(LDFLAGS) $(LIBS)


