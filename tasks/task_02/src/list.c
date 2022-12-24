#include "../inc/list.h"

node_t *node_create(node_t *tmp, int value)
{
    tmp = malloc(sizeof(node_t));

    if (tmp)
    {
        tmp->value = value;

        tmp->next = NULL;
        tmp->prev = NULL;
    }

    return tmp;
}

node_t *list_create(node_t *head)
{
    int value, rc, i = 0;

    FILE *f_in = fopen("data.txt", "r");

    if (!f_in)
        return NULL;

    while (!feof(f_in))
    {
        rc = fscanf(f_in, "%d", &value);

        if (rc == 1)
            head = list_add_by_index(head, value, i);
        else
        {
            list_free(head);
            fclose(f_in);

            return NULL;
        }
        i++;
    }

    fclose(f_in);
    return head;
}

node_t *list_add_by_index(node_t *head, int value, int index)
{
    int cur_index;
    node_t *tmp = NULL, *new = NULL, *prev = NULL;

    cur_index = 0;
    tmp = head;

    if (index <= list_len(head) && index >= 0)
    {
        while (cur_index++ != index)
        {
            prev = tmp;
            tmp = tmp->next;
        }
        
        new = node_create(new, value);

        if (tmp)
        {
            if (tmp->prev)
            {  
                tmp->prev->next = new;
                new->prev = tmp->prev;

                new->next = tmp;
                tmp->prev = new;
            }
            else
            {
                tmp->prev = new;
                new->next = tmp;
                head = new;
            }
        }
        else if (prev)
        {
            prev->next = new;
            new->prev = prev;
        }
        else
            head = new;
    }

    return head;
}

node_t *list_delete_by_index(node_t *head, int index)
{
    int cur_index;
    node_t *tmp;

    cur_index = 0;
    tmp = head;

    if (index < list_len(head) && index >= 0)
    {
        while (cur_index++ != index)
            tmp = tmp->next;
        
        if (index == 0)
        {
            tmp->next->prev = NULL;
            head = tmp->next;
        }
        else if (index == list_len(head) - 1)
            tmp->prev->next = NULL;
        else
        {
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
        }
        
        free(tmp);
        tmp = NULL;
    }

    return head;
}

node_t *list_delete_by_value(node_t *head, int value)
{
    node_t *tmp = head;
    
    while (tmp)
    {
        if (tmp->value == value)
        {
            if (!tmp->prev)
            {
                tmp->next->prev = NULL;
                head = tmp->next;
            }
            else if (!tmp->next)
                tmp->prev->next = NULL;
            else
            {
                tmp->prev->next = tmp->next;
                tmp->next->prev = tmp->prev;
            }
            
            free(tmp);
            tmp = NULL;
        }
        else
            tmp = tmp->next;
    }

    return head;
}

node_t *list_reverse(node_t *head)
{
    node_t *tmp = head, *cur = head;

    while (tmp)
    {
        cur = tmp->next;
        tmp->next = tmp->prev;
        tmp->prev = cur;

        cur = tmp;
        tmp = tmp->prev;
    }

    return cur;
}

node_t *list_sort(node_t *head)
{
    int index = 0;
    node_t *min = NULL, *new_head = NULL;
    node_t *tmp_i = head, *tmp_j = NULL;

    if (!head)
        return head;

    while (tmp_i)
    {
        tmp_j = tmp_i->next;
        min = tmp_i;

        while (tmp_j)
        {
            if (tmp_j->value < min->value)
                min = tmp_j;

            tmp_j = tmp_j->next;
        }

        new_head = list_add_by_index(new_head, min->value, index);
        
        tmp_j = min;
        min->value = tmp_i->value;
        tmp_i->value = tmp_j->value;
        
        index++;

        tmp_i = tmp_i->next;
    }

    list_free(head);

    return new_head;
}

int list_len(node_t *head)
{
    int len;
    node_t *tmp = NULL;

    len = 0;
    tmp = head;

    while (tmp)
    {
        len++;
        tmp = tmp->next;
    }   

    return len; 
}

void list_free(node_t *head)
{
    node_t *tmp = NULL;

    while (head)
    {
        tmp = head;
        head = head->next;

        free(tmp);
    }
}

void list_print(node_t *head)
{
    node_t *tmp = head;

    while (tmp)
    {
        printf("%d\n", tmp->value);
        tmp = tmp->next;
    }
}

