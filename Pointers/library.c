#include "library.h"

#include <stdio.h>


int main(void) {
    int* intPointer;

    int integer = 9;
    intPointer = &integer;

    printf("intPointer points to the memory address %p which stores the value %i", intPointer, *intPointer);


    return 0;
}