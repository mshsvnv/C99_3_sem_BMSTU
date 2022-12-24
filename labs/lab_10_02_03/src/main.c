#include "../inc/defs.h"
#include "../inc/node_funcs.h"
#include "../inc/math_funcs.h"

int main()
{
    node_t *head_1 = NULL, *head_2 = NULL, *res = NULL;
    int rc, num_1, num_2;
    char func[100];

    rc = fscanf(stdin, "%s", func);

    if (strcmp(func, "out") == 0)
    {
        rc = fscanf(stdin, "%d", &num_1);

        if (rc == 0 || num_1 <= 1)
            return ERR_WRONG_DATA;

        head_1 = list_make(head_1, &num_1);

        if (!head_1)
            return ERR_MEMORY;

        list_print(head_1);

        node_free(head_1);
    }
    else if (strcmp(func, "mul") == 0)
    {
        rc = fscanf(stdin, "%d%d", &num_1, &num_2);

        if (rc != 2 || num_1 < 1 || num_2 < 1 || (num_1 == num_2 && num_1 == 1))
            return ERR_WRONG_DATA;

        head_1 = list_make(head_1, &num_1);

        if (!head_1)
            return ERR_MEMORY;

        head_2 = list_make(head_2, &num_2);

        if (!head_2)
        {
            node_free(head_1);
            return ERR_MEMORY;
        }

        res = multiplication(res, head_1, head_2);

        if (!res)
        {
            node_free(head_1);
            node_free(head_2);
            return ERR_MEMORY;
        }    

        list_print(res);

        node_free(head_1);
        node_free(head_2);
        node_free(res);
    }
    else if (strcmp(func, "sqr") == 0)
    {
        rc = fscanf(stdin, "%d", &num_1);

        if (rc == 0 || num_1 <= 1)
            return ERR_WRONG_DATA;

        head_1 = list_make(head_1, &num_1);

        if (!head_1)
            return ERR_MEMORY;

        res = to_square(res, head_1);

        if (!res)
        {
            node_free(head_1);
            return ERR_MEMORY;
        }
        
        list_print(res);

        node_free(head_1);
        node_free(res);
    }
    else if (strcmp(func, "div") == 0)
    {
        rc = fscanf(stdin, "%d%d", &num_1, &num_2);

        if (rc != 2 || num_1 < 1 || num_2 < 1 || num_1 == num_2)
            return ERR_WRONG_DATA;

        head_1 = list_make(head_1, &num_1);

        if (!head_1)
            return ERR_MEMORY;

        head_2 = list_make(head_2, &num_2);

        if (!head_2)
        {
            node_free(head_1);
            return ERR_MEMORY;
        }

        res = division(res, head_1, head_2);

        if (!res)
        {
            node_free(head_1);
            node_free(head_2);
            return ERR_MEMORY;
        }

        list_print(res);

        node_free(head_1);
        node_free(head_2);
        node_free(res);
    }
    else
        return ERR_WRONG_FUNC;

    return SUCCESS;
}