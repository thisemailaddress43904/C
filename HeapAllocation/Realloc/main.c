#include <stdio.h>
#include <stdlib.h>

static void alterInt(int* integer, const int newValue) {
    *integer = newValue;
}

int main(void) {
    int arrayLength = 5;

    //returns on the heap, an array of arrayLength elements with the default value of each item set to 0
    int* startOfIntArr = calloc(arrayLength, sizeof(int));

    for (int i = 0; i < arrayLength; i++) {
        printf("%d ", startOfIntArr[i]);
    }
    printf("\n");

    alterInt(&arrayLength, 7);
    startOfIntArr = realloc(startOfIntArr, arrayLength * sizeof(int));

    for (int i = 0; i < arrayLength; i++) {
        printf("%d ", startOfIntArr[i]);
    }

    return 0;
}
