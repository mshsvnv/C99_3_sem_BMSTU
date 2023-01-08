#ifndef __LIST_H__
#define __LIST_H__

#define MAX_LEN        80
#define SUCCESS        0
#define EMPTY_LIST_ERR 1
#define LEN_STR_ERR    2
#define MEM_ERR        3
#define END            "The end\0"

typedef struct node node_t;

struct node
{
    char *data;
    node_t *next;
};

int string_len(char *string);

int list_read(node_t **head);

node_t *node_create(char *data);

node_t *list_push(node_t *head, node_t *new_node);

void list_free(node_t **head);

void list_print(node_t *head);

int list_len(node_t *head);

#endif // __LIST_H__