#include "../inc/my_lib.h"

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    if (! pb_src || ! pe_src|| pb_src == pe_src || pb_src == *pb_dst || ! *pb_dst)
        return MEMORY_ERR;

    const int *p_cur = pb_src;
    const int *p_max = p_cur, *p_min = p_cur;

    p_cur++;

    while (p_cur < pe_src)
    {
        if (*p_cur > *p_max)
            p_max = p_cur;
        
        if (*p_cur < *p_min)
            p_min = p_cur;
    
        p_cur++;
    }

    if (p_max < p_min)
    {
        p_cur = p_min;
        p_min = p_max;
        p_max = p_cur;
    }

    if (p_max - p_min == 1 || p_max == p_min)
        return NO_DATA_ERR;

    p_min++;

    *pe_dst = *pb_dst;
    **pb_dst = *p_min;

    p_min++;
    p_cur = p_min;

    while (p_cur <= p_max)
    {
        (*pe_dst)++;
        **pe_dst = *p_cur;
        
        p_cur++;
    }
    
    return SUCCESS;
}

int compare(const void *i, const void *j)
{
    if (*(char *)i > *(char *)j)
        return 1;
    else if (*(char *)i < *(char *)j)
        return -1;
    else
        return 0;
}

void swap(char *a, char *b, size_t size)
{
    size_t size_cur = size;		
    char *new_a = a, *new_b = b;

    do								      
    {								      
        char tmp = *new_a;						      
        *new_a++ = *new_b;	  
        *new_b++ = tmp;						      
    } while (--size_cur > 0);
}

void mysort(void *base, size_t num, size_t size, int (*compare)(const void *, const void *))
{
    char *pb = (char *)base;
    char *pe = pb + (num - 1) * size;
    char *last = pb, *end = pe;

    for (char *pi = pb; pi < pe; pi += size)
    {
        for (char *pj = pb; pj < end; pj += size)
        { 
            if (compare(pj, pj + size) > 0)
            {
                last = pj;
                swap(pj, pj + size, size);
            }
        }
        end = last;
    }
}