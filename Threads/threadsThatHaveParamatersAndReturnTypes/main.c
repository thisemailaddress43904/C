#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void* worker(void* arg) {
    //convert arg, a null pointer to an int pointer and then dereference it
    int value = *(int*)arg;

    printf("Received value: %d\n", value);

    int* result = malloc(sizeof(int));

    if (result == NULL) {
        return NULL;
    }

    *result = value * 2;

    return result;
}

int main(void) {
    pthread_t thread;
    int param = 21;
    void* result;

    pthread_create(&thread, NULL, worker, &param);
    pthread_join(thread, &result);

    printf("Thread successfully returned %d\n", *(int*)result);

    free(result);

    return 0;
}
