#ifndef __LIST_FUNCS_H__
#define __LIST_FUNCS_H__ 

#include "defs.h"
#include "node_funcs.h"

node_t *list_add_front(node_t *head, node_t *tmp);

node_t *list_add_back(node_t *head, node_t *tmp);

void list_free(node_t **head, short num);

void remove_duplicates(node_t **head, int (*comparator)(const void *, const void *));

int list_amount(node_t *head);

node_t *sort(node_t *head, int (*comparator)(const void *, const void *));

void front_back_split(node_t *head, node_t **back);

node_t *sorted_merge(node_t **head_a, node_t **head_b, int (*comparator)(const void *, const void *));

node_t *list_copy(node_t *head);

#endif // __LIST_FUNCS_H__