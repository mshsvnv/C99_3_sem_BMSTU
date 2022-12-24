#include "../inc/defs.h"
#include "../inc/array_funcs.h"

int create_array(FILE *f, int **arr_pb, int **arr_pe, size_t *num)
{
    int *pb = NULL;
    int rc;

    pb = calloc(*num, sizeof(int));

    if (pb == NULL)
    {
        return MEMORY_ERR;
    }
    else
    {
        *arr_pb = pb;

        rc = fscanf(f, "%d", (*arr_pb)++);

        while (rc == 1)
            rc = fscanf(f, "%d", (*arr_pb)++);

        *arr_pe = *arr_pb - 1;
        *arr_pb = pb;
    }

    return SUCCESS;
}

int get_num(FILE *f, size_t *num)
{
    int dig;

    while (!feof(f))
    {
        if (fscanf(f, "%d", &dig) == 1)
            (*num)++;
        else
            return INCORR_DATA_ERR;
    }

    rewind(f);

    return SUCCESS; 
}
