#include "../inc/my_lib.h"

int main(int argc, char **argv)
{
    int *arr_pb = NULL, *arr_pe = NULL;
    int *arr_pb_filter = NULL, *arr_pe_filter = NULL;

    int rc;
    size_t num = 0;
    long size;

    if (argc != 3 && argc != 4)
        return ARGS_AMOUNT_ERR;

    if (argc == 4 && strcmp(argv[3], "f") != 0)
        return INCORR_ARG_ERR;

    FILE *f = fopen(argv[1], "r");

    if (f == NULL)
        return INCORR_FILE_ERR;

    size = check_file_size(f);
    if (size == 0)
    {
        fclose(f);
        return EMPTY_FILE_ERR;
    }

    FILE *f_out = fopen(argv[2], "w");
    if (f_out == NULL)
    {
        fclose(f);
        return INCORR_FILE_ERR;
    }

    rc = get_num(f, &num);
    if (rc == INCORR_DATA_ERR)
    {
        fclose(f);
        fclose(f_out);
        return INCORR_DATA_ERR;
    }

    rc = create_array(f, &arr_pb, &arr_pe, &num);
    if (rc == MEMORY_ERR)
    {
        fclose(f);
        fclose(f_out);
        return MEMORY_ERR;
    }

    if (argc == 4)
    {
        arr_pb_filter = malloc(sizeof(int) * (arr_pe - arr_pb));

        if (! arr_pb_filter)
        {
            free(arr_pb);
            fclose(f);
            fclose(f_out);
            return MEMORY_ERR;
        }

        rc = key(arr_pb, arr_pe, &arr_pb_filter, &arr_pe_filter);

        if (rc)
        {
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

    return SUCCESS;
}