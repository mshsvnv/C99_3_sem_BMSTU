#include "../inc/defs.h"
#include "../inc/memory_func.h"

int check_dims(ptr_t ptr_matrix_1, ptr_t ptr_matrix_2, char ch)
{
    if (ch == 'a')
        return (ptr_matrix_1->columns == ptr_matrix_2->columns && ptr_matrix_1->rows == ptr_matrix_2->rows) ? SUCCESS : WRONG_SIZE_ERR;
    else if (ch == 'm')
        return (ptr_matrix_1->columns == ptr_matrix_2->rows) ? SUCCESS : WRONG_SIZE_ERR;
    else
        return (ptr_matrix_1->columns == ptr_matrix_1->rows) ? SUCCESS : WRONG_SIZE_ERR;
}

void swap(double **matrix, size_t i, size_t j)
{
    double *tmp = matrix[i];
    matrix[i] = matrix[j];
    matrix[j] = tmp;
}

double **convert_triangle(ptr_t ptr_matrix)
{
    size_t i, j, k, flag;
    double ratio, **new_matrix;

    new_matrix = allocation(ptr_matrix->rows, ptr_matrix->columns);

    if (!new_matrix) 
        return NULL;

    for (i = 0; i < ptr_matrix->rows; i++)
    {
        for (j = 0; j < ptr_matrix->columns; j++)
            new_matrix[i][j] = ptr_matrix->pointer[i][j];
    }

    for (i = 0; i < ptr_matrix->rows - 1; i++)
    {
        flag = 0;

        if (fabs(new_matrix[i][i]) < EPS)
        {
            for (j = i + 1; j < ptr_matrix->rows; j++)
            {
                if (fabs(new_matrix[j][i]) > EPS)
                {
                    flag = 1;
                    swap(new_matrix, i, j);
                    break;
                }
            }
            
            if (flag == 0)
            {
                free(new_matrix);
                return NULL;
            }
        }

        for (j = i + 1; j < ptr_matrix->rows; j++)
        {
            if (fabs(new_matrix[j][i]) > EPS)
            {
                ratio = -(new_matrix[j][i] / new_matrix[i][i]);

                for (k = 0; k < ptr_matrix->columns; k++)
                    new_matrix[j][k] += ratio * new_matrix[i][k];
            }
        }
    }

    return new_matrix;
}

int determinant(ptr_t ptr_matrix, double *det)
{
    size_t i;
    double **new_matrix;
    
    new_matrix = convert_triangle(ptr_matrix);

    if (!new_matrix)
        return MEMORY_ERR;

    for (i = 0; i < ptr_matrix->rows; i++)
        *det *= new_matrix[i][i];

    free(new_matrix);

    if (fabs(*det) < EPS)
        return DEG_MATRIX_ERR;
        
    return SUCCESS;
}

double **extended_matrix(ptr_t ptr_matrix, double *x)
{
    size_t i, j = 0;
    double **new_matrix = allocation(ptr_matrix->rows, ptr_matrix->columns + 1);

    if (!new_matrix)
        return NULL;

    for (i = 0; i < ptr_matrix->rows; i++)
    {
        for (j = 0; j < ptr_matrix->rows; j++)
            new_matrix[i][j] = ptr_matrix->pointer[i][j];
        new_matrix[i][ptr_matrix->rows] = x[i];
    }

    return new_matrix;
}

double *gauss(ptr_t ptr_matrix, double *f)
{
    size_t i, j, k;
    double s, *x;

    matrix_t ex_matrix, tr_matrix;
    ptr_t ptr_ex = &ex_matrix;

    x = calloc(ptr_matrix->rows, sizeof(double));

    if (!x)
        return NULL;

    ex_matrix.pointer = extended_matrix(ptr_matrix, f);
    ex_matrix.rows = ptr_matrix->rows, ex_matrix.columns = ptr_matrix->columns + 1;

    if (!ex_matrix.pointer)
    {
        free(x);
        return NULL;
    }

    tr_matrix.pointer = convert_triangle(ptr_ex);

    if (!tr_matrix.pointer) 
    {
        free(x), free(ex_matrix.pointer);
        return NULL;
    }

    for (i = ptr_matrix->rows - 1, k = 0; k <= ptr_matrix->rows - 1; i--, k++)
    {
        for (s = 0, j = i + 1; j < ptr_matrix->rows; j++)
            s += tr_matrix.pointer[i][j] * x[j];

        x[i] = (tr_matrix.pointer[i][ptr_matrix->rows] - s) / tr_matrix.pointer[i][i];
    }

    free(ex_matrix.pointer);
    free(tr_matrix.pointer);

    return x;
}