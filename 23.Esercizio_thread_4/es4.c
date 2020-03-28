 /*
        Creare un programma che simuli l'acquisto dei biglietti di un concerto
        I biglietti disponibili sono prefissati (risorsa condivisa)
        All'avvio vengono generati n clienti/threads che "vanno alla cassa" per procedere all'acquisto.
        Ogni cliente:
            - accede alla risorsa "biglietti disponibili" in modalità ESCLUSIVA
            - random, acquista un numero di biglietti compreso tra 1 e 10 
            - infine, stampa un messaggio a video indicando 
                1. Quanti biglietti ha tentato di acquistare
                2. Quanti biglietti ha di fatto acquistato
                3. Quanti biglietti sono ancora disponibili
            - prevedere la possibilità in cui:
                1. non tutti i clienti riescano ad acquistare x biglietti (in questo caso acquistare i biglietti residui)
                2. i biglietti siano completamente esauriti

        Esempio esecuzione:
        > Sono il cliente 489737546 e voglio acquistare 4 biglietti:
        > biglietti acquistati: 4
        > biglietti disponibili: 96
        ....
        > Sono il cliente 792837528 e voglio acquistare 8 biglietti:
        > biglietti acquistati: 2
        > biglietti disponibili: 0
        > Sono il cliente 876865756 e voglio acquistare 10 biglietti:
        > biglietti acquistati: 0
        > biglietti disponibili: 0
    */ 

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

int biglietti;
pthread_mutex_t cassa;

void compraBiglietto(void *arg){
    int numero = rand() % 9 + 1;
    int acquistati = 0;
    // SEZIONE CRITICA
    pthread_mutex_lock(&cassa); // blocco mutex cassa -> Rosso
    printf("sono il cliente %u e vorrei acquistare %d biglietti\n", pthread_self() , numero);
    if (biglietti >= numero){
        biglietti-= numero;
        acquistati= numero;
    }else{
        acquistati=biglietti;
        biglietti=0;
    }
    printf("\tbiglietti acquistati: %d\n\tbiglietti disponibili: %d\n", acquistati, biglietti);
	// FINE SEZIONE CRITICA
    pthread_mutex_unlock(&cassa); // sblocco mutex cassa -> Verde
}

int main(int argc, char **argv){
    srand(time(NULL));
    biglietti=100;
    int n_clienti=100;
    pthread_t clienti[n_clienti];
    pthread_mutex_unlock(&cassa); // sblocco cassa -> Verde
    int i;

    for(i=0; i<n_clienti; i++){
        if(biglietti>0){
            pthread_create(&clienti[i], NULL, (void*) &compraBiglietto, NULL);
        }else{
            n_clienti=i-1;
        }
    }

    for(i=0; i<n_clienti; i++){
        pthread_join(clienti[i], NULL); // ATTENDO TERMINAZIONE THREAD E LEGGO VALORE RESTITUITO (tipo void)
    }
    printf("Avanzano %d biglietti\n", biglietti);
}