#include <stdio.h>
#include <stdlib.h>

#define N 3
#define MAX_STRLEN 30

struct s_studente{
    char nome[MAX_STRLEN+1];
    char cognome[MAX_STRLEN+1];
    unsigned int eta;
    char classe[MAX_STRLEN+1];
};
typedef struct s_studente studente;
int main(int argc, char** argv) {
    int i;
    FILE *puntafile;
    char fname[MAX_STRLEN+1];
    char temp[MAX_STRLEN+1];
    studente elenco;
        
    printf("Inserisci il nome del file da leggere: ");
    scanf("%s",fname);
    
    puntafile=fopen(fname,"r");
    if(puntafile==NULL){
        printf("Errore! Impossibile leggere il file %s\n",fname);
        exit(-1);
    }
    else
        puts("Sto leggendo il file ...\n");
    
    fscanf(puntafile,"%[^;];%[^;];%[^;];%[^;\n]\n",temp,temp,temp,temp);
    i=0;
    while(!feof(puntafile)){
        fscanf(puntafile,"%[^;];%[^;];%d;%[^;\n]\n",elenco.nome,elenco.cognome,&(elenco.eta),elenco.classe);
        
        printf("Studente: %d\nNome: %s\nCognome: %s\nEtà: %d\nClasse: %s\n\n",i+1,elenco.nome,elenco.cognome,elenco.eta,elenco.classe);
        i++;
    }
    fclose(puntafile);
    return (EXIT_SUCCESS);
}

