#include "../inc/node_funcs.h"

node_t *node_create(char *amino_acid, char *triplet, int *amount)
{
    node_t *tmp = malloc(sizeof(node_t));

    if (!tmp)
        return NULL;
    
    code_t *code = malloc(sizeof(code_t));

    if (!code)
    {
        free(tmp);
        return NULL; 
    }

    code->amino_acid = malloc(sizeof(amino_acid));

    if (!code->amino_acid)
    {
        free(tmp);
        free(code);
        return NULL;
    }

    strcpy(code->amino_acid, amino_acid);

    code->triplet = malloc(sizeof(triplet));

    if (!code->amino_acid)
    {
        free(tmp);
        free(code->amino_acid);
        free(code);
        return NULL;
    }

    strcpy(code->triplet, triplet);

    code->amount = *amount;

    tmp->next = NULL;
    tmp->data = code;

    return tmp;
}

node_t *node_copy_data(void *data)
{
    node_t *new = NULL;

    new = malloc(sizeof(node_t));

    if (!new)
        return NULL;

    new->data = data;
    new->next = NULL;

    return new;
}

void node_free(node_t **head)
{
    if ((*head)->data)
        clean_data(&((*head)->data));
    
    free((*head)->data);

    (*head)->data = NULL;
}

node_t *find(node_t *head, const void *data, int (*comparator)(const void *, const void *))
{
    if (data)
    {
        for (; head; head = head->next)
        {
            if (comparator((const void *)head->data, data) == 0)
                return head;
        }
    }

    return NULL;
}

void *pop_front(node_t **head)
{
    node_t *new;

    if (head && *head)
    {
        void *p = (*head)->data;

        new = (*head)->next;

        free(*head);

        *head = new;

        return p;
    }
    
    return NULL;
}

