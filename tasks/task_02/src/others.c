#include "../inc/others.h"

void export_to_dot(node_t *head, FILE *f)
{
    int i = 0;

    fprintf(f, "digraph \"Doubly Linked List\" {\nrankdir=LR;\nnode [shape=record];\nstart [label=\"null\" shape=circle];\nend [label=\"null\" shape=circle];\n");

    node_t *tmp = head;

    while(tmp)
    {
        fprintf(f, "f%d [label=\"{ <ref1> | <data> %d | <ref2>  }\"];\n", i, tmp->value);
        if (!tmp->prev)
            fprintf(f, "start -> f0:ref1:c ");
        else 
            fprintf(f, "f%d:ref1:c -> f%d:data:s ", i, i - 1);
        fprintf(f, "[arrowhead=dot, arrowtail=vee, dir=both, headclip=false];\n");

        if (!tmp->next) 
            fprintf(f, "f%d:ref2:c -> end [arrowhead=vee, arrowtail=dot, dir=both, tailclip=false]", i);
        else
            fprintf(f, "f%d:ref2:c -> f%d:data:n [arrowhead=dot, arrowtail=vee, dir=both, headclip=false];\n", i, i + 1);

        i++;

        tmp = tmp->next;
    }

    fprintf(f, "}\n");
}

int check_digit(char *str, int *num)
{
    int i = 0, j = 0;
    char *tmp = malloc(sizeof(str));

    *num = 1;

    while (str[i])
    {
        if (i == 0 && str[i] == '-')
            *num = -1;

        else if (str[i] < 48 || str[i] > 58)
        {
            free(tmp);
            return ERR_WRONG_DATA;
        }
        else
            tmp[j++] = str[i];

        i++;
    }

    tmp[j] = '\0';

    *num = (*num) * atoi(tmp);

    free(tmp);

    return SUCCESS;
}