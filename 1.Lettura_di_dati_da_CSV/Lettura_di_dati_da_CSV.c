/*
Autore: Gabriele bagnis
Data: 26/09/2019
Es Csv: Creare un programma in linguaggio C che legga il file vgsales.csv e lo importi in un array di strutture.
Ogni riga contiene i campi separati da virgole, per cui puo' essere comodo creare una funzione split
che dalla riga letta ritorni la struttura valorizzata.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define L_CAMPO 50          //definizione della dimensione massima di ogni stringa della mia tabella
#define L_RIGA 300          //definizione della dimensione massima di ogni riga del mio file
#define NUMERO_RIGHE 16598  //numero righe vhe voglio leggere del mio file CSV
#define N_ELEM 11           //numero delle colonne della tabella

typedef struct Tabella{ //dichiarazione della struttura
 int Rank;
 int Year;
 char Name[L_CAMPO];
 char Platform[L_CAMPO];
 char Genre[L_CAMPO];
 char Publisher[L_CAMPO];
 float NA_Sales;
 float EU_Sales;
 float JP_Sales;
 float Other_Sales;
 float Global_Sales;
}Tabella;

void ScannerizzaTabella(Tabella dati[], int *elementi, char descrizione[][L_CAMPO]);    //dichiarazione delle funzioni
void StampaTabella(Tabella dati[], int elementi, char descrizione[][L_CAMPO]);

Tabella dati[NUMERO_RIGHE];     //dichiarazione della tabella (in questo caso l'ho dichiarata globalmente perchè nello 
                                //stack non avevo abbastanza memoria)
int main(){
    int elementi=0;        //conta il numero di elementi per evitare di stampare qualcosa che non ho letto
    char descrizione[N_ELEM][L_CAMPO];  //memorizza la descrizione delle colonne della tabella
    ScannerizzaTabella(dati,&elementi,descrizione);   //scannerizzo la tabella
    StampaTabella(dati,elementi,descrizione);        //stampo la tabella
    fflush(stdin); //pulisco l'input da testiera
    getch(); //attendo un tasto
    return 0;
}

void ScannerizzaTabella(Tabella dati[], int *elementi, char descrizione[][L_CAMPO]){
    FILE *fp;   //creo il puntatore al file
    fp=fopen("vgsales.csv", "r");   //apro il file da cui devo prendere le informazioni
    int i=-1; //lo impongo uguale a -1 perchè così la prima volta che legge una riga non la memorizza nella tabella
    char riga[L_RIGA];  //dichiaro il vettore di char dove memorizzerò una riga alla volta
    char* campo;  //dichiaro il puntatore campo di tipo char
    while(i<NUMERO_RIGHE&&fgets(riga,L_RIGA,fp)!=NULL){  //ripeto questo ciclo finchè riuscirò a leggere dal file o finchè non raggiungo la dimensione massima della tabella
        if(i!=-1){ //se i>=0 allora devo occupare le celle della tabella altrimenti memorizzo l'intestazione
            campo=strtok(riga,",");     //prelevo i campi della tabella dalla riga e li salvo
            dati[i].Rank=atoi(campo);   //strtok mi permette di dividere una stringa alla prima occorenza del secondo parametro
            campo=strtok(NULL,",");     //successivamente se al posto della stringa scrivo NULL continuerà dal punto a cui ero rimasto precedentemente
            strcpy(dati[i].Name,campo); //strtok mi restituisce un puntatore alla stringa
            campo=strtok(NULL,",");
            strcpy(dati[i].Platform,campo); //strcpy mi permette di copiare il contenuto della seconda stringa nella prima
            campo=strtok(NULL,",");
            dati[i].Year=atoi(campo);   //utilizzo atoi per trasformare una stringa in un numero intero
            campo=strtok(NULL,",");
            strcpy(dati[i].Genre,campo);
            campo=strtok(NULL,",");
            strcpy(dati[i].Publisher,campo);
            campo=strtok(NULL,",");
            dati[i].NA_Sales=atof(campo); //utilizzo atof per trasformare una stringa in un numero decimale
            campo=strtok(NULL,",");
            dati[i].EU_Sales=atof(campo);
            campo=strtok(NULL,",");
            dati[i].JP_Sales=atof(campo);
            campo=strtok(NULL,",");
            dati[i].Other_Sales=atof(campo);
            campo=strtok(NULL,",");
            dati[i].Global_Sales=atof(campo);
            *elementi=*elementi+1;      //incremento il conteggio degli elementi
        }else{              //nel caso leggo la prima riga mi salvo le decrizioni nel vettore descrizione
            campo=strtok(riga,","); 
            strcpy(descrizione[0],campo);
            campo=strtok(NULL,",");
            strcpy(descrizione[1],campo);
            campo=strtok(NULL,",");
            strcpy(descrizione[2],campo);
            campo=strtok(NULL,",");
            strcpy(descrizione[3],campo);
            campo=strtok(NULL,",");
            strcpy(descrizione[4],campo);
            campo=strtok(NULL,",");
            strcpy(descrizione[5],campo);
            campo=strtok(NULL,",");
            strcpy(descrizione[6],campo);
            campo=strtok(NULL,",");
            strcpy(descrizione[7],campo);
            campo=strtok(NULL,",");
            strcpy(descrizione[8],campo);
            campo=strtok(NULL,",");
            strcpy(descrizione[9],campo);
            campo=strtok(NULL,",");
            strcpy(descrizione[10],campo);
        }
        i++;    //incremento la i per memorizzare nella riga successiva della mia tabella
    }
    fclose(fp); //chiudo il file
    return;
}

void StampaTabella(Tabella dati[], int elementi, char descrizione[][L_CAMPO]){
    int i;  //contatore
    printf("%s\t", descrizione[0]); //stampo il primo elemento della descrizione separatamente a causa della tabulazione e dei ;
    for(i=1;i<N_ELEM;i++){ //ripeto a partire del secondo elemento del mio vettore descrizione fino al numero di campi
        printf(";%s", descrizione[i]); //stampo la descrizione
    }
    for(i=0;i<elementi;i++){    //stampo una riga alla volta della mia tabella
        printf("\n%d\t;%s;%s;%d;%s;%s;%.2f;%.2f;%.2f;%.2f;%.2f",dati[i].Rank,
        dati[i].Name,dati[i].Platform,dati[i].Year,dati[i].Genre,dati[i].Publisher,
        dati[i].NA_Sales,dati[i].EU_Sales,dati[i].JP_Sales,dati[i].Other_Sales,dati[i].Global_Sales);
    }
    return;
}