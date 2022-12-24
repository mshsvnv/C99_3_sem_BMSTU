#ifndef __DEFS_H__
#define __DEFS_H__

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS         0
#define WRONG_ARGS_ERR  1
#define WRONG_FILE_ERR  2
#define EMPTY_FILE_ERR  3
#define WRONG_SIZE_ERR  4
#define MEMORY_ERR      6
#define INCORR_DATA_ERR 7
#define MANY_MAX_ERR    8
typedef struct 
{
    int *pointer;
    int rows, columns;
} matrix_t;

#endif // __DEFS_H__