#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdatomic.h>

static atomic_int counter = 0;

int numberOfTimesToIncrtementBy = 1000000;

void* Incrementer(void* arg) {
    for (int i = 0; i < numberOfTimesToIncrtementBy; i++) {
        atomic_fetch_add(&counter, 1);
    }
    return NULL;
}


int main(void) {

    printf("Counter: %d\n", counter);

    pthread_t t1, t2;
    pthread_create(&t1, NULL, Incrementer, NULL);
    pthread_create(&t2, NULL, Incrementer, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Counter: %d\n", counter);
    return 0;
}
