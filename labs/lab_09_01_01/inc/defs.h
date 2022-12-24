#ifndef __DEFS_H__
#define __DEFS_H__

#define _GNU_SOURCE

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define SUCCESS               0
#define ERR_ARGS_AMOUNT       2 
#define ERR_IO                3
#define ERR_EMPTY_FILE        5
#define ERR_FIELD_NAME        7
#define ERR_MEMORY            8
#define ERR_EMPTY_FIELD       9
#define ERR_WRONG_YEAR        10

#define INIT_SIZE             1
#define ARGS_AMOUNT           4
#define NOT_FOUND             11
#define FAILURE               12
#define TITLE                "title"
#define NAME                 "name"
#define YEAR                 "year"

typedef struct
{
    char *title;
    char *name;
    int year;
} film_t;

typedef struct
{
    int len;
    int allocated;
    int step;
    char *filed_to_sort;
    film_t *pointer;
} films_array_t;

#endif // __DEFS_H__