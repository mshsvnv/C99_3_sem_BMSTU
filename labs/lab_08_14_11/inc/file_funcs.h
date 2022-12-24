#ifndef __FILE_FUNC_H__
#define __FILE_FUNC_H__

long check_file_size(FILE *f);
int read_rows_columns(FILE *f, ptr_t ptr_matrix);
int read_matrix(FILE *f, ptr_t ptr_matrix);
void write_file(FILE *f, ptr_t ptr_matrix);

#endif // __FILE_FUNC_H__