/**
 * @file letture_da_file
 *
 * @brief Libreria per la lettura dei contenuti dei file.
 *
 * La libreria letture_da_file è stata implementata per permettere la lettura
 * dei contenuti dei 4 file utilizzati.
 * Con le funzioni in essa contenute verranno letti i dati degli artisti, utenti e preferenze presenti all'interno
 * dei rispettivi file e per ciascuno di essi restituire il numero di elementi salvati.
 * Inoltre, permette di tener traccia dell'indice corrispondente all'utente che ha effettuato il login alla piattaforma.
 *
 * @authors Andrea De Matteis, Marco Epifani, Giorgio Calcagnile
 */

#ifndef LETTURE_DA_FILE_H_
#define LETTURE_DA_FILE_H_

/**
 * La funzione "lettura_indice_utente_loggato" permette di leggere dal file "indice_utente_loggato.txt"
 * l'indice dell'utente che ha effettuato il login.
 *
 * @return "z" l'indice corrispondente all'utente loggato
 */

int lettura_indice_utente_loggato(FILE* file_utenti, utenti utente[], int i, int z); //FUNZIONE CHE LEGGE DAL FILE "indice_utente_loggato.txt" L'INDICE DELL'UTENTE CHE HA EFFETTUATO IL LOGIN E LO RESTITUISCE COME VALORE DI RITORNO

/**
 * La funzione "lettura_artisti_da_file" permette di leggere dal file "Artisti.txt" i dati degli artisti salvati
 *
 * @return il numero di artisti salvati sul file
 */

int lettura_artisti_da_file(FILE* file_artisti, artisti artista[], int i); //FUNZIONE CHE LEGGE IL CONTENUTO DEL FILE "Artisti.txt" E RESTITUISCE IL NUMERO DEGLI ARTISTI IN ESSO SALVATI

/**
 * La funzione "lettura_utenti_da_file" permette di leggere dal file "Utenti.txt" i dati degli utenti salvati
 *
 * @return il numero di utenti salvati sul file
 */

int lettura_utenti_da_file(FILE* file_utenti, utenti utente[], int i); //FUNZIONE CHE LEGGE IL CONTENUTO DEL FILE "Utenti.txt" E RESTITUISCE IL NUMERO DEGLI UTENTI IN ESSO SALVATI

/**
 * La funzione "lettura_preferenze_da_file" permette di leggere dal file "Preferenze.txt" i dati delle preferenze salvate
 *
 * @return il numero di preferenze salvate sul file
 */

int lettura_preferenze_da_file(FILE* file_preferenze, artisti artista[], preferenze_artisti preferenza_artista[], int i); //FUNZIONE CHE LEGGE IL CONTENUTO DEL FILE "Preferenze.txt" E RESTITUISCE IL NUMERO DELLE PREFERENZE SALVATE

#endif /* LETTURE_DA_FILE_H_ */
