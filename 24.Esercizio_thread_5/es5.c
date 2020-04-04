#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

int biglietti, successivo, cassa1, cassa2=0;
pthread_mutex_t mcassa = PTHREAD_MUTEX_INITIALIZER;

void cassa(void *arg){
    int cassa=*((int*)arg);
    if(cassa==1){
        cassa1++;
    }else{
        cassa2++;
    }
    int exit=1;
    int numero= rand() % 10;
    int acquistati = 0;
    while(exit==1){
        if((cassa==1&&successivo==1&&pthread_mutex_lock(&mcassa)==0)||cassa2==0){
            exit=0;
        }else if ((cassa==2&&successivo==2&&pthread_mutex_lock(&mcassa)==0)||cassa1==0){
            exit=0;
        }
    }
    if (biglietti >= numero){
        biglietti-= numero;
        acquistati= numero;
    }else{
        acquistati=biglietti;
        biglietti=0;
    }
    successivo=rand() % 10;
    if(successivo>5){
        successivo=1;
    }else{
        successivo=2;
    }
    pthread_mutex_unlock(&mcassa);
    if(cassa==1){
        cassa1--;
    }else{
        cassa2--;
    }
    printf("CASSA: %d sono il cliente %u e vorrei acquistare %d biglietti\n\tbiglietti acquistati: %d\n\tbiglietti disponibili: %d\n\tcassa successiva: %d\n", cassa, pthread_self() , numero, acquistati, biglietti, successivo);

    pthread_exit(0);
}

int main(int argc, char **argv){
    srand(time(NULL));
    biglietti=500;
    successivo=1;
    int n_clienti=100;
    pthread_t clienti[n_clienti];
    int i;

    for(i=0; i<n_clienti; i++){
        int *x=(int*)malloc(sizeof(int));
        *x=(i%2)+1;
        if(i%2==0){
            pthread_create(&clienti[i], NULL, (void*) &cassa, (void *) x);
        }else{
            pthread_create(&clienti[i], NULL, (void*) &cassa, (void *) x);
        }
    }

    for(i=0; i<n_clienti; i++){
        pthread_join(clienti[i], NULL); // ATTENDO TERMINAZIONE THREAD E LEGGO VALORE RESTITUITO (tipo void)
    }

    printf("Avanzano %d biglietti\n", biglietti);
}