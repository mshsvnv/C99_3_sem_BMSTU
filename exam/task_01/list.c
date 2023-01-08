#include "list.h"

int read_list(node_t **head)
{
    int value;
    int rc = SUCCESS + 1;

    while (rc == SUCCESS + 1)
    {
        rc = fscanf(stdin, "%d", &value);

        if (rc != 1)
            return IO_ERR;
        else if (value == 0)
        {
            if (len_list(*head) == 0)
                return EMPTY_LIST_ERR;
            else    
                rc++;
        }
        else
        {
            node_t *tmp = create_node(value);

            if (tmp)
                *head = push_back(*head, tmp);
            else
                return MEM_ERR;
        }
    }

    return SUCCESS;
}

int len_list(node_t *head)
{
    int len = 0;

    while (head)
    {
        len++;
        head = head->next;
    }

    return len;
}

node_t *create_node(int data)
{
    node_t *tmp = malloc(sizeof(node_t));

    if (tmp)
    {
        tmp->data = data;
        tmp->next = NULL;
    }

    return tmp;
}

node_t *push_back(node_t *head, node_t *new_node)
{
    if (!head)
        head = new_node;
    else
    {
        node_t *tmp = head;

        while (tmp->next)
            tmp = tmp->next;

        tmp->next = new_node;
    }

    return head;
}

void clear_list(node_t **head)
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

void print_list(node_t *head, char *arg)
{
    printf("%s", arg);
    while (head)
    {
        printf("%d ", head->data);
        head = head->next;
    }

    printf("\n");
}

void reverse(node_t **head)
{
    int len = len_list(*head);
    int i = 0;

    node_t *prev = NULL, *next = NULL;

    while (i < len)
    {
        next = (*head)->next;
        (*head)->next = prev;
        prev = *head;
        *head = next;

        i++;
    }

    *head = prev;
}
