#ifndef __FILMS_ARRAY_FUNCS_H__ 
#define __FILMS_ARRAY_FUNCS_H__

void init_films_array(films_array_t *films_array, char *field);
int append_films_array(films_array_t *films_array, film_t *tmp_film);
void free_films_array(films_array_t *films_array);
int print_films_array(films_array_t *films_array);

#endif // __FILMS_ARRAY_FUNCS_H__