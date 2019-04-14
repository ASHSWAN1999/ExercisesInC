/* Example code for Exercises in C.

Copyright 2016 Allen B. Downey
License: MIT License https://opensource.org/licenses/MIT

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/types.h>
#include <wait.h>

int globalVar = 0;

// errno is an external global variable that contains
// error information
extern int errno;


// get_seconds returns the number of seconds since the
// beginning of the day, with microsecond precision
double get_seconds() {
    struct timeval tv[1];
    gettimeofday(tv, NULL);
    return tv->tv_sec + tv->tv_usec / 1e6;
}


void child_code(int i, int localVar, int* p) {
    sleep(i);

    printf("\n Child Process Initial Value :: localVar = %d, globalVar = %d",
           localVar, globalVar);

    localVar++;
    globalVar++;

    printf("\n Address of malloced mem child = %p and value is %d", p, *p);
    *p = *p + 50;
    printf("\n Address of malloced mem child = %p and value is %d", p, *p);
    // *p = 200;
    // printf("\n Address of malloced mem child = %p and value is %d", p, *p);
    printf("Hello from child %d. ", i);
}

// main takes two parameters: argc is the number of command-line
// arguments; argv is an array of strings containing the command
// line arguments
int main(int argc, char *argv[])
{
    int status;
    pid_t pid;
    double start, stop;
    int i, num_children;

    int* p = malloc(sizeof(int));
    *p = 0;
    int localVar = 0;

    // the first command-line argument is the name of the executable.
    // if there is a second, it is the number of children to create.
    if (argc == 2) {
        num_children = atoi(argv[1]);
    } else {
        num_children = 1;
    }

    // get the start time
    start = get_seconds();

    for (i=0; i<num_children; i++) {

        // create a child process
        printf("Creating child %d.\n", i);
        pid = fork();

        /* check for an error */
        if (pid == -1) {
            fprintf(stderr, "fork failed: %s\n", strerror(errno));
            perror(argv[0]);
            exit(1);
        }

        /* see if we're the parent or the child */
        if (pid == 0) {
            child_code(i, localVar, p);
            exit(i);
        }
    }

    /* parent continues */
    printf("Hello from the parent.\n");

    for (i=0; i<num_children; i++) {
        pid = wait(&status);

        if (pid == -1) {
            fprintf(stderr, "wait failed: %s\n", strerror(errno));
            perror(argv[0]);
            exit(1);
        }

        // check the exit status of the child
        status = WEXITSTATUS(status);
        printf("Child %d exited with error code %d.\n", pid, status);
    }
    // compute the elapsed time
    stop = get_seconds();
    printf("Elapsed time = %f seconds.\n", stop - start);

    exit(0);
}

"""

 The child processes seem to have copies of the local (stack) and global
 variables passed to them, as the second child did see that the first
 incremented either variable. This goes for the malloced variable as well
 (heap). However, upon printing the addresses of instance of the malloced variables,
 they are all the same from child to child, indictating that variables share the
 same virtual space but are stored in different physical locations.

 The children seem to share the same code and statics segment given that they
 can all read from globalVar and they all execute the same commands outlined
 in child_code()

 """
