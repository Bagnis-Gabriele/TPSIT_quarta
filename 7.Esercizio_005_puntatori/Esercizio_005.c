/*
Autore: Gabriele bagnis
Data: 30/10/2019
Es 5 puntatori: Scrivi un programma in modo da memorizzare dei contatti in un ordine deciso dall'utente utilizzando una struttura autoreferenziata
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>  

#define DIM 50  //creo la costante DIM per indicare il valore massimo da dare al nome

typedef struct contact{ //creo la struttura contact per memorizzare i contatti
    char name[20];  //creo un puntatore di tipo char per memorizzarne il nome del contatto
    int number;      //creo una variabile di tipo int per memorizzare il numero del contatto
    struct contact* next; //creo un puntatore alla struttura
}Contact;

int main(){
    Contact giovanni;   //creo il primo contatto, giovanni
    strcpy(giovanni.name,"giovanni"); //assegno il nome al mio contatto
    giovanni.number=8;  //assegno il numero al mio contatto
    giovanni.next=NULL; //dato che è l'unico contatto non punto a nessun altro contatto successivo
    
    Contact mamma;  //creo il contatto mamma
    strcpy(mamma.name,"mamma"); //assegno il nome al mio contatto
    mamma.number=7; //assegno il numero al mio contatto
    mamma.next= &giovanni; //dato che ho già un altro contatto lo aggiungo alla serie di contatti

    Contact io; //creo il contatto io e voglio inserirlo tra mamma e giovanni
    strcpy(io.name,"io");
    io.number=9;
    io.next= &giovanni; //per farlo metto il contatto giovanni subito dopo il contatto io nella serie

    mamma.next= &io;    //e poi metto il contatto io subito dopo il contatto mamma
    giovanni.next= &mamma;
    Contact* support= &mamma;   //ora creo il puntatore al contatto support per riuscire a stampare i contatti in modo ciclico senza dover stamparli uno a uno

    printf("name: %s \t number: %d\n", support->name, support->number); //stampo il primo contatto
    do{
        support= support->next; //aggiorno il puntatore puntandolo al contatto successivo
        printf("name: %s \t number: %d\n", support->name, support->number); //stampo il contatto attualmente puntato
    }while(support->next != NULL);  //ripetò finchè esiste un contatto successivo

    printf("\ncliccare un tasto per proseguire"); //aspetto un input da tastiera per proseguire
    fflush(stdin);  
    getch();
}