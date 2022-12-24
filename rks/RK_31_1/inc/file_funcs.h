#ifndef __FILE_FUNC_H__
#define __FILE_FUNC_H__

long check_file_size(FILE *f);
int read_rows_columns(FILE *f, matrix_t *matrix);
int read_matrix(FILE *f, matrix_t *matrix);
void write_file(FILE *f, matrix_t *matrix, char *ch);

#endif // __FILE_FUNC_H__