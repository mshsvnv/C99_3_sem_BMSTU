#include "../inc/my_lib.h"

void fill_fib(int *arr, int num)
{
    int i;

    for (i = 0; i < num; i++)
    {
        if (i <= 1)
            arr[i] = i;
        else    
            arr[i] = arr[i - 1] + arr[i - 2]; 
    }
}

int filter(int *src, int src_len, int *dst, int *dst_len, short mem)
{
    int i, j, cur_dst;

    cur_dst = -1;

    for (i = 0; i < src_len; i++)
    {
        for (j = 0; j < i; j++)
            if (src[i] == src[j])
                break;

        if (i == j)
        {
            cur_dst++;
            
            if (mem)
                dst[cur_dst] = src[i];
        }
    }

    *dst_len = cur_dst + 1;
    
    return (mem) ? SUCCESS : cur_dst + 1;   
}