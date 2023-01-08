#include "list.h"

int main()
{
    node_t *pos = NULL, *neg = NULL;
    int rc;

    rc = list_read(&pos, &neg);

    if (rc)
        printf("ERROR: %d\n", rc);
    else
    {
        pos = list_union(pos, neg);

        list_print(pos);
        list_free(&pos);
    }

    return rc;
}