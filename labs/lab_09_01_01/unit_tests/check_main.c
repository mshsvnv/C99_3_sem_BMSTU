#include <check.h>

#include "check_sort.c"
#include "check_binary_search.c"

int main(void)
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = sort_suite();
    runner = srunner_create(s);

    s = binary_search_suite();
    srunner_add_suite(runner, s);
 
    srunner_run_all(runner, CK_VERBOSE);

    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return (no_failed == 0) ? SUCCESS : FAILURE;
}