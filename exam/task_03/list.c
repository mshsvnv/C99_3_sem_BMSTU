#define __GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

int list_len(node_t *head)
{
    int len = 0;

    while (head)
    {
        len++;
        head = head->next;
    }

    return len;
}

node_t *node_create(char *data)
{
    node_t *tmp = malloc(sizeof(node_t));

    if (tmp)
    {
        tmp->data = data;
        tmp->next = NULL;
    }

    return tmp;
}

int string_len(char *string)
{
    int len = 0;

    while (*string != '\0')
    {
        len++;
        string++;
    }

    return len;
}

int string_cmp(char *str_1, char *str_2)
{
    while (*str_1 && *str_2)
    {
        if (*str_1 > *str_2)
            return 1;
        else
            return (*str_1 == *str_2) ? 0 : -1;

        str_1++, str_2++;
    }

    return (*str_1) ? 1 : -1;
}

int list_read(node_t **head)
{
    char buffer[MAX_LEN + 2];
    int rc = SUCCESS, i;
    int len;

    while (!rc)
    {
        fgets(buffer, MAX_LEN + 2, stdin);

        len = string_len(buffer);

        if (len > MAX_LEN || len == 1)
            return LEN_STR_ERR;

        if (!string_cmp(buffer, END))
        {
            if (!list_len(*head))
                return EMPTY_LIST_ERR;

            rc++;
        }
        else
        {
            i = 0;

            char *new_string = malloc(sizeof(char) * (string_len(buffer) + 1));

            if (new_string)
            {
                while (buffer[i] != '\n')
                {
                    new_string[i] = buffer[i];
                    i++;
                }

                new_string[i] = '\0';
            }
            else
                return MEM_ERR;

            node_t *tmp = node_create(new_string);

            if (!tmp)
            {
                free(new_string);
                free(tmp);

                return MEM_ERR;
            }

            *head = list_push(*head, tmp);
        }
    }

    return SUCCESS;

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
        (*head) = (*head)->next;

        free(tmp->data);
        free(tmp);

        tmp = (*head);
    }
}

void list_print(node_t *head)
{
    while (head)
    {
        printf("\'%s\' ", head->data);
        head = head->next;
    }
    printf("\n");
}

