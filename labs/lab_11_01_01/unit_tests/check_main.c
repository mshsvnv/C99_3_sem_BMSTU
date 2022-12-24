#include <check.h>

#include "check_s.c"
#include "check_hd.c"
#include "check_all.c"

int main(void)
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = s_suite();
    runner = srunner_create(s);

    s = hd_suite();
    srunner_add_suite(runner, s);

    s = all_suite();
    srunner_add_suite(runner, s);
 
    srunner_run_all(runner, CK_VERBOSE);

    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return (no_failed == 0) ? SUCCESS : FAILURE;
}