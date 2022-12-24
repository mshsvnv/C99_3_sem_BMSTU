#ifndef __OTHER_FUNCS_H__
#define __OTHER_FUNCS_H__ 

#include "defs.h"
#include "node_funcs.h"

int check_amount(char *string, int *amount);

int compare_amino_acid(const void *left, const void *right);

int compare_triplet(const void *left, const void *right);

int compare_amount(const void *left, const void *right);

void clean_data(void **p);

#endif // __OTHER_FUNCS_H__