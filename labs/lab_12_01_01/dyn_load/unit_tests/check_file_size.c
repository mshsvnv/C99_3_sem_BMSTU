#include <check.h>
#include <dlfcn.h>
#include "../inc/defs.h"

typedef long (*fn_check_file_size_t) (FILE *);

//-------------------------------positives-------------------------------//
START_TEST(test_size_empty_file)
{
    void *hlib;
    hlib = dlopen("out/my_lib.so", RTLD_NOW);

    fn_check_file_size_t check_file_size = (fn_check_file_size_t)dlsym(hlib, "check_file_size");

    FILE *f = fopen("func_tests/data/neg_04_in.txt", "r");

    long size = check_file_size(f);
    dlclose(hlib);

    ck_assert_int_eq(size, 0);

    fclose(f);
} 
END_TEST

START_TEST(test_size_not_empty_file)
{
    void *hlib;
    hlib = dlopen("out/my_lib.so", RTLD_NOW);

    fn_check_file_size_t check_file_size = (fn_check_file_size_t)dlsym(hlib, "check_file_size");

    FILE *f = fopen("func_tests/data/pos_01_in.txt", "r");

    long size = check_file_size(f);
    dlclose(hlib);

    ck_assert_int_eq(size,27);

    fclose(f);
} 
END_TEST

Suite* file_size_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("file_size");

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_size_empty_file);
    tcase_add_test(tc_pos, test_size_not_empty_file);

    suite_add_tcase(s, tc_pos);

    return s;
}