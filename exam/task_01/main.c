#include "list.h"

int main(void)
{
    node_t *head = NULL;
    int rc;

    rc = read_list(&head);

    if (rc != SUCCESS)
    {
        printf("ERROR: %d\n", (rc == IO_ERR) ? IO_ERR : MEM_ERR);

        if (len_list(head) != 0)
            clear_list(&head);

        return (rc == IO_ERR) ? IO_ERR : MEM_ERR;
    }

    print_list(head, "before: ");
    reverse(&head);
    print_list(head, "after: ");

    clear_list(&head);
   
    return SUCCESS;
}

