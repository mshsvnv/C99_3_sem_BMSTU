#include "../inc/defs.h"
#include "../inc/memory_func.h"
#include "../inc/file_funcs.h"
#include "../inc/matrix_funcs.h"

int main(int argc, char **argv)
{
    FILE *f_in, *f_out;
    long size;
    int rc;
    char ch;

    matrix_t matrix;

    if (argc != 3)
        return WRONG_ARGS_ERR;

    f_in = fopen(argv[1], "r");

    if (!f_in)
        return WRONG_FILE_ERR;

    size = check_file_size(f_in);

    if (size == 0)
    {
        fclose(f_in);
        return EMPTY_FILE_ERR;
    }

    rc = read_rows_columns(f_in, &matrix);

    if (rc)
    {
        fclose(f_in);
        return WRONG_SIZE_ERR;
    }

    matrix.pointer = allocation(matrix.rows, matrix.columns);

    if (matrix.pointer == NULL)
    {
        fclose(f_in);
        return MEMORY_ERR;
    }

    rc = read_matrix(f_in, &matrix);

    if (rc)
    {
        free(matrix.pointer);
        fclose(f_in);
        return INCORR_DATA_ERR;
    }

    rc = find_max(&matrix, &ch);

    if (rc)
    {
        free(matrix.pointer);
        fclose(f_in);
        return MANY_MAX_ERR;
    }

    f_out = fopen(argv[2], "w");

    if (f_out == NULL)
        return WRONG_FILE_ERR;

    write_file(f_out, &matrix, &ch);
    free(matrix.pointer);
    fclose(f_out);
    fclose(f_in);
}

