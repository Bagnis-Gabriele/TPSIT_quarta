/*
Autore: Gabriele bagnis
Data: 16/10/2019
Es 1 puntatori: Write a program in C to store n elements in an array and print element using pointer
*/

#include<stdio.h>
#include<stdlib.h>

int main(){
    float *punt;  //dichiaro il puntatore di tipo intero
    float num;    //variabile per memorizzare il numero inserito
    int n;      //numeri da inserire
    int i=0;    //contatore
    do{
        printf("quanti numeri si vuole inserire?"); //chiedo quanti numeri voglio inserire
        scanf("%d", &n);
    }while(n<0);
    punt=(float*)malloc(n*sizeof(float));     //alloco lo spazio di memoria per il puntatore
    for(i=0;i<n;i++){       //ripeto per il numero di elementi
        printf("inserire un numero: "); //richiedo il numero da inserire
        scanf("%f", &num);
        *(punt+i)=num;    //metto nel vettore il valore di num  
    }
    for(i=0;i<n;i++){       //ripeto per il numero di elementi
        printf("\nil numero %d e': %f", i, *(punt+i)); //stampo i numeri per verificarne il funzionamento
    }

    fflush(stdin);    //aspetto un input da tastiera per proseguire
    getch();
}