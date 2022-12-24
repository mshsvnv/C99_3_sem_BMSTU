#include <check.h>

#include "../inc/defs.h"
#include "../inc/matrix_funcs.h"
#include "../inc/memory_func.h"
#include "../inc/file_funcs.h"

//-------------------------------positives-------------------------------//
START_TEST(test_multiplication_size_1_1)
{
    matrix_t matrix_1, matrix_2, res, ideal;
    ptr_t ptr_m1 = &matrix_1, ptr_m2 = &matrix_2, ptr_res = &res, ptr_ideal = &ideal;
    int rc = 0;
    FILE *f;

    f = fopen("./func_tests/data/pos_09_01_in.txt", "r");
    if (fill(f, ptr_m1) != SUCCESS)
        rc++;
    fclose(f);

    f = fopen("./func_tests/data/pos_09_02_in.txt", "r");
    if (fill(f, ptr_m2) != SUCCESS)
        rc++;
    fclose(f);

    f = fopen("./func_tests/data/pos_09_out.txt", "r");
    if (fill(f, ptr_ideal) != SUCCESS)
        rc++;
    fclose(f);

    //ck_assert_int_eq(SUCCESS, rc);

    res.rows = matrix_1.rows, res.columns = matrix_2.columns;
    res.pointer = multiplication(ptr_m1, ptr_m2);

    rc = check_matrix(ptr_res, ptr_ideal);

    ck_assert_ptr_nonnull(res.pointer);
    ck_assert_int_eq(SUCCESS, rc);

    free(matrix_1.pointer), free(matrix_2.pointer), free(res.pointer), free(ideal.pointer);  
} 
END_TEST

START_TEST(test_multiplication_size_2_2)
{
    matrix_t matrix_1, matrix_2, res, ideal;
    ptr_t ptr_m1 = &matrix_1, ptr_m2 = &matrix_2, ptr_res = &res, ptr_ideal = &ideal;
    int rc = 0;
    FILE *f;

    f = fopen("./func_tests/data/pos_05_01_in.txt", "r");
    if (fill(f, ptr_m1) != SUCCESS)
        rc++;
    fclose(f);

    f = fopen("./func_tests/data/pos_05_02_in.txt", "r");
    if (fill(f, ptr_m2) != SUCCESS)
        rc++;
    fclose(f);

    f = fopen("./func_tests/data/pos_05_out.txt", "r");
    if (fill(f, ptr_ideal) != SUCCESS)
        rc++;
    fclose(f);

    //ck_assert_int_eq(SUCCESS, rc);

    res.rows = matrix_1.rows, res.columns = matrix_2.columns;
    res.pointer = multiplication(ptr_m1, ptr_m2);
    
    rc = check_matrix(ptr_res, ptr_ideal);

    ck_assert_ptr_nonnull(res.pointer);
    ck_assert_int_eq(SUCCESS, rc);

    free(matrix_1.pointer), free(matrix_2.pointer), free(res.pointer), free(ideal.pointer);  
} 
END_TEST

START_TEST(test_multiplication_size_1_4_4_1)
{
    matrix_t matrix_1, matrix_2, res, ideal;
    ptr_t ptr_m1 = &matrix_1, ptr_m2 = &matrix_2, ptr_res = &res, ptr_ideal = &ideal;
    int rc = 0;
    FILE *f;

    f = fopen("./func_tests/data/pos_07_01_in.txt", "r");
    if (fill(f, ptr_m1) != SUCCESS)
        rc++;
    fclose(f);

    f = fopen("./func_tests/data/pos_07_02_in.txt", "r");
    if (fill(f, ptr_m2) != SUCCESS)
        rc++;
    fclose(f);

    f = fopen("./func_tests/data/pos_07_out.txt", "r");
    if (fill(f, ptr_ideal) != SUCCESS)
        rc++;
    fclose(f);

    //ck_assert_int_eq(SUCCESS, rc);

    res.rows = matrix_1.rows, res.columns = matrix_2.columns;
    res.pointer = multiplication(ptr_m1, ptr_m2);
    
    rc = check_matrix(ptr_res, ptr_ideal);

    ck_assert_ptr_nonnull(res.pointer);
    ck_assert_int_eq(SUCCESS, rc);

    free(matrix_1.pointer), free(matrix_2.pointer), free(res.pointer), free(ideal.pointer);  
} 
END_TEST

START_TEST(test_multiplication_size_4_1_1_4)
{
    matrix_t matrix_1, matrix_2, res, ideal;
    ptr_t ptr_m1 = &matrix_1, ptr_m2 = &matrix_2, ptr_res = &res, ptr_ideal = &ideal;
    int rc = 0;
    FILE *f;

    f = fopen("./func_tests/data/pos_08_01_in.txt", "r");
    if (fill(f, ptr_m1) != SUCCESS)
        rc++;
    fclose(f);

    f = fopen("./func_tests/data/pos_08_02_in.txt", "r");
    if (fill(f, ptr_m2) != SUCCESS)
        rc++;
    fclose(f);

    f = fopen("./func_tests/data/pos_08_out.txt", "r");
    if (fill(f, ptr_ideal) != SUCCESS)
        rc++;
    fclose(f);

    //ck_assert_int_eq(SUCCESS, rc);

    res.rows = matrix_1.rows, res.columns = matrix_2.columns;
    res.pointer = multiplication(ptr_m1, ptr_m2);
    
    rc = check_matrix(ptr_res, ptr_ideal);

    ck_assert_ptr_nonnull(res.pointer);
    ck_assert_int_eq(SUCCESS, rc);

    free(matrix_1.pointer), free(matrix_2.pointer), free(res.pointer), free(ideal.pointer);  
} 
END_TEST


START_TEST(test_multiplication_size_3_2_2_3)
{
    matrix_t matrix_1, matrix_2, res, ideal;
    ptr_t ptr_m1 = &matrix_1, ptr_m2 = &matrix_2, ptr_res = &res, ptr_ideal = &ideal;
    int rc = 0;
    FILE *f;

    f = fopen("./func_tests/data/pos_06_01_in.txt", "r");
    if (fill(f, ptr_m1) != SUCCESS)
        rc++;
    fclose(f);

    f = fopen("./func_tests/data/pos_06_02_in.txt", "r");
    if (fill(f, ptr_m2) != SUCCESS)
        rc++;
    fclose(f);

    f = fopen("./func_tests/data/pos_06_out.txt", "r");
    if (fill(f, ptr_ideal) != SUCCESS)
        rc++;
    fclose(f);

    //ck_assert_int_eq(SUCCESS, rc);

    res.rows = matrix_1.rows, res.columns = matrix_2.columns;
    res.pointer = multiplication(ptr_m1, ptr_m2);
    
    rc = check_matrix(ptr_res, ptr_ideal);

    ck_assert_ptr_nonnull(res.pointer);
    ck_assert_int_eq(SUCCESS, rc);

    free(matrix_1.pointer), free(matrix_2.pointer), free(res.pointer), free(ideal.pointer);  
} 
END_TEST

Suite* multiplication_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("multiplication");

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_multiplication_size_1_1);
    tcase_add_test(tc_pos, test_multiplication_size_2_2);
    tcase_add_test(tc_pos, test_multiplication_size_1_4_4_1);
    tcase_add_test(tc_pos, test_multiplication_size_4_1_1_4);
    tcase_add_test(tc_pos, test_multiplication_size_3_2_2_3);

    suite_add_tcase(s, tc_pos);
    return s;
}
