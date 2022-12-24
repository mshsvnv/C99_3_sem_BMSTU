#ifndef __OTHERS_H__
#define __OTHERS_H__

#include "constants.h"
#include "list.h"

void list_print(char *name, node_t *head);

node_t *read_from_file(node_t *head, FILE *f_in);

long file_size(FILE *f_in);

#endif // __OTHERS_H__