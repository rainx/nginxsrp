all:  basic_types_int basic_types_str mem_op array_and_hash

C_OPT=-c -O -pipe  -O -W -Wall -Wpointer-arith -Wno-unused-parameter -Wunused-function -Wunused-variable -Wunused-value -Werror -g -I ../../nginx-0.7.61/objs/ -I ../../nginx-0.7.61/src/os/unix/  -I../../nginx-0.7.61/src/core -I../../nginx-0.7.61/src/event -I../../nginx-0.7.61/src/os

L_OPT= -lcrypt -lpcre -lcrypto -lz

OBJS=basic_types_int.o \
	 basic_types_str.o \
     mem_op.o \
     array_and_hash.o 


TARGETS=basic_types_int \
		basic_types_str \
		mem_op \
		array_and_hash

NGX_OBJ_BASE=../../nginx-0.7.61/objs/src

basic_types_int: basic_types_int.c
	gcc $(C_OPT) basic_types_int.c -o basic_types_int.o ;\
	gcc $(L_OPT) basic_types_int.o -o basic_types_int

basic_types_str: basic_types_str.c
	gcc $(C_OPT) basic_types_str.c -o basic_types_str.o ;\
	gcc $(L_OPT) $(NGX_OBJ_BASE)/core/ngx_string.o $(NGX_OBJ_BASE)/core/ngx_palloc.o ../../nginx-0.7.61/objs/src/os/unix/ngx_alloc.o  basic_types_str.o -o basic_types_str

mem_op: mem_op.c
	gcc $(C_OPT) mem_op.c -o mem_op.o ;\
	gcc $(L_OPT) $(NGX_OBJ_BASE)/core/ngx_string.o $(NGX_OBJ_BASE)/core/ngx_palloc.o ../../nginx-0.7.61/objs/src/os/unix/ngx_alloc.o  mem_op.o -o mem_op

array_and_hash: array_and_hash.c
	gcc $(C_OPT) array_and_hash.c -o array_and_hash.o ;\
	gcc $(L_OPT) $(NGX_OBJ_BASE)/core/ngx_string.o $(NGX_OBJ_BASE)/core/ngx_palloc.o $(NGX_OBJ_BASE)/core/ngx_array.o ../../nginx-0.7.61/objs/src/os/unix/ngx_alloc.o  array_and_hash.o -o array_and_hash


clean:
	rm -rf $(OBJS) $(TARGETS)
