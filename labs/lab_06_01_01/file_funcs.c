/**
 * @file file_funcs.c
 * @author Maria Savinova
 * @brief functions associated to file
 * @version 0.1
 * @date 2022-09-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

#include "defs.h"

/**
 * @brief function to chek up if the file exist
 * 
 * @param[in] f file variable
 * @return int SUCCESS if file actually exist otherwise IO_ERROR
 */
int check_file_exist(FILE *f)
{
    return (f == NULL) ? IO_ERROR: SUCCESS;
}

/**
 * @brief function to chek up the file size
 * 
 * @param[in] f file variable
 * @return int size of input file
 */
long check_file_size(FILE *f)
{
    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    fseek(f, 0, SEEK_SET);

    return size;
}