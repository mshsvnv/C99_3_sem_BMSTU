#include "../inc/defs.h"
#include "../inc/node_funcs.h"
#include "../inc/math_funcs.h"

START_TEST(test_division_1)
{
    node_t *head_1 = NULL, *head_2 = NULL, *res = NULL;
    int num_1, num_2, tmp;

    num_1 = 124;
    head_1 = list_make(head_1, &num_1);

    num_2 = 1;
    head_2 = list_make(head_2, &num_2);

    res = division(res, head_1, head_2);

    tmp = take_int(res);

    node_free(head_1);
    node_free(head_2);
    node_free(res);

    ck_assert_int_eq(num_1 / num_2, tmp);
} 
END_TEST

START_TEST(test_division_2_prime)
{
    node_t *head_1 = NULL, *head_2 = NULL, *res = NULL;
    int num_1, num_2, tmp;

    num_1 = 77;
    head_1 = list_make(head_1, &num_1);

    num_2 = 7;
    head_2 = list_make(head_2, &num_2);

    res = division(res, head_1, head_2);

    tmp = take_int(res);

    node_free(head_1);
    node_free(head_2);
    node_free(res);

    ck_assert_int_eq(num_1 / num_2, tmp);
} 
END_TEST

Suite* division_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("division");

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_division_1);
    tcase_add_test(tc_pos, test_division_2_prime);

    suite_add_tcase(s, tc_pos);

    return s;
}