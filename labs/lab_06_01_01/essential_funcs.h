#ifndef __ESSENTIAL_FUNCS_H__
#define __ESSENTIAL_FUNCS_H__

void swap(int *beg, int *end);
int show(int *count);
int binary_search(char *field, char *key, int *count);
void sort(int *count, char *field);
int read_struct(FILE *f, char *field, int *count);

#endif // __ESSENTIAL_FUNCS_H__