#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 5
pthread_barrier_t barrier;

void* tarefa(void* arg) {
    printf("Thread %ld chegou à barreira\n", (long)arg);
    pthread_barrier_wait(&barrier);  

    printf("Thread %ld passou pela barreira\n", (long)arg);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];

    pthread_barrier_init(&barrier, NULL, NUM_THREADS);  

    for (long i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, tarefa, (void*)i);
    }

    for (long i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_barrier_destroy(&barrier); 
    return 0;
}