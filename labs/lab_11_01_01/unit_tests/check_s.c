#include "../inc/my_snprintf.h"

START_TEST(test_s_1)
{
    char *str = "something to write";

    int ideal_amount = snprintf(NULL, 0, "%s", str);
    int my_amount = my_snprintf(NULL, 0, "%s", str);

    ck_assert_int_eq(ideal_amount, my_amount);    
} 
END_TEST

START_TEST(test_s_2)
{
    char my_buf[100] = { '\0' }, ideal_buf[100] = { '\0' };
    char *str = "On a dark desert highway";

    int ideal_amount = snprintf(ideal_buf, 0, "%s", str);
    int my_amount = my_snprintf(my_buf, 0, "%s", str);

    ck_assert_int_eq(ideal_amount, my_amount);
    ck_assert_str_eq(ideal_buf, my_buf);  
} 
END_TEST

START_TEST(test_s_3)
{
    char my_buf[20] = { '\0' }, ideal_buf[20] = { '\0' };
    char *str = "Cool wind in my hair";

    int ideal_amount = snprintf(ideal_buf, 20, "%s", str);
    int my_amount = my_snprintf(my_buf, 20, "%s", str);

    ck_assert_int_eq(ideal_amount, my_amount);
    ck_assert_str_eq(ideal_buf, my_buf);  
} 
END_TEST

START_TEST(test_s_4)
{
    char my_buf[100] = { '\0' }, ideal_buf[100] = { '\0' };
    char *str = "Rising up through the air";

    int ideal_amount = snprintf(ideal_buf, 60, "%s", str);
    int my_amount = my_snprintf(my_buf, 60, "%s", str);

    ck_assert_int_eq(ideal_amount, my_amount);
    ck_assert_str_eq(ideal_buf, my_buf);  
} 
END_TEST

START_TEST(test_s_5)
{
    char my_buf[100] = { '\0' }, ideal_buf[100] = { '\0' };
    char *str = "";

    int ideal_amount = snprintf(ideal_buf, 60, "%s", str);
    int my_amount = my_snprintf(my_buf, 60, "%s", str);

    ck_assert_int_eq(ideal_amount, my_amount);
    ck_assert_str_eq(ideal_buf, my_buf);  
} 
END_TEST

START_TEST(test_s_6)
{
    char my_buf[100] = { '\0' }, ideal_buf[100] = { '\0' };
    char *str = "abcdefgh";

    int ideal_amount = snprintf(ideal_buf, 3, "%s", str);
    int my_amount = my_snprintf(my_buf, 3, "%s", str);

    ck_assert_int_eq(ideal_amount, my_amount);
    ck_assert_str_eq(ideal_buf, my_buf);  
} 
END_TEST


Suite* s_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("s");

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_s_1);
    tcase_add_test(tc_pos, test_s_2);
    tcase_add_test(tc_pos, test_s_3);
    tcase_add_test(tc_pos, test_s_4);
    tcase_add_test(tc_pos, test_s_5);
    tcase_add_test(tc_pos, test_s_6);
    
    suite_add_tcase(s, tc_pos);

    return s;
}