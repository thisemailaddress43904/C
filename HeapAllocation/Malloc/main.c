#include <stdio.h>
#include <stdlib.h>

int numberChanger(int* pointer, int number) {
    *pointer = number;
}

int main(void) {
    int* intPointer = malloc(sizeof(int));
    *intPointer = 10;

    printf("intPointer points to the value %i by being a pointer with the memory address %p\n", *intPointer, intPointer);

    numberChanger(intPointer, 11);

    printf("intPointer points to the value %i by being a pointer with the memory address %p", *intPointer, intPointer);

    return 0;
}
