#include <stdio.h>
#include "list.h"

int main()
{
    node_t *head = NULL;
    int rc;

    rc = list_read(&head);

    if (rc)
    {
        if (rc == EMPTY_LIST_ERR)
            printf("Empty list\n");
        else if (rc == LEN_STR_ERR)
            printf("Wrong len\n");
        else
            printf("Memory error\n");
    }
    else
        list_print(head);

    list_free(&head);

    return rc;
}