#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

int biglietti;
pthread_mutex_t mcassa1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mcassa2 = PTHREAD_MUTEX_INITIALIZER;

void compraBiglietto(int cassa){
    int numero= rand() % 9 + 1;
    int acquistati = 0;
    if (biglietti >= numero){
        biglietti-= numero;
        acquistati= numero;
    }else{
        acquistati=biglietti;
        biglietti=0;
    }
    printf("CASSA: %d sono il cliente %u e vorrei acquistare %d biglietti\n\tbiglietti acquistati: %d\n\tbiglietti disponibili: %d\n", cassa, pthread_self() , numero, acquistati, biglietti);
    return;
}

void cassa1(void *arg){
    pthread_mutex_lock(&mcassa1);
    compraBiglietto(1);
    pthread_mutex_unlock(&mcassa1);

    pthread_exit(0);
}

void cassa2(void *arg){
    pthread_mutex_lock(&mcassa2);
    compraBiglietto(2);
    pthread_mutex_unlock(&mcassa2);

    pthread_exit(0);
}

int main(int argc, char **argv){
    srand(time(NULL));
    biglietti=100;
    int n_clienti=100;
    pthread_t clienti[n_clienti];
    int i;

    for(i=0; i<n_clienti; i++){
        if(i%2==0){
            pthread_create(&clienti[i], NULL, (void*) &cassa1, NULL);
        }else{
            pthread_create(&clienti[i], NULL, (void*) &cassa2, NULL);
        }
    }

    for(i=0; i<n_clienti; i++){
        pthread_join(clienti[i], NULL); // ATTENDO TERMINAZIONE THREAD E LEGGO VALORE RESTITUITO (tipo void)
    }

    printf("Avanzano %d biglietti\n", biglietti);
}