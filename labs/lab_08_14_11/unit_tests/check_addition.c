#include <check.h>

#include "../inc/defs.h"
#include "../inc/matrix_funcs.h"
#include "../inc/memory_func.h"
#include "../inc/file_funcs.h"

int check_matrix(ptr_t ptr_m1, ptr_t ptr_m2)
{
    for (size_t i = 0; i < ptr_m1->rows; i++)
    {
        for (size_t j = 0; j < ptr_m1->rows; j++)
        {
            if (fabs(ptr_m1->pointer[i][j] - ptr_m2->pointer[i][j]) > EPS)
                return -1;
        }
    }

    return SUCCESS;
}

int fill(FILE *f, ptr_t ptr_m)
{
    int rc = 0;

    rc = read_rows_columns(f, ptr_m);

    if (rc)
        return rc;

    ptr_m->pointer = allocation(ptr_m->rows, ptr_m->columns);

    if (ptr_m->pointer == NULL)
        return rc;
    
    rc = read_matrix(f, ptr_m);

    if (rc)
    {
        free(ptr_m->pointer);
        return rc;
    }

    return SUCCESS;
}

//-------------------------------positives-------------------------------//
START_TEST(test_addition_size_1_1)
{
    matrix_t matrix_1, matrix_2, res, ideal;
    ptr_t ptr_m1 = &matrix_1, ptr_m2 = &matrix_2, ptr_res = &res, ptr_ideal = &ideal;
    int rc = 0;
    FILE *f;

    f = fopen("./func_tests/data/pos_04_01_in.txt", "r");
    if (fill(f, ptr_m1) == SUCCESS)
        rc++;
    fclose(f);

    f = fopen("./func_tests/data/pos_04_02_in.txt", "r");
    if (fill(f, ptr_m2) == SUCCESS)
        rc++;
    fclose(f);

    f = fopen("./func_tests/data/pos_04_out.txt", "r");
    if (fill(f, ptr_ideal) == SUCCESS)
        rc++;
    fclose(f);

    //ck_assert_int_eq(SUCCESS, rc);

    res.rows = matrix_1.rows, res.columns = matrix_2.columns;
    res.pointer = addition(ptr_m1, ptr_m2);

    rc = check_matrix(ptr_res, ptr_ideal);

    ck_assert_ptr_nonnull(res.pointer);
    ck_assert_int_eq(SUCCESS, rc);

    free(matrix_1.pointer), free(matrix_2.pointer), free(res.pointer), free(ideal.pointer);  
} 
END_TEST

START_TEST(test_addition_size_2_2)
{
    matrix_t matrix_1, matrix_2, res, ideal;
    ptr_t ptr_m1 = &matrix_1, ptr_m2 = &matrix_2, ptr_res = &res, ptr_ideal = &ideal;
    int rc = 0;
    FILE *f;

    f = fopen("./func_tests/data/pos_01_01_in.txt", "r");
    if (fill(f, ptr_m1) == SUCCESS)
        rc++;
    fclose(f);

    f = fopen("./func_tests/data/pos_01_02_in.txt", "r");
    if (fill(f, ptr_m2) == SUCCESS)
        rc++;
    fclose(f);

    f = fopen("./func_tests/data/pos_01_out.txt", "r");
    if (fill(f, ptr_ideal) == SUCCESS)
        rc++;
    fclose(f);

   // ck_assert_int_eq(SUCCESS, rc);

    res.rows = matrix_1.rows, res.columns = matrix_2.columns;
    res.pointer = addition(ptr_m1, ptr_m2);
    
    rc = check_matrix(ptr_res, ptr_ideal);

    ck_assert_ptr_nonnull(res.pointer);
    ck_assert_int_eq(SUCCESS, rc);

    free(matrix_1.pointer), free(matrix_2.pointer), free(res.pointer), free(ideal.pointer);  
} 
END_TEST

START_TEST(test_addition_size_1_5)
{
    matrix_t matrix_1, matrix_2, res, ideal;
    ptr_t ptr_m1 = &matrix_1, ptr_m2 = &matrix_2, ptr_res = &res, ptr_ideal = &ideal;
    int rc = 0;
    FILE *f;

    f = fopen("./func_tests/data/pos_02_01_in.txt", "r");
    if (fill(f, ptr_m1) == SUCCESS)
        rc++;
    fclose(f);

    f = fopen("./func_tests/data/pos_02_02_in.txt", "r");
    if (fill(f, ptr_m2) == SUCCESS)
        rc++;
    fclose(f);

    f = fopen("./func_tests/data/pos_02_out.txt", "r");
    if (fill(f, ptr_ideal) == SUCCESS)
        rc++;
    fclose(f);

    //ck_assert_int_eq(SUCCESS, rc);

    res.rows = matrix_1.rows, res.columns = matrix_2.columns;
    res.pointer = addition(ptr_m1, ptr_m2);
    
    rc = check_matrix(ptr_res, ptr_ideal);

    ck_assert_ptr_nonnull(res.pointer);
    ck_assert_int_eq(SUCCESS, rc);

    free(matrix_1.pointer), free(matrix_2.pointer), free(res.pointer), free(ideal.pointer);  
} 
END_TEST

Suite* addition_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("addition");

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_addition_size_1_1);
    tcase_add_test(tc_pos, test_addition_size_2_2);
    tcase_add_test(tc_pos, test_addition_size_1_5);

    suite_add_tcase(s, tc_pos);

    return s;
}
