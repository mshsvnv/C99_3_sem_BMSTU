#include "../inc/defs.h"
#include "../inc/memory_func.h"
#include "../inc/other_matrix_funcs.h"

double **addition(ptr_t ptr_matrix_1, ptr_t ptr_matrix_2)
{
    size_t i, j;
    double sum = 0;
    double **res_matrix = allocation(ptr_matrix_1->rows, ptr_matrix_1->columns);

    if (!res_matrix)
        return NULL;

    for (i = 0; i < ptr_matrix_1->rows; i++)
    {
        for (j = 0; j < ptr_matrix_1->columns; j++)
        { 
            sum = ptr_matrix_1->pointer[i][j] + ptr_matrix_2->pointer[i][j];
            res_matrix[i][j] = sum, sum = 0; 
        }
    }

    return res_matrix;
}

double **multiplication(ptr_t ptr_matrix_1, ptr_t ptr_matrix_2)
{
    size_t i, j, k;
    double sum = 0, **res_matrix;
    
    res_matrix = allocation(ptr_matrix_1->rows, ptr_matrix_2->columns);

    if (!res_matrix)
        return NULL;

    for (i = 0; i < ptr_matrix_1->rows; i++)
    {
        for (j = 0; j < ptr_matrix_2->columns; j++)
        {
            for (k = 0; k < ptr_matrix_1->columns; k++)
                sum += ptr_matrix_1->pointer[i][k] * ptr_matrix_2->pointer[k][j];
            
            res_matrix[i][j] = sum, sum = 0;
        }
    }

    return res_matrix;
}

double **inversion_matrix(ptr_t ptr_matrix)
{
    double **res_matrix, *x_cur, *x_res;
    size_t i, j, k; 

    x_cur = calloc(ptr_matrix->rows, sizeof(double));

    if (!x_cur)
        return NULL;

    res_matrix = allocation(ptr_matrix->rows, ptr_matrix->columns);

    if (!res_matrix)
    {
        free(x_cur);
        return NULL;
    }

    for (i = 0; i < ptr_matrix->rows; i++)
    {
        for (j = 0; i < ptr_matrix->rows; i++)
            res_matrix[i][j] = ptr_matrix->pointer[i][j];
    }

    for (i = 0; i < ptr_matrix->rows; i++)
    {
        for (j = 0; j < ptr_matrix->rows; j++)
            x_cur[j] = (i == j) ? 1 : 0;

        x_res = gauss(ptr_matrix, x_cur);

        if (!x_res)
        {
            free(x_cur), free(res_matrix);
            return NULL;
        }

        for (k = 0; k < ptr_matrix->rows; k++)
            res_matrix[k][i] = x_res[k];

        free(x_res);
        x_res = NULL;
    }

    free(x_cur);
    return res_matrix;
}