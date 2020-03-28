#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER; // Variabili pthread_mutex_t 

void *ping(void *arg){ // funzione eseguita da thread t1 
    while(1){ // ciclo infinito
        // SEZIONE CRITICA
        pthread_mutex_lock(&lock); // blocco mutex m1 -> 0 -> Rosso
        printf("ping\n");
	// FINE SEZIONE CRITICA
        pthread_mutex_unlock(&lock); // sblocco mutex m2 -> 1 -> Verde
    }
}

void *pong(void *arg){ // funzione eseguita da thread t2
    while(1){ // ciclo infinito
        // SEZIONE CRITICA
        pthread_mutex_lock(&lock); // blocco mutex m2 -> Rosso
        printf("pong\n");
	// FINE SEZIONE CRITICA
        pthread_mutex_unlock(&lock); // sblocco mutex m1 -> Verde
    }
}

int main(int argc, char **argv){
    pthread_t t1, t2;

    pthread_create(&t1, NULL, (void*)ping, NULL);
    pthread_create(&t2, NULL, (void*)pong, NULL);

 // istruzioni superflue, i thread t1, t2 non termineranno mai [while(1)]
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}
