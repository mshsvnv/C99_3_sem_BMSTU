#include "../inc/list.h"
#include "../inc/others.h"

int main(int argc, char **argv)
{
    node_t *head = NULL;
    FILE *f_in = NULL;

    if (argc != 2)
        return ERR_ARGUMENTS;

    f_in = fopen(argv[1], "r");

    if (!f_in)
        return ERR_NO_FILE;

    if (file_size(f_in) == 0)
    {
        fclose(f_in);
        return ERR_EMPTY_FILE;
    }

    head = read_from_file(head, f_in);
    fclose(f_in);

    if (!head)
        printf("Empty list!\n");
    else
    {
        list_print("before", head);
        head = list_change(head); 
        list_print("after", head);
    }

    list_free(head);

    return SUCCESS;
}