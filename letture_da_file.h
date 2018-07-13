#ifndef LETTURE_DA_FILE_H_
#define LETTURE_DA_FILE_H_

int lettura_indice_utente_loggato(FILE* file_utenti, utenti utente[], int i, int z); //FUNZIONE CHE LEGGE DAL FILE "indice_utente_loggato.txt" L'INDICE DELL'UTENTE CHE HA EFFETTUATO IL LOGIN E LO RESTITUISCE COME VALORE DI RITORNO
int lettura_artisti_da_file(FILE* file_artisti, artisti artista[], int i); //FUNZIONE CHE LEGGE IL CONTENUTO DEL FILE "Artisti.txt" E RESTITUISCE IL NUMERO DEGLI ARTISTI IN ESSO SALVATI
int lettura_utenti_da_file(FILE* file_utenti, utenti utente[], int i); //FUNZIONE CHE LEGGE IL CONTENUTO DEL FILE "Utenti.txt" E RESTITUISCE IL NUMERO DEGLI UTENTI IN ESSO SALVATI
int lettura_preferenze_da_file(FILE* file_preferenze, artisti artista[], preferenze_artisti preferenza_artista[], int i); //FUNZIONE CHE LEGGE IL CONTENUTO DEL FILE "Preferenze.txt" E RESTITUISCE IL NUMERO DELLE PREFERENZE SALVATE

#endif /* LETTURE_DA_FILE_H_ */
