/*
Autore: Gabriele bagnis
Data: 27/11/2019
Es 1 code: Implementare i metodi enqueue() e dequeue() e creare un programma che permetta all’utente di
riempire una coda di numeri interi di lunghezza arbitraria. Successivamente testare la funzione
dequeue per svuotare la coda
*/

#include <stdio.h>
#include <stdlib.h>

struct El{
    int valore;
    struct El* next;
};

void stampaLista(struct El* l);
struct El* dequeue(struct El** head, struct El** tail);
void enqueue(struct El** head, struct El** tail, struct El* element);

int main(){
    char ancora;
    struct El* head;   //testa della coda
    struct El* tail;   //coda della coda
    struct El* element;   //nuovo elemento
    head=NULL;  //inizializzo la testa e la coda della pila
    tail=NULL;

    do{
        element = (struct El*) malloc(sizeof(struct El));   //alloco lo spazio necessario al puntatore
        printf("\n----------------------------------------\n");
        printf("Inserisci un numero naturale\n");   //chiedo il valore e lo assegno all'elemento
        fflush(stdin);
        scanf("%d",&element->valore);
        enqueue(&head, &tail, element);     //aggiungo l'elemento in coda
        printf("Vuoi inserire un altro elemento (s per si)\n"); //chido se si vuole inserire un altro elemento
        fflush(stdin);
        scanf("%c",&ancora);
        printf("----------------------------------------\n");
    }while(ancora=='s'||ancora=='S');   //continuo finchè ci sono elementi
    
    printf("\n----------------------------------------\n"); //stampo la coda
    printf("lista:\n");
    stampaLista(head);
    printf("----------------------------------------\n");

    while(element!=NULL){   //estraggo tutti gli elementi della coda liberandone lo spazio
        element=dequeue(&head, &tail);
        free(element);
    }

    printf("\n----------------------------------------\n"); //stampo la coda ormai vuota
    printf("lista:\n");
    stampaLista(head);
    printf("----------------------------------------\n");

    printf("\npremere un tasto per continuare...");
    fflush(stdin);
    getch();
    return 0;
}

void enqueue(struct El** head, struct El** tail, struct El* element){   //aggiungo elemento in coda
	if(*head==NULL){
		*head=element;
	}else{
		(*tail)->next=element;
	}
	*tail=element;
    element->next=NULL;
    return;
}

struct El* dequeue(struct El** head, struct El** tail){ //estraggo un elemento dalla coda
	struct El* ret = *head;
	if(*head==NULL){
		return NULL;
	}else{
		*head = ret->next;
	}
	if(*head==NULL){
		*tail = NULL;
	}
	return ret;
}

void stampaLista(struct El* l){  //inserire l'inizio della lista
    if(l!=NULL){    //ripeto finchè esiste un elemento successivo
        printf("%d \n",l->valore);    //stampo il valore dell'elemento della lista e l'indirizzo del successivo
        l=l->next; //passo all'elemento successivo della lista
        stampaLista(l); //passo all'elemento successivo
    }
    return;
}
