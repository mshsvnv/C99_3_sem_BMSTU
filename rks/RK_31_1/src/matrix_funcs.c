#include "../inc/defs.h"


void transpose_main(matrix_t *matrix)
{
    int i, j, temp;

    for (i = 0; i < matrix->rows - 1; i++)
    {
        for (j = i + 1; j < matrix->columns; j++)
        {
            temp = matrix->pointer[i * matrix->columns + j];
            matrix->pointer[i * matrix->columns + j] = matrix->pointer[j * matrix->columns + i];
            matrix->pointer[j * matrix->columns + i] = temp;
        }
    }
}

void transpose_side(matrix_t *matrix)
{
    int i, j, temp;

    for (i = 0; i < matrix->rows - 1; i++)
    {
        for (j = 0; j < matrix->columns - 1; j++)
        {
            temp = matrix->pointer[i * matrix->columns + j];
            matrix->pointer[i * matrix->columns + j] = matrix->pointer[(matrix->columns - j)* matrix->columns - i - 1];
            matrix->pointer[(matrix->columns - j)* matrix->columns - i - 1] = temp;
        }
    }
}

void delete(matrix_t *matrix)
{
    int i, k;

    for (i = 0; i < matrix->rows - 1; i++)
    {
        for (k = i + 1; k < matrix->rows; k++)
            matrix->pointer[i*matrix->columns + k - 1] = matrix->pointer[i*matrix->columns + k];
    }

    matrix->columns--;
}

int find_max(matrix_t *matrix, char *ch)
{
    int count = 1, i, j, m_i, m_j;
    int max_elem = matrix->pointer[0];
    *ch = 1;

    for (i = 0; i < matrix->rows; i++)
    {
        for (j = (i == 0) ? 1 : 0; j < matrix->columns; j++)
        {
            if (matrix->pointer[i*matrix->columns + j] > max_elem)
            {
                max_elem = matrix->pointer[i*matrix->columns + j];
                count = 1;
                m_i = i, m_j = j;
            }
            else if (matrix->pointer[i*matrix->columns + j] == max_elem)
                count++;
        }
    }

    if (count != 1)
        return MANY_MAX_ERR;

    if (m_i == m_j)
    {
        delete(matrix);
        *ch = 0;
    }
    else if (m_i > m_j)
        transpose_side(matrix);
    else  
        transpose_main(matrix);

    

    return SUCCESS;
}