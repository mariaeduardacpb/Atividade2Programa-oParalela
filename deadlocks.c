#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

pthread_mutex_t lock1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock2 = PTHREAD_MUTEX_INITIALIZER;

void* thread1(void* arg) {
    pthread_mutex_lock(&lock1);
    printf("Thread 1: Acquired lock1\n");
    sleep(1);  
    pthread_mutex_lock(&lock2);
    printf("Thread 1: Acquired lock2\n");
    pthread_mutex_unlock(&lock2);
    pthread_mutex_unlock(&lock1);
    return NULL;
}

void* thread2(void* arg) {
    pthread_mutex_lock(&lock2);
    printf("Thread 2: Acquired lock2\n");
    sleep(1);  
    pthread_mutex_lock(&lock1);
    printf("Thread 2: Acquired lock1\n");
    pthread_mutex_unlock(&lock1);
    pthread_mutex_unlock(&lock2);
    return NULL;
}

int main() {
    pthread_t t1, t2;
    pthread_create(&t1, NULL, thread1, NULL);
    pthread_create(&t2, NULL, thread2, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}