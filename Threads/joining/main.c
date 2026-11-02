#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

static int maximumNumberOfMyTurnRuns = 4;
static int MyTurnHasRanThisManyTimes = 0;
void* myTurn(void* arg) {
    while (maximumNumberOfMyTurnRuns > MyTurnHasRanThisManyTimes++) {
        sleep(1);
        printf("My turn!\n");
    }
}

static int maximumNumberOfOtherTurnRuns = 4;
static int OtherTurnHasRanThisManyTimes = 0;
void* otherTurn(void* arg) {
    while (maximumNumberOfOtherTurnRuns > OtherTurnHasRanThisManyTimes++) {
        sleep(2);
        printf("Other turn!\n");
    }
}

int main(void) {

    pthread_t myThread;
    pthread_create(&myThread, NULL, myTurn, NULL);

    pthread_t otherThread;
    pthread_create(&otherThread, NULL, otherTurn, NULL);

    pthread_join(myThread, NULL);
    pthread_join(otherThread, NULL);

    return 0;
}