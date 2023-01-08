#include "list.h"

node_t *node_create(int data)
{
    node_t *tmp = malloc(sizeof(node_t));

    if (tmp)
    {
        tmp->data = data;
        tmp->next = NULL;
    }

    return tmp;
}

int list_read(node_t **pos, node_t **neg)
{
    int data;
    int rc = SUCCESS + 1, ideal = SUCCESS + 1;

    while (rc == ideal)
    {
        rc = fscanf(stdin, "%d", &data);

        if (!rc)
        {
            if (list_len(*pos))
                list_free(pos);

            if (list_len(*neg))
                list_free(neg);

            return IO_ERR;
        }
        else if (data == 0)
        {
            if (!list_len(*pos) && !list_len(*neg))
                return EMPTY_LIST_ERR;
            else    
                rc++;
        }
        else
        {
            node_t *tmp = node_create(data);

            if (tmp)
            {
                if (data > 0)
                    *pos = list_push(*pos, tmp);
                else    
                    *neg = list_push(*neg, tmp);
            }
        }
    }

    return SUCCESS;
}

int list_len(node_t *head)
{
    int len = 0;

    while (head)
    {
        head = head->next;
        len++;
    }

    return len;
}

node_t *list_push(node_t *head, node_t *new_node)
{
    new_node->next = head;

    return new_node;
}

void list_free(node_t **head)
{
    node_t *tmp = *head;

    while (*head)
    {
        *head = (*head)->next;

        free(tmp);

        tmp = NULL;
        tmp = *head;
    }
}

node_t *list_union(node_t *pos, node_t *neg)
{
    node_t *head = NULL;

    if (!pos)
        head = neg;
    else if (!neg)
        head = pos;
    else
    {
        head = pos;

        while (pos->next)
            pos = pos->next;

        pos->next = neg;
    }

    return head;
}

void list_print(node_t *head)
{
    while (head)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}