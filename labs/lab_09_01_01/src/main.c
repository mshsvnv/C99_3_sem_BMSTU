#include "../inc/defs.h"
#include "../inc/file_funcs.h"
#include "../inc/films_array_funcs.h"
#include "../inc/film_funcs.h"
#include "../inc/essential_funcs.h"

int main(int argc, char **argv)
{
    FILE *f_in;
    films_array_t films_array;
    int rc, index;

    if (argc != ARGS_AMOUNT && argc != ARGS_AMOUNT - 1)
        return ERR_ARGS_AMOUNT;

    f_in = fopen(argv[1], "r");

    if (!f_in)
        return ERR_IO;

    if (check_file_size(f_in) == 0)
    {
        fclose(f_in);
        return ERR_EMPTY_FILE;
    }

    if (strcmp(argv[2], TITLE) == 0)
    {
        init_films_array(&films_array, TITLE);
    }
    else if (strcmp(argv[2], NAME) == 0)
    {
        init_films_array(&films_array, NAME);
    }
    else if (strcmp(argv[2], YEAR) == 0)
    {
        init_films_array(&films_array, YEAR);
    }
    else
    {
        fclose(f_in);
        return ERR_FIELD_NAME;
    }

    rc = fill_films_array(f_in, &films_array);

    if (rc)
    {
        fclose(f_in);
        free_films_array(&films_array);
        return rc;
    }

    if (argc == ARGS_AMOUNT - 1)
    {
        rc = print_films_array(&films_array);
    }
    else if (argc == ARGS_AMOUNT)
    {
        rc = binary_search(&films_array, argv[3], &index);

        if (rc == NOT_FOUND)
        {
            rc = SUCCESS;
            printf("Not found\n");
        }
        else if (rc == SUCCESS)
            printf("%s\n%s\n%d\n", films_array.pointer[index].title, films_array.pointer[index].name, films_array.pointer[index].year);
    }

    free_films_array(&films_array);
    fclose(f_in);

    return rc;
}
