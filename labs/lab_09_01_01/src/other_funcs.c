#include "../inc/defs.h"
#include "../inc/film_funcs.h"

int check_year(char *year)
{
    size_t i = 0;

    while (isdigit(year[i]) != 0)
        i++;

    return (i == strlen(year)) ? SUCCESS : ERR_WRONG_YEAR;
}

void swap(films_array_t *films_array, int *beg, int *end)
{
    film_t tmp_film;
    
    tmp_film.title = NULL;
    tmp_film.name = NULL;

    copy_film(&films_array->pointer[*beg], &tmp_film);

    int j = *beg;
    while (j > *end)
    {
        copy_film(&films_array->pointer[j - 1], &films_array->pointer[j]);
        j--;
    }

    copy_film(&tmp_film, &films_array->pointer[*end]);

    free_film(&tmp_film);
}
