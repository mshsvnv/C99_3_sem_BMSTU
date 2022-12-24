#ifndef  __MATH_FUNCS_H__
#define  __MATH_FUNCS_H__

#include "defs.h"
#include "node_funcs.h"
#include <math.h>

int is_prime(int *num);

node_t *multiplication(node_t *head, node_t *first_num, node_t *second_num);

node_t *division(node_t *head, node_t *first_num, node_t *second_num);

node_t *to_square(node_t *head, node_t *num);

#endif  // __MATH_FUNCS_H__