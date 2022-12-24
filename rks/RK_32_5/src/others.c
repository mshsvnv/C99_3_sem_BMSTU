#include "../inc/others.h"

void list_print(char *name, node_t *head)
{
    node_t *tmp = head;

    printf("%s: ", name);

    while (tmp)
    {
        printf("%d ", tmp->value);
        tmp = tmp->next;
    }
    
    printf("\n");
}

node_t *read_from_file(node_t *head, FILE *f_in)
{
    int value;

    while (! feof(f_in))
    {
        if (fscanf(f_in, "%d", &value) != 1)
        {
            list_free(head);
            return NULL;
        }
        
        head = list_push_back(head, value);
    }

    return head;
}

long file_size(FILE *f_in)
{
    fseek(f_in, 0, SEEK_END);
    long size = ftell(f_in);
    fseek(f_in, 0, SEEK_SET);

    return size;
}