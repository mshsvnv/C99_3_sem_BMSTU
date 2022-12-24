#include "../inc/defs.h"

long check_file_size(FILE *f)
{
    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    fseek(f, 0, SEEK_SET);

    return size;
}

int read_rows_columns(FILE *f, ptr_t ptr_matrix)
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
        ptr_matrix->rows = tmp[0], ptr_matrix->columns = tmp[1];

    return SUCCESS;
}


int read_matrix(FILE *f, ptr_t ptr_matrix)
{
    double dig;
    size_t i, j;
    char ch;
    int rc;

    while (!feof(f) && (ch = fgetc(f)) != EOF)
    {
        fseek(f, -1, SEEK_CUR);

        for (i = 0; i < ptr_matrix->rows; i++)
        {
            for (j = 0; j < ptr_matrix->columns; j++)
            {
                if (fscanf(f, "%lf", &dig) == 1)
                {
                    ptr_matrix->pointer[i][j] = dig;
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

void write_file(FILE *f, ptr_t ptr_matrix)
{
    size_t i, j;

    fprintf(f, "%ld %ld\n", ptr_matrix->rows, ptr_matrix->columns);

    for (i = 0; i < ptr_matrix->rows; i++)
    {
        for (j = 0; j < ptr_matrix->columns; j++)
        {
            if (j < ptr_matrix->columns - 1)
                fprintf(f, "%lf ", ptr_matrix->pointer[i][j]);
            else
                fprintf(f, "%lf\n", ptr_matrix->pointer[i][j]);
        }
    }
}