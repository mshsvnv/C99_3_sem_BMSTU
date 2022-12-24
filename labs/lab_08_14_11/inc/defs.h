#ifndef __DEFS_H__
#define __DEFS_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define SUCCESS         0
#define WRONG_ARGS_ERR  1
#define WRONG_FILE_ERR  2
#define EMPTY_FILE_ERR  3
#define WRONG_SIZE_ERR  4
#define MEMORY_ERR      6
#define INCORR_DATA_ERR 7
#define DEG_MATRIX_ERR  8

#define MAX_ARGS 5
#define EPS 0.000001
#define FAILURE -1
typedef struct 
{
    double **pointer;
    size_t rows, columns;
} matrix_t;

typedef matrix_t *ptr_t;

#endif // __DEFS_H__