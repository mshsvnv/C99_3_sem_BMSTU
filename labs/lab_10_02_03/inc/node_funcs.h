#ifndef  __NODE_FUNCS_H__
#define  __NODE_FUNCS_H__

#include "defs.h"

typedef struct node node_t;
struct node
{
    int amount;
    node_t *next;
};

node_t *node_add_back(node_t *head, node_t *new);

void node_free(node_t *head);

node_t *node_create(int *amount);

node_t *list_make(node_t *head, int *num);

void list_print(node_t *head);

node_t *list_del_last(node_t *head);

#endif  // __NODE_FUNCS_H__