#include <check.h>

#include "../inc/defs.h"
#include "../inc/films_array_funcs.h"
#include "../inc/file_funcs.h"

int compare(films_array_t *p1, films_array_t *p2)
{
    int i = 0;

    for (; i < p1->len; i++)
    {
        if (p1->pointer[i].year != p2->pointer[i].year)
            return ERR_MEMORY;

        if (strcmp(p1->pointer[i].name, p2->pointer[i].name) != 0)
            return ERR_MEMORY;

        if (strcmp(p1->pointer[i].title, p2->pointer[i].title) != 0)
            return ERR_MEMORY;
    }

    return SUCCESS;
}

//-------------------------------positives-------------------------------//
START_TEST(test_sort_no_year)
{
    FILE *f_in, *f_res;
    films_array_t films_array, films_array_res;
    int rc;

    f_in = fopen("./func_tests/data/pos_01_in.txt", "r");

    init_films_array(&films_array, YEAR);

    rc = fill_films_array(f_in, &films_array);

    f_res = fopen("./func_tests/data/pos_01_out.txt", "r");

    init_films_array(&films_array_res, YEAR);

    rc = fill_films_array(f_res, &films_array_res);

    rc = compare(&films_array, &films_array_res);

    ck_assert_int_eq(rc, SUCCESS);

    free_films_array(&films_array);
    fclose(f_in);

    free_films_array(&films_array_res);
    fclose(f_res);
} 
END_TEST

START_TEST(test_sort_yes_year)
{
    FILE *f_in, *f_res;
    films_array_t films_array, films_array_res;
    int rc;

    f_in = fopen("./func_tests/data/pos_02_in.txt", "r");

    init_films_array(&films_array, YEAR);

    rc = fill_films_array(f_in, &films_array);

    f_res = fopen("./func_tests/data/pos_02_out.txt", "r");

    init_films_array(&films_array_res, YEAR);

    rc = fill_films_array(f_res, &films_array_res);

    rc = compare(&films_array, &films_array_res);

    ck_assert_int_eq(rc, SUCCESS);

    free_films_array(&films_array);
    fclose(f_in);

    free_films_array(&films_array_res);
    fclose(f_res);
} 
END_TEST

START_TEST(test_sort_same_films)
{
    FILE *f_in, *f_res;
    films_array_t films_array, films_array_res;
    int rc;

    f_in = fopen("./func_tests/data/pos_04_in.txt", "r");

    init_films_array(&films_array, YEAR);

    rc = fill_films_array(f_in, &films_array);

    f_res = fopen("./func_tests/data/pos_04_out.txt", "r");

    init_films_array(&films_array_res, YEAR);

    rc = fill_films_array(f_res, &films_array_res);

    rc = compare(&films_array, &films_array_res);

    ck_assert_int_eq(rc, SUCCESS);

    free_films_array(&films_array);
    fclose(f_in);

    free_films_array(&films_array_res);
    fclose(f_res);
} 
END_TEST

START_TEST(test_sort_one_film)
{
    FILE *f_in, *f_res;
    films_array_t films_array, films_array_res;
    int rc;

    f_in = fopen("./func_tests/data/pos_05_in.txt", "r");

    init_films_array(&films_array, YEAR);

    rc = fill_films_array(f_in, &films_array);

    f_res = fopen("./func_tests/data/pos_05_out.txt", "r");

    init_films_array(&films_array_res, YEAR);

    rc = fill_films_array(f_res, &films_array_res);

    rc = compare(&films_array, &films_array_res);

    ck_assert_int_eq(rc, SUCCESS);

    free_films_array(&films_array);
    fclose(f_in);

    free_films_array(&films_array_res);
    fclose(f_res);
} 
END_TEST

Suite* sort_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("sort");

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_sort_no_year);
    tcase_add_test(tc_pos, test_sort_yes_year);
    tcase_add_test(tc_pos, test_sort_same_films);
    tcase_add_test(tc_pos, test_sort_one_film);
    
    suite_add_tcase(s, tc_pos);

    return s;
}