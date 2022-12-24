#ifndef __FILE_FUNCS_H__
#define __FILE_FUNCS_H__ 

#include "defs.h"
#include "node_funcs.h"
#include "list_funcs.h"
#include "other_funcs.h"

long check_file_size(FILE *f);

int fill_list(FILE *f_in, node_t **head);

void write_list(FILE *f_out, node_t *head);

void write_node(FILE *f_out, void *data);

#endif // __FILE_FUNCS_H__