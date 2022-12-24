#include "../inc/defs.h"
#include "../inc/memory_func.h"
#include "../inc/file_funcs.h"
#include "../inc/matrix_funcs.h"
#include "../inc/other_matrix_funcs.h"

int main(int argc, char **argv)
{
    FILE *f_in_1, *f_in_2, *f_out;
    long size;
    double det = -1.0;
    int rc;

    matrix_t matrix_1, matrix_2, res_matrix;
    ptr_t ptr_m1 = &matrix_1;
    ptr_t ptr_m2 = &matrix_2;
    ptr_t ptr_r = &res_matrix;

    if (argc != MAX_ARGS && argc != MAX_ARGS - 1)
        return WRONG_ARGS_ERR;

    f_in_1 = fopen(argv[2], "r");

    if (f_in_1 == NULL)
        return WRONG_FILE_ERR;

    size = check_file_size(f_in_1);

    if (size == 0)
    {
        fclose(f_in_1);
        return EMPTY_FILE_ERR;
    }

    rc = read_rows_columns(f_in_1, ptr_m1);

    if (rc)
    {
        fclose(f_in_1);
        return WRONG_SIZE_ERR;
    }

    matrix_1.pointer = allocation(ptr_m1->rows, ptr_m1->columns);

    if (matrix_1.pointer == NULL)
    {
        fclose(f_in_1);
        return MEMORY_ERR;
    }

    rc = read_matrix(f_in_1, ptr_m1);

    if (rc)
    {
        free(matrix_1.pointer);
        fclose(f_in_1);
        return INCORR_DATA_ERR;
    }

    fclose(f_in_1);

    if (argc == MAX_ARGS)
    {
        if (strcmp(argv[1], "a") != 0 && strcmp(argv[1], "m") != 0)
        {
            free(matrix_1.pointer);
            return WRONG_ARGS_ERR;
        }
        else
        {
            f_in_2 = fopen(argv[3], "r");

            if (f_in_2 == NULL)
            {
                free(matrix_1.pointer);
                return WRONG_FILE_ERR;
            }

            size = check_file_size(f_in_2);

            if (size == 0)
            {
                free(matrix_1.pointer);
                fclose(f_in_2);
                return EMPTY_FILE_ERR;
            }

            rc = read_rows_columns(f_in_2, ptr_m2);

            if (rc)
            {
                free(matrix_1.pointer);
                fclose(f_in_2);
                return WRONG_SIZE_ERR;
            }

            matrix_2.pointer = allocation(ptr_m2->rows, ptr_m2->columns);

            if (matrix_2.pointer == NULL)
            {
                free(matrix_1.pointer);
                fclose(f_in_2);
                return MEMORY_ERR;
            }

            rc = read_matrix(f_in_2, ptr_m2);

            if (rc)
            {
                free(matrix_1.pointer), free(matrix_2.pointer);
                fclose(f_in_2);
                return INCORR_DATA_ERR;
            }

            fclose(f_in_2);

            f_out = fopen(argv[4], "w");

            if (!f_out)
            {
                free(matrix_1.pointer), free(matrix_2.pointer);
                return EMPTY_FILE_ERR;
            }    

            if (strcmp(argv[1], "a") == 0)
            {
                rc = check_dims(ptr_m1, ptr_m2, 'a');

                if (rc)
                {
                    free(matrix_1.pointer), free(matrix_2.pointer);
                    fclose(f_out);
                    return WRONG_SIZE_ERR;
                }
                else
                {
                    res_matrix.rows = matrix_1.rows, res_matrix.columns = matrix_1.columns;
                    res_matrix.pointer = addition(ptr_m1, ptr_m2);

                    if (!res_matrix.pointer)
                    {
                        free(matrix_1.pointer), free(matrix_2.pointer);
                        fclose(f_out);
                        return MEMORY_ERR;
                    }

                    write_file(f_out, ptr_r);
                    free(res_matrix.pointer), free(matrix_2.pointer), free(matrix_1.pointer);
                    fclose(f_out);

                    return SUCCESS;
                }
            }
            else
            {
                rc = check_dims(ptr_m1, ptr_m2, 'm');

                if (rc)
                {
                    free(matrix_1.pointer), free(matrix_2.pointer);
                    fclose(f_out);
                    return WRONG_SIZE_ERR;
                }
                else
                {
                    res_matrix.rows = matrix_1.rows, res_matrix.columns = matrix_2.columns;
                    res_matrix.pointer = multiplication(ptr_m1, ptr_m2);

                    if (!res_matrix.pointer)
                    {
                        free(matrix_1.pointer), free(matrix_2.pointer);
                        fclose(f_out);
                        return MEMORY_ERR;
                    }

                    write_file(f_out, ptr_r);
                    free(res_matrix.pointer), free(matrix_2.pointer), free(matrix_1.pointer);
                    fclose(f_out);

                    return SUCCESS;                                         
                }
            }
        }
    }
    else if (argc == MAX_ARGS - 1)
    {
        f_out = fopen(argv[3], "w");  

        if (!f_out)
        {
            free(matrix_1.pointer);
            return EMPTY_FILE_ERR;
        }   

        if (strcmp(argv[1], "o") != 0)
        {
            free(matrix_1.pointer);
            fclose(f_out);
            return WRONG_ARGS_ERR;
        }

        rc = check_dims(ptr_m1, NULL, 'o');

        if (rc)
        {
            free(matrix_1.pointer);
            fclose(f_out);
            return WRONG_SIZE_ERR;
        }
        
        rc = determinant(ptr_m1, &det);

        if (rc)
        {
            free(matrix_1.pointer);
            fclose(f_out);
            return DEG_MATRIX_ERR;
        }
        
        res_matrix.rows = matrix_1.rows, res_matrix.columns = matrix_1.columns;
        res_matrix.pointer = inversion_matrix(ptr_m1);

        if (!res_matrix.pointer)
        {
            free(matrix_1.pointer);
            fclose(f_out);
            return MEMORY_ERR;
        }

        write_file(f_out, ptr_r);

        free(matrix_1.pointer), free(res_matrix.pointer);
        fclose(f_out);

        return SUCCESS;
    }
}

