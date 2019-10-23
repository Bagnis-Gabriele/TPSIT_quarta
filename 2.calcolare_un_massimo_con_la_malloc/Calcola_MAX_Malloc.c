/*
Autore: Gabriele bagnis
Data: 26/09/2019
Es Malloc: Creare un programma che calcoli un massimo tra n numeri utilizzando la malloc
*/

#include<stdio.h>
#include<stdlib.h>

int main(){
    int *punt;  //dichiaro il puntatore di tipo intero
    int num;    //variabile per memorizzare il numero inserito
    int n;      //numeri da inserire
    int max;    //numero massimo
    int i=0;    //contatore
    printf("quanti numeri si vuole inserire?"); //chiedo quanti numeri voglio inserire
    scanf("%d", &n);
    punt=malloc(n*sizeof(int));     //alloco lo spazio di memoria per il puntatore
    punt[0]=0;  //iniziallizzo il punt di 0 a 0 per il calcolo nel caso del max
    while(n>0&&i<n){       //verifico che il numero di elementi sia maggiore di zero e ripeto il ciclo finchè non ho richiesto tutti i numeri
        printf("inserire un numero: "); //richiedo il numero da inserire
        scanf("%d", &num);
        punt[i]=num;    //metto nel vettore il valore di num
        i++;    
    }
    max=punt[0];    //inizializzo il massimo al primo elemento del vettore
    for(i=1;i<n;i++){   //ripete il ciclo finchè non sono arrivato al numero massimo di elementi
        if(punt[i]>max){  //controllo se l'elemento del vettore è maggiore di quello precedente
            max=punt[i];    //cambio il massimo
        }
    }
    printf("il numero piu' grande e': %d", max);    //stampo il valore massimo
    fflush(stdin);
    getch();
    return 0;
}