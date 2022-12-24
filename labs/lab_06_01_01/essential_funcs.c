/**
 * @file essential_funcs.c
 * @author Maria Savinova
 * @brief important functions to work with structures
 * @version 0.1
 * @date 2022-09-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "defs.h"
#include "struct.h"
#include "file_funcs.h"
#include "specific_funcs.h"

/**
 * @brief function to shift structures in the array
 * 
 * @param[in] beg fist position
 * @param[in] end decond position
 */
void swap(int *beg, int *end)
{
    struct film_data temp = films[*beg];

    int j = *beg;
    while (j > *end)
    {
        films[j] = films[j - 1];
        j--;
    }

    films[*end] = temp;
}

/**
 * @brief function to show array elemenrs
 * 
 * @param[in] count amount of the elements
 * @return int SUCCESS
 */
int show(int *count)
{
    for (int i = 0; i < *count; i++)
        printf("%s\n%s\n%d\n", films[i].title, films[i].name, films[i].year);

    return SUCCESS;
}

/**
 * @brief function to find required element in the defenite field 
 * 
 * @param[in] field where we have to find
 * @param[in] key name of the required element
 * @param[in] count amount of the elements
 * @return int SUCCESS
 */
int binary_search(char *field, char *key, int *count)
{
    int left = 0, right = *count - 1, index = -1, rc, year;

    if (strlen(key) > MAX_LEN - 1)
        return FIND_FIELD_ERORR;

    if (strcmp(field, NAME) == 0)
    {
        while (left <= right)
        {
            int mid = (left + right) / 2;
            rc = strcmp(films[mid].name, key);

            if (rc == 0)
            {
                index = mid;
                break;
            }

            if (rc > 0)
                right = mid - 1;
            else
                left = mid + 1;
        }
    }
    else if (strcmp(field, TITLE) == 0)
    {
        while (left <= right)
        {
            int mid = (left + right) / 2;
            rc = strcmp(films[mid].title, key);

            if (rc == 0)
            {
                index = mid;
                break;
            }

            if (rc > 0)
                right = mid - 1;
            else
                left = mid + 1;
        }
    }
    else if (strcmp(field, YEAR) == 0)
    {
        year = (int)(strlen(key));

        rc = check_digit(key, &year);
        if (rc != 0)
            return FIND_FIELD_ERORR;

        year = atoi(key);

        while (left <= right)
        {
            int mid = (left + right) / 2;

            if (films[mid].year == year)
            {
                index = mid;
                break;
            }

            if (year < films[mid].year)
                right = mid - 1;
            else
                left = mid + 1;
        }
    }

    if (index == -1)
        printf("Not found\n");
    else
        printf("%s\n%s\n%d\n", films[index].title, films[index].name, films[index].year);

    return SUCCESS;
}

/**
 * @brief function to sort array
 * 
 * @param [in] count amount of the elements
 * @param[in] field on which field our sort process based
 */
void sort(int *count, char *field)
{
    int left = 0, right = *count - 1, mid, rc, i = *count - 1;

    if (strcmp(field, NAME) == 0)
    {
        while (left < right)
        {
            mid = (left + right) / 2;
            rc = strcmp(films[mid].name, films[i].name);
            
            if (rc > 0)
                right = mid;
            else
                left = mid + 1;
        }
        swap(&i, &left);
    }
    else if (strcmp(field, TITLE) == 0)
    {
        while (left < right)
        {
            mid = (left + right) / 2;
            rc = strcmp(films[mid].title, films[i].title);

            if (rc > 0)
                right = mid;
            else
                left = mid + 1;
        }
        swap(&i, &left);
    }
    else if (strcmp(field, YEAR) == 0)
    {
        while (left < right)
        {
            mid = (left + right) / 2;

            if (films[i].year < films[mid].year)
                right = mid;
            else
                left = mid + 1;
        }
        swap(&i, &left);
    }
}

/**
 * @brief function to read a structer from the file
 * 
 * @param[in] f file variable
 * @param [in] field on which field our future sort process based
 * @param[in] count amount of the elements
 * @return int SUCCESS if all the structures were read otherwise another exitcode
 */
int read_struct(FILE *f, char *field, int *count)
{
    char buffer[BUF_LEN];
    int i = 0, j = 0, rc, len_buffer;

    while (! feof(f))
    {
        rc = read_line(f, buffer, &len_buffer);

        if (rc != 0 && len_buffer == 0)
            break;
        
        if (len_buffer > MAX_LEN - 1 || len_buffer == 0)
            return FIELD_LEN_ERROR;

        rc = -1;

        if (j == 0)
            strcpy(films[i].title, buffer);
        else if (j == 1)
            strcpy(films[i].name, buffer);
        else
        {
            rc = check_digit(buffer, &len_buffer);

            if (rc == 0)
                films[i].year = atoi(buffer);
            else
                return rc;
        }

        j = (j + 1) % 3;

        if (j == 0 && rc == 0)
        {
            i++;
            sort(&i, field);
        }
        else if (j == 0 && rc != 0)
            return FIELD_AMOUNT_ERROR;
    }
    
    if (j == 0 && i <= STRUCTS_AMOUNT)
        *count = i;
    else if (i > STRUCTS_AMOUNT || j != 0)
        return STRUCTS_ANOUNT_ERROR;

    return SUCCESS;
}
