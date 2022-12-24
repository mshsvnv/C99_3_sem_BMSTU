#include "../inc/list.h"
#include "../inc/others.h"

int main(int argc, char **argv)
{
    int rc = SUCCESS;
    int index, value;

    FILE *f_old = NULL;
    FILE *f_new = NULL;

    node_t *head = NULL;

    head = list_create(head);

    if (! head)
        return ERR_WRONG_DATA;

    f_old = fopen("old_list.gv", "wb");

    export_to_dot(head, f_old);

    fclose(f_old);

    if (argc == 2)
    {
        if (strcmp(argv[1], "s") == 0)
            head = list_sort(head);
        else if (strcmp(argv[1], "r") == 0)
            head = list_reverse(head);
        else
        {
            rc = ERR_WRONG_DATA;
            list_free(head);
            head = NULL;
        }
    }
    else if (argc == 3)
    {
        if (strcmp(argv[1], "d_i") == 0 && !check_digit(argv[2], &index))
            head = list_delete_by_index(head, index);
        else if (strcmp(argv[1], "d_v") == 0 && !check_digit(argv[2], &value))
            head = list_delete_by_value(head, atoi(argv[2]));
        else
        {
            rc = ERR_WRONG_DATA;
            list_free(head);
            head = NULL;
        }  
    }
    else if (argc == 4)
    {
        if (strcmp(argv[1], "a_i") == 0 && !check_digit(argv[2], &value) && !check_digit(argv[3], &index))
            head = list_add_by_index(head, value, index);
        else
        {
            rc = ERR_WRONG_DATA;
            list_free(head);
            head = NULL;
        }
    }
    else
    {
        rc = ERR_WRONG_ARGS;
        list_free(head);
        head = NULL;
    }

    // list_print(head);

    if (head)
    {
        f_new = fopen("new_list.gv", "wb");

        export_to_dot(head, f_new);

        fclose(f_new);

        list_free(head);
    }

    return rc;
}