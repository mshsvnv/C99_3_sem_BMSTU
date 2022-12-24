#ifndef __OPTS_H__
#define __OPTS_H__

#include "constants.h"

void write_string(char *restrict buf, char *str, size_t num, size_t *len);

void write_short_int(char *restrict buf, int digit, size_t num, size_t *len);

char *from_dig_to_num(int dig);


#endif // __OPTS_H__