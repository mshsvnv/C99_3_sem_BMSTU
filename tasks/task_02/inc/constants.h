#ifndef __CONSTANTS_H__
#define __CONSTANTS_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS          0
#define DUPLICATE        1
#define ERR_WRONG_DATA   2
#define ERR_WRONG_ARGS   3

typedef struct node node_t;

struct node
{
    int value;

    node_t *next;
    node_t *prev;
};

#endif // __CONSTANTS_H__