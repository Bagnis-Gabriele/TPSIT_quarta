/*
Autore: Gabriele bagnis
Data: 16/10/2019
Es 2 puntatori: Write a program in C to find the largest element using Dynamic Memory Allocation.
*/

#include<stdio.h>
#include<stdlib.h>

int main(){
    float *punt;  //dichiaro il puntatore di tipo decimale
    float num;    //variabile per memorizzare il numero inserito
    int n;      //numeri da inserire
    int i=0;    //contatore
    float max;  //creo la variabile per memorizzare il massimo
    do{
        printf("quanti numeri si vuole inserire?"); //chiedo quanti numeri voglio inserire
        scanf("%d", &n);
    }while(n<0);
    punt=(float*)malloc(n*sizeof(float));     //alloco lo spazio di memoria per il puntatore
    *punt=0;  //iniziallizzo il punt di 0 a 0 per il calcolo nel caso del max
    for(i=0;i<n;i++){       //ripeto per il numero di elementi
        printf("inserire un numero: "); //richiedo il numero da inserire
        scanf("%f", &num);
        *(punt+i)=num;    //metto nel vettore il valore di num  
    }
    for(i=0;i<n;i++){       //ripeto per il numero di elementi
        printf("\nil numero %d e': %f", i, punt[i]); //stampo i numeri per verificarne il funzionamento
    }
    max=*punt;    //inizializzo il massimo al primo elemento del vettore
    for(i=0;i<n;i++){   //ripete il ciclo finchè non sono arrivato al numero massimo di elementi
        if(max<*(punt+i)){  //controllo se l'elemento del vettore è maggiore di quello precedente
            max=*(punt+i);    //cambio il massimo
        }
    }
    printf("\nil numero piu' grande e': %f", max);    //stampo il valore massimo

    free(punt); //libero lo spazio occupato dal vettore punt

    fflush(stdin);  //aspetto un input da tastiera per proseguire
    getch();
}