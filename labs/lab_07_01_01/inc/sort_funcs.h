#ifndef __SORT_FUNCS_H__
#define __SORT_FUNCS_H__

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);
int compare(const void *i, const void *j);
void swap(char *a, char *b, size_t size);
void mysort(void *base, size_t num, size_t size, int (*compare)(const void *, const void *));

#endif // __SORT_FUNCS_H__