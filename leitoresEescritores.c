#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t recurso = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t leitor_mutex = PTHREAD_MUTEX_INITIALIZER;
int leitores = 0;

void* leitor(void* arg) {
    pthread_mutex_lock(&leitor_mutex);
    leitores++;
    if (leitores == 1) pthread_mutex_lock(&recurso);  
    pthread_mutex_unlock(&leitor_mutex);

    printf("Leitor está lendo\n");
    sleep(1);  

    pthread_mutex_lock(&leitor_mutex);
    leitores--;
    if (leitores == 0) pthread_mutex_unlock(&recurso);  
    pthread_mutex_unlock(&leitor_mutex);

    return NULL;
}

void* escritor(void* arg) {
    pthread_mutex_lock(&recurso);
    printf("Escritor está escrevendo\n");
    sleep(1);  
    pthread_mutex_unlock(&recurso);

    return NULL;
}

int main() {
    pthread_t leitores_threads[5], escritores_threads[5];
    
    for (int i = 0; i < 5; i++) {
        pthread_create(&leitores_threads[i], NULL, leitor, NULL);
        pthread_create(&escritores_threads[i], NULL, escritor, NULL);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(leitores_threads[i], NULL);
        pthread_join(escritores_threads[i], NULL);
    }

    return 0;
}
