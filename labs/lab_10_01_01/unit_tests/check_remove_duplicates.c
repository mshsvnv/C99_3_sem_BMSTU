#include "../inc/defs.h"
#include "../inc/file_funcs.h"
#include "../inc/node_funcs.h"
#include "../inc/other_funcs.h"
#include "../inc/list_funcs.h"

int compare(node_t *ideal, node_t *head)
{
    int rc = 0;

    for (; head; ideal = ideal->next, head = head->next)
        rc += compare_amino_acid(head->data, ideal->data) + compare_amount(head->data, ideal->data) + compare_triplet(head->data, ideal->data);
    
    return rc;
}

// positives
START_TEST(test_remove_amount_node)
{
    node_t *head = NULL, *res = NULL, *ideal = NULL;
    int rc;

    FILE *f_in = fopen("func_tests/data/pos_17_in.txt", "r");

    rc = fill_list(f_in, &head);

    head = sort(head, compare_amount);
    res = list_copy(head);
    remove_duplicates(&head, compare_amount);
        
    fclose(f_in);

    f_in = fopen("func_tests/data/pos_17_out.txt", "r");

    rc = fill_list(f_in, &ideal);

    rc = compare(ideal, head);

    fclose(f_in);

    list_free(&res, 1);
    list_free(&head, 0);
    list_free(&ideal, 1);

    ck_assert_int_eq(rc, 0);
} 
END_TEST

START_TEST(test_remove_amount_repeats)
{
    node_t *head = NULL, *res = NULL, *ideal = NULL;
    int rc;

    FILE *f_in = fopen("func_tests/data/pos_18_in.txt", "r");

    rc = fill_list(f_in, &head);

    head = sort(head, compare_amount);
    res = list_copy(head);
    remove_duplicates(&head, compare_amount);
        
    fclose(f_in);

    f_in = fopen("func_tests/data/pos_18_out.txt", "r");

    rc = fill_list(f_in, &ideal);

    rc = compare(ideal, head);

    fclose(f_in);

    list_free(&res, 1);
    list_free(&head, 0);
    list_free(&ideal, 1);

    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(test_remove_amount_same_nodes)
{
    node_t *head = NULL, *res = NULL, *ideal = NULL;
    int rc;

    FILE *f_in = fopen("func_tests/data/pos_19_in.txt", "r");

    rc = fill_list(f_in, &head);

    head = sort(head, compare_amount);
    res = list_copy(head);
    remove_duplicates(&head, compare_amount);
        
    fclose(f_in);

    f_in = fopen("func_tests/data/pos_19_out.txt", "r");

    rc = fill_list(f_in, &ideal);

    rc = compare(ideal, head);

    fclose(f_in);

    list_free(&res, 1);
    list_free(&head, 0);
    list_free(&ideal, 1);

    ck_assert_int_eq(rc, 0);
}
END_TEST

Suite* remove_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("remove");

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_remove_amount_node);
    tcase_add_test(tc_pos, test_remove_amount_repeats);
    tcase_add_test(tc_pos, test_remove_amount_same_nodes);

    suite_add_tcase(s, tc_pos);

    return s;
}