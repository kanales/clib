#include <stdlib.h>

#include "queue_test.h"
#include "vector_test.h"

int run_suite(Suite *s)
{
    int no_failed = 0;
    SRunner *runner = srunner_create(s);

    srunner_run_all(runner, CK_NORMAL);
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return no_failed;
}

int main()
{
    return run_suite(vector_suite()) || run_suite(queue_suite()) || 0;
}