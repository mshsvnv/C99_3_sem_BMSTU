#include "../inc/other_funcs.h"

int check_amount(char *string, int *amount)
{
    size_t i = 0;

    do
    {
        if (isdigit(string[i++]) == 0)
            return ERR_WRONG_DATA;
    } while (i < strlen(string));

    *amount = atoi(string);

    if (*amount == 0)
        return ERR_WRONG_DATA;
    
    return SUCCESS;
}

int compare_amino_acid(const void *left, const void *right)
{
    const code_t *p_left = left;
    const code_t *p_right = right;
    int rc;

    if ((rc = strcmp(p_left->amino_acid, p_right->amino_acid)) == 0)
        return 0;
    else if (rc > 0)
        return 1;
    else    
        return -1;
}

int compare_triplet(const void *left, const void *right)
{
    const code_t *p_left = left;
    const code_t *p_right = right;
    int rc;

    if ((rc = strcmp(p_left->triplet, p_right->triplet)) == 0)
        return 0;
    else if (rc > 0)
        return 1;
    else    
        return -1;
}

int compare_amount(const void *left, const void *right)
{ 
    const code_t *p_left = left;
    const code_t *p_right = right;
    int rc;

    if ((rc = p_left->amount - p_right->amount) == 0)
        return 0;
    else if (rc > 0)
        return 1;
    else    
        return -1;
}

void clean_data(void **p)
{
    code_t *tmp = *p;

    if (*p)
    {
        if (tmp->amino_acid)
        {
            free(tmp->amino_acid);
            tmp->amino_acid = NULL;
        }

        if (tmp->triplet)
        {
            free(tmp->triplet);
            tmp->triplet = NULL;
        }
    }
}