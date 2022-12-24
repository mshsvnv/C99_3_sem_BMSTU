#include "../inc/list_funcs.h"

node_t *list_add_front(node_t *head, node_t *tmp)
{
    tmp->next = head;
    return tmp;
}

void list_free(node_t **head, short num)
{
    node_t *tmp;

    for (; *head; *head = tmp)
    {
        tmp = (*head)->next;

        if (num == 1)
            node_free(head);

        free(*head);

        *head = NULL;
    }
}

int list_amount(node_t *head)
{
    int amount = 0;

    for (; head; head = head->next)
        amount++;

    return amount;
}

void front_back_split(node_t *head, node_t **back)
{
    int amount, median, i;

    if (!head || !head->next)
        *back = head;
    
    amount = list_amount(head);
    median = (amount % 2 == 0) ? amount / 2 : amount / 2 + 1;

    for (i = 0; i < median; i++, head = head->next)
    {
        if (i == median - 1)
        {
            (*back) = head->next;
            head->next = NULL;
        }
    }
}

node_t *sorted_merge(node_t **head_a, node_t **head_b, int (*comparator)(const void *, const void *))
{
    node_t *res = NULL, *cur = NULL;
    void *data = NULL;

    while (*head_a && *head_b)
    {
        if (comparator((*head_a)->data, (*head_b)->data) <= 0)
            data = pop_front(head_a);
        else
            data = pop_front(head_b);

        cur = node_copy_data(data);

        if (!cur)
            return NULL;

        res = list_add_back(res, cur);
    }

    if (*head_a)
    {
        while (*head_a)
        {
            data = pop_front(head_a);
            
            cur = node_copy_data(data);

            if (!cur)
                return NULL;

            res = list_add_back(res, cur);
        }
    }
    
    if (*head_b)
    {
        while (*head_b)
        {
            data = pop_front(head_b);
            
            cur = node_copy_data(data);

            if (!cur)
                return NULL;

            res = list_add_back(res, cur);
        }
    }

    return res;
}

node_t *sort(node_t *head, int (*comparator)(const void *, const void *))
{   
    if (!head)
        return NULL;

    if (!head->next)
        return head;

    node_t *low = head;
    node_t *high = NULL;

    front_back_split(low, &high);

    low = sort(low, comparator);
    high = sort(high, comparator);

    node_t *res = sorted_merge(&low, &high, comparator);

    return res;
}

void remove_duplicates(node_t **head, int (*comparator)(const void *, const void *))
{
    if (*head)
    {
        node_t *tmp = (*head)->next, *res = *head, *st = res, *cur = NULL;
        int f;

        while (tmp)
        {
            f = 0;

            if (comparator(res->data, tmp->data) != 0)
            {
                res->next = tmp;
                res = res->next;

                f = 1;
            }

            cur = tmp;
            tmp = tmp->next;

            if (!f)
            {
                free(cur);
                cur = NULL;
            }
        }
        
        res->next = NULL;

        *head = st;
    }
}

node_t *list_add_back(node_t *head, node_t *tmp)
{
    if (!head)
        return tmp;
    else
    {
        node_t *cur = head, *st = cur;

        while (cur->next)
            cur = cur->next;

        cur->next = tmp;

        return st;
    }
}

node_t *list_copy(node_t *head)
{
    node_t *cur = NULL, *res = NULL;
    
    for (; head; head = head->next)
    {
        cur = node_copy_data(head->data);

        res = list_add_back(res, cur);
    }

    return res;
}
