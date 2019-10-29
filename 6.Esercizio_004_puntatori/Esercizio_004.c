/*
Autore: Gabriele bagnis
Data: 22/10/2019
Es 4 puntatori: Write a program in C to show a pointer to an array which contents are pointer to structure.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>  //includo string per la funzione strlen

#define DIMNOME 50  //creo la costante DIMNOME per indicare il valore massimo da dare al nome

typedef struct emp{ //creo la struttura emp per memorizzare gli impiegati
    char* empname;  //creo un puntatore di tipo char per memorizzarne il nome dell'impiegato
    int empid;      //creo una variabile di tipo int per memorizzare l'id dell'impiegato
}Emp;

int main(){
    Emp** vett; //creo un vettore di puntatori alla struttura Emp
    int dim;    //creo la variabile dimensione per sapere quanti sono gli impiegati
    int i=0;    //creo la variabile i come contatore
    char riga[DIMNOME]; //creo la stringa riga per momorizzare il nome dell'impiegato temporaneamente
    printf("quanti impiegati ci sono?");    //chiedo quanti sono gli impiegati
    scanf("%d", &dim);  
    Emp imp[dim]; //creo un vettore di tipo Emp per memorizzare il contenuto delle strutture
    vett= (Emp**) malloc(dim*sizeof(Emp*)); //tramite l'allocazione dinamica riservo uno spazio al vettore di puntatori grande esattamente quanto serve
    for(i=0;i<dim;i++){     //ripeto il ciclo per il numero di impiegati
        printf("inserire il nome dell'impiegato (max %d caratteri)", DIMNOME);  //richiedo il nome dell'impiegato
        fflush(stdin);  //pulisco la testiera per evitare errori
        gets(riga); //leggo il nome dell'impiegato
        (imp+i)->empname= (char*) malloc(strlen(riga)*sizeof(char));    //ritaglio uno spazio in memoria grande quanto il nome dell'impiegato e lo assegno a empname
        strcpy((imp+i)->empname,riga);  //copio il nome dell'impiegato nella struttura Emp
        (imp+i)->empid=1000+i;  //assegno all'impiegato un ID
        *(vett+i)=(imp+i);  //assegno alla cella del mio vettore di puntatori il puntatore della struttura
    }
    for(i=0;i<dim;i++){ //ripeto il ciclo per il numero di impiegati
        printf("\n empid= %d \t empname= %s", (*(*(vett+i))).empid, (*(*(vett+i))).empname);    //stampo l'id e il nome dell'impiegato
    }

    free(vett); //libero lo spazio utilizzato dal vettore di strutture

    printf("\ncliccare un tasto per proseguire"); //aspetto un input da tastiera per proseguire
    fflush(stdin);  
    getch();
}