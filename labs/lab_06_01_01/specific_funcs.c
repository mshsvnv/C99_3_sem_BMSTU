/**
 * @file specific_funcs.c
 * @author Maria Savinova
 * @brief additioinal functions to extend its facilities
 * @version 0.1
 * @date 2022-09-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "defs.h"

/**
 * @brief function to check up digit 
 * 
 * @param[i] buffer probable number
 * @param[i] buf_len len of the probable number
 * @return int SUCCESS if its a number otherwise another exit code
 */
int check_digit(char *buffer, int *buf_len)
{
    int i = 0;

    while (isdigit(buffer[i]) != 0 && i < *buf_len)
        i++;

    return (i < *buf_len) ? INCORRECT_YEAR_ERROR: SUCCESS;
}

/**
 * @brief function to read one line from the file
 * 
 * @param[in] f file variable
 * @param[in] buffer our future line
 * @return int length oh the line
 */
int read_line(FILE *f, char *buffer, int *len)
{
    int i = 0;
   
    char cur = fgetc(f);

    while (cur != '\n' && cur != EOF)
    {
        buffer[i] = cur;
        cur = fgetc(f);
        i++;
    }

    buffer[i] = '\0';
    *len = i;

    if (cur == EOF)
        return FILE_END_ERROR;
    
    return SUCCESS;
}