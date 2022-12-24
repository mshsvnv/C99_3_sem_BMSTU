#include "../inc/defs.h"
#include "../inc/node_funcs.h"
#include "../inc/math_funcs.h"

START_TEST(test_multiplication_1)
{
    node_t *head_1 = NULL, *head_2 = NULL, *res = NULL;
    int num_1, num_2, tmp;

    num_1 = 1;
    head_1 = list_make(head_1, &num_1);

    num_2 = 124;
    head_2 = list_make(head_2, &num_2);

    res = multiplication(res, head_1, head_2);

    tmp = take_int(res);

    node_free(head_1);
    node_free(head_2);
    node_free(res);

    ck_assert_int_eq(num_1 * num_2, tmp);
} 
END_TEST

START_TEST(test_multiplication_2_prime)
{
    node_t *head_1 = NULL, *head_2 = NULL, *res = NULL;
    int num_1, num_2, tmp;

    num_1 = 5;
    head_1 = list_make(head_1, &num_1);

    num_2 = 7;
    head_2 = list_make(head_2, &num_2);

    res = multiplication(res, head_1, head_2);

    tmp = take_int(res);

    node_free(head_1);
    node_free(head_2);
    node_free(res);

    ck_assert_int_eq(num_1 * num_2, tmp);
} 
END_TEST

Suite* multiplication_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("multiplication");

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_multiplication_1);
    tcase_add_test(tc_pos, test_multiplication_2_prime);

    suite_add_tcase(s, tc_pos);

    return s;
}