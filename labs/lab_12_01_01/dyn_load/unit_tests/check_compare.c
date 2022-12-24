#include <check.h>
#include <dlfcn.h>
#include "../inc/defs.h"

typedef int (*fn_compare_t) (const void *, const void *);

//-------------------------------positives-------------------------------//
START_TEST(test_compare_pos_digs)
{
    void *hlib;
    hlib = dlopen("out/my_lib.so", RTLD_NOW);

    fn_compare_t compare = (fn_compare_t)dlsym(hlib, "compare");

    int a = 10, b = 20;
    int rc;

    rc = compare(&a, &b);
    dlclose(hlib);

    ck_assert_int_eq(rc, -1);
} 
END_TEST

START_TEST(test_compare_equal_digs)
{
    void *hlib;
    hlib = dlopen("out/my_lib.so", RTLD_NOW);

    fn_compare_t compare = (fn_compare_t)dlsym(hlib, "compare");

    int a = 10, b = 10;
    int rc;

    rc = compare(&a, &b);
    dlclose(hlib);

    ck_assert_int_eq(rc, 0);
} 
END_TEST

START_TEST(test_compare_symb)
{
    void *hlib;
    hlib = dlopen("out/my_lib.so", RTLD_NOW);

    fn_compare_t compare = (fn_compare_t)dlsym(hlib, "compare");

    char a = 'a', b = 'b';
    int rc;

    rc = compare(&a, &b);
    dlclose(hlib);

    ck_assert_int_eq(rc, -1);
} 
END_TEST

START_TEST(test_compare_symb_and_dig)
{
    void *hlib;
    hlib = dlopen("out/my_lib.so", RTLD_NOW);

    fn_compare_t compare = (fn_compare_t)dlsym(hlib, "compare");

    char a = 'a';
    int b = 1;
    int rc;

    rc = compare(&a, &b);
    dlclose(hlib);

    ck_assert_int_eq(rc, 1);
} 
END_TEST

Suite* compare_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("compare");

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_compare_pos_digs);
    tcase_add_test(tc_pos, test_compare_equal_digs);
    tcase_add_test(tc_pos, test_compare_symb);
    tcase_add_test(tc_pos, test_compare_symb_and_dig);

    suite_add_tcase(s, tc_pos);

    return s;
}
