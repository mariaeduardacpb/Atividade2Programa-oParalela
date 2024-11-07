#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>

sem_t semaforo;

void* produtor(void* arg) {
    printf("Produzindo\n");
    sleep(2);  
    sem_post(&semaforo);  
    return NULL;
}

void* consumidor(void* arg) {
    sem_wait(&semaforo);  
    printf("Consumindo\n");
    return NULL;
}

int main() {
    pthread_t t1, t2;
    sem_init(&semaforo, 0, 0);  

    pthread_create(&t1, NULL, produtor, NULL);
    pthread_create(&t2, NULL, consumidor, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    sem_destroy(&semaforo);  
    return 0;
}