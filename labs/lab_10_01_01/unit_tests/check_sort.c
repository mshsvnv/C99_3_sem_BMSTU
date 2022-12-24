#include "../inc/defs.h"
#include "../inc/file_funcs.h"
#include "../inc/node_funcs.h"
#include "../inc/other_funcs.h"
#include "../inc/list_funcs.h"

// positives
START_TEST(test_sort_amount_ascending)
{
    node_t *head = NULL, *ideal = NULL;
    int rc;

    FILE *f_in = fopen("func_tests/data/pos_09_in.txt", "r");

    rc = fill_list(f_in, &head);
    head = sort(head, compare_amount);
        
    fclose(f_in);

    f_in = fopen("func_tests/data/pos_09_out.txt", "r");

    rc = fill_list(f_in, &ideal);
    ideal = sort(ideal, compare_amount);

    fclose(f_in);

    rc = compare(ideal, head);

    list_free(&head, 1);
    list_free(&ideal, 1);

    ck_assert_int_eq(rc, 0);
} 
END_TEST

START_TEST(test_sort_amount_descending)
{
    node_t *head = NULL, *ideal = NULL;
    int rc;

    FILE *f_in = fopen("func_tests/data/pos_10_in.txt", "r");

    rc = fill_list(f_in, &head);
    head = sort(head, compare_amount);
        
    fclose(f_in);

    f_in = fopen("func_tests/data/pos_10_out.txt", "r");

    rc = fill_list(f_in, &ideal);

    fclose(f_in);

    rc = compare(ideal, head);

    list_free(&head, 1);
    list_free(&ideal, 1);

    ck_assert_int_eq(rc, 0);
} 
END_TEST

START_TEST(test_sort_amount_not_sorted)
{
    node_t *head = NULL, *ideal = NULL;
    int rc;

    FILE *f_in = fopen("func_tests/data/pos_11_in.txt", "r");

    rc = fill_list(f_in, &head);
    head = sort(head, compare_amount);
        
    fclose(f_in);

    f_in = fopen("func_tests/data/pos_11_out.txt", "r");

    rc = fill_list(f_in, &ideal);

    fclose(f_in);

    rc = compare(ideal, head);

    list_free(&head, 1);
    list_free(&ideal, 1);

    ck_assert_int_eq(rc, 0);
} 
END_TEST

START_TEST(test_sort_amount_one_node)
{
    node_t *head = NULL, *ideal = NULL;
    int rc;

    FILE *f_in = fopen("func_tests/data/pos_12_in.txt", "r");

    rc = fill_list(f_in, &head);
    head = sort(head, compare_amount);
        
    fclose(f_in);

    f_in = fopen("func_tests/data/pos_12_out.txt", "r");

    rc = fill_list(f_in, &ideal);

    fclose(f_in);

    rc = compare(ideal, head);

    list_free(&head, 1);
    list_free(&ideal, 1);

    ck_assert_int_eq(rc, 0);
} 
END_TEST

START_TEST(test_sort_head_null)
{
    node_t *head = NULL;

    head = sort(NULL, compare_amount);

    ck_assert_ptr_null(head);
} 
END_TEST

Suite* sort_suite(void)
{
    Suite *s;
    TCase *tc_pos, *tc_neg;

    s = suite_create("sort");

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_sort_amount_ascending);
    tcase_add_test(tc_pos, test_sort_amount_descending);
    tcase_add_test(tc_pos, test_sort_amount_not_sorted);
    tcase_add_test(tc_pos, test_sort_amount_one_node);

    tc_neg = tcase_create("negatives");

    tcase_add_test(tc_neg, test_sort_head_null);

    suite_add_tcase(s, tc_pos);
    suite_add_tcase(s, tc_neg);

    return s;
}