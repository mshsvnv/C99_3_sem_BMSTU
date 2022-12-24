#include "../inc/math_funcs.h"

int is_prime(int *num)
{
    int sq = (int)sqrt(*num);
    int i;

    for (i = 2; i <= sq; i++)
    {
        if (*num % i == 0)
            return NOT_PRIME;
    }

    return SUCCESS;
}

node_t *multiplication(node_t *head, node_t *first_num, node_t *second_num)
{
    int amount;
    node_t *cur = NULL;

    amount = first_num->amount + second_num->amount;

    head = node_create(&amount);

    if (!head)
        return NULL;
    
    first_num = first_num->next;
    second_num = second_num->next;

    while (first_num && second_num)
    {
        amount = first_num->amount + second_num->amount;

        cur = node_create(&amount);

        if (!cur)
        {
            node_free(head);
            return NULL;
        }

        head = node_add_back(head, cur);

        first_num = first_num->next;
        second_num = second_num->next;
    }

    if (first_num)
    {
        while (first_num)
        {
            amount = first_num->amount;

            cur = node_create(&amount);

            if (!cur)
            {
                node_free(head);
                return NULL;
            }

            head = node_add_back(head, cur);

            first_num = first_num->next;
        }
    }

    if (second_num)
    {
        while (second_num)
        {
            amount = second_num->amount;

            cur = node_create(&amount);

            if (!cur)
            {
                node_free(head);
                return NULL;
            }

            head = node_add_back(head, cur);

            second_num = second_num->next;
        }
    }

    return head;
}

node_t *to_square(node_t *head, node_t *num)
{
    node_t *cur = NULL;
    int amount;

    amount = 2 * num->amount;

    head = node_create(&amount);

    if (!head)
        return NULL;

    num = num->next;

    while (num)
    {
        amount = 2 * num->amount;

        cur = node_create(&amount);

        if (!cur)
        {
            node_free(head);
            return NULL;
        }

        head = node_add_back(head, cur);
        
        num = num->next;                                                            
    }

    return head;
}

node_t *division(node_t *head, node_t *first_num, node_t *second_num)
{
    int amount;
    node_t *cur = NULL;

    amount = first_num->amount - second_num->amount;

    if (amount < 0)
        return NULL;

    head = node_create(&amount);

    if (!head)
        return NULL;
    
    first_num = first_num->next;
    second_num = second_num->next;

    while (first_num && second_num)
    {
        amount = first_num->amount - second_num->amount;

        if (amount < 0)
        {
            node_free(head);
            return NULL;
        }

        cur = node_create(&amount);

        if (!cur)
        {
            node_free(head);
            return NULL;
        }

        head = node_add_back(head, cur);

        first_num = first_num->next;
        second_num = second_num->next;
    }

    if (first_num)
    {
        while (first_num)
        {
            amount = first_num->amount;

            cur = node_create(&amount);

            if (!cur)
            {
                node_free(head);
                return NULL;
            }

            head = node_add_back(head, cur);

            first_num = first_num->next;
        }
    }

    if (second_num)
    {
        node_free(head);
        return NULL;
    }

    while (head)
    {
        cur = head;
        head = list_del_last(head);
    }

    return cur;
}