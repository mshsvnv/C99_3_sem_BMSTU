#ifndef __LIST_H__
#define __LIST_H__

#include "const.h"

typedef struct node node_t;

struct node
{
    int data;
    node_t *next;
};

node_t *node_create(int data);

int list_read(node_t **pos, node_t **neg);

int list_len(node_t *head);

node_t *list_push(node_t *head, node_t *new_node);

void list_free(node_t **head);

node_t *list_union(node_t *pos, node_t *neg);

void list_print(node_t *head);

#endif // __LIST_H__