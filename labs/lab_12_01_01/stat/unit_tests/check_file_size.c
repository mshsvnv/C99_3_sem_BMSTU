#include <check.h>
#include "../inc/my_lib.h"

//-------------------------------positives-------------------------------//
START_TEST(test_size_empty_file)
{
    FILE *f = fopen("func_tests/data/neg_04_in.txt", "r");

    long size = check_file_size(f);
    ck_assert_int_eq(size, 0);

    fclose(f);
} 
END_TEST

START_TEST(test_size_not_empty_file)
{
    FILE *f = fopen("func_tests/data/pos_01_in.txt", "r");

    long size = check_file_size(f);
    ck_assert_int_eq(size,27);

    fclose(f);
} 
END_TEST

Suite* file_size_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("file_size");

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_size_empty_file);
    tcase_add_test(tc_pos, test_size_not_empty_file);

    suite_add_tcase(s, tc_pos);

    return s;
}