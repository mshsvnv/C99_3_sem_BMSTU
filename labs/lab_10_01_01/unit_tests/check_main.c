#include <check.h>
#include "check_find.c"
#include "check_pop_front.c"
#include "check_remove_duplicates.c"
#include "check_sort.c"

int main(void)
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = find_suite();
    runner = srunner_create(s);

    s = pop_front_suite();
    srunner_add_suite(runner, s); 

    s = remove_suite();
    srunner_add_suite(runner, s); 

    s = sort_suite();
    srunner_add_suite(runner, s); 

    srunner_run_all(runner, CK_VERBOSE);

    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return (no_failed == 0) ? SUCCESS : FAILURE;
}