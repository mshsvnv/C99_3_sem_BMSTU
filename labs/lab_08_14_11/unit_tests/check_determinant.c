#include <check.h>

#include "../inc/defs.h"
#include "../inc/matrix_funcs.h"
#include "../inc/memory_func.h"
#include "../inc/file_funcs.h"
#include "../inc/other_matrix_funcs.h"

//-------------------------------positives-------------------------------//

START_TEST(test_determinant_size_1_1)
{
    matrix_t matrix_1;
    ptr_t ptr_m1 = &matrix_1;
    int rc = 0;
    double det = -1;
    FILE *f;

    f = fopen("./func_tests/data/pos_11_in.txt", "r");
    if (fill(f, ptr_m1) != SUCCESS)
        rc++;
    fclose(f);

    //ck_assert_int_eq(SUCCESS, rc);

    rc = determinant(ptr_m1, &det);

    ck_assert_int_eq(SUCCESS, rc);

    free(matrix_1.pointer);
} 
END_TEST

START_TEST(test_determinant_size_3_3)
{
    matrix_t matrix_1;
    ptr_t ptr_m1 = &matrix_1;
    int rc = 0;
    double det = -1;
    FILE *f;

    f = fopen("./func_tests/data/pos_10_in.txt", "r");
    if (fill(f, ptr_m1) != SUCCESS)
        rc++;
    fclose(f);

    ck_assert_int_eq(SUCCESS, rc);

    rc = determinant(ptr_m1, &det);

    ck_assert_int_eq(SUCCESS, rc);

    free(matrix_1.pointer);
} 
END_TEST

//-------------------------------negatives-------------------------------//

START_TEST(test_determinant_size_deg_mtr)
{
    matrix_t matrix_1;
    ptr_t ptr_m1 = &matrix_1;
    int rc = 0;
    double det = -1;
    FILE *f;

    f = fopen("./func_tests/data/neg_11_in.txt", "r");
    if (fill(f, ptr_m1) != SUCCESS)
        rc++;
    fclose(f);

    rc = determinant(ptr_m1, &det);

    ck_assert_int_eq(MEMORY_ERR, rc);

    free(matrix_1.pointer);
} 
END_TEST

Suite* determinant_suite(void)
{
    Suite *s;
    TCase *tc_pos, *tc_neg;

    s = suite_create("determinant");

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_determinant_size_1_1);
    tcase_add_test(tc_pos, test_determinant_size_3_3);

    suite_add_tcase(s, tc_pos);

    tc_neg = tcase_create("negatives");

    tcase_add_test(tc_pos, test_determinant_size_deg_mtr);

    suite_add_tcase(s, tc_neg);
    return s;
}
