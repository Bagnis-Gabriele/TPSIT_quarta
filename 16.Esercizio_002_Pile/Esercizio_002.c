/*
Autore: Gabriele bagnis
Data: 19/11/2019
Es 2 Pile: Scrivere un programma che chieda all’utente una stringa composta da parentesi aperte e chiuse: 
(,),[,],{,} e che verifichi se le coppie e l’ordine delle (,),[,],{,} sono corretti. Utilizzare uno stack.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct El{
    char valore;
    struct El* next;
}El;

struct El* pop(struct El** head);
void push(struct El** head, struct El* element);
bool controlloParentesi(struct El** head);

int main(){
    struct El* head;
    struct El* element;
    char stringa[1000];
    printf("\nInserire la stringa:  ");
    fflush(stdin);
    scanf("%s", stringa);
    int i=0;
    do{
        element = (struct El*) malloc(sizeof(struct El));
        element->valore=stringa[i];
        i++;
        push(&head,element);
    }while(stringa[i]!='\0');
    printf("\nfine caricamento \n");
    if(controlloParentesi(&head)){
        printf("le parentesi sono giuste");
    }else{
        printf("le parentesi sono errate");
    }
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

bool controlloParentesi(struct El** head){
    struct El *ret;
    char c;
    int t,q,g; //tonde, quadre, graffe
    t=0;
    q=0;
    g=0;
    ret=pop(head);
    while(ret!=NULL){
        c=ret->valore;
        if(c=='('){
            t++;
        }
        if(c=='['){
            q++;
        }
        if(c=='{'){
            g++;
        }
        if(c==')'){
            t--;
        }
        if(c==']'){
            q--;
        }
        if(c=='}'){
            g--;
        }
        free(ret);
        ret=pop(head);
    }
    if(t==0&&q==0&&g==0){
        return true;
    }
    return false;
}
