#ifndef __CONSTANTS_H__
#define __CONSTANTS_H__

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS         0
#define ERR_ARGUMENTS   1
#define ERR_NO_FILE     2
#define ERR_EMPTY_FILE  3

typedef struct node node_t;

struct node
{
    int value;
    node_t *next;
};

#endif // __CONSTANTS_H__