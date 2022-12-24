#include "../inc/defs.h"

double *allocation(size_t rows, size_t columns)
{
    double *matrix;

    matrix = malloc(sizeof(int) * columns * rows);

    if (!matrix)
        return NULL;

    return matrix;
}