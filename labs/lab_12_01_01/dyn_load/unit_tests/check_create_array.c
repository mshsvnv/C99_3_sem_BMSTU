#include <check.h>
#include <dlfcn.h>
#include "../inc/defs.h"

typedef int (*fn_create_array_t) (FILE *, int **, int **, size_t *);

//-------------------------------positives-------------------------------//
START_TEST(test_create_array_pos_file_few_ints)
{
    void *hlib;
    hlib = dlopen("out/my_lib.so", RTLD_NOW);

    fn_create_array_t create_array = (fn_create_array_t)dlsym(hlib, "create_array");

    FILE *f = fopen("func_tests/data/pos_01_in.txt", "r");
    int *arr_pb = NULL, *arr_pe = NULL, rc;
    size_t num = 11;
    
    rc = create_array(f, &arr_pb, &arr_pe, &num);
    dlclose(hlib);

    ck_assert_int_eq(rc, SUCCESS);

    free(arr_pb);
    fclose(f);
} 
END_TEST

START_TEST(test_create_array_pos_file_one_int)
{
    void *hlib;
    hlib = dlopen("out/my_lib.so", RTLD_NOW);

    fn_create_array_t create_array = (fn_create_array_t)dlsym(hlib, "create_array");
    
    FILE *f = fopen("func_tests/data/pos_08_in.txt", "r");
    int *arr_pb = NULL, *arr_pe = NULL, rc;
    size_t num = 1;
    
    rc = create_array(f, &arr_pb, &arr_pe, &num);
    dlclose(hlib);

    ck_assert_int_eq(rc, SUCCESS);

    free(arr_pb);
    fclose(f);
} 
END_TEST

Suite* create_array_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("create_array");

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_create_array_pos_file_few_ints);
    tcase_add_test(tc_pos, test_create_array_pos_file_one_int);

    suite_add_tcase(s, tc_pos);

    return s;
}