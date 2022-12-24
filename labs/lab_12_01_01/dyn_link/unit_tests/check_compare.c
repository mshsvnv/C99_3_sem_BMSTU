#include <check.h>
#include "../inc/my_lib.h"

//-------------------------------positives-------------------------------//
START_TEST(test_compare_pos_digs)
{
    int a = 10, b = 20;
    int rc;

    rc = compare(&a, &b);
    ck_assert_int_eq(rc, -1);
} 
END_TEST

START_TEST(test_compare_equal_digs)
{
    int a = 10, b = 10;
    int rc;

    rc = compare(&a, &b);
    ck_assert_int_eq(rc, 0);
} 
END_TEST

START_TEST(test_compare_symb)
{
    char a = 'a', b = 'b';
    int rc;

    rc = compare(&a, &b);
    ck_assert_int_eq(rc, -1);
} 
END_TEST

START_TEST(test_compare_symb_and_dig)
{
    char a = 'a';
    int b = 1;
    int rc;

    rc = compare(&a, &b);
    ck_assert_int_eq(rc, 1);
} 
END_TEST

Suite* compare_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("compare");

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_compare_pos_digs);
    tcase_add_test(tc_pos, test_compare_equal_digs);
    tcase_add_test(tc_pos, test_compare_symb);
    tcase_add_test(tc_pos, test_compare_symb_and_dig);

    suite_add_tcase(s, tc_pos);

    return s;
}
