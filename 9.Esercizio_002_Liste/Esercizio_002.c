/*
Autore: Gabriele bagnis
Data: 30/10/2019
Es 2 liste: Scrivere una funzione stampaLista basata sulla ricorsione, che ricevuta una Lista di elementi, la stampi a video in questo ordine: 1 -> 2 -> 3 -> 4 -> // 
*/

#include <stdio.h>
#include <stdlib.h>

struct El{
    int valore;
    struct El* next;
};

void stampaLista(struct El* l); //dichiaro la funzione per stampare la lista

int main(){
    int n;
    struct El* lista;   //puntatore al primo elemento
    struct El* l;       //serve per scorrere la lista
    lista=NULL; //assegno il valore NULL al puntatore per indicare che non punta nulla

    do{
        printf("Inserisci un naturale o -1 per terminare\n");
        scanf("%d",&n);
        if (n>=0){
            if (lista==NULL){ //se il punttore lista punta al nulla
                //riservo lo spazio per il primo elemento della lista e lo assegno a l 
                lista = (struct El*) malloc(sizeof(struct El));
                l = lista;
            } else {// se invece il puntatore lista punta a qualcosa
                //riservo lo spazio per una nuovo elemento della lista e lo assegno al puntatore dell'elemento successivo di l
                l->next = (struct El*) malloc(sizeof(struct El));
                l = l->next;
            }
            l->valore = n; //assegno al nuovo l il valore inserito da tastiera
            l->next = NULL; //porto il puntatore del nuovo l a NULL
        }
    } while (n>=0);

    l=lista; //porto l all'inizio della lista
    printf("numeri inseriti: \n");
    stampaLista(lista);
    fflush(stdin);
    getch();
    return 0;
 }

void stampaLista(struct El* l){  //inserire l'inizio della lista
    if(l!=NULL){    //ripeto finchè esiste un elemento successivo
        printf("%d \n",l->valore);    //stampo il valore dell'elemento della lista e l'indirizzo del successivo
        l=l->next; //passo all'elemento successivo della lista
        stampaLista(l); //passo all'elemento successivo
    }
    return;
}