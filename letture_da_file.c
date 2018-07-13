#include <stdio.h>
#include <stdlib.h>

#include "costanti.h"
#include "struct.h"

int lettura_indice_utente_loggato(FILE* file_utenti, utenti utente[], int i, int z)
{
	FILE* file_indice= NULL; //DICHIARAZIONE & INIZIALIZZAZIONE DELLA VARIABILE "file_indice" PUNTATORE A FILE

//APERTURA DEL FILE "indice_utente_loggato.txt" IN MODALITA' DI LETTURA ("r")
	if((file_indice=  fopen("indice_utente_loggato.txt" , "r")) == NULL)
		printf("Errore nell'apertura!\n");

	else
	{
		while(!feof(file_indice))
			fscanf(file_indice, "%d", &z); //LETTURA DAL FILE DELL'INDICE DELL'UTENTE CHE HA EFFETTUATO IL LOGIN
	}
	fclose(file_indice); //CHIUSURA DEL FILE

	return z; //RESTITUISCE IL VALORE DI "z", L'INDICE DELL'UTENTE CHE HA EFFETTUATO IL LOGIN
}

int lettura_utenti_da_file(FILE* file_utenti, utenti utente[], int i)
{
	int count_utenti= 0; //VARIABILE CONTATORE CHE CONTERRA' IL NUMERO DI UTENTI SALVATI SUL FILE "Utenti.txt"

//APERTURA DEL FILE "Utenti.txt" IN MODALITA' DI LETTURA ("r")
	if((file_utenti=  fopen("Utenti.txt" , "r")) == NULL)
		printf("Errore nell'apertura!\n");

	else
	{
		i=0; //AZZERAMENTO DELL'INDICE "i"
		rewind(file_utenti); //RIAVVOLGIMENTO DELLO STREAM, RIPORTA IL PUNTATORE ALL'INIZIO DEL FILE

	//CONTEGGIO DEGLI UTENTI SALVATI SUL FILE "Utenti.txt"
		while(!feof(file_utenti))
		{
			fscanf(file_utenti,"%d %s %s %d %d %d %s %s", &utente[i].id_utente, utente[i].nome_utente, utente[i].cognome_utente, &utente[i].giorno_nascita, &utente[i].mese_nascita, &utente[i].anno_nascita, utente[i].username, utente[i].password); //LETTURA DAL FILE "Utenti.txt" DEI DATI DELL'i-ESIMO UTENTE
			count_utenti++; //INCREMENTO UNITARIO DEL CONTATORE DEGLI UTENTI SALVATI
			i++; //INCREMENTO UNITARIO DELL'INDICE DELL'UTENTE
		}
	}
	fclose(file_utenti); //CHIUSURA DEL FILE

	return count_utenti; //RESTITUISCE IL NUMERO DEGLI UTENTI SALVATI SUL FILE "Utenti.txt"
}

int lettura_artisti_da_file(FILE* file_artisti, artisti artista[], int i)
{
	int count_artisti= 0; //VARIABILE CONTATORE CHE CONTERRA' IL NUMERO DI ARTISTI SALVATI SUL FILE "Artisti.txt"

//APERTURA DEL FILE "Artisti.txt" IN MODALITA' DI LETTURA ("r")
	if((file_artisti=  fopen("Artisti.txt" , "r")) == NULL)
		printf("Errore nell'apertura!\n");

	else
	{
		i= 0; //AZZERAMENTO DELL'INDICE DELL'INDICE "i"
		rewind(file_artisti); //RIAVVOLGIMENTO DELLO STREAM, RIPORTA IL PUNTATORE ALL'INIZIO DEL FILE

	//CONTEGGIO DEL NUMERO DI ARTISTI SALVATI SUL FILE "Artisti.txt"
		while(!feof(file_artisti))
		{
			fscanf(file_artisti,"%d %s %s %s %d %s %d %d %d", &artista[i].id_artista, artista[i].nome_artista, artista[i].genere, artista[i].nazionalita, &artista[i].anno_inizio, artista[i].canzone, &artista[i].count_listen, &artista[i].count_like, &artista[i].count_dislike); //LETTURA DAL FILE "Artisti.txt" DEI DATI DELL'i-ESIMO ARTISTA
			count_artisti++; //INCREMENTO UNITARIO DEL CONTATORE DEGLI ARTISTI SALVATI
			i++; //INCREMENTO UNITARIO DELL'INDICE DELL'ARTISTA
		}
	}
	fclose(file_artisti); //CHIUSURA DEL FILE

	return count_artisti; //RESTITUISCE IL NUMERO DI ARTISTI SALVATI SUL FILE "Artisti.txt"
}

int lettura_preferenze_da_file(FILE* file_preferenze, artisti artista[], preferenze_artisti preferenza_artista[], int i)
{
	int count_preferenze= 0; //VARIABILE CONTATORE CHE CONTERRA' IL NUMERO DI PREFERENZE SALVATE SUL FILE "Preferenze.txt"

//APERTURA DEL FILE "Preferenze.txt" IN MODALITA' DI LETTURA ("r")
	if((file_preferenze=  fopen("Preferenze.txt" , "r")) == NULL)
		printf("Errore nell'apertura!\n");

	else
	{
		i= 0; //AZZERAMENTO DELL' INDICE "i"
		rewind(file_preferenze); //RIAVVOLGIMENTO DEL FILE, RIPORTA IL PUNTATORE ALL'INIZIO DEL FILE

	//CONTEGGIO DEL NUMERO DI PREFERENZE SALVATE SUL FILE "Preferenze.txt"
		while(!feof(file_preferenze))
		{
			fscanf(file_preferenze,"%d %s %s %s", &preferenza_artista[i].id_preferenza, preferenza_artista[i].username_utente, preferenza_artista[i].nome_artista, preferenza_artista[i].preferenza); //LETTURA DAL FILE "Preferenze.txt" DELLE PREFERENZE SALVATE
			count_preferenze++; //INCREMENTO UNITARIO DEL CONTATORE DELLE PREFERENZE SALVATE
			i++; //INCREMENTO UNITARIO DELL'INDICE DELLA PREFERENZA
		}
	}
	fclose(file_preferenze); //CHIUSURA DEL FILE

	return count_preferenze; //RESTITUISCE IL NUMERO DI PREFERENZE SALVATE SUL FILE "Preferenze.txt"
}
