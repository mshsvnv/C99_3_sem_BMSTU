#include "../inc/defs.h"
#include "../inc/film_funcs.h"
#include "../inc/other_funcs.h"

int read_film(FILE *f, char **title, char **name, int *year)
{
    char *buffer = NULL;
    char *title_tmp = NULL;
    char *name_tmp = NULL;
    size_t len;
    ssize_t read;

    read = getline(&title_tmp, &len, f);
    if (read == -1)
        return ERR_MEMORY;
    else if (strlen(title_tmp) == 1)
        return ERR_EMPTY_FIELD;

    if (title_tmp[strlen(title_tmp) - 1] == '\n')
        title_tmp[strlen(title_tmp) - 1] = '\0';

    read = getline(&name_tmp, &len, f);
    if (read == -1)
    {
        free(title_tmp);
        return ERR_MEMORY;
    }
    else if (strlen(name_tmp) == 1)
    {
        free(title_tmp), free(name_tmp);
        return ERR_EMPTY_FIELD;
    }

    if (name_tmp[strlen(name_tmp) - 1] == '\n')
        name_tmp[strlen(name_tmp) - 1] = '\0';

    read = getline(&buffer, &len, f);
    if (read == -1)
    {
        free(title_tmp), free(name_tmp);
        return ERR_MEMORY;
    }
    else if (strlen(buffer) == 1)
    {
        free(title_tmp), free(name_tmp), free(buffer);
        return ERR_EMPTY_FIELD;
    }

    if (buffer[strlen(buffer) - 1] == '\n')
        buffer[strlen(buffer) - 1] = '\0';

    if (check_year(buffer) != SUCCESS)
    {
        free(title_tmp), free(name_tmp), free(buffer);
        return ERR_WRONG_YEAR; 
    }

    *year = atoi(buffer);
    if (*year == 0)
    {
        free(title_tmp), free(name_tmp), free(buffer);
        return ERR_WRONG_YEAR; 
    }

    *title = title_tmp;
    *name = name_tmp;

    free(buffer);

    return SUCCESS;
}

void free_film(film_t *film)
{
    free(film->name);
    free(film->title);
}

int init_film(film_t *film, char *title, char *name, int year)
{ 
    film->year = year;

    char *ptmp = strdup(title);

    if (ptmp)
    {
        free(film->title);
        film->title = ptmp;
    }
    else
        return ERR_MEMORY;

    ptmp = strdup(name);

    if (ptmp)
    {
        free(film->name);
        film->name = ptmp;
    }
    else
        return ERR_MEMORY;

    return SUCCESS;
}

int copy_film(film_t *src_film, film_t *dst_film)
{
    return init_film(dst_film, src_film->title, src_film->name, src_film->year);
}

