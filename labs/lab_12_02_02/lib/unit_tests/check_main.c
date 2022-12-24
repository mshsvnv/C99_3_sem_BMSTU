#include <check.h>

#include "check_fill_fib.c"
#include "check_filter.c"

int main(void)
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = filter_suite();
    runner = srunner_create(s);

    s = fill_fib_suite();
    srunner_add_suite(runner, s); 

    srunner_run_all(runner, CK_VERBOSE);

    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return (no_failed == 0) ? 0 : 1;
}