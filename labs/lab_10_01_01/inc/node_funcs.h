#ifndef __NODE_FUNCS_H__
#define __NODE_FUNCS_H__ 

#include "defs.h"
#include "other_funcs.h"

typedef struct node node_t;
struct node
{
    void *data;
    node_t *next;
};

typedef struct code
{
    char *amino_acid;
    char *triplet;
    int amount;
} code_t;

node_t *node_create(char *amino_acid, char *tmp_triplet, int *tmp_amount);

void node_free(node_t **head);

node_t *find(node_t *head, const void *data, int (*comparator)(const void*, const void *));

void *pop_front(node_t **head);

node_t *node_copy_data(void *data);

#endif // __NODE_FUNCS_H__