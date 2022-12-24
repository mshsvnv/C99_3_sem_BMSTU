#ifndef __LIST_H__
#define __LIST_H__

#include "constants.h"
#include "others.h"

node_t *node_create(node_t *tmp, int value);

node_t *list_create(node_t *head);

node_t *list_add_by_index(node_t *head, int value, int index);

node_t *list_delete_by_index(node_t *head, int index);

node_t *list_delete_by_value(node_t *head, int value);

node_t *list_reverse(node_t *head);

node_t *list_sort(node_t *head); // выбором

int list_len(node_t *head);

void list_free(node_t *head);

void list_print(node_t *head);

#endif // __LIST_H__