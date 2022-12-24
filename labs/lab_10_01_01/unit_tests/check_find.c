#include "../inc/defs.h"
#include "../inc/file_funcs.h"
#include "../inc/node_funcs.h"
#include "../inc/other_funcs.h"
#include "../inc/list_funcs.h"

// positives
START_TEST(test_find_amino_acid)
{
    node_t *head = NULL, *res = NULL;
    int rc;

    code_t value = {"Valine", "AAG", 3};
    void *p_value = &value;

    FILE *f_in = fopen("func_tests/data/pos_04_in.txt", "r");

    rc = fill_list(f_in, &head);

    res = find(head, p_value, compare_amino_acid);

    fclose(f_in);

    rc = compare_amino_acid(p_value, res->data);
    list_free(&head, 1);

    ck_assert_int_eq(rc, 0);
} 
END_TEST

START_TEST(test_find_triplet)
{
    node_t *head = NULL, *res = NULL;
    int rc;

    code_t value = {"Valine", "AAA", 3};
    void *p_value = &value;

    FILE *f_in = fopen("func_tests/data/pos_04_in.txt", "r");

    rc = fill_list(f_in, &head);

    res = find(head, p_value, compare_triplet);

    fclose(f_in);

    rc = compare_triplet(p_value, res->data);
    list_free(&head, 1);

    ck_assert_int_eq(rc, 0);
} 
END_TEST

START_TEST(test_find_amount)
{
    node_t *head = NULL, *res = NULL;
    int rc;

    code_t value = {"Valine", "AAG", 10};
    void *p_value = &value;

    FILE *f_in = fopen("func_tests/data/pos_08_in.txt", "r");

    rc = fill_list(f_in, &head);

    res = find(head, p_value, compare_amount);

    fclose(f_in);

    rc = compare_amount(p_value, res->data);
    list_free(&head, 1);

    ck_assert_int_eq(rc, 0);
} 
END_TEST

// negatives
START_TEST(test_find_head_null)
{
    node_t *res = NULL;

    int value = 10;
    void *p_value = &value;

    res = find(NULL, p_value, compare_amount);

    ck_assert_ptr_null(res);
} 
END_TEST

START_TEST(test_find_data_null)
{
    node_t *head = NULL, *res = NULL;
    int rc;

    FILE *f_in = fopen("func_tests/data/pos_04_in.txt", "r");

    rc = fill_list(f_in, &head);

    if (rc)
        ck_assert_int_eq(rc, 0);

    res = find(head, NULL, compare_amount);

    fclose(f_in);
    list_free(&head, 1);

    ck_assert_ptr_null(res);
} 
END_TEST

START_TEST(test_find_no_data)
{
    node_t *head = NULL, *res = NULL;
    int rc;

    code_t value = {"Valine", "AAG", -1};
    void *p_value = &value;

    FILE *f_in = fopen("func_tests/data/pos_04_in.txt", "r");

    rc = fill_list(f_in, &head);

    if (rc)
        ck_assert_int_eq(rc, 0);

    res = find(head, p_value, compare_amount);

    fclose(f_in);
    list_free(&head, 1);

    ck_assert_ptr_null(res);
} 
END_TEST

Suite* find_suite(void)
{
    Suite *s;
    TCase *tc_pos, *tc_neg;

    s = suite_create("find");

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_find_amino_acid);
    tcase_add_test(tc_pos, test_find_amount);
    tcase_add_test(tc_pos, test_find_triplet);

    tc_neg = tcase_create("negatives");

    tcase_add_test(tc_neg, test_find_data_null);
    tcase_add_test(tc_neg, test_find_head_null);
    tcase_add_test(tc_neg, test_find_no_data);

    suite_add_tcase(s, tc_pos);
    suite_add_tcase(s, tc_neg);

    return s;
}