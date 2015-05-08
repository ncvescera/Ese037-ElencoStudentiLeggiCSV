#include <stdio.h>
#include <stdlib.h>

// Definisci le costanti
#define MAX_STRLEN 30
#define MAX_FNAMELEN 255

// Definisci il tipo di dato struct s_studente
struct s_studente {
    char nome[MAX_STRLEN+1];
    char cognome[MAX_STRLEN+1];
    int eta;
    char classe[MAX_STRLEN+1];
};

// Definisci studente come struct s_studente
typedef struct s_studente studente;

int main(int argc, char** argv) {
    // Dichiara le variabili locali
    studente s;
    int i;
    FILE *inf;
    char fileName[MAX_FNAMELEN+1];
    char temporanea[MAX_STRLEN+1];  /* Questa variabile verrà impiegata per leggere
                                     * delle stringhe che non saranno effettivamente
                                     * utilizzate.
                                     */ 
    
    // Codice per la richiesta del nome del file
    printf("Inserisci il nome del file da cui leggere i dati: ");
    scanf("%s", fileName);
    
    // Codice per l'apertura del file, la lettura e la stampa a schermo
    inf = fopen(fileName, "r");
    if(inf == NULL) {
        fprintf(stderr, "ERRORE: Impossibile aprire il file %s in lettura\n", fileName);
        exit(1);
    }
    
    // La prima riga contiene l'instestazione: la leggo e non ne faccio nulla.
    fscanf(inf, "%[^;];%[^;];%[^;];%[^;\n]\n", 
                    temporanea,
                    temporanea,
                    temporanea,
                    temporanea);
    
    i=0;
    while(!feof(inf)) {
        i++;
        fscanf(inf, "%[^;];%[^;];%d;%[^;\n]\n",
                s.nome,
                s.cognome,
                &(s.eta),
                s.classe);
        printf("Studente %d\nNome: %s\nCognome: %s\nEta': %d\nClasse: %s\n\n",
                i,
                s.nome,
                s.cognome,
                s.eta,
                s.classe);
    }
    fclose(inf);
    
    return (EXIT_SUCCESS);
}

