#include <check.h>
#include <stdlib.h>
#include "../inc/my_lib.h"

START_TEST(test_one_elem)
{
    int ideal[] = {1};
    int src[] = {1}, src_len = 1;
    int dst[6], dst_len = 0;
    
    filter(src, src_len, dst, &dst_len, 1);

    for (int i = 0; i < dst_len; i++)
        ck_assert_int_eq(dst[i], ideal[i]);
} 
END_TEST

START_TEST(test_all_dif)
{
    int ideal[] = {1, 2, 3, 4, 5, 6};
    int src[] = {1, 2, 3, 4, 5, 6}, src_len = 6;
    int dst[6], dst_len = 0;
    
    filter(src, src_len, dst, &dst_len, 1);

    for (int i = 0; i < dst_len; i++)
        ck_assert_int_eq(dst[i], ideal[i]);
} 
END_TEST

START_TEST(test_all_same)
{
    int ideal[] = {1};
    int src[] = {1, 1, 1, 1, 1, 1}, src_len = 6;
    int dst[6], dst_len = 0;
    
    filter(src, src_len, dst, &dst_len, 1);

    for (int i = 0; i < dst_len; i++)
        ck_assert_int_eq(dst[i], ideal[i]);
} 
END_TEST

START_TEST(test_both)
{
    int ideal[] = {1, -2, -21, 11};
    int src[] = {1, -2, 1, -21, 1, 11}, src_len = 6;
    int dst[6], dst_len = 0;
    
    filter(src, src_len, dst, &dst_len, 1);

    for (int i = 0; i < dst_len; i++)
        ck_assert_int_eq(dst[i], ideal[i]);
} 
END_TEST

Suite* filter_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("filter");

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_one_elem);
    tcase_add_test(tc_pos, test_all_dif);
    tcase_add_test(tc_pos, test_all_same);
    tcase_add_test(tc_pos, test_both);

    suite_add_tcase(s, tc_pos);

    return s;
}