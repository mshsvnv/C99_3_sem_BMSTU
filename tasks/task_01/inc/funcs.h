#ifndef __FUNCS_H__
#define __FUNCS_H__

#include "constants.h"

void count_words(char *file_name, int flag);

void apply(int n, ...);

void show_cur_dir(char *current_path);

char *get_real_path(char *cur_dir, char *file_name);

#endif // __FUNCS_H__