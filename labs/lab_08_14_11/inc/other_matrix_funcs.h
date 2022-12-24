#ifndef __OTHER_MATRIX_FUNCS_H__
#define __OTHER_MATRIX_FUNCS_H__

int check_dims(ptr_t ptr_matrix_1, ptr_t ptr_matrix_2, char ch);
int determinant(ptr_t ptr_matrix, double *det);
double *gauss(ptr_t ptr_matrix, double *x);
double **convert_triangle(ptr_t ptr_matrix);
double **extended_matrix(ptr_t ptr_matrix, double *x);
void swap(double **matrix, size_t i, size_t j);

#endif // __OTHER_MATRIX_FUNCS_H__