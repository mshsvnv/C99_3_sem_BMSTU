#include "../inc/defs.h"
#include <dlfcn.h>

typedef long (*fn_check_file_size_t) (FILE *);
typedef int (*fn_get_num_t) (FILE *, size_t *);
typedef int (*fn_create_array_t) (FILE *, int **, int **, size_t *);
typedef int (*fn_key_t) (const int *, const int *, int **, int **);
typedef void (*fn_mysort_t) (void *, size_t, size_t, int (*compare)(const void *, const void *));
typedef int (*fn_write_array_t) ( FILE *, int *, int *);
typedef int (*fn_compare_t) (const void *, const void *);

int main(int argc, char **argv)
{
    void *hlib;
    hlib = dlopen("out/my_lib.so", RTLD_NOW);

    if (!hlib)
        return LIB_ERR;

    fn_check_file_size_t check_file_size = (fn_check_file_size_t)dlsym(hlib, "check_file_size");
    
    if (!check_file_size)
    {
        return LIB_ERR;
        dlclose(hlib);     
    }

    fn_get_num_t get_num = (fn_get_num_t)dlsym(hlib, "get_num");

    if (!get_num)
    {
        return LIB_ERR;
        dlclose(hlib);
    }

    fn_create_array_t create_array = (fn_create_array_t)dlsym(hlib, "create_array");

    if (!create_array)
    {
        return LIB_ERR;
        dlclose(hlib);
    }

    fn_key_t key = (fn_key_t)dlsym(hlib, "key");

    if (!key)
    {
        return LIB_ERR;
        dlclose(hlib);
    }

    fn_mysort_t mysort = (fn_mysort_t)dlsym(hlib, "mysort");

    if (!mysort)
    {
        return LIB_ERR;
        dlclose(hlib);
    }

    fn_write_array_t write_array = (fn_write_array_t)dlsym(hlib, "write_array");

    if (!write_array)
    {
        return LIB_ERR;
        dlclose(hlib);
    }

    fn_compare_t compare = (fn_compare_t)dlsym(hlib, "compare");

    if (!compare)
    {
        return LIB_ERR;
        dlclose(hlib);
    }

    int *arr_pb = NULL, *arr_pe = NULL;
    int *arr_pb_filter = NULL, *arr_pe_filter = NULL;

    int rc;
    size_t num = 0;
    long size;

    if (argc != 3 && argc != 4)
    {
        dlclose(hlib);
        return ARGS_AMOUNT_ERR;
    }

    if (argc == 4 && strcmp(argv[3], "f") != 0)
    {
        dlclose(hlib);
        return INCORR_ARG_ERR;
    }

    FILE *f = fopen(argv[1], "r");

    if (f == NULL)
    {
        dlclose(hlib);
        return INCORR_FILE_ERR;
    }

    size = check_file_size(f);
    if (size == 0)
    {
        dlclose(hlib);
        fclose(f);
        return EMPTY_FILE_ERR;
    }

    FILE *f_out = fopen(argv[2], "w");
    if (f_out == NULL)
    {
        dlclose(hlib);
        fclose(f);
        return INCORR_FILE_ERR;
    }

    rc = get_num(f, &num);
    if (rc == INCORR_DATA_ERR)
    {
        dlclose(hlib);
        fclose(f);
        fclose(f_out);
        return INCORR_DATA_ERR;
    }

    rc = create_array(f, &arr_pb, &arr_pe, &num);
    if (rc == MEMORY_ERR)
    {
        dlclose(hlib);
        fclose(f);
        fclose(f_out);
        return MEMORY_ERR;
    }

    if (argc == 4)
    {
        arr_pb_filter = malloc(sizeof(int) * (arr_pe - arr_pb));

        if (! arr_pb_filter)
        {
            dlclose(hlib);
            free(arr_pb);
            fclose(f);
            fclose(f_out);
            return MEMORY_ERR;
        }

        rc = key(arr_pb, arr_pe, &arr_pb_filter, &arr_pe_filter);

        if (rc)
        {
            dlclose(hlib);
            free(arr_pb);
            fclose(f);
            fclose(f_out);

            return rc;
        }

        mysort(arr_pb_filter, arr_pe_filter - arr_pb_filter, sizeof(*arr_pb_filter), compare);
        write_array(f_out, arr_pb_filter, arr_pe_filter);

        free(arr_pb_filter);
    }
    else
    {
        mysort(arr_pb, arr_pe - arr_pb, sizeof(*arr_pb), compare);
        write_array(f_out, arr_pb, arr_pe);
    }

    free(arr_pb);
    fclose(f);
    fclose(f_out);
    dlclose(hlib);

    return SUCCESS;
}