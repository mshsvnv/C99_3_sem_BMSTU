#ifndef __LIST_H__
#define __LIST_H__

#include "constants.h"

node_t *node_create(int value);

node_t *list_push_back(node_t *head, int value);

void list_free(node_t *head);

node_t *list_change(node_t *head);

#endif // __LIST_H__