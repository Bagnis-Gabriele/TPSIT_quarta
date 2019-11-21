/*
Autore: Gabriele bagnis
Data: 13/11/2019
Es 6 liste: Definire una funzione merge che date due ListaDiElementi ordinate, restituisca una nuova ListaDiElementi
ordinata contenente tutti gli elementi delle due liste. Le liste originali devono restare immutate. 
*/

#include <stdio.h>
#include <stdlib.h>

struct El{
    int valore;
    struct El* next;
}El;

void deallocaLista(struct El* l); 
void ordinaLista(struct El* l);
void stampaLista(struct El* l);
struct El* UnisciListeOrdinanodole(struct El* l1, struct El* l2);

int main(){
    int n, k;
    struct El* lista;
    struct El* l;
    struct El* lista1;   //puntatore al primo elemento
    struct El* l1;       //serve per scorrere la lista
    struct El* lista2;   //puntatore al primo elemento
    struct El* l2;       //serve per scorrere la lista
    struct El* listaFinale;
    int num;
    lista=NULL; //assegno il valore NULL al puntatore per indicare che non punta nulla
    for(k=0;k<2;k++){
        if(k==0){
            printf("\nlista 1:\n");
        }else{
            printf("\nlista 2:\n");
        }
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
        if(k==0){
            lista1=lista;
            l1=l;
            lista=NULL;
            l=NULL;
        }else{
            lista2=lista;
            l2=l;
            lista=NULL;
            l=NULL;
        }
    }
    printf("\nlista 1 non ordinata:\n");
    stampaLista(lista1);
    printf("\nlista 2 non ordinata:\n");
    stampaLista(lista2);    
    listaFinale=UnisciListeOrdinanodole(lista1,lista2);
    printf("\nlista ordinata:\n");
    stampaLista(listaFinale);
    l=lista; //porto l all'inizio della lista
    deallocaLista(lista);
    printf("\n\n premere un tasto per continuare...");
    fflush(stdin);
    getch();
    return 0;
 }

void deallocaLista(struct El* l){   //gli passo l'inizio lista
    if(l!=NULL){    //ripeto finchè esiste un elemento successivo
        l=l->next; //passo all'elemento successivo della lista
        deallocaLista(l); //passo all'elemento successivo
    }
    free(l);    //libero l'elemento della lista
    return;
}

void stampaLista(struct El* l){  //inserire l'inizio della lista
    if(l!=NULL){    //ripeto finchè esiste un elemento successivo
        printf("%d \n",l->valore);    //stampo il valore dell'elemento della lista e l'indirizzo del successivo
        l=l->next; //passo all'elemento successivo della lista
        stampaLista(l); //passo all'elemento successivo
    }
    return;
}

void ordinaLista(struct El* l) { //inserire l'inizio della lista
    struct El* lista = l;   //creo un puntatore all'inizio della struttura
    int x;  //creo una variabile di appoggio
    while(l->next!=NULL) {
        if((l->valore)>(l->next->valore)){  //se il valore dell'elemento attuale è maggiore di quello successivo inverto i due valori
            x=l->next->valore;
            l->next->valore=l->valore;
            l->valore=x;
            l=lista;    //riporto la lista all'inizio 
        }else{
            l=l->next;  //passo all'elemeto successivo
        }
    }
    return;
}

struct El* UnisciListeOrdinanodole(struct El* l1, struct El* l2) { //inserire l'inizio delle liste
    struct El* lista=NULL;   //puntatore all'inizio della lista
    struct El* l=NULL;   //puntatore per spostarsi nella lista
    int x;  //creo una variabile di appoggio
    while(l1!=NULL||l2!=NULL) {     //copio le due liste nella mia nuova lista unendole
        if (lista==NULL){ 
            lista = (struct El*) malloc(sizeof(struct El));
            l = lista;
        } else {
            l->next = (struct El*) malloc(sizeof(struct El));
            l=l->next;
        }
        if(l1!=NULL){
            l->valore=l1->valore;
            l1=l1->next;
        }else{
            l->valore=l2->valore;
            l2=l2->next;
        }
        l->next=NULL;
    }
    printf("fine");
    ordinaLista(lista); //riordino la mia nuova lista
    return lista;
}