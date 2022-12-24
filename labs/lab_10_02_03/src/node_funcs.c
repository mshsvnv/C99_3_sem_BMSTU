#include "../inc/node_funcs.h"
#include "../inc/math_funcs.h"

node_t *list_make(node_t *head, int *num)
{
    int del, amount, tmp;
    node_t *cur = NULL;

    del = 2;
    amount = 0;
    tmp = *num;

    while (tmp != 1)
    {
        if (!is_prime(&del))
        {
            while (tmp % del == 0)
            {
                tmp = tmp / del;
                amount++;
            }

            cur = node_create(&amount);

            if (!cur)
            {
                node_free(head);
                return NULL;
            }

            head = node_add_back(head, cur);
        }
        
        del++;
        amount = 0;
    }

    if (*num == 1)
    {
        cur = node_create(&amount);

        if (!cur)
        {
            node_free(head);
            return NULL;
        }

        head = node_add_back(head, cur);
    }

    return head;
}

node_t *node_create(int *amount)
{
    node_t *tmp = malloc(sizeof(node_t));

    if (!tmp)
        return NULL;

    tmp->amount = *amount;
    tmp->next = NULL;
    
    return tmp;
}

node_t *node_add_back(node_t *head, node_t *new)
{
    node_t *cur = head;

    if (!head)
        return new;

    while (cur->next)
        cur = cur->next;
    
    // for (; cur->next; cur = cur->next)
    //     ;

    cur->next = new;

    return head;
}

void node_free(node_t *head)
{
    node_t *cur = head;

    for (; head; head = cur)
    {
        cur = head->next;
        free(head);
    }
}

void list_print(node_t *head)
{
    for (; head; head = head->next)
        printf("%d ", head->amount);
    printf("L\n");
}

node_t *list_del_last(node_t *head)
{
    node_t *cur = head, *prev = NULL;

    while (cur->next)
    {
        prev = cur;
        cur = cur->next;
    }
    
    if (!cur->amount)
    {
        prev->next = NULL;
        free(cur);
        
        return head;
    }
    else
        return NULL;
}
