#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int arrayLength = 5;

    //returns on the heap, an array of arrayLength elements with the default value of each item set to 0
    int* startOfIntArr = calloc(arrayLength, sizeof(int));

    for (int i = 0; i < arrayLength; i++) {
        printf("%d ", startOfIntArr[i]);
        startOfIntArr[i] = i;
        printf("%d ", startOfIntArr[i]);
    }

    return 0;
}
