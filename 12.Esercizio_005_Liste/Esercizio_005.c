/*
Autore: Gabriele bagnis
Data: 12/11/2019
Es 5 liste: Definire una funzione ordinaLista che modifica una ListaDiElementi data ordinandola in modo crescente. 
Lafunzione non deve usare allocazione dinamica della memoria (malloc e free), né modificare il campo info
degli elementi. La funzione restituisce il puntatore al primo elemento ottenuto dopo l’ordinamento.
*/

#include <stdio.h>
#include <stdlib.h>

struct El{
    int valore;
    struct El* next;
};

void deallocaLista(struct El* l); 
void ordinaLista(struct El* l);
void stampaLista(struct El* l);

int main(){
    int n;
    struct El* lista;   //puntatore al primo elemento
    struct El* l;       //serve per scorrere la lista
    int num;
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
    printf("\nlista non ordinata:\n");
    stampaLista(lista);
    ordinaLista(lista);
    printf("\nlista ordinata:\n");
    stampaLista(lista);
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