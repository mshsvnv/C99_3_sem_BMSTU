#include "../inc/list.h"

node_t *node_create(int value)
{
    node_t *tmp = malloc(sizeof(node_t));

    if (tmp)
    {
        tmp->value = value;
        tmp->next = NULL;
    }

    return tmp;
}

node_t *list_push_back(node_t *head, int value)
{
    node_t *new = NULL, *tmp = head;

    if (!head)
        head = node_create(value);
    else
    {
        while (tmp->next)
            tmp = tmp->next;

        new = node_create(value);

        if (new)
            tmp->next = new;
    }

    return head;
}

void list_free(node_t *head)
{
    node_t *tmp = NULL;

    while (head)
    {
        tmp = head;
        head = head->next;

        free(tmp);
    }
}

node_t *list_change(node_t *head)
{
    node_t *tmp = NULL, *min = NULL, *prev = NULL, *min_prev = NULL, *min_next = NULL;

    tmp = head;
    min = head;

    while (tmp)
    {
        if (tmp->value < min->value)
        {
            min_prev = prev;   
            min = tmp;
            min_next = min->next;
        }

        prev = tmp;
        tmp = tmp->next;
    }

    if (min != head)
    {
        if (min_prev == head)
            min->next = head;
        else
        {
            min->next = head->next;
            min_prev->next = head;
        }

        head->next = min_next;
        head = min;
    }
        
    return head;
}
