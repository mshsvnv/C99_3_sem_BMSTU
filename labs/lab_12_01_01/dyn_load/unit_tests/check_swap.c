#include <check.h>
#include <dlfcn.h>
#include "../inc/defs.h"

typedef int (*fn_swap_t) (char *, char *, size_t);

//-------------------------------positives-------------------------------//
START_TEST(test_swap_two_ints_1)
{
    void *hlib;
    hlib = dlopen("out/my_lib.so", RTLD_NOW);

    fn_swap_t swap = (fn_swap_t)dlsym(hlib, "swap");

    int a = 10, b = 20;
    void *p_a = &a, *p_b = &b;

    swap((char *)p_a, (char *)p_b, sizeof(int));
    dlclose(hlib);

    ck_assert_int_eq(a, 20);
    ck_assert_int_eq(b, 10);
} 
END_TEST

START_TEST(test_swap_two_ints_2)
{
    void *hlib;
    hlib = dlopen("out/my_lib.so", RTLD_NOW);

    fn_swap_t swap = (fn_swap_t)dlsym(hlib, "swap");

    int a = -10, b = -20;
    void *p_a = &a, *p_b = &b;

    swap((char *)p_a, (char *)p_b, sizeof(int));
    dlclose(hlib);

    ck_assert_int_eq(a, -20);
    ck_assert_int_eq(b, -10);
} 
END_TEST

START_TEST(test_swap_two_chars)
{
    void *hlib;
    hlib = dlopen("out/my_lib.so", RTLD_NOW);

    fn_swap_t swap = (fn_swap_t)dlsym(hlib, "swap");

    char a = 'a', b = 'b';

    swap(&a, &b, sizeof(char));
    ck_assert_int_eq(a, 'b');
    ck_assert_int_eq(b, 'a');
} 
END_TEST

START_TEST(test_swap_two_doubles)
{
    void *hlib;
    hlib = dlopen("out/my_lib.so", RTLD_NOW);

    fn_swap_t swap = (fn_swap_t)dlsym(hlib, "swap");

    double a = -1.0, b = -55.0;
    void *p_a = &a, *p_b = &b;

    swap((char *)p_a, (char *)p_b, sizeof(double));
    dlclose(hlib);

    ck_assert_double_eq(a, -55.0);
    ck_assert_double_eq(b, -1.0);
} 
END_TEST

Suite* swap_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("swap");

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_swap_two_ints_1);
    tcase_add_test(tc_pos, test_swap_two_ints_2);
    tcase_add_test(tc_pos, test_swap_two_chars);
    tcase_add_test(tc_pos, test_swap_two_doubles);

    suite_add_tcase(s, tc_pos);

    return s;
}
