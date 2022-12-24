/**
 * @file main.c
 * @author Maria Savinova
 * @brief main function
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

#include "essential_funcs.h"
#include "specific_funcs.h"
#include "file_funcs.h"
#include "defs.h"

/**
 * @brief main function where all funtions are perfomed
 * 
 * @param argc amount of command line arguments
 * @param argv array of the line arguments
 * @return int exit code
 */
int main(int argc, char **argv)
{
    int count = 0, rc;

    // check up args amount
    if (argc != MIN_ARGS && argc != MAX_ARGS)
    {
        //printf("Wrong amount of arguments!\n");
        return ARGS_AMOUNT_ERROR;
    }
    
    FILE *f = fopen(argv[1], "r");

    // if we actually have a file
    if (check_file_exist(f))
    {
        //printf("No input file!\n");
        return IO_ERROR;
    }

    // determine size of it
    if (! check_file_size(f))
    {
        //printf("Intput file is empty!\n");
        fclose(f);
        return FILE_SIZE_ERROR;
    }

    if (strcmp(argv[2], TITLE) == 0 || strcmp(argv[2], NAME) == 0 || strcmp(argv[2], YEAR) == 0)
    {
        rc = read_struct(f, argv[2], &count);
    
        if (rc)
        {
            fclose(f);
            return rc;
        }
            
        rc = (argc == 3) ? show(&count) : binary_search(argv[2], argv[3], &count);
    }
    else
    {
        //printf("Incorrect struct field name!\n");
        fclose(f);
        return FIELD_NAME_ERROR;
    }

    fclose(f);

    return rc;
}
