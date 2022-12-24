#include "../inc/defs.h"
#include "../inc/node_funcs.h"
#include "../inc/math_funcs.h"

int take_int(node_t *head)
{
    int i = 2, tmp = 1, t;

    for (; head; head = head->next)
    {
        t = 1;

        while (t)
        {
            if (! is_prime(&i))
            {
                t = 0;
                tmp = tmp * (int)pow(i, head->amount);
            }
            i++;
        }

    }

    return tmp;
}

START_TEST(test_list_create_no_prime)
{
    node_t *head = NULL;
    int num, tmp;

    num = 124;

    head = list_make(head, &num);

    tmp = take_int(head);

    node_free(head);

    ck_assert_int_eq(num, tmp);

} 
END_TEST

START_TEST(test_list_create_prime)
{
    node_t *head = NULL;
    int num, tmp;

    num = 107;

    head = list_make(head, &num);

    tmp = take_int(head);

    node_free(head);

    ck_assert_int_eq(num, tmp);
} 
END_TEST

Suite* list_create_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("list_create");

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_list_create_no_prime);
    tcase_add_test(tc_pos, test_list_create_prime);

    suite_add_tcase(s, tc_pos);

    return s;
}