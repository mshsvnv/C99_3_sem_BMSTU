#include "../inc/my_lib.h"

long check_file_size(FILE *f)
{
    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    fseek(f, 0, SEEK_SET);

    return size;
}

void write_array(FILE *f_out, int *pb, int *pe)
{
    int *p_cur = pb;

    while (p_cur < pe)
        fprintf(f_out, "%d ", *(p_cur)++);
}