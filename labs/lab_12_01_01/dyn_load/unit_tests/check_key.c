#include <check.h>
#include <dlfcn.h>
#include "../inc/defs.h"

typedef int (*fn_key_t) (const int *, const int *, int **, int **);

//-------------------------------negatives-------------------------------//
START_TEST(test_key_NULL_pointers)
{
    void *hlib;
    hlib = dlopen("out/my_lib.so", RTLD_NOW);

    fn_key_t key = (fn_key_t)dlsym(hlib, "key");

    int rc;

    rc = key(NULL, NULL, NULL, NULL);
    dlclose(hlib);

    ck_assert_int_eq(rc, MEMORY_ERR);
} 
END_TEST

START_TEST(test_key_pe_src_NULL)
{
    void *hlib;
    hlib = dlopen("out/my_lib.so", RTLD_NOW);

    fn_key_t key = (fn_key_t)dlsym(hlib, "key");

    int rc;
    int a[] = {1, 2, 3};
    int *pb_src = a;

    rc = key(pb_src, NULL, NULL, NULL);
    dlclose(hlib);

    ck_assert_int_eq(rc, MEMORY_ERR);
} 
END_TEST

START_TEST(test_key_empty_arr)
{
    void *hlib;
    hlib = dlopen("out/my_lib.so", RTLD_NOW);

    fn_key_t key = (fn_key_t)dlsym(hlib, "key");

    int rc;
    int a[] = {1, 2, 3};
    int *pb_src = a;

    rc = key(pb_src, pb_src, NULL, NULL);
    dlclose(hlib);

    ck_assert_int_eq(rc, MEMORY_ERR);
} 
END_TEST

START_TEST(test_key_one_dig)
{
    void *hlib;
    hlib = dlopen("out/my_lib.so", RTLD_NOW);

    fn_key_t key = (fn_key_t)dlsym(hlib, "key");

    int rc, num = 1;
    int *pb_dst = malloc(sizeof(int) * num);

    int a[] = {1};

    rc = key(a, a + 1, &pb_dst, NULL);
    dlclose(hlib);

    free(pb_dst);

    ck_assert_int_eq(rc, NO_DATA_ERR);
} 
END_TEST

START_TEST(test_key_same_digs)
{
    void *hlib;
    hlib = dlopen("out/my_lib.so", RTLD_NOW);

    fn_key_t key = (fn_key_t)dlsym(hlib, "key");

    int rc, num = 5;
    int *pb_dst = malloc(sizeof(int) * num);

    int a[] = {1, 1, 1, 1, 1};

    rc = key(a, a + num, &pb_dst, NULL);
    dlclose(hlib);

    free(pb_dst);

    ck_assert_int_eq(rc, NO_DATA_ERR);
} 
END_TEST

START_TEST(test_key_max_min_close)
{
    void *hlib;
    hlib = dlopen("out/my_lib.so", RTLD_NOW);

    fn_key_t key = (fn_key_t)dlsym(hlib, "key");

    int rc, num = 5;
    int a[] = {1, 10, 10, 10, 10};
    int *pb_dst = malloc(sizeof(int) * num);

    rc = key(a, a + num, &pb_dst, NULL);
    dlclose(hlib);

    ck_assert_int_eq(rc, NO_DATA_ERR);
} 
END_TEST

//-------------------------------positives-------------------------------//
START_TEST(test_key_digs_between_max_min)
{
    void *hlib;
    hlib = dlopen("out/my_lib.so", RTLD_NOW);

    fn_key_t key = (fn_key_t)dlsym(hlib, "key");

    int rc, num = 5;
    int a[] = {1, 2, 3, 4, 5};
    int *pb_src = a;  
    int *pb_dst = malloc(sizeof(int) * num), *pe_dst = NULL;
  

    rc = key(pb_src, pb_src + num, &pb_dst, &pe_dst);
    dlclose(hlib);

    free(pb_dst);

    ck_assert_int_eq(rc, SUCCESS);
} 
END_TEST

START_TEST(test_key_one_dig_between_max_min)
{
    void *hlib;
    hlib = dlopen("out/my_lib.so", RTLD_NOW);

    fn_key_t key = (fn_key_t)dlsym(hlib, "key");

    int rc, num = 6;
    int a[] = {10, 15, 22, 11, 18, 13};
    int *pb_src = a;  
    int *pb_dst = malloc(sizeof(int) * num), *pe_dst = NULL;
  
    rc = key(pb_src, pb_src + num, &pb_dst, &pe_dst);
    dlclose(hlib);

    free(pb_dst);
    
    ck_assert_int_eq(rc, SUCCESS);

} 
END_TEST

START_TEST(test_key_few_maxs)
{
    void *hlib;
    hlib = dlopen("out/my_lib.so", RTLD_NOW);

    fn_key_t key = (fn_key_t)dlsym(hlib, "key");

    int rc, num = 8;
    int a[] = {7, 4, 8, 10, 10, 10, 10, 1};
    int *pb_src = a;  
    int *pb_dst = malloc(sizeof(int) * num), *pe_dst = NULL;
       
    rc = key(pb_src, pb_src + num, &pb_dst, &pe_dst);
    dlclose(hlib);

    free(pb_dst);

    ck_assert_int_eq(rc, SUCCESS);
} 
END_TEST

START_TEST(test_key_few_mins)
{
    void *hlib;
    hlib = dlopen("out/my_lib.so", RTLD_NOW);

    fn_key_t key = (fn_key_t)dlsym(hlib, "key");

    int rc, num = 8;
    int a[] = {5, 7, 8, 1, 1, 1, 1, 10};
    int *pb_src = a;  
    int *pb_dst = malloc(sizeof(int) * num), *pe_dst = NULL;
    
    rc = key(pb_src, pb_src + num, &pb_dst, &pe_dst);
    dlclose(hlib);

    free(pb_dst);
    
    ck_assert_int_eq(rc, SUCCESS);
} 
END_TEST

Suite* key_suite(void)
{
    Suite *s;
    TCase *tc_neg, *tc_pos;

    s = suite_create("key");

    tc_neg = tcase_create("negatives");

    tcase_add_test(tc_neg, test_key_NULL_pointers);
    tcase_add_test(tc_neg, test_key_pe_src_NULL);
    tcase_add_test(tc_neg, test_key_empty_arr);
    tcase_add_test(tc_neg, test_key_one_dig);
    tcase_add_test(tc_neg, test_key_same_digs);
    tcase_add_test(tc_neg, test_key_max_min_close);

    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_key_digs_between_max_min);
    tcase_add_test(tc_pos, test_key_one_dig_between_max_min);
    tcase_add_test(tc_pos, test_key_few_mins);
    tcase_add_test(tc_pos, test_key_few_maxs);

    suite_add_tcase(s, tc_pos);

    return s;
}