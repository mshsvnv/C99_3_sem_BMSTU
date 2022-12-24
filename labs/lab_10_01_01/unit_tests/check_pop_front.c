#include "../inc/defs.h"
#include "../inc/file_funcs.h"
#include "../inc/node_funcs.h"
#include "../inc/other_funcs.h"
#include "../inc/list_funcs.h"

// positives
START_TEST(test_pop_front_node)
{
    node_t *head = NULL;
    int rc;

    code_t value = {"Valine", "GUU", 10};
    void *p_value = &value, *res;

    FILE *f_in = fopen("func_tests/data/pos_01_in.txt", "r");

    rc = fill_list(f_in, &head);

    res = pop_front(&head);

    rc = compare_amino_acid(p_value, res) + compare_amount(p_value, res) + compare_triplet(p_value, res);
    
    fclose(f_in);
    list_free(&head, 1);

    clean_data(&res);
    free(res);

    ck_assert_int_eq(rc, 0);
} 
END_TEST

START_TEST(test_pop_front_nodes)
{
    node_t *head = NULL;
    int rc;

    code_t value = {"Valine", "GUU", 10};
    void *p_value = &value, *res;

    FILE *f_in = fopen("func_tests/data/pos_02_in.txt", "r");

    rc = fill_list(f_in, &head);

    res = pop_front(&head);

    rc = compare_amino_acid(p_value, res) + compare_amount(p_value, res) + compare_triplet(p_value, res);
    
    fclose(f_in);
    list_free(&head, 1);

    clean_data(&res);
    free(res);

    ck_assert_int_eq(rc, 0);
} 
END_TEST

// negatives
START_TEST(test_pop_front_head_null)
{
    node_t *res = NULL;

    res = pop_front(NULL);
    
    ck_assert_ptr_null(res);
} 
END_TEST


Suite* pop_front_suite(void)
{
    Suite *s;
    TCase *tc_pos, *tc_neg;

    s = suite_create("pop_front");

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_pop_front_node);
    tcase_add_test(tc_pos, test_pop_front_nodes);

    tc_neg = tcase_create("negatives");

    tcase_add_test(tc_neg, test_pop_front_head_null);

    suite_add_tcase(s, tc_pos);
    suite_add_tcase(s, tc_neg);

    return s;
}