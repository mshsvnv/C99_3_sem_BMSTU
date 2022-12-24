#include <check.h>
//#include <dlfcn.h>
#include "../inc/defs.h"

#include "check_compare.c"
#include "check_swap.c"
#include "check_mysort.c"
#include "check_key.c"
#include "check_get_num.c"
#include "check_create_array.c"
#include "check_file_size.c"

int main(void)
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = compare_suite();
    runner = srunner_create(s);

    s = swap_suite();
    srunner_add_suite(runner, s); 

    s = mysort_suite();
    srunner_add_suite(runner, s); 

    s = key_suite();
    srunner_add_suite(runner, s);

    s = get_num_suite();
    srunner_add_suite(runner, s);

    s = create_array_suite();
    srunner_add_suite(runner, s);

    s = file_size_suite();
    srunner_add_suite(runner, s);

    srunner_run_all(runner, CK_VERBOSE);

    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return (no_failed == 0) ? SUCCESS : FAILURE;
}