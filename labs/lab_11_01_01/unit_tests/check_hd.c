#include "../inc/my_snprintf.h"

START_TEST(test_hd_1)
{
    char my_buf[100] = { '\0' }, ideal_buf[100] = { '\0' };
    short num = 11;

    int ideal_amount = snprintf(ideal_buf, 3, "%hd", num);
    int my_amount = my_snprintf(my_buf, 3, "%hd", num);

    ck_assert_int_eq(ideal_amount, my_amount);
    ck_assert_str_eq(ideal_buf, my_buf);  
} 
END_TEST

START_TEST(test_hd_2)
{
    char my_buf[100] = { '\0' }, ideal_buf[100] = { '\0' };
    short num = -10;

    int ideal_amount = snprintf(ideal_buf, 4, "%hd", num);
    int my_amount = my_snprintf(my_buf, 4, "%hd", num);

    ck_assert_int_eq(ideal_amount, my_amount);
    ck_assert_str_eq(ideal_buf, my_buf);  
} 
END_TEST

START_TEST(test_hd_3)
{
    char my_buf[100] = { '\0' }, ideal_buf[100] = { '\0' };
    short num = -10;

    int ideal_amount = snprintf(ideal_buf, 0, "%hd", num);
    int my_amount = my_snprintf(my_buf, 0, "%hd", num);

    ck_assert_int_eq(ideal_amount, my_amount);
    ck_assert_str_eq(ideal_buf, my_buf);  
} 
END_TEST

START_TEST(test_hd_4)
{
    char my_buf[100] = { '\0' }, ideal_buf[100] = { '\0' };
    short num = 1000;

    int ideal_amount = snprintf(ideal_buf, 2, "%hd", num);
    int my_amount = my_snprintf(my_buf, 2, "%hd", num);

    ck_assert_int_eq(ideal_amount, my_amount);
    ck_assert_str_eq(ideal_buf, my_buf);  
} 
END_TEST

START_TEST(test_hd_5)
{
    char my_buf[100] = { '\0' }, ideal_buf[100] = { '\0' };
    short num = 1000;

    int ideal_amount = snprintf(ideal_buf, 10, "%hd", num);
    int my_amount = my_snprintf(my_buf, 10, "%hd", num);

    ck_assert_int_eq(ideal_amount, my_amount);
    ck_assert_str_eq(ideal_buf, my_buf);  
} 
END_TEST

Suite* hd_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("hd");

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_hd_1);
    tcase_add_test(tc_pos, test_hd_2);
    tcase_add_test(tc_pos, test_hd_3);
    tcase_add_test(tc_pos, test_hd_4);
    tcase_add_test(tc_pos, test_hd_5);
    
    suite_add_tcase(s, tc_pos);

    return s;
}