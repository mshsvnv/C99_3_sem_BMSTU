#include "../inc/file_funcs.h"

long check_file_size(FILE *f)
{
    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    fseek(f, 0, SEEK_SET);

    return size;
}

int read_string(FILE *f, char **tmp_string)
{
    void *p;
    size_t len = 0, i;
    char ch;

    while ((ch = fgetc(f)) != '\n')
        len++;
    
    fseek(f, -1 * (len + 1), SEEK_CUR);

    if (len == 0)
        return ERR_EMPTY_FIELD;

    len++;

    p = malloc(len);
    
    if (!p)
        return ERR_MEMORY;

    *tmp_string = p;

    for (i = 0; i < len; i++)
        (*tmp_string)[i] = fgetc(f);
    
    (*tmp_string)[len - 1] = '\0';

    return SUCCESS;
}

int fill_list(FILE *f_in, node_t **head)
{
    int rc;
    char ch;

    node_t *tmp;
    char *tmp_amino_acid = NULL, *tmp_triplet = NULL, *tmp_amount_str = NULL;
    int tmp_amount;

    while (!feof(f_in) && (ch = fgetc(f_in)) != EOF)
    {
        fseek(f_in, -1, SEEK_CUR);

        rc = read_string(f_in, &tmp_amino_acid);

        if (rc)
            return rc;

        rc = read_string(f_in, &tmp_triplet);

        if (rc)
        {
            free(tmp_amino_acid);
            return rc;
        }

        if (strlen(tmp_triplet) != 3)
        {
            free(tmp_amino_acid), free(tmp_triplet);
            return ERR_WRONG_DATA;
        }

        rc = read_string(f_in, &tmp_amount_str);

        if (rc)
        {
            free(tmp_amino_acid), free(tmp_triplet);
            return rc;
        }

        rc = check_amount(tmp_amount_str, &tmp_amount);

        if (rc)
        {
            free(tmp_amino_acid), free(tmp_triplet), free(tmp_amount_str);
            return rc;
        }

        tmp = node_create(tmp_amino_acid, tmp_triplet, &tmp_amount);

        if (!tmp)
        {
            free(tmp_amino_acid), free(tmp_triplet), free(tmp_amount_str);
            return ERR_MEMORY;
        }

        free(tmp_amount_str);
        free(tmp_amino_acid);
        free(tmp_triplet);
        
        *head = list_add_back(*head, tmp);
    }

    return SUCCESS;
}

void write_node(FILE *f_out, void *data)
{
    code_t *tmp = data;

    fprintf(f_out, "%s\n%s\n%d\n", tmp->amino_acid, tmp->triplet, tmp->amount);
}

void write_list(FILE *f_out, node_t *head)
{
    for (; head; head = head->next)
        write_node(f_out, head->data);
}