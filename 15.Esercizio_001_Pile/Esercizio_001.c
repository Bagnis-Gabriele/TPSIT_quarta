/*
Autore: Gabriele bagnis
Data: 21/11/2019
Es 1 Pile: Creare un programma che dato un numero intero, avente un numero arbitrario di cifre inserite
dall’utente, lo scriva in output con le cifre in ordine inverso. Utilizzare una pila e le implementazioni
dei metodi push e pop
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct El{
    int valore;
    struct El* next;
}El;

bool controlloStringa(char cifra[]);
struct El* pop(struct El** head);
void push(struct El** head, struct El* element);
void stampaPila(struct El** head);

int main(){
    struct El* head;
    struct El* element;
    char cifra[1000];
    printf("\nCaricamento della pila:");
    do{
        printf("\nInserire la cifra:  ");
        fflush(stdin);
        scanf("%s", cifra);
    }while(!controlloStringa(cifra));
    int i=0;
    do{
        element = (struct El*) malloc(sizeof(struct El));
        element->valore=cifra[i]-48;
        i++;
        push(&head,element);
    }while(cifra[i]!='\0');
    printf("\nfine caricamento \n");
    stampaPila(&head);
    printf("\n\npremere un tasto per continuare...");
    fflush(stdin);
    getch();
    return 0;
 }

void push(struct El** head, struct El* element){
	if (&head==NULL){
		*head = element;
		element->next = NULL;
	}else{
		element->next = *head;
		*head = element;
	}
}

struct El* pop(struct El** head){
	struct El *ret = *head;
	if(&head==NULL){
		return NULL;
	}else{
		*head = ret->next;
	}
	return ret;
}

bool controlloStringa(char cifra[]){
    char numeri[11]="0123456789";
    int i,k;
    bool error=true;
    for(i=0;cifra[i]!='\0';i++){
        for(k=0;k<11;k++){
            if(cifra[i]==numeri[k]){
               error=false;
            }
        }
        if(error!=false){
            return false;
        }else{
            error=true;
        }
    }
    return true;
}

void stampaPila(struct El** head){
    struct El *ret;
    int i=1;
    printf("\n------------------------------------------------\nSTAMPA:");
    ret=pop(head);
    while(ret!=NULL){
        printf("\n valore [%d]: %d", i, ret->valore);
        i++;
        free(ret);
        ret=pop(head);
    }
    printf("\n------------------------------------------------\n");
    return;
}
