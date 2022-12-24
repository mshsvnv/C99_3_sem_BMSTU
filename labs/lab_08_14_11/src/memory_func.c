#include "../inc/defs.h"

double **allocation(size_t rows, size_t columns)
{
    double **matrix;

    size_t i = 0;

    matrix = malloc(sizeof(double *) * rows + rows * columns * sizeof(double));
    
    if (matrix == NULL)
        return NULL;

    for (; i < rows; i++)
        matrix[i] = (double *)((char *)matrix + rows * sizeof(double *) + i * columns * sizeof(double));

    return matrix;
}