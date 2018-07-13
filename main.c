/**
 * @file main.c
 *
 * @brief Main del programma.
 *
 * Le funzionalita' della piattaforma sono implementate mediante l'utilizzo di 7 librerie delle quali due,
 * costanti.h e struct.h, sono riservate a contenere rispettivamente la definizione delle costanti simboliche
 * utilizzate nel programma (valori di determinati elementi) e le struct per memorizzare le informazioni relative agli utenti,
 * agli artisti e alle preferenze; le restanti 5 implementano le funzionalita' vere e proprie che l'utente o l'amministratore
 * della piattaforma possono far eseguire.
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "costanti.h"
#include "struct.h"
#include "intestazioni.h"
#include "interfaccia_iniziale.h"

int main(void)
{
	FILE* file_utenti= NULL; //DICHIARAZIONE & INIZIALIZZAZIONE DELLA VARIABILE "file_utenti" PUNTATORE A FILE
	FILE* file_artisti= NULL; //DICHIARAZIONE & INIZIALIZZAZIONE DELLA VARIABILE "file_artisti" PUNTATORE A FILE
	FILE* file_preferenze= NULL; //DICHIARAZIONE & INIZIALIZZAZIONE DELLA VARIABILE "file_preferenze" PUNTATORE A FILE

	preferenze_artisti preferenza_artista[N_PREFERENZE]; //ARRAY "preferenza_artista[]" DI TIPO  "preferenze_artisti" CON DIMENSIONE "N_PREFERENZE" (= max 100)
	utenti utente[N_UTENTI]; //ARRAY "utente[]" DI TIPO "utenti" CON DIMENSIONE "N_UTENTI" (= max 100)
    artisti artista[N_ARTISTI]; //ARRAY "artista[]" DI TIPO "artisti" CON DIMENSIONE "N_ARTISTI" (= max 100)
    int i= 0; //DICHIARAZIONE & INIZIALIZZAZIONE DELL'INDICE DEGLI ARRAY "i"
    char scelta= 0; //DICHIARAZIONE DELLA VARIABILE "scelta", DESTINATA A CONTENERE UN CARATTERE (NUMERICO), INSERITO DALL'UTENTE (o ADMIN), ASSOCIATO ALLA FUNZIONALITA', PROPOSTA NEL MENU', CHE L'UTENTE DESIDERA FAR ESEGUIRE. (N.B.: SE SI INSERISCE UNA STRINGA, VIENE PRESO IN CONSIDERAZIONE SOLO IL 1° CARATTERE DELLA STRINGA)
    int z= 0;  //DICHIARAZIONE & INIZIALIZZAZIONE DELL'INDICE "z" UTILIZZATO PER MEMORIZZARE SUL FILE "indice_utente_loggato" L'INDICE DELL'UTENTE CHE HA EFFETTUATO IL LOGIN

    interfaccia_iniziale(file_artisti, file_utenti, file_preferenze, utente, artista, preferenza_artista, i, scelta, z); //CHIAMATA DELLA PROCEDURA "interfaccia iniziale"
    system("pause");
}
