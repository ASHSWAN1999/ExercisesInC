/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int *foo() {
    int i;
    int array[SIZE];

    // printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
        array[i] = 42;
    }
    return array;
}

void bar() {
    int i;
    int array[SIZE];

    // printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
        array[i] = i;
    }
}

int main()
{
    int i;
    int *array = foo();
    bar();

    for (i=0; i<SIZE; i++) {
        printf("%d\n", array[i]);
    }

    return 0;
}

// Yes, the complier says this "returns address of local variable."
// Returning array is problematic because the program only allocates
// space for local variables inside the scope of the block.
// This means that array is returning the memory address of
// a place that may no longer contain the correct data.
//
// There is a segmentation fault because when you attempt to set
// foo equal to array, you are accessing memory that is unallocated.
//
// Commenting out prints did not change the segmentation fault
// or the warning about addresses of local variables.
// However, the fact that the functions printed the same Address
// verifies that the program unallocated space when foo concluded
// and reallocated it to bar.
