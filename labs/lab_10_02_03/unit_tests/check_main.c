#include <check.h>
#include "check_list_create.c"
#include "check_multiplication.c"
#include "check_division.c"
#include "check_to_square.c"

int main(void)
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = list_create_suite();
    runner = srunner_create(s);

    s = multiplication_suite();
    srunner_add_suite(runner, s); 

    s = division_suite();
    srunner_add_suite(runner, s); 

    s = to_square_suite();
    srunner_add_suite(runner, s);

    srunner_run_all(runner, CK_VERBOSE);

    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return (no_failed == 0) ? SUCCESS : FAILURE;
}