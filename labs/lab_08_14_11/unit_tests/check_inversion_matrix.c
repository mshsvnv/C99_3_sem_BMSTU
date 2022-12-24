#include <check.h>

#include "../inc/defs.h"
#include "../inc/matrix_funcs.h"
#include "../inc/memory_func.h"
#include "../inc/file_funcs.h"

//-------------------------------positives-------------------------------//
START_TEST(test_inversion_matrix_size_3_3)
{
    matrix_t matrix_1, res, ideal;
    ptr_t ptr_m1 = &matrix_1, ptr_res = &res, ptr_ideal = &ideal;
    int rc = 0;
    FILE *f;

    f = fopen("./func_tests/data/pos_10_in.txt", "r");
    if (fill(f, ptr_m1) != SUCCESS)
        rc++;
    fclose(f);

    f = fopen("./func_tests/data/pos_10_out.txt", "r");
    if (fill(f, ptr_ideal) != SUCCESS)
        rc++;
    fclose(f);

    //ck_assert_int_eq(SUCCESS, rc);

    res.rows = matrix_1.rows, res.columns = matrix_1.columns;
    res.pointer = inversion_matrix(ptr_m1);

    rc = check_matrix(ptr_res, ptr_ideal);

    ck_assert_ptr_nonnull(res.pointer);
    ck_assert_int_eq(SUCCESS, rc);

    free(matrix_1.pointer), free(res.pointer), free(ideal.pointer);  
} 
END_TEST

START_TEST(test_inversion_matrix_size_1_1)
{
    matrix_t matrix_1, res, ideal;
    ptr_t ptr_m1 = &matrix_1, ptr_res = &res, ptr_ideal = &ideal;
    int rc = 0;
    FILE *f;

    f = fopen("./func_tests/data/pos_11_in.txt", "r");
    if (fill(f, ptr_m1) != SUCCESS)
        rc++;
    fclose(f);

    f = fopen("./func_tests/data/pos_11_out.txt", "r");
    if (fill(f, ptr_ideal) != SUCCESS)
        rc++;
    fclose(f);

    //ck_assert_int_eq(SUCCESS, rc);

    res.rows = matrix_1.rows, res.columns = matrix_1.columns;
    res.pointer = inversion_matrix(ptr_m1);

    rc = check_matrix(ptr_res, ptr_ideal);

    ck_assert_ptr_nonnull(res.pointer);
    ck_assert_int_eq(SUCCESS, rc);

    free(matrix_1.pointer), free(res.pointer), free(ideal.pointer);  
} 
END_TEST

Suite* inversion_matrix_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("inversion_matrix");

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_inversion_matrix_size_1_1);
    tcase_add_test(tc_pos, test_inversion_matrix_size_3_3);

    suite_add_tcase(s, tc_pos);
    return s;
}
