#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "util.h"
#include "minunit.h"

int tests_run = 0;

static char *test1() {
    char* res = icmpcode_v4(0);
    char *message = "test1 failed: should say 'network unreachable'";
    mu_assert(message, res == "network unreachable");
    return NULL;
}

static char *test2() {
    char* res = icmpcode_v4(1);
    char *message = "test1 failed: should say 'host unreachable'";
    mu_assert(message, res == "host unreachable");
    return NULL;
}

static char *test3() {
    int res = icmpcode_v4(2);
    char *message = "test1 failed: should say 'protocol unreachable'";
    mu_assert(message, res == "protocol unreachable");
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
    if (result != NULL) {
        printf("%s\n", result);
    } else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}
