#include "../inc/defs.h"
#include "../inc/film_funcs.h"
#include "../inc/other_funcs.h"
#include "../inc/essential_funcs.h"

void sort_films_array(films_array_t *films_array)
{
    int left = 0, right = films_array->len - 1, mid, i = right;
    int rc;

    if (strcmp(films_array->filed_to_sort, NAME) == 0)
    {
        while (left < right)
        {
            mid = (left + right) / 2;
            rc = strcmp(films_array->pointer[mid].name, films_array->pointer[i].name);
            
            if (rc > 0)
                right = mid;
            else
                left = mid + 1;
        }
    }
    else if (strcmp(films_array->filed_to_sort, TITLE) == 0)
    {
        while (left < right)
        {
            mid = (left + right) / 2;
            rc = strcmp(films_array->pointer[mid].title, films_array->pointer[i].title);

            if (rc > 0)
                right = mid;
            else
                left = mid + 1;
        }
    }
    else if (strcmp(films_array->filed_to_sort, YEAR) == 0)
    {
        while (left < right)
        {
            mid = (left + right) / 2;

            if (films_array->pointer[i].year < films_array->pointer[mid].year)
                right = mid;
            else
                left = mid + 1;
        }
    }
    swap(films_array, &i, &left);
}

int binary_search(films_array_t *films_array, char *key, int *index)
{
    int left = 0, right = films_array->len - 1;
    int rc, year;

    *index = -1;

    if (strcmp(films_array->filed_to_sort, NAME) == 0)
    {
        while (left <= right)
        {
            int mid = (left + right) / 2;
           
            rc = strcmp(films_array->pointer[mid].name, key);

            if (rc == 0)
            {
                *index = mid;
                break;
            }

            if (rc > 0)
                right = mid - 1;
            else
                left = mid + 1;
        }
    }
    else if (strcmp(films_array->filed_to_sort, TITLE) == 0)
    {
        while (left <= right)
        {
            int mid = (left + right) / 2;
            rc = strcmp(films_array->pointer[mid].title, key);

            if (rc == 0)
            {
                *index = mid;
                break;
            }

            if (rc > 0)
                right = mid - 1;
            else
                left = mid + 1;
        }
    }
    else if (strcmp(films_array->filed_to_sort, YEAR) == 0)
    {
        rc = check_year(key);
        if (rc != 0)
            return ERR_WRONG_YEAR;

        year = atoi(key);
        if (year <= 0)
            return ERR_WRONG_YEAR;

        while (left <= right)
        {
            int mid = (left + right) / 2;

            if (films_array->pointer[mid].year == year)
            {
                *index = mid;
                break;
            }

            if (year < films_array->pointer[mid].year)
                right = mid - 1;
            else
                left = mid + 1;
        }
    }

    if (*index == -1)
        return NOT_FOUND;
    else
        return SUCCESS;
}