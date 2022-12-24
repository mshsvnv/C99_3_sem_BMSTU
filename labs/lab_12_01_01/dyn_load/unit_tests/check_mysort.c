#include <check.h>
#include <dlfcn.h>
#include "../inc/defs.h"

typedef void (*fn_mysort_t) (void *, size_t, size_t, int (*compare)(const void *, const void *));
typedef int (*fn_compare_t) (const void *, const void *);

int ideal_int[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
char ideal_char[] = {'a', 'b', 'c', 'd', 'e', 'f'};
double ideal_double[] = {-5.0, -4.0, -3.0, -2.0, -1.0, 0.0};

//-------------------------------positives-------------------------------//
int comp(void *src, void *ideal, int n, size_t size)
{
    void *hlib;
    hlib = dlopen("out/my_lib.so", RTLD_NOW);

    fn_compare_t compare = (fn_compare_t)dlsym(hlib, "compare");

    int i = 0;
    char *p_s = (char *)src, *p_i = (char *)ideal;

    for (; i < n; i += size)
    {
        if (compare(p_s + i, p_i + i) != 0)
        {
            dlclose(hlib);
            return FAILURE;
        }
    }

    dlclose(hlib);
    return SUCCESS;
}

START_TEST(test_mysort_int_sorted)
{
    void *hlib;
    hlib = dlopen("out/my_lib.so", RTLD_NOW);

    fn_mysort_t mysort = (fn_mysort_t)dlsym(hlib, "mysort");

    fn_compare_t compare = (fn_compare_t)dlsym(hlib, "compare");

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    mysort(arr, 10, sizeof(int), compare);
    dlclose(hlib);

    ck_assert_int_eq(comp(arr, ideal_int, 10, sizeof(int)), SUCCESS);
} 
END_TEST

START_TEST(test_mysort_int_reverse_sorted)
{
    void *hlib;
    hlib = dlopen("out/my_lib.so", RTLD_NOW);

    fn_mysort_t mysort = (fn_mysort_t)dlsym(hlib, "mysort");

    fn_compare_t compare = (fn_compare_t)dlsym(hlib, "compare");

    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    mysort(arr, 10, sizeof(int), compare);
    dlclose(hlib);

    ck_assert_int_eq(comp(arr, ideal_int, 10, sizeof(int)), SUCCESS);
} 
END_TEST

START_TEST(test_mysort_int_unsorted)
{
    void *hlib;
    hlib = dlopen("out/my_lib.so", RTLD_NOW);

    fn_mysort_t mysort = (fn_mysort_t)dlsym(hlib, "mysort");

    fn_compare_t compare = (fn_compare_t)dlsym(hlib, "compare");

    int arr[] = {8, 2, 7, 4, 1, 9, 6, 5, 3, 10};

    mysort(arr, 10, sizeof(int), compare);
    dlclose(hlib);

    ck_assert_int_eq(comp(arr, ideal_int, 10, sizeof(int)), SUCCESS);
} 
END_TEST

START_TEST(test_mysort_int_one_dig)
{
    void *hlib;
    hlib = dlopen("out/my_lib.so", RTLD_NOW);

    fn_mysort_t mysort = (fn_mysort_t)dlsym(hlib, "mysort");

    fn_compare_t compare = (fn_compare_t)dlsym(hlib, "compare");

    int arr[] = {1};

    mysort(arr, 1, sizeof(int), compare);
    dlclose(hlib);

    ck_assert_int_eq(arr[0], 1);
} 
END_TEST

START_TEST(test_mysort_int_same_digs)
{
    void *hlib;
    hlib = dlopen("out/my_lib.so", RTLD_NOW);

    fn_mysort_t mysort = (fn_mysort_t)dlsym(hlib, "mysort");

    fn_compare_t compare = (fn_compare_t)dlsym(hlib, "compare");

    int arr[] = {5, 5, 5, 5, 5};
    int ideal[] = {5, 5, 5, 5, 5};

    mysort(arr, 5, sizeof(int), compare);
    dlclose(hlib);

    ck_assert_int_eq(comp(arr, ideal, 5, sizeof(int)), SUCCESS);
} 
END_TEST

START_TEST(test_mysort_char_sorted)
{
    void *hlib;
    hlib = dlopen("out/my_lib.so", RTLD_NOW);

    fn_mysort_t mysort = (fn_mysort_t)dlsym(hlib, "mysort");

    fn_compare_t compare = (fn_compare_t)dlsym(hlib, "compare");

    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};

    mysort(arr, 6, sizeof(char), compare);
    dlclose(hlib);

    ck_assert_int_eq(comp(arr, ideal_char, 6, sizeof(char)), SUCCESS);
} 
END_TEST

START_TEST(test_mysort_char_sorted_reverse)
{
    void *hlib;
    hlib = dlopen("out/my_lib.so", RTLD_NOW);

    fn_mysort_t mysort = (fn_mysort_t)dlsym(hlib, "mysort");

    fn_compare_t compare = (fn_compare_t)dlsym(hlib, "compare");

    char arr[] = {'f', 'e', 'd', 'c', 'b', 'a'};

    mysort(arr, 6, sizeof(char), compare);
    dlclose(hlib);

    ck_assert_int_eq(comp(arr, ideal_char, 6, sizeof(char)), SUCCESS);
} 
END_TEST

START_TEST(test_mysort_char_unsorted)
{
    void *hlib;
    hlib = dlopen("out/my_lib.so", RTLD_NOW);

    fn_mysort_t mysort = (fn_mysort_t)dlsym(hlib, "mysort");

    fn_compare_t compare = (fn_compare_t)dlsym(hlib, "compare");

    char arr[] = {'d', 'a', 'c', 'e', 'f', 'b'};

    mysort(arr, 6, sizeof(char), compare);
    dlclose(hlib);

    ck_assert_int_eq(comp(arr, ideal_char, 6, sizeof(char)), SUCCESS);
} 
END_TEST

START_TEST(test_mysort_double_sorted)
{
    void *hlib;
    hlib = dlopen("out/my_lib.so", RTLD_NOW);

    fn_mysort_t mysort = (fn_mysort_t)dlsym(hlib, "mysort");

    fn_compare_t compare = (fn_compare_t)dlsym(hlib, "compare");

    double arr[] = {-5.0, -4.0, -3.0, -2.0, -1.0, 0.0};

    mysort(arr, 6, sizeof(double), compare);
    dlclose(hlib);

    ck_assert_int_eq(comp(arr, ideal_double, 6, sizeof(double)), SUCCESS);
} 
END_TEST

START_TEST(test_mysort_double_sorted_reverse)
{
    void *hlib;
    hlib = dlopen("out/my_lib.so", RTLD_NOW);

    fn_mysort_t mysort = (fn_mysort_t)dlsym(hlib, "mysort");

    fn_compare_t compare = (fn_compare_t)dlsym(hlib, "compare");

    double arr[] = {0.0, -1.0, -2.0, -3.0, -4.0, -5.0};

    mysort(arr, 6, sizeof(double), compare);
    dlclose(hlib);

    ck_assert_int_eq(comp(arr, ideal_double, 6, sizeof(double)), SUCCESS);
} 
END_TEST

START_TEST(test_mysort_double_unsorted)
{
    void *hlib;
    hlib = dlopen("out/my_lib.so", RTLD_NOW);

    fn_mysort_t mysort = (fn_mysort_t)dlsym(hlib, "mysort");

    fn_compare_t compare = (fn_compare_t)dlsym(hlib, "compare");

    double arr[] = {-1.0, -4.0, -5.0, -2.0, -3.0, 0.0};

    mysort(arr, 6, sizeof(double), compare);
    dlclose(hlib);

    ck_assert_int_eq(comp(arr, ideal_double, 6, sizeof(double)), SUCCESS);
} 
END_TEST

Suite* mysort_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("mysort");

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_mysort_int_sorted);
    tcase_add_test(tc_pos, test_mysort_int_reverse_sorted);
    tcase_add_test(tc_pos, test_mysort_int_unsorted);
    tcase_add_test(tc_pos, test_mysort_int_one_dig);
    tcase_add_test(tc_pos, test_mysort_int_same_digs);

    tcase_add_test(tc_pos, test_mysort_char_sorted);
    tcase_add_test(tc_pos, test_mysort_char_sorted_reverse);
    tcase_add_test(tc_pos, test_mysort_char_unsorted);

    tcase_add_test(tc_pos, test_mysort_double_sorted);
    tcase_add_test(tc_pos, test_mysort_double_sorted_reverse);
    tcase_add_test(tc_pos, test_mysort_double_unsorted);

    suite_add_tcase(s, tc_pos);

    return s;
}