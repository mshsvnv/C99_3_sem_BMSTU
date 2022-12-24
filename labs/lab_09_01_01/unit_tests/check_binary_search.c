#include <check.h>

#include "../inc/defs.h"
#include "../inc/films_array_funcs.h"
#include "../inc/essential_funcs.h"

//-------------------------------positives-------------------------------//
START_TEST(test_binary_search_no_year)
{
    FILE *f_in;
    films_array_t films_array;
    int rc, index;
    char *key = "1980";

    f_in = fopen("./func_tests/data/pos_06_in.txt", "r");

    init_films_array(&films_array, YEAR);

    rc = fill_films_array(f_in, &films_array);

    rc = binary_search(&films_array, key, &index);

    ck_assert_int_eq(index, -1);
    ck_assert_int_eq(rc, NOT_FOUND);

    free_films_array(&films_array);
    fclose(f_in);
} 
END_TEST

START_TEST(test_binary_search_no_title)
{
    FILE *f_in;
    films_array_t films_array;
    int rc, index;
    char *key = "Titanic";

    f_in = fopen("./func_tests/data/pos_07_in.txt", "r");

    init_films_array(&films_array, TITLE);

    rc = fill_films_array(f_in, &films_array);

    rc = binary_search(&films_array, key, &index);

    ck_assert_int_eq(index, -1);
    ck_assert_int_eq(rc, NOT_FOUND);

    free_films_array(&films_array);
    fclose(f_in);
} 
END_TEST

START_TEST(test_binary_search_no_name)
{
    FILE *f_in;
    films_array_t films_array;
    int rc, index;
    char *key = "Steven Spielberg";

    f_in = fopen("./func_tests/data/pos_08_in.txt", "r");

    init_films_array(&films_array, NAME);

    rc = fill_films_array(f_in, &films_array);

    rc = binary_search(&films_array, key, &index);

    ck_assert_int_eq(index, -1);
    ck_assert_int_eq(rc, NOT_FOUND);

    free_films_array(&films_array);
    fclose(f_in);
} 
END_TEST

START_TEST(test_binary_search_yes_year)
{
    FILE *f_in;
    films_array_t films_array;
    int rc, index;
    char *key = "1949";

    f_in = fopen("./func_tests/data/pos_09_in.txt", "r");

    init_films_array(&films_array, YEAR);

    rc = fill_films_array(f_in, &films_array);

    rc = binary_search(&films_array, key, &index);

    ck_assert_int_eq(index, 3);
    ck_assert_int_eq(rc, SUCCESS);

    free_films_array(&films_array);
    fclose(f_in);
} 
END_TEST

START_TEST(test_binary_search_yes_title)
{
    FILE *f_in;
    films_array_t films_array;
    int rc, index;
    char *key = "The Third Man";

    f_in = fopen("./func_tests/data/pos_10_in.txt", "r");

    init_films_array(&films_array, TITLE);

    rc = fill_films_array(f_in, &films_array);

    rc = binary_search(&films_array, key, &index);

    ck_assert_int_eq(index, 5);
    ck_assert_int_eq(rc, SUCCESS);

    free_films_array(&films_array);
    fclose(f_in);
} 
END_TEST

START_TEST(test_binary_search_yes_name)
{
    FILE *f_in;
    films_array_t films_array;
    int rc, index;
    char *key = "David Lean";

    f_in = fopen("./func_tests/data/pos_11_in.txt", "r");

    init_films_array(&films_array, NAME);

    rc = fill_films_array(f_in, &films_array);

    rc = binary_search(&films_array, key, &index);

    ck_assert_int_eq(index, 2);
    ck_assert_int_eq(rc, SUCCESS);

    free_films_array(&films_array);
    fclose(f_in);
} 
END_TEST

Suite* binary_search_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("binary_search");

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_binary_search_no_year);
    tcase_add_test(tc_pos, test_binary_search_no_name);
    tcase_add_test(tc_pos, test_binary_search_no_title);
    tcase_add_test(tc_pos, test_binary_search_yes_year);
    tcase_add_test(tc_pos, test_binary_search_yes_name);
    tcase_add_test(tc_pos, test_binary_search_yes_title);
    
    suite_add_tcase(s, tc_pos);

    return s;
}

