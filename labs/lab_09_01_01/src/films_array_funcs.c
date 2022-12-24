#include "../inc/defs.h"
#include "../inc/films_array_funcs.h"
#include "../inc/film_funcs.h"

void init_films_array(films_array_t *films_array, char *field)
{
    films_array->len = 0;
    films_array->allocated = 0;
    films_array->step = 2;
    films_array->filed_to_sort = field;
    films_array->pointer = NULL;
}

int append_films_array(films_array_t *films_array, film_t *tmp_film)
{
    int rc;

    if (!films_array->pointer)
    {
        void *p = malloc(sizeof(film_t) * INIT_SIZE);

        if (!p)
            return ERR_MEMORY;

        films_array->allocated = INIT_SIZE;
        films_array->pointer = p;
    }
    else
    {
        if (films_array->len >= films_array->allocated)
        {
            void *p = realloc(films_array->pointer, films_array->allocated * films_array->step * sizeof(film_t));

            if (!p)
                return ERR_MEMORY;

            films_array->allocated *= films_array->step;
            films_array->pointer = p;
        }
    }

    films_array->pointer[films_array->len].title = NULL;
    films_array->pointer[films_array->len].name = NULL;
    
    rc = copy_film(tmp_film, &films_array->pointer[films_array->len]);

    if (rc)
        return rc;
    
    films_array->len++;

    return SUCCESS;
}

void free_films_array(films_array_t *films_array)
{
    int i = 0;

    for (; i < films_array->len; i++)
        free_film(&films_array->pointer[i]);

    free(films_array->pointer);
}

int print_films_array(films_array_t *films_array)
{
    int i = 0;

    for (; i < films_array->len; i++)
        printf("%s\n%s\n%d\n", films_array->pointer[i].title, films_array->pointer[i].name, films_array->pointer[i].year);

    return SUCCESS;
}