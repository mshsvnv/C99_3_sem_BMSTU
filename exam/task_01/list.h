#ifndef __LIST_H__
#define __LIST_H__

#include "constants.h"

typedef struct node node_t;

struct node
{
    int data;
    node_t *next;
};

int read_list(node_t **head);

int len_list(node_t *head);

node_t *create_node(int data);

node_t *push_back(node_t *head, node_t *new_node);

void clear_list(node_t **head);

void print_list(node_t *head, char *arg);

void reverse(node_t **head);

#endif // __LIST_H__