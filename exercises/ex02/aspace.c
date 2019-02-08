/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

int var1;

void print_loc()
{
  int local = 5;
  printf("Address of local is %p\n", &local);
}

int main ()
{
    int var2 = 5;
    void *p = malloc(128);
    void *q = malloc(128);
    char *s = "Hello, World";

    void *chunk1 = malloc(14);
    void *chunk2 = malloc(14);

    print_loc();

    printf ("Address of main is %p\n", main);
    printf ("Address of var1 is %p\n", &var1);
    printf ("Address of var2 is %p\n", &var2);
    printf ("p points to %p\n", p);
    printf ("q points to %p\n", q);
    printf ("s points to %p\n", s);

    printf ("chunk1 points to %p\n", chunk1);
    printf ("chunk2 points to %p\n", chunk2);

    return 0;
}


// main-code
// var1-globals
// var2-stack
// *p-stack, pointing to the heap
// *s-stack, pointing to the constants

// p-0x161f010-23195664
// q-0x161f0a0-23195808
// Confirmed: the heap grows up

// var2-0x7ffd2ff69e2c
// local-0x7ffd2ff69e04
// Confirmed: the stack grows down

// |0x123e130-0x123e150| = 0x20 = 32
// There are 32 bytes between them, despite only allocating
// 14 bytes of space
