#include <check.h>
#include <stdlib.h>
#include "../inc/my_lib.h"

int ideal[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34};

START_TEST(test_one_dig_stat)
{
    int arr[1], num = 1;

    fill_fib(arr, num);

    for (int i = 0; i < num; i++)
        ck_assert_int_eq(arr[i], ideal[i]);
} 
END_TEST

START_TEST(test_one_dig_dym)
{
    int num = 1;
    int *arr = malloc(sizeof(int) * num);

    fill_fib(arr, num);

    for (int i = 0; i < num; i++)
        ck_assert_int_eq(arr[i], ideal[i]);

    free(arr);
} 
END_TEST

START_TEST(test_five_dig_stat)
{
    int arr[5], num = 5;

    fill_fib(arr, num);

    for (int i = 0; i < num; i++)
        ck_assert_int_eq(arr[i], ideal[i]);
} 
END_TEST

START_TEST(test_five_dig_dym)
{
    int num = 5;
    int *arr = malloc(sizeof(int) * num);

    fill_fib(arr, num);

    for (int i = 0; i < num; i++)
        ck_assert_int_eq(arr[i], ideal[i]);

    free(arr);
} 
END_TEST

START_TEST(test_ten_dig_stat)
{
    int arr[10], num = 10;

    fill_fib(arr, num);

    for (int i = 0; i < num; i++)
        ck_assert_int_eq(arr[i], ideal[i]);
} 
END_TEST

START_TEST(test_ten_dig_dym)
{
    int num = 10;
    int *arr = malloc(sizeof(int) * num);

    fill_fib(arr, num);

    for (int i = 0; i < num; i++)
        ck_assert_int_eq(arr[i], ideal[i]);

    free(arr);
} 
END_TEST

Suite* fill_fib_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("fill_fib");

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_one_dig_stat);
    tcase_add_test(tc_pos, test_one_dig_dym);

    tcase_add_test(tc_pos, test_five_dig_stat);
    tcase_add_test(tc_pos, test_five_dig_dym);

    tcase_add_test(tc_pos, test_ten_dig_stat);
    tcase_add_test(tc_pos, test_ten_dig_dym);

    suite_add_tcase(s, tc_pos);

    return s;
}