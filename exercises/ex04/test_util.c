/* file minunit_example.c */

#include <stdio.h>
#include "minunit.h"
#include "endswith.h"


int tests_run = 0;


static char *test1() {
    int res = endswith("endswith", "swith");
    char *message = "test1 failed: endswith(\"endswith\", \"swith\") should return 1";
    mu_assert(message, res == 1);
    return NULL;
}

static char *test2() {
    int res = endswith("endswith", "ends");
    char *message = "test2 failed: endswith(\"endswith\", \"ends\") should return 0";
    mu_assert(message, res == 0);
    return NULL;
}

static char *test3() {
    int res = endswith("endswith", "offendswith");
    char *message = "test3 failed: endswith(\"offendswith\", \"swith\") should return 0";
    mu_assert(message, res == 0);
    return NULL;
}

static char * all_tests() {
    mu_run_test(test1);
    mu_run_test(test2);
    mu_run_test(test3);
    return NULL;
}

int main(int argc, char **argv) {
    char *result = all_tests();
    if (result != 0) {
        printf("%s\n", result);
    }
    else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}
