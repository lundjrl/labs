#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>

long i = 0;
sem_t mutex;

int main (int argc, char** argv) {
    sem_init(&mutex, 0, 2147480000);
    while(sem_post(&mutex) == 0) {
      sem_getvalue(&mutex, &i);
    }
    printf("Max value at %ld\n", i);
    sem_destroy(&mutex);
}
