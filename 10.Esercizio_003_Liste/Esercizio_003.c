/*
Autore: Gabriele bagnis
Data: 30/10/2019
Es 3 liste: Definire una funzione (in due versioni, una iterativa e una ricorsiva) lunghezzaLista che data una ListaDiElementi, restituisca la sua lunghezza.
*/

#include <stdio.h>
#include <stdlib.h>

struct El{
    int valore;
    struct El* next;
};

int calcoloLunghezzaRicorsiva(struct El* l);
int calcolaLunghezzaIterativa(struct El* l);

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

    l=lista; //porto l all'inizio della lista
    printf("numeri inseriti: \n");
    while (l!=NULL){    //ripeto finchè esiste un elemento successivo
        printf("%d - %p \n",l->valore, l->next);    //stampo il valore dell'elemento della lista e l'indirizzo del successivo
        l=l->next; //passo all'elemento successivo della lista
    }
    num= calcolaLunghezzaIterativa(lista);      //calcolo la lunghezza della lista tramite il metodo iterativo
    printf("\n\nnumero di elementi:%d", num);
    num= calcoloLunghezzaRicorsiva(lista);      //calcolo la lunghezza della lista tramite il metodo ricorsivo
    printf("\n\nnumero di elementi:%d", num);
    printf("\n");
    fflush(stdin);
    getch();
    return 0;
 }

int calcolaLunghezzaIterativa(struct El* l){    //inserire l'inizio della lista
    int num=0;
    while (l!=NULL){    //ripeto finchè esiste un elemento successivo
            num++;
            l=l->next; //passo all'elemento successivo della lista
    } 
    return num; //ritorno il numero di elementi
}

int calcoloLunghezzaRicorsiva(struct El* l){  //inserire l'inizio della lista
    int num=0;
    if(l!=NULL){    //ripeto finchè esiste un elemento successivo
        l=l->next; //passo all'elemento successivo della lista
        num=calcoloLunghezzaRicorsiva(l)+1; //passo all'elemento successivo
    }
    return num; //ritorno il numero di elementi
}