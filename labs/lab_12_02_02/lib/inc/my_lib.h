#ifndef __MY_LIB_H__
#define __MY_LIB_H__

#include <stdio.h>

#define SUCCESS 0

void fill_fib(int *arr, int num);
int filter(int *src, int src_len, int *dst, int *dst_len, short mem);

#endif // __MY_LIB_H__