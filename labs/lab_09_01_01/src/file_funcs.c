#include "../inc/defs.h"
#include "../inc/films_array_funcs.h"
#include "../inc/film_funcs.h"
#include "../inc/file_funcs.h"
#include "../inc/essential_funcs.h"

long check_file_size(FILE *f)
{
    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    fseek(f, 0, SEEK_SET);

    return size;
}

int fill_films_array(FILE *f, films_array_t *films_array)
{
    int rc;
    char ch;
    film_t tmp_film;
    
    char *title = NULL, *name = NULL;
    int year;

    while (!feof(f) && (ch = fgetc(f)) != EOF)
    {
        fseek(f, -1, SEEK_CUR);

        tmp_film.title = NULL;
        tmp_film.name = NULL;

        rc = read_film(f, &title, &name, &year);

        if (rc)
            return rc;

        rc = init_film(&tmp_film, title, name, year);

        if (rc)
        {
            free_film(&tmp_film);
            return rc;
        }

        rc = append_films_array(films_array, &tmp_film);
        
        free_film(&tmp_film);

        free(title);
        free(name);

        title = NULL;
        name = NULL;

        if (rc)
            return rc;

        sort_films_array(films_array);
    } 

    return SUCCESS;
}
