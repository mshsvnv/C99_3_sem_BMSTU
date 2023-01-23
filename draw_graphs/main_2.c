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
void init(int *a);

unsigned long long milliseconds_now(void);

int main()
{
    long long unsigned beg, end;

    init(arr);
    void *p = arr;

    beg = milliseconds_now();
    qsort(p, len, sizeof(int), compare);
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
    if (*(char *)i > *(char *)j)
        return 1;
    else if (*(char *)i < *(char *)j)
        return -1;
    else
        return 0;
}

unsigned long long milliseconds_now(void)
{
    struct timeval val;

    if (gettimeofday(&val, NULL))
        return (unsigned long long) - 1;

    return val.tv_sec * 1000ULL + val.tv_usec / 1000ULL;
}
