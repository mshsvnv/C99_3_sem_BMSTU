#include "../inc/defs.h"

long check_file_size(FILE *f)
{
    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    fseek(f, 0, SEEK_SET);

    return size;
}

int read_rows_columns(FILE *f, matrix_t *matrix)
{
    int tmp[2];
    int rc;
    char ch;

    rc = fscanf(f, "%d%d%c", &tmp[0], &tmp[1], &ch);

    if (rc != 3 || ch != '\n')
        return WRONG_SIZE_ERR;

    if (tmp[0] <= 0 || tmp[1] <= 0)
        return WRONG_SIZE_ERR;
    else
    {
        if (tmp[0] != tmp[1] || tmp[0] == 1 || tmp[1] == 1)
            return WRONG_SIZE_ERR;

        matrix->rows = tmp[0], matrix->columns = tmp[1];
    }
    return SUCCESS;
}


int read_matrix(FILE *f, matrix_t *matrix)
{
    int dig;
    int i, j;
    char ch;
    int rc;

    while (!feof(f) && (ch = fgetc(f)) != EOF)
    {
        fseek(f, -1, SEEK_CUR);

        for (i = 0; i < matrix->rows; i++)
        {
            for (j = 0; j < matrix->columns; j++)
            {
                if (fscanf(f, "%d", &dig) == 1)
                {
                    matrix->pointer[i*matrix->columns + j] = dig;
                }
                else
                    return INCORR_DATA_ERR;
            }
        }
        rc = fscanf(f, "%c", &ch);

        if ((rc == 1 && ch == '\n') || rc == -1)
            return SUCCESS;
        else if (rc == 1 && ch != '\n')
            return INCORR_DATA_ERR;                     
    }

    return SUCCESS;
}

void write_file(FILE *f, matrix_t *matrix, char *ch)
{
    int i, j;

    fprintf(f, "%d %d\n", matrix->rows, matrix->columns);

    if (*ch != 0)
    {
        for (i = 0; i < matrix->rows; i++)
        {
            for (j = 0; j < matrix->columns; j++)
            {
                fprintf(f, "%d ", matrix->pointer[i*matrix->columns + j]);
            }
            fprintf(f, "\n");
        }
    }
    else
    {
        for (i = 0; i < matrix->rows; i++)
        {
            for (j = 0; j < matrix->columns; j++)
            {
                fprintf(f, "%d ", matrix->pointer[i*matrix->columns + j + i]);
            }
            fprintf(f, "\n");
        }
    }    
}