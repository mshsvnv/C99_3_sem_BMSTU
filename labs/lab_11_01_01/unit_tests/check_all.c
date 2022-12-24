#include "../inc/my_snprintf.h"

START_TEST(test_all_1)
{
    char my_buf[100] = { '\0' }, ideal_buf[100] = { '\0' };
    short num = 1000;
    char *str = "apples";

    int ideal_amount = snprintf(ideal_buf, 0, "%hd %s", num, str);
    int my_amount = my_snprintf(my_buf, 0, "%hd %s", num, str);

    ck_assert_int_eq(ideal_amount, my_amount);
    ck_assert_str_eq(ideal_buf, my_buf);  
} 
END_TEST

START_TEST(test_all_2)
{
    char my_buf[100] = { '\0' }, ideal_buf[100] = { '\0' };
    short num = -500;
    char *str_1 = "apples";
    char *str_2 = "oranges";

    int ideal_amount = snprintf(ideal_buf, 10, "%hd %s %s", num, str_1, str_2);
    int my_amount = my_snprintf(my_buf, 10, "%hd %s %s", num, str_1, str_2);

    ck_assert_int_eq(ideal_amount, my_amount);
    ck_assert_str_eq(ideal_buf, my_buf);  
} 
END_TEST

START_TEST(test_all_3)
{
    char my_buf[100] = { '\0' }, ideal_buf[100] = { '\0' };
    short num = -500;
    char *str_1 = "apples";
    char *str_2 = "oranges";

    int ideal_amount = snprintf(ideal_buf, 50, "%hd %s %s", num, str_1, str_2);
    int my_amount = my_snprintf(my_buf, 50, "%hd %s %s", num, str_1, str_2);

    ck_assert_int_eq(ideal_amount, my_amount);
    ck_assert_str_eq(ideal_buf, my_buf);  
} 
END_TEST

START_TEST(test_all_4)
{
    char my_buf[100] = { '\0' }, ideal_buf[100] = { '\0' };
    short num = -500;
    char *str_1 = "apples";
    char *str_2 = "oranges";

    int ideal_amount = snprintf(ideal_buf, 19, "%hd %s %s", num, str_1, str_2);
    int my_amount = my_snprintf(my_buf, 19, "%hd %s %s", num, str_1, str_2);

    ck_assert_int_eq(ideal_amount, my_amount);
    ck_assert_str_eq(ideal_buf, my_buf);  
} 
END_TEST

Suite* all_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("all");

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_all_1);
    tcase_add_test(tc_pos, test_all_2);
    tcase_add_test(tc_pos, test_all_3);
    tcase_add_test(tc_pos, test_all_4);

    suite_add_tcase(s, tc_pos);

    return s;
}