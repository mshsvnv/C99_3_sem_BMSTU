#include "../inc/defs.h"
#include "../inc/node_funcs.h"
#include "../inc/math_funcs.h"

START_TEST(test_to_square_no_prime)
{
    node_t *head = NULL, *res = NULL;
    int num, tmp;

    num = 124;

    head = list_make(head, &num);

    res = to_square(res, head);

    tmp = take_int(res);

    node_free(head);
    node_free(res);

    ck_assert_int_eq(num * num, tmp);
} 
END_TEST

START_TEST(test_to_square_prime)
{
    node_t *head = NULL, *res = NULL;
    int num, tmp;

    num = 11;

    head = list_make(head, &num);

    res = to_square(res, head);

    tmp = take_int(res);

    node_free(head);
    node_free(res);

    ck_assert_int_eq(num * num, tmp);
} 
END_TEST

Suite* to_square_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("to_square");

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_to_square_no_prime);
    tcase_add_test(tc_pos, test_to_square_prime);

    suite_add_tcase(s, tc_pos);

    return s;
}