#ifndef __FILMS_FUNCS_H__ 
#define __FILMS_FUNCS_H__

int read_film(FILE *f, char **title, char **name, int *year);
void free_film(film_t *film);
int init_film(film_t *film, char *title, char *name, int year);
int copy_film(film_t *src_film, film_t *dst_film);

#endif // __FILMS_FUNCS_H__