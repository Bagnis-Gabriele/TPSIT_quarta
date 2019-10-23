/*
Autore: Gabriele bagnis
Data: 22/10/2019
Es 3 puntatori: Write a program in C to Calculate the length of the string using a pointer.
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define DIM 300

int main(){
    char str[DIM];  //creo la stringa
    printf("inserire un stringa (max %d caratteri)", DIM);  //chiedo di inserire la stringa
    gets(str);
    bool fine=true; //creo la variabile dove mi segno se la stringa 
    int cont=0; //creo la variabile contatore e la inizializzo
    int i;  //creo il contatore
    for(i=0;fine;i++){  //ripeto finchè non finisce la stringa
        if(*(str+i)=='\0'){ //controllo se il carattere è quello di fine stringa
            fine=false; //se il carattere è quello della fine della stringa finisco il ciclo
        }
        cont++; //incremento il contatore
    }
    printf("la stringa è lunga %d caratteri", cont);    //stampo la lunghezza della stringa

    fflush(stdin);  //aspetto un input da tastiera per proseguire
    getch();
}