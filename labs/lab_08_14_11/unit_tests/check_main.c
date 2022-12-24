#include <check.h>

#include "check_addition.c"
#include "check_multiplication.c"
#include "check_inversion_matrix.c"
#include "check_determinant.c"

int main(void)
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = addition_suite();
    runner = srunner_create(s);

    s = multiplication_suite();
    srunner_add_suite(runner, s); 

    s = inversion_matrix_suite();
    srunner_add_suite(runner, s); 

    s = determinant_suite();
    srunner_add_suite(runner, s);

    srunner_run_all(runner, CK_VERBOSE);

    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return (no_failed == 0) ? SUCCESS : FAILURE;
}