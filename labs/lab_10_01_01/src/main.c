#include "../inc/defs.h"
#include "../inc/node_funcs.h"
#include "../inc/list_funcs.h"
#include "../inc/file_funcs.h"
#include "../inc/other_funcs.h"

int main(int argc, char **argv)
{
    FILE *f_in, *f_out;
    long size;
    int rc, amount;
    void *data = NULL;
    code_t code_tmp;
    node_t *head = NULL, *res = NULL;

    rc = SUCCESS;

    if (strcmp(argv[3], "pf") != 0 && 
        strcmp(argv[3], "f") != 0 && 
        strcmp(argv[3], "s") != 0 &&
        strcmp(argv[3], "rd") != 0)
        return ERR_WRONG_ACT; 

    if ((strcmp(argv[3], "pf") == 0 && argc != ARGS_AMOUNT) || 
        (strcmp(argv[3], "f") == 0 && argc != ARGS_AMOUNT + 2) || 
        (strcmp(argv[3], "s") == 0 && argc != ARGS_AMOUNT + 1) ||
        (strcmp(argv[3], "rd") == 0 && argc != ARGS_AMOUNT + 1))
        return ERR_ARGS_AMOUNT;

    f_in = fopen(argv[1], "r");

    if (!f_in)
        return ERR_IO;

    size = check_file_size(f_in);

    if (! size)
    {
        fclose(f_in);
        return ERR_EMPTY_FILE;
    }

    f_out = fopen(argv[2], "w");

    if (!f_out)
        return ERR_IO;

    rc = fill_list(f_in, &head);

    if (rc)
    {
        list_free(&head, 1);
        fclose(f_in), fclose(f_out);
        return rc;
    }

    if (strcmp(argv[3], "pf") == 0)
    {
        data = pop_front(&head);
        write_node(f_out, data);

        list_free(&head, 1);

        clean_data(&data);

        free(data);

        rc = SUCCESS;
    }
    else if (strcmp(argv[3], "f") == 0)
    {
        rc = SUCCESS;

        if (strcmp(argv[4], "amino_acid") == 0)
        {
            code_tmp.amino_acid = argv[5];
            data = &code_tmp;

            res = find(head, data, compare_amino_acid);
        }
        else if (strcmp(argv[4], "triplet") == 0)
        {
            code_tmp.triplet = argv[5];
            data = &code_tmp;

            res = find(head, data, compare_triplet);
        }
        else if (strcmp(argv[4], "amount") == 0)
        {
            rc = check_amount(argv[5], &amount);

            if (!rc)
            {
                code_tmp.amount = amount;
                data = &code_tmp;

                res = find(head, data, compare_amount);
            }
            else
                rc = ERR_WRONG_DATA;
        }
        else
            rc = ERR_WRONG_FIELD;

        if (!res)
            rc = ERR_WRONG_DATA;

        if (!rc)
            write_node(f_out, res->data);

        list_free(&head, 1);
    }
    else if (strcmp(argv[3], "s") == 0)
    {
        rc = SUCCESS;

        if (strcmp(argv[4], "amino_acid") == 0)
        {
            head = sort(head, compare_amino_acid);
        }
        else if (strcmp(argv[4], "triplet") == 0)
        {
            head = sort(head, compare_triplet);
        }
        else if (strcmp(argv[4], "amount") == 0)
        {
            head = sort(head, compare_amount);
        }
        else
            rc = ERR_WRONG_FIELD;

        if (!rc)
            write_list(f_out, head);

        list_free(&head, 1);
    }
    else if (strcmp(argv[3], "rd") == 0)
    {
        rc = SUCCESS;

        if (strcmp(argv[4], "amino_acid") == 0)
        {
            head = sort(head, compare_amino_acid);
            res = list_copy(head);
            remove_duplicates(&head, compare_amino_acid);
        }
        else if (strcmp(argv[4], "triplet") == 0)
        {
            head = sort(head, compare_triplet);
            res = list_copy(head);
            remove_duplicates(&head, compare_triplet);
        }
        else if (strcmp(argv[4], "amount") == 0)
        {
            head = sort(head, compare_amount);
            res = list_copy(head);
            remove_duplicates(&head, compare_amount);
        }
        else
            rc = ERR_WRONG_FIELD;

        if (!rc)
        {
            write_list(f_out, head);

            list_free(&res, 1);
            list_free(&head, 0);
        }
    }

    fclose(f_in), fclose(f_out);

    return rc;
}