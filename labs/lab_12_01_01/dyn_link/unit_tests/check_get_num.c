#include <check.h>
#include "../inc/my_lib.h"

//-------------------------------positives-------------------------------//
START_TEST(test_get_num_pos_file_few_ints)
{
    FILE *f = fopen("func_tests/data/pos_01_in.txt", "r");
    size_t num = 0;
    int rc;
    
    rc = get_num(f, &num);
    ck_assert_int_eq(rc, SUCCESS);
    ck_assert_int_eq(num, 11);

    fclose(f);
} 
END_TEST

START_TEST(test_get_num_pos_file_one_int)
{
    FILE *f = fopen("func_tests/data/pos_08_in.txt", "r");
    size_t num = 0;
    int rc;
    
    rc = get_num(f, &num);
    ck_assert_int_eq(rc, SUCCESS);
    ck_assert_int_eq(num, 1);

    fclose(f);
} 
END_TEST

//-------------------------------negatives-------------------------------//
START_TEST(test_get_num_neg_file_chars)
{
    FILE *f = fopen("func_tests/data/neg_06_in.txt", "r");
    size_t num = 0;
    int rc;
    
    rc = get_num(f, &num);
    ck_assert_int_eq(rc, INCORR_DATA_ERR);

    fclose(f);
} 
END_TEST

START_TEST(test_get_num_neg_file_doubles)
{
    FILE *f = fopen("func_tests/data/neg_10_in.txt", "r");
    size_t num = 0;
    int rc;
    
    rc = get_num(f, &num);
    ck_assert_int_eq(rc, INCORR_DATA_ERR);
    fclose(f);
} 
END_TEST

Suite* get_num_suite(void)
{
    Suite *s;
    TCase *tc_pos, *tc_neg;

    s = suite_create("get_num");

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_get_num_pos_file_few_ints);
    tcase_add_test(tc_pos, test_get_num_pos_file_one_int);

    suite_add_tcase(s, tc_pos);

    tc_neg = tcase_create("negatives");

    tcase_add_test(tc_neg, test_get_num_neg_file_chars);
    tcase_add_test(tc_neg, test_get_num_neg_file_doubles);

    suite_add_tcase(s, tc_neg);

    return s;
}