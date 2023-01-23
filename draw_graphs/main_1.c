#include <stdio.h>
#include <stdlib.h>

#include <sys/time.h>
#include <time.h>

#ifndef NMAX
#error not defined
#endif

size_t len = NMAX;
int arr[NMAX];

int compare(const void *i, const void *j);
void swap(char *a, char *b, size_t size);
void mysort(void *base, size_t num, size_t size, int (*compare)(const void *, const void *));
void init(int *a);

unsigned long long milliseconds_now(void);

int main()
{
    long long unsigned beg, end;
    init(arr);

    void *p = arr;

    beg = milliseconds_now();
    mysort(p, len, sizeof(int), compare);
    end = milliseconds_now();

    // for (int i = 0; i < NMAX; i++)
    //     printf("%d ", arr[i]);

    printf("%llu\n", end - beg);

    return 0;

}

void init(int *arr)
{
    int k = 0;
    //srand(time(NULL));
    for (int i = 0; i < NMAX / 2; i++)
        *(arr + i) = k;

    for (int i = NMAX / 2; i < NMAX; i++)
        *(arr + i) = k + 1;
}

int compare(const void *i, const void *j)
{
    if (*(int *)i > *(int *)j)
        return 1;
    else if (*(int *)i < *(int *)j)
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
                swap(pj, pj + size, size);
                last = pj;
            }
        }

        end = last;
    }
}

unsigned long long milliseconds_now(void)
{
    struct timeval val;

    if (gettimeofday(&val, NULL))
        return (unsigned long long) - 1;

    return val.tv_sec * 1000ULL + val.tv_usec / 1000ULL;
}

