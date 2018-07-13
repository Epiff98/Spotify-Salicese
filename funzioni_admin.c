#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "costanti.h"
#include "struct.h"
#include "intestazioni.h"
#include "letture_da_file.h"
#include "interfaccia_iniziale.h"
#include "funzioni_admin.h"
#include "funzioni_utente.h"

//----------------------------------------------------------- FUNZIONI DELL'INTERFACCIA ADMIN --------------------------------------------------------------//

/**
 * Procedura login_admin(): permette all'amministratore di accedere alla piattaforma spotify.
 *
 * Si acquisisce l'username dell'amministratore che intende accedere e, se corrisponde con quello predefinito ("admin"),
 * si acquisisce la password dell'utente, finche' non risulta corretta (= "Admin123")
 *
 * Eseguito l'accesso, l'utente sarà indirizzato nella sua interfaccia e qui potrà visualizzare il menù con le relative operazioni
 * che potrà eseguire.
 *
 * @param file_artisti
 * @param file_utenti
 * @param file_preferenze
 * @param utente
 * @param artista
 * @param preferenza_artista
 * @param i
 * @param scelta
 * @param z
 */

void login_admin(FILE* file_artisti, FILE* file_utenti,  FILE* file_preferenze, utenti utente[], artisti artista[], preferenze_artisti preferenza_artista[], int i, char scelta, int z)
{
	char username_ricercato[LUNG_USERNAME]; //USERNAME DELL'AMMINISTRATORE CHE DESIDERA ACCEDERE NELLA SUA AREA RISERVATA DELLA PIATTAFORMA "SPOTIFY"
	char password_ricercata[LUNG_PASSWORD]; //PASSWORD DELL'AMMINISTRATORE CHE DESIDERA ACCEDERE NELLA SUA AREA RISERVATA DELLA PIATTAFORMA "SPOTIFY", ASSOCIATA AL SUO USERNAME

//ACQUISIZIONE DELL'USERNAME DELL'AMMINISTRATORE CHE VUOLE EFFETTUARE L'ACCESSO, TALE USERNAME SARA' CONFRONTATO CON UN USERNAME PREDEFINITO "admin"
	do
	{
		printf("\n> INSERISCI USERNAME ADMIN:  ");
		scanf("%s", username_ricercato); //ACQUISIZONE DELL'USERNAME DELL'AMMINISTRATORE CHE VUOLE ACCEDERE ALLA PIATTAFORMA

		if(strcmp(username_ricercato, "admin") != 0)
			printf("\n   * USERNAME ADMIN NON VALIDO, RIPROVA!\n\n");

	}while(strcmp(username_ricercato, "admin") != 0); //RIPETE IL CICLO FINCHE' L'USERNAME INSERITO NON CORRISPONDE A QUELLO PREDEFINITO ("admin").

	if(strcmp(username_ricercato, "admin") == 0) //SE L'USERNAME INSERITO E' CORRETTO, OSSIA CORRISPONDE A QUELLO PREDEFINITO ("admin"), SI RICHIEDE DI INSERIRE LA PASSWORD ASSOCIATA
	{
	//ACQUISIZIONE DELLA PASSWORD DELL'AMMINISTRATORE CHE VUOLE EFFETTUARE L'ACCESSO, TALE PASSWORD SARA' CONFRONTATA CON UNA PASSWORD PREDEFINITA "Admin123"
		do
		{
			printf("\n> INSERISCI PASSWORD ADMIN:  ");
			scanf("%s", password_ricercata); //ACQUISIZIONE DELLA PASSWORD DELL'AMMINISTRATORE CHE VUOLE ACCEDERE ALLA PIATTAFORMA

			if(strcmp(password_ricercata, "Admin123") != 0)
				printf("\n   * PASSWORD ADMIN NON VALIDA, RIPROVA!\n\n");

		}while(!(strcmp(password_ricercata, "Admin123") == 0)); //RIPETE IL CICLO FINCHE' LA PASSWORD INSERITA NON CORRISPONDE A QUELLA PREDEFINITA ("Admin123")

	//SE IL LOGIN E' ANDATO A BUON FINE (USERNAME E PASSWORD CORRETTI):
		menu_admin(file_artisti, file_utenti, file_preferenze, utente, artista, preferenza_artista, i, scelta, z); //CHIAMATA DELLA PROCEDURA "menu_utente" CHE STAMPA A VIDEO IL MENU' CON LE DIVERSE OPERAZIONI CHE L'UTENTE PUO' FAR ESEGUIRE UNA VOLTA EFFETTUATO IL LOGIN
	}
}

/**
 * Procedura menu_admin():
 *
 * Viene stampato il menù con le 5 operazioni a disposizione dell'amministratore della piattaforma,
 * quest'ultimo sceglierà una voce tra quelle elencate inserendo un valore di scelta. Il valore della scelta
 * è un carattere numerico, si richiede, quindi, di inserire un valore compreso nel range indicato.
 * Se si inserisce una stringa o un carattere non valido verra' richiesto di reinserire il valore.
 *
 * @param file_artisti
 * @param file_utenti
 * @param file_preferenze
 * @param utente
 * @param artista
 * @param preferenza_artista
 * @param i
 * @param scelta
 * @param z
 */

void menu_admin(FILE* file_artisti, FILE* file_utenti,  FILE* file_preferenze, utenti utente[], artisti artista[], preferenze_artisti preferenza_artista[], int i, char scelta, int z)
{
	system("cls"); //PULIZIA DELLO SCHERMO
	scritta_spotify(); //CHIAMATA DELLA PROCEDURA "scritta_spotify" CHE STAMPA A VIDEO LA SCRITTA "SPOTIFY"

	printf("\n\n\t\t\t\t\t\t\t\t\t\t\tBenvenuto Admin");
	printf("\n\n\t\t\t\t\t\t\t\t\t   _______________________________________");
	printf("\n\t\t\t\t\t\t\t\t\t  |                                       |");
	printf("\n\t\t\t\t\t\t\t\t\t  |       1. VISUALIZZA LISTA UTENTI      |");
	printf("\n\t\t\t\t\t\t\t\t\t  |_______________________________________|");
	printf("\n\n\t\t\t\t\t\t\t\t\t   _______________________________________");
	printf("\n\t\t\t\t\t\t\t\t\t  |                                       |");
	printf("\n\t\t\t\t\t\t\t\t\t  |         2. AGGIUNGI UN ARTISTA        |");
	printf("\n\t\t\t\t\t\t\t\t\t  |_______________________________________|");
	printf("\n\n\t\t\t\t\t\t\t\t\t   _______________________________________");
	printf("\n\t\t\t\t\t\t\t\t\t  |                                       |");
	printf("\n\t\t\t\t\t\t\t\t\t  |        3. MODIFICA UN ARTISTA         |");
	printf("\n\t\t\t\t\t\t\t\t\t  |_______________________________________|");
	printf("\n\n\t\t\t\t\t\t\t\t\t   _______________________________________");
	printf("\n\t\t\t\t\t\t\t\t\t  |                                       |");
	printf("\n\t\t\t\t\t\t\t\t\t  |         4. ELIMINA UN ARTISTA         |");
	printf("\n\t\t\t\t\t\t\t\t\t  |_______________________________________|");
	printf("\n\n\t\t\t\t\t\t\t\t\t   _______________________________________");
	printf("\n\t\t\t\t\t\t\t\t\t  |                                       |");
	printf("\n\t\t\t\t\t\t\t\t\t  |              5. LOGOUT                |");
	printf("\n\t\t\t\t\t\t\t\t\t  |_______________________________________|");

	do
	{
		fflush(stdin); //PULIZIA DEL BUFFER DELLA TASTIERA PRIMA...
		printf("\n\n\n\t\t\t\t\t\t\t\t\t   > QUALE OPERAZIONE DESIDERI EFFETTUARE?   ");
		scanf("%c", &scelta); //ACQUISIZIONE DELLA SCELTA
		fflush(stdin); //...E DOPO L'UTILIZZO

		if(scelta < '1' || scelta > '5')
			printf("\n\n\t\t\t\t\t\t\t\t\t       * SCELTA NON VALIDA, RIPROVA!\n");

	}while(scelta < '1' || scelta > '5'); //RIPETE IL CICLO FINCHE' IL CARATTERE INSERITO NON E' VALIDO

	switch(scelta)
	{
		case '1': //"scelta"= '1' -> VISUALIZZA LISTA UTENTI
			system("cls"); //PULIZIA DELLO SCHERMO
			scritta_spotify(); //CHIAMATA DELLA PROCEDURA "scritta_spotify" CHE STAMPA A VIDEO LA SCRITTA "SPOTIFY"
			visualizza_utenti(file_artisti, file_utenti, file_preferenze, utente, artista, preferenza_artista, i, scelta, z); //CHIAMATA DELLA PROCEDURA "visualizza_utenti" CHE STAMPA A VIDEO LA LISTA DEGLI UTENTI SALVATI NEL FILE "Utenti.txt"
			return_menu_admin(file_artisti, file_utenti, file_preferenze, utente, artista, preferenza_artista, i, scelta, z); //CHIAMATA DELLA PROCEDURA "return_menu_admin" CHE PERMETTE ALL'AMMINISTRATORE DI RITORNARE AL SUO MENU' AL TERMINE DELL'OPERAZIONE ESEGUITA
			break;

		case '2': //"scelta"= '2' -> AGGIUNGI UN ARTISTA
			system("cls"); //PULIZIA DELLO SCHERMO
			scritta_spotify(); //CHIAMATA DELLA PROCEDURA "scritta_spotify" CHE STAMPA A VIDEO LA SCRITTA "SPOTIFY"
			aggiungi_artista(file_artisti, file_utenti, file_preferenze, utente, artista, preferenza_artista, i, scelta, z); //CHIAMATA DELLA PROCEDURA "aggiungi_artista" CHE PERMETTE ALL'AMMINISTRATORE DELLA PIATTAFORMA DI AGGIUNGERE UN NUOVO ARTISTA
			return_menu_admin(file_artisti, file_utenti, file_preferenze, utente, artista, preferenza_artista, i, scelta, z); //CHIAMATA DELLA PROCEDURA "return_menu_admin" CHE PERMETTE ALL'AMMINISTRATORE DI RITORNARE AL SUO MENU' AL TERMINE DELL'OPERAZIONE ESEGUITA
			break;

		case '3': //"scelta"= '3' -> MODIFICA UN ARTISTA
			system("cls"); //PULIZIA DELLO SCHERMO
			scritta_spotify(); //CHIAMATA DELLA PROCEDURA "scritta_spotify" CHE STAMPA A VIDEO LA SCRITTA "SPOTIFY"
			modifica_artista(file_artisti, file_utenti, file_preferenze, utente, artista, preferenza_artista, i, scelta, z); //CHIAMATA DELLA PROCEDURA "modifica_artista" CHE PERMETTE ALL'AMMINISTRATORE DELLA PIATTAFORMA DI MODIFICARE I DATI DI UN DETERMINATO ARTISTA INDICATO
			break;

		case '4': //"scelta"= '4' -> ELIMINA UN ARTISTA
			system("cls"); //PULIZIA DELLO SCHERMO
			scritta_spotify(); //CHIAMATA DELLA PROCEDURA "scritta_spotify" CHE STAMPA A VIDEO LA SCRITTA "SPOTIFY"
			elimina_artista(file_artisti, file_utenti, file_preferenze, utente, artista, preferenza_artista, i, scelta, z); //CHIAMATA DELLA PROCEDURA "elimina_artista" CHE PERMETTE ALL'AMMINISTRATORE DELLA PIATTAFORMA DI ELIMINARE UN DETERMINATO ARTISTA INDICATO
			break;

		case '5': //"scelta"= '5' -> LOGOUT
			interfaccia_iniziale(file_artisti, file_utenti, file_preferenze, utente, artista, preferenza_artista, i, scelta, z); //CHIAMATA DELLA PROCEDURA "interfaccia_iniziale" CHE PERMETTE ALL'AMMINISTRATORE DI USCIRE DALLA PIATTAFORMA
			break;
	}
}

/**
 * Procedura visualizza_utenti():
 *
 * Viene stampato a video, in formato tabellare, l'elenco degli utenti iscritti alla piattaforma.
 * Per ogni utente l'amministratore visualizza:
 *
 * - ID. dell'utente
 * - Nome dell'utente
 * - Cognome dell'utente
 * - Data di nascita dell'utente (GG//MM/AA)
 * - Username dell'utente
 * - Password dell'utente
 *
 * @param file_artisti
 * @param file_utenti
 * @param file_preferenze
 * @param utente
 * @param artista
 * @param preferenza_artista
 * @param i
 * @param scelta
 * @param z
 */


void visualizza_utenti(FILE* file_artisti, FILE* file_utenti,  FILE* file_preferenze, utenti utente[], artisti artista[], preferenze_artisti preferenza_artista[], int i, char scelta, int z)
{
	printf("\n\n\t\t\t\t\t\t\t\t\t   _______________________________________");
	printf("\n\t\t\t\t\t\t\t\t\t  |                                       |");
	printf("\n\t\t\t\t\t\t\t\t\t  |         VISUALIZZA LISTA UTENTI       |");
	printf("\n\t\t\t\t\t\t\t\t\t  |_______________________________________|");

	int count_utenti= 0; //VARIABILE CONTATORE CHE CONTERRA' IL NUMERO DI UTENTI SALVATI SUL FILE "Utenti.txt", CALCOLATO NELLA FUNZIONE "lettura_utenti_da_file"
	count_utenti= lettura_utenti_da_file(file_utenti, utente, i); //ASSEGNA A "count_utenti" IL VALORE RESTITUITO DALLA FUNZIONE "lettura_utenti_da_file", OSSIA IL NUMERO DEGLI UTENTI SALVATI NEL FILE "Utenti.txt"

//STAMPA DELLA LISTA DEGLI UTENTI REGISTRATI ALLA PIATTAFORMA
	printf("\n\n\n\n\t\t\t\t\tID. UTENTE|\t      NOME|\t     COGNOME|\t      DATA DI NASCITA|\t        USERNAME|\t   PASSWORD|\n\n");

	for(i=0; i<count_utenti; i++)
		printf("\t\t\t\t  %16d|%15s|%17s|%12d / %2d / %d|%18s|%18s|  \n", utente[i].id_utente, utente[i].nome_utente, utente[i].cognome_utente, utente[i].giorno_nascita, utente[i].mese_nascita, utente[i].anno_nascita, utente[i].username, utente[i].password); //STAMPA DEI DATI DELL'i-ESIMO UTENTE
}


/**
 * Procedura aggiungi_artista(): Permette all'amministratore di aggiungere un nuovo artista.
 *
 * Si assegna un ID. all'artista che verra' aggiunto (identificativo numerico);
 * Si acquisisce la stringa del nome d'arte dell'artista, verificandone la correttezza (no caratteri numerici!) e se è
 * già presente nel file;
 * si acquisisce la stringa del genere dell'artista, verificandone la correttezza (no caratteri numerici!);
 * si acquisisce la nazionalità dell'artista, verificandone la correttezza (no caratteri numerici!);
 * si acquisisce l'anno di inizio di produzione dell'artista, verificando che il valore sia compreso nel range predefinito (1901 - 2018)
 * si acquisisce la stringa della canzone popolare dell'artista, verificandone la correttezza (no caratteri numerici!);
 * si associano i contatori delle preferenze espresse per l'artista: listen, like e dislike inizializzati a 0
 *
 * Una volta aggiunto, i dati dell'artista saranno memorizzati nel file
 *
 * @param file_artisti
 * @param file_utenti
 * @param file_preferenze
 * @param utente
 * @param artista
 * @param preferenza_artista
 * @param i
 * @param scelta
 * @param z
 */

void aggiungi_artista(FILE* file_artisti, FILE* file_utenti,  FILE* file_preferenze, utenti utente[], artisti artista[], preferenze_artisti preferenza_artista[], int i, char scelta, int z)
{
	printf("\n\n\t\t\t\t\t\t\t\t\t   _______________________________________");
	printf("\n\t\t\t\t\t\t\t\t\t  |                                       |");
	printf("\n\t\t\t\t\t\t\t\t\t  |           AGGIUNGI UN ARTISTA         |");
	printf("\n\t\t\t\t\t\t\t\t\t  |_______________________________________|\n\n");

	int count_artisti= 0; //VARIABILE CONTATORE CHE CONTERRA' IL NUMERO DI ARTISTI SALVATI SUL FILE "Artisti.txt", CALCOLATO NELLA FUNZIONE "lettura_artisti_da_file"
	count_artisti= lettura_artisti_da_file(file_artisti, artista, i); //ASSEGNA A "count_artisit" IL VALORE RESTITUITO DALLA FUNZIONE "lettura_artisti_da_file", OSSIA IL NUMERO DEGLI ARTISTI SALVATI NEL FILE "Artisti.txt"

	int artista_esistente= 0; //FLAG CHE VERRA' IMPOSTATO A '1' NEL CASO IN CUI L' ARTISTA DA AGGIUNGERE, E' GIA' PRESENTE NEL FILE "Artisti.txt"

//APERTURA DEL FILE "Artisti.txt" IN MODALITA' DI SCRITTURA IN CODA ("a")
	if((file_artisti =  fopen("Artisti.txt" , "a")) == NULL)
		printf("Errore nell'apertura!\n");

	else
	{
		artista[count_artisti].id_artista= count_artisti+1; //ASSEGNAZIONE DELL'"ID. ARTISTA", UN IDENTIFICATIVO NUMERICO CHE DENOTA CIASCUN ARTISTA. SI TRATTA DI UN NUMERO PROGRESSIVO CHE PARTE DA '1'

		do
		{
			artista_esistente= 0; //RIPRISTINO DEL VALORE DI PARTENZA DEL FLAG "artista_esistente"

		//ACQUISIZIONE DEL NOME D'ARTE DEL NUOVO ARTISTA
			printf("\n\n\n> INSERISCI IL NOME D'ARTE:   ");
			scanf(" %s", artista[count_artisti].nome_artista); //ACQUISIZIONE NOME D'ARTE

			for(int j=0; j < LUNG_NOME; j++)
				artista[count_artisti].nome_artista[j]= toupper(artista[count_artisti].nome_artista[j]); //CONVERSIONE DI TUTTI I CARATTERI DELLA STRINGA (NOME ARTISTA) IN MAIUSCOLO.

		//VERIFICA ESISTENZA ARTISTA
			for(i=0; i<count_artisti; i++)
			{
				if(strcmp(artista[count_artisti].nome_artista, artista[i].nome_artista) == 0) //CONDIZIONE CHE VERIFICA SE IL NOME D'ARTE DELL'ARTISTA CHE SI VUOLE AGGIUNGERE E' GIA PRESENTE NEL FILE "Artisti.txt"
					artista_esistente= 1; //IMPOSTA IL FLAG "artista_esistente" A '1' POICHE' L'ARTISTA INDICATO E' GIA PRESENTE NEL FILE "Artista.txt"
			}

			if(artista_esistente != 0)
				printf("\n   * ARTISTA GIA' PRESENTE!");

		}while(artista_esistente != 0); //RIPETE IL CICLO FINCHE' IL VALORE DEL FLAG "artista_esistente" E' DIVERSO DA '0', OSSIA L'ARTISTA INDICATO E' GIA' PRESENTE NEL FILE "Artista.txt"

	//ACQUISIZIONE DEL GENERE DEL NUOVO ARTISTA
		int genere_errato= 0; //FLAG CHE VERRA' IMPOSTATO A '1' NEL CASO IN CUI LA STRINGA DEL GENERE INSERITO CONTENGA AL SUO INTERNO UN CARATTERE NUMERICO (non consentito!)
		do
		{
			genere_errato= 0;  //RIPRISTINO DEL VALORE DI PARTENZA DEL FLAG "genere_errato"

			printf("\n\n\n> INSERISCI IL GENERE di '%s':   ", artista[count_artisti].nome_artista);
			scanf("%s", artista[count_artisti].genere); //ACQUISIZIONE GENERE

		//VERIFICA VALIDITA' GENERE
			for(int j=0; j < LUNG_GENERE; j++)
			{
				if((isdigit(artista[count_artisti].genere[j])) == 1)  //CONDIZIONE CHE VERIFICA SE IL j-CARATTERE DELLA STRINGA INSERITA (GENERE) E' UN CARATTERE NUMERICO
				{
					genere_errato= 1; //IMPOSTA IL FLAG "genere_errato" A '1' POICHE' E' STATO RILEVATO UN CARATTERE NUMERICO (non consentito!) ALL'INTERNO DELLA STRINGA INSERITA
					j= LUNG_GENERE; //NON ABBIAMO BISOGNO DI SCORRERE TUTTI I CICLI, E' SUFFICIENTE FERMARSI ALLA PRIMA OCCORRENZA DEL CARATTERE NUMERICO
				}

				else
					artista[count_artisti].genere[j]= toupper(artista[count_artisti].genere[j]);  //CONVERSIONE DI TUTTI I CARATTERI DELLA STRINGA (GENERE) IN MAIUSCOLO
			}

			if(genere_errato != 0)
				printf("\n   * GENERE NON VALIDO, RIPROVA!");

		}while(genere_errato != 0); //RIPETE IL CICLO FINCHE' IL VALORE DEL FLAG "genere_errato" RISULTA DIVERSO DA '0', CIO' IMPLICA CHE IL GENERE INSERITO NON E' VALIDO

	//ACQUISIZIONE DELLA NAZIONALITA' DEL NUOVO ARTISTA
		int nazionalita_errata= 0; //FLAG CHE VERRA' IMPOSTATO A '1' NEL CASO IN CUI LA STRINGA DELLA NAZIONALITA' INSERITA CONTENGA AL SUO INTERNO UN CARATTERE NUMERICO (non consentito!)
		do
		{
			nazionalita_errata= 0; //RIPRISTINO DEL VALORE DI PARTENZA DEL FLAG "nazionalita_errata"

			printf("\n\n\n> INSERISCI LA NAZIONALITA' di '%s':   ", artista[count_artisti].nome_artista);
			scanf("%s", artista[count_artisti].nazionalita); //ACQUISIZIONE DELLA NAZIONALITA'

		//VERIFICA VALIDITA' NAZIONALITA'
			for(int j=0; j < LUNG_NAZIONALITA; j++)
			{
				if((isdigit(artista[count_artisti].nazionalita[j])) == 1) //CONDIZIONE CHE VERIFICA SE IL j-CARATTERE DELLA STRINGA INSERITA (NAZIONALITA') E' UN CARATTERE NUMERICO
				{
					nazionalita_errata= 1; //IMPOSTA IL FLAG "nazionalita_errata" A '1' POICHE' E' STATO RILEVATO UN CARATTERE NUMERICO (non consentito!) ALL'INTERNO DELLA STRINGA INSERITA
					j= LUNG_NAZIONALITA; //NON ABBIAMO BISOGNO DI SCORRERE TUTTI I CICLI, E' SUFFICIENTE FERMARSI ALLA PRIMA OCCORRENZA DEL CARATTERE NUMERICO
				}

				else
					artista[count_artisti].nazionalita[j]= toupper(artista[count_artisti].nazionalita[j]); //CONVERSIONE DI TUTTI I CARATTERI DELLA STRINGA (NAZIONALITA') IN MAIUSCOLO
			}

			if(nazionalita_errata != 0)
				printf("\n   * NAZIONALITA' NON VALIDA, RIPROVA!");

		}while(nazionalita_errata != 0); //RIPETE IL CICLO FINCHE' IL VALORE DEL FLAG "nazionalita_errata" RISULTA DIVERSO DA '0', CIO' IMPLICA CHE LA NAZIONALITA' INSERITA NON E' VALIDA

	//ACQUISIZIONE DELL'ANNO DI INIZIO CARRIERA DEL NUOVO ARTISTA
		do
		{
			printf("\n\n\n> INSERISCI L'ANNO DI INIZIO CARRIERA DI '%s':   ", artista[count_artisti].nome_artista);
			scanf("%d", &artista[count_artisti].anno_inizio); //ACQUISIZIONE ANNO INIZIO CARRIERA

		//VERIFICA VALIDITA' ANNO DI INIZIO CARRIERA
			if(artista[count_artisti].anno_inizio < ANNO_MIN || artista[count_artisti].anno_inizio > ANNO_MAX)
				printf("\n   * ANNO NON VALIDO! INSERISCI UN VALORE COMPRESO TRA %d E %d.", ANNO_MIN, ANNO_MAX);

		}while(artista[count_artisti].anno_inizio < ANNO_MIN || artista[count_artisti].anno_inizio > ANNO_MAX); //RIPETE IL CICLO FINCHE' L'ANNO INSERITO NON E' VALIDO: MINORE DI 1901 oppure MAGGIORE DI 2018

	//ACQUISIZIONE DELLA CANZONE POPOLARE DEL NUOVO ARTISTA
		printf("\n\n\n> INSERISCI IL TITOLO DELLA SUA CANZONE POPOLARE:   ");
		scanf("%s", artista[count_artisti].canzone); //ACQUISIZIONE DELLA CANZONE POPOLARE

		for(int j=0; j < LUNG_CANZONE; j++)
			artista[count_artisti].canzone[j]= toupper(artista[count_artisti].canzone[j]); //CONVERSIONE DI TUTTI I CARATTERI DELLA STRINGA (CANZONE) IN MAIUSCOLO

		artista[count_artisti].count_listen= 0; //ASSEGNA '0' AL CONTATORE DI "LISTEN" DEL NUOVO ARTISTA
		artista[count_artisti].count_like= 0; //ASSEGNA '0' AL CONTATORE DI "LIKE" DEL NUOVO ARTISTA
		artista[count_artisti].count_dislike= 0; //ASSEGNA '0' AL CONTATORE DI "DISLIKE" DEL NUOVO ARTISTA

		fprintf(file_artisti,"\n%d %s %s %s %d %s %d %d %d", artista[count_artisti].id_artista, artista[count_artisti].nome_artista, artista[count_artisti].genere, artista[count_artisti].nazionalita, artista[count_artisti].anno_inizio, artista[count_artisti].canzone, artista[count_artisti].count_listen, artista[count_artisti].count_like, artista[count_artisti].count_dislike); //SALVATAGGIO SUL FILE "Artisti.txt" DEI DATI DEL NUOVO ARTISTA

		printf("\n\n\n***************** ARTISTA AGGIUNTO CORRETTAMENTE! *****************\n");
	}
	fclose(file_artisti); //CHIUSURA DEL FILE
}


/**
 * Procedura modifica_artista(): Permette all'amministratore di modificare i campi di un artista.
 *
 * Verrà stampata la lista degli artisti salvati. L'utente sceglierà l'artista che intende modificare
 * inserendo l'id associato ad esso, verificandone la presenza di tale id. nella lista.
 * L'amministratore potrà poi scegliere quale campo modificare tra quelli indicati, inserendo un valore di scelta.
 * Il valore della scelta è un carattere numerico, si richiede, quindi, di inserire un valore compreso nel range indicato.
 * Se si inserisce una stringa o un carattere non valido verra' richiesto di reinserire il valore.
 * Si verifica la correttezza di ogni campo modificato.
 *
 * Verranno poi salvati su file i dati dell'artista con le varie modifiche apportate.
 *
 * @param file_artisti
 * @param file_utenti
 * @param file_preferenze
 * @param utente
 * @param artista
 * @param preferenza_artista
 * @param i
 * @param scelta
 * @param z
 */

void modifica_artista(FILE* file_artisti, FILE* file_utenti,  FILE* file_preferenze, utenti utente[], artisti artista[], preferenze_artisti preferenza_artista[], int i, char scelta, int z)
{
	printf("\n\n\t\t\t\t\t\t\t\t\t   _______________________________________");
	printf("\n\t\t\t\t\t\t\t\t\t  |                                       |");
	printf("\n\t\t\t\t\t\t\t\t\t  |          MODIFICA UN ARTISTA          |");
	printf("\n\t\t\t\t\t\t\t\t\t  |_______________________________________|");

	visualizza_artisti(file_artisti, file_utenti, file_preferenze, utente, artista, preferenza_artista, i, z); //CHIAMATA DELLA PROCEDURA "visualizza_artisti" CHE STAMPA A VIDEO LA LISTA DEGLI ARTISTI SALVATI NEL FILE "Artisti.txt"

	int count_artisti= 0; //VARIABILE CONTATORE CHE CONTERRA' IL NUMERO DI ARTISTI SALVATI SUL FILE "Artisti.txt", CALCOLATO NELLA FUNZIONE "lettura_artisti_da_file"
	count_artisti= lettura_artisti_da_file(file_artisti, artista, i); //ASSEGNA A "count_artisit" IL VALORE RESTITUITO DALLA FUNZIONE "lettura_artisti_da_file", OSSIA IL NUMERO DEGLI ARTISTI SALVATI NEL FILE "Artisti.txt"

//ACQUISIZIONE DELL'ID. DELL'ARTISTA DA MODIFICARE
	int id_artista_ricercato= 0; //VARIABILE CHE CONTERRA' L'ID DELL'ARTISTA CHE L'AMMINISTRATORE VUOLE MODIFICARE

	printf("\n\n\n> INSERISCI L'ID DELL'ARTISTA CHE VUOI MODIFICARE:   ");
	scanf("%d", &id_artista_ricercato); //ACQUISIZIONE ID. DELL'ARTISTA

	int id_artista_trovato= 0; //FLAG CHE VERRA' IMPOSTATO A '1' NEL CASO IN CUI L'ID DELL'ARTISTA INSERITO DALL'UTENTE E' PRESENTE NEL FILE "Artisti.txt"

//VERIFICA PRESENZA ARTISTA
	for(i=0; i<count_artisti; i++)
	{
		if(id_artista_ricercato == artista[i].id_artista) //CONDIZIONE CHE VERIFICA SE L'ID DELL'ARTISTA INSERITO (DA MODIFICARE) E' PRESENTE NEL FILE "Artisti.txt"
			id_artista_trovato= 1; //IMPOSTA IL FLAG "id_artista_trovato" A '1' POICHE' L'ID DELL'ARTISTA INSERITO DALL'UTENTE A CUI ASSEGNARE LA PREFERENZA E' STATO TROVATO NEL FILE "Artisti.txt"
	}

	if(id_artista_trovato == 0) //SE AL TERMINE DI TUTTI I CICLI, IL VALORE DEL FLAG "id_artista_trovato" RISULTA ANCORA '0', SIGNIFICA CHE L'ID DELL'ARTISTA INSERITO DALL'UTENTE NON E'PRESENTE NEL FILE "Artisti.txt".
	{
		printf("\n\n   * ARTISTA NON TROVATO!\n\n");

		printf("\n\n1. RIPROVA\n");
		printf("\n2. RITORNA AL MENU'");

		do
		{
			fflush(stdin); //PULIZIA DEL BUFFER DELLA TASTIERA PRIMA...
			printf("\n\n\n> QUALE OPERAZIONE DESIDERI EFFETTUARE?   ");
			scanf("%c", &scelta); //ACQUISIZIONE DELLA SCELTA
			fflush(stdin); //...E DOPO L'UTILIZZO

			if(scelta < '1' || scelta > '2')
				printf("\n   * INPUT NON VALIDO, RIPROVA!");

		}while(scelta < '1' || scelta > '2'); //RIPETE IL CICLO FINCHE' IL CARATTERE INSERITO NON E' VALIDO

		switch(scelta)
		{
			case '1': //"scelta"= '1' -> RIPROVA
				system("cls"); //PULIZIA DELLO SCHERMO
				scritta_spotify(); //CHIAMATA DELLA PROCEDURA "scritta_spotify" CHE STAMPA A VIDEO LA SCRITTA "SPOTIFY"
				modifica_artista(file_utenti, file_artisti, file_preferenze, utente, artista, preferenza_artista, i, scelta, z); //CHIAMATA DELLA PROCEDURA "modifica_artista" CHE PERMETTE ALL'AMMINISTRATORE DELLA PIATTAFORMA DI MODIFICARE I DATI DI UN DETERMINATO ARTISTA INDICATO
				break;

			case '2': //"scelta"= '2' -> RITORNA AL MENU
				system("cls"); //PULIZIA DELLO SCHERMO
				scritta_spotify(); //CHIAMATA DELLA PROCEDURA "scritta_spotify" CHE STAMPA A VIDEO LA SCRITTA "SPOTIFY"
				menu_admin(file_utenti, file_artisti, file_preferenze, utente, artista, preferenza_artista, i, scelta, z); //CHIAMATA DELLA PROCEDURA "menu_admin" CHE PERMETTE ALL'AMMINISTRATORE DI RITORNARE AL SUO MENU' PER ESEGUIRE UNA NUOVA OPERAZIONE
				break;
		}
	}

	else
	{
		for(i=0; i<count_artisti; i++)
		{
			if(id_artista_ricercato == artista[i].id_artista) //CONDIZIONE CHE VERIFICA SE L'ID. DELL'i-ESIMO ARTISTA PRESENTE NEL FILE E' UGUALE ALL'ID. DELL'ARTISTA INSERITO (DA MODIFICARE)
			{
			//MODIFICA DELL'ARTISTA
				printf("\n\n\nMODIFICA: ");
				printf("\n\n\t1. NOME  |  2. GENERE  |  3. NAZIONALITA'  |  4. ANNO INIZIO  |  5. CANZONE POPOLARE\n");

				do
				{
					fflush(stdin); //PULIZIA DEL BUFFER DELLA TASTIERA PRIMA...
					printf("\n\n> QUALE CAMPO VUOI MODIFICARE?   ");
					scanf("%c", &scelta); //ACQUISIZIONE DELLA SCELTA
					fflush(stdin); //...E DOPO L'UTILIZZO

					if(scelta < '1' || scelta > '5')
						printf("\n   * INPUT NON VALIDO, RIPROVA!\n");

				}while(scelta < '1' || scelta > '5'); //RIPETE IL CICLO FINCHE' IL CARATTERE INSERITO NON E' VALIDO

				int nome_errato= 0; //FLAG CHE VERRA' IMPOSTATO A '1' NEL CASO IN CUI LA STRINGA DEL NOME INSERITO CONTENGA AL SUO INTERNO UN CARATTERE NUMERICO (non consentito!)
				int genere_errato= 0; //FLAG CHE VERRA' IMPOSTATO A '1' NEL CASO IN CUI LA STRINGA DEL GENERE INSERITO CONTENGA AL SUO INTERNO UN CARATTERE NUMERICO (non consentito!)
				int nazionalita_errata= 0; //FLAG CHE VERRA' IMPOSTATO A '1' NEL CASO IN CUI LA STRINGA DELLA NAZIONALITA' INSERITA CONTENGA AL SUO INTERNO UN CARATTERE NUMERICO (non consentito!)

				switch(scelta)
				{
					case '1': //"scelta"= '1' -> MODIFICA "NOME ARTISTA"
						do
						{
							nome_errato= 0; //RIPRISTINO DEL VALORE DI PARTENZA DEL FLAG "nome_errato"

							printf("\n\n> INSERISCI IL NUOVO NOME:   ");
							scanf("%s", artista[i].nome_artista); //ACQUISIZIONE DEL NUOVO NOME

						//VERIFICA VALIDITA' NOME
							for(int j=0; j < LUNG_NOME; j++)
							{
								if(isdigit(artista[i].nome_artista[j]) == 1) //CONDIZIONE CHE VERIFICA SE IL j-CARATTERE DELLA STRINGA INSERITA (NOME ARTISTA) E' UN CARATTERE NUMERICO
								{
									nome_errato= 1; //IMPOSTA IL FLAG "nome_errato" A '1' POICHE' E' STATO RILEVATO UN CARATTERE NUMERICO (non consentito!) ALL'INTERNO DELLA STRINGA INSERITA
									j= LUNG_NOME; //NON ABBIAMO BISOGNO DI SCORRERE TUTTI I CICLI, E' SUFFICIENTE FERMARSI ALLA PRIMA OCCORRENZA DEL CARATTERE NUMERICO
								}

								else
									artista[i].nome_artista[j]= toupper(artista[i].nome_artista[j]); //CONVERSIONE DI TUTTI I CARATTERI DELLA STRINGA (NOME ARTISTA) IN MAIUSCOLO
							}

							if(nome_errato != 0)
								printf("\n   * NOME NON VALIDO, RIPROVA!\n");

						}while(nome_errato != 0); //RIPETE IL CICLO FINCHE' IL VALORE DEL FLAG "nome_errato" RISULTA DIVERSO DA '0', CIO' IMPLICA CHE IL NOME INSERITO NON E' VALIDO

						break;

					case '2': //"scelta"= '2' -> MODIFICA "GENERE"
						do
						{
							genere_errato= 0; //RIPRISTINO DEL VALORE DI PARTENZA DEL FLAG "genere_errato"

							printf("\n\n> INSERISCI IL NUOVO GENERE: ");
							scanf("%s", artista[i].genere); //ACQUISIZIONE DEL NUOVO GENERE

						//VERIFICA VALIDITA' GENERE
							for(int j=0; j < LUNG_GENERE; j++)
							{
								if(isdigit(artista[i].genere[j]) == 1) //CONDIZIONE CHE VERIFICA SE IL j-CARATTERE DELLA STRINGA INSERITA (GENERE) E' UN CARATTERE NUMERICO
								{
									genere_errato= 1; //IMPOSTA IL FLAG "genere_errato" A '1' POICHE' E' STATO RILEVATO UN CARATTERE NUMERICO (non consentito!) ALL'INTERNO DELLA STRINGA INSERITA
									j= LUNG_GENERE; //NON ABBIAMO BISOGNO DI SCORRERE TUTTI I CICLI, E' SUFFICIENTE FERMARSI ALLA PRIMA OCCORRENZA DEL CARATTERE NUMERICO
								}

								else
									artista[i].genere[j]= toupper(artista[i].genere[j]); //CONVERSIONE DI TUTTI I CARATTERI DELLA STRINGA (GENERE) IN MAIUSCOLO
							}

							if(genere_errato != 0)
								printf("\n   * GENERE NON VALIDO, RIPROVA!\n");

						}while(genere_errato != 0); //RIPETE IL CICLO FINCHE' IL VALORE DEL FLAG "genere_errato" RISULTA DIVERSO DA '0', CIO' IMPLICA CHE IL GENERE INSERITO NON E' VALIDO

						break;

					case '3': //"scelta"= '3' -> MODIFICA "NAZIONALITA'"
						do
						{
							nazionalita_errata= 0; //RIPRISTINO DEL VALORE DI PARTENZA DEL FLAG "nazionalita_errata"

							printf("\n\n> INSERISCI LA NUOVA NAZIONALITA':   ");
							scanf("%s", artista[i].nazionalita); //ACQUISIZIONE DELLA NUOVA NAZIONALITA'

						//VERIFICA VALIDITA' NAZIONALITA'
							for(int j=0; j < LUNG_NAZIONALITA; j++)
							{
								if(isdigit(artista[i].nazionalita[j]) == 1) //CONDIZIONE CHE VERIFICA SE IL j-CARATTERE DELLA STRINGA INSERITA (NAZIONALITA') E' UN CARATTERE NUMERICO
								{
									nazionalita_errata= 1; //IMPOSTA IL FLAG "nazionalita_errata" A '1' POICHE' E' STATO RILEVATO UN CARATTERE NUMERICO (non consentito!) ALL'INTERNO DELLA STRINGA INSERITA
									j= LUNG_NAZIONALITA; //NON ABBIAMO BISOGNO DI SCORRERE TUTTI I CICLI, E' SUFFICIENTE FERMARSI ALLA PRIMA OCCORRENZA DEL CARATTERE NUMERICO
								}

								else
									artista[i].nazionalita[j]= toupper(artista[i].nazionalita[j]); //CONVERSIONE DI TUTTI I CARATTERI DELLA STRINGA (NAZIONALITA') IN MAIUSCOLO
							}

							if(nazionalita_errata != 0)
								printf("\n   * NAZIONALITA' NON VALIDA, RIPROVA!\n");

						}while(nazionalita_errata != 0); //RIPETE IL CICLO FINCHE' IL VALORE DEL FLAG "nazionalita_errata" RISULTA DIVERSO DA '0', CIO' IMPLICA CHE LA NAZIONALITA' INSERITA NON E' VALIDA

						break;

					case '4': //"scelta" = '4' -> MODIFICA "ANNO INIZIO PRODUZIONE"
						do
						{
							printf("\n\n> INSERISCI L'ANNO DI INIZIO CARRIERA:   ");
							scanf("%d", &artista[i].anno_inizio); //ACQUISIZIONE DEL NUOVO ANNO DI INIZIO CARRIERA

							if(artista[i].anno_inizio < ANNO_MIN || artista[i].anno_inizio > ANNO_MAX)
								printf("\n   * ANNO NON VALIDO! INSERISCI UN VALORE COMPRESO TRA %d E %d.\n", ANNO_MIN, ANNO_MAX);

						}while(artista[i].anno_inizio < ANNO_MIN || artista[i].anno_inizio > ANNO_MAX); //RIPETE IL CICLO FINCHE' L'ANNO INSERITO NON E' VALIDO: MINORE DI '1901' oppure MAGGIORE DI '2018'

						break;

					case '5': //"scelta"= '5' -> MODIFICA "CANZONE POPOLARE"
						printf("\n\n> INSERISCI LA NUOVA CANZONE POPOLARE:   ");
						scanf("%s", artista[i].canzone); //ACQUISIZIONE DELLA NUOVA CANZONE POPOLARE

						for(int j=0; j < LUNG_CANZONE; j++)
							artista[i].canzone[j]= toupper(artista[i].canzone[j]); //CONVERSIONE DI TUTTI I CARATTERI DELLA STRINGA (CANZONE) IN MAIUSCOLO

						break;
				}

			//APERTURA DEL FILE "Artisti.txt" IN MODALITA' DI SCRITTURA ("w")
				if((file_artisti =  fopen("Artisti.txt" , "w")) == NULL)
					printf("Errore nell'apertura!\n");

				else
				{
				//SALVATAGGIO DELLE MODIFICHE APPORTATE
					for(i=0; i<count_artisti; i++)
						fprintf(file_artisti,"\n%d %s %s %s %d %s %d %d %d", artista[i].id_artista, artista[i].nome_artista, artista[i].genere, artista[i].nazionalita, artista[i].anno_inizio, artista[i].canzone, artista[i].count_listen, artista[i].count_like, artista[i].count_dislike); //SALVATAGGIO SUL FILE "Artisti.txt" I DATI DELL'i-ESIMO ARTISTA

					printf("\n\n\n***************** ARTISTA MODIFICATO CORRETTAMENTE! *****************\n");
				}
				fclose(file_artisti); //CHIUSURA DEL FILE

				return_menu_admin(file_artisti, file_utenti, file_preferenze, utente, artista, preferenza_artista, i, scelta, z); //CHIAMATA DELLA PROCEDURA "return_menu_admin" CHE PERMETTE ALL'AMMINISTRATORE DI RITORNARE AL SUO MENU' AL TERMINE DELL'OPERAZIONE ESEGUITA
				break;
			}
		}
	}
}


/**
 * Procedura elimina_artista(): Permette all'amministratore di eliminare un artista.
 *
 * Verrà stampata la lista degli artisti salvati. L'utente sceglierà l'artista che intende eliminare
 * inserendo l'id associato ad esso, verificandone la presenza di tale id. nella lista.
 *
 * Verranno salvati nuovamente tutti fli artisti su file, eccetto l'artista che l'amministratore ha deciso di eliminare
 * di eliminare
 *
 * @param file_artisti
 * @param file_utenti
 * @param file_preferenze
 * @param utente
 * @param artista
 * @param preferenza_artista
 * @param i
 * @param scelta
 * @param z
 */

void elimina_artista(FILE* file_artisti, FILE* file_utenti,  FILE* file_preferenze, utenti utente[], artisti artista[], preferenze_artisti preferenza_artista[], int i, char scelta, int z)
{
	printf("\n\n\t\t\t\t\t\t\t\t\t   _______________________________________");
	printf("\n\t\t\t\t\t\t\t\t\t  |                                       |");
	printf("\n\t\t\t\t\t\t\t\t\t  |           ELIMINA UN ARTISTA          |");
	printf("\n\t\t\t\t\t\t\t\t\t  |_______________________________________|");

	visualizza_artisti(file_artisti, file_utenti, file_preferenze, utente, artista, preferenza_artista, i, z); //CHIAMATA DELLA PROCEDURA "visualizza_artisti" CHE STAMPA A VIDEO LA LISTA DEGLI ARTISTI SALVATI NEL FILE "Artisti.txt"

	int count_artisti= 0; //VARIABILE CONTATORE CHE CONTERRA' IL NUMERO DI ARTISTI SALVATI SUL FILE "Artisti.txt", CALCOLATO NELLA FUNZIONE "lettura_artisti_da_file"
	count_artisti= lettura_artisti_da_file(file_artisti, artista, i); //ASSEGNA A "count_artisit" IL VALORE RESTITUITO DALLA FUNZIONE "lettura_artisti_da_file", OSSIA IL NUMERO DEGLI ARTISTI SALVATI NEL FILE "Artisti.txt"

//ACQUISIZIONE DELL' ID DELL'ARTISTA DA ELIMINARE
	int id_artista_ricercato= 0; //VARIABILE CHE CONTERRA' L'ID DELL'ARTISTA CHE L'AMMINISTRATORE VUOLE ELIMINARE

	printf("\n\n\n> INSERISCI L'ID DELL'ARTISTA CHE VUOI ELIMINARE:   ");
	scanf("%d", &id_artista_ricercato); //ACQUISIZIONE ID. DELL ARTISTA

	int id_artista_trovato= 0; //FLAG CHE VERRA' IMPOSTATO A '1' NEL CASO IN CUI L'ID DELL'ARTISTA INSERITO DALL'UTENTE E' PRESENTE NEL FILE "Artisti.txt"

//VERIFICA PRESENZA ARTISTA
	for(i=0; i<count_artisti; i++)
	{
		if(id_artista_ricercato == artista[i].id_artista) //CONDIZIONE CHE VERIFICA SE L'ID DELL'ARTISTA INSERITO (DA ELIMINARE) E' PRESENTE NEL FILE "Artisti.txt"
			id_artista_trovato= 1; //IMPOSTA IL FLAG "id_artista_trovato" A '1' POICHE' L'ID DELL'ARTISTA INSERITO (DA ELIMINARE) E' STATO TROVATO NEL FILE "Artisti.txt"
	}

	if(id_artista_trovato == 0) //SE AL TERMINE DI TUTTI I CICLI, IL VALORE DEL FLAG "id_artista_trovato" RISULTA ANCORA '0', SIGNIFICA CHE L'ID DELL'ARTISTA INSERITO DALL'UTENTE NON E'PRESENTE NEL FILE "Artisti.txt".
	{
		printf("\n\n   * ARTISTA NON TROVATO!\n\n");

		printf("\n\n1. RIPROVA\n");
		printf("\n2. RITORNA AL MENU'");

		do
		{
			fflush(stdin); //PULIZIA DEL BUFFER DELLA TASTIERA PRIMA...
			printf("\n\n\n> QUALE OPERAZIONE DESIDERI EFFETTUARE?   ");
			scanf("%c", &scelta); //ACQUISIZIONE DELLA SCELTA
			fflush(stdin); //...E DOPO L'UTILIZZO

			if(scelta < '1' || scelta > '2')
				printf("\n   * INPUT NON VALIDO, RIPROVA!");

		}while(scelta < '1' || scelta > '2'); //RIPETE IL CICLO FINCHE' IL CARATTERE INSERITO NON E' VALIDO

		switch(scelta)
		{
			case '1': //"scelta"= '1' -> RIPROVA
				system("cls"); //PULIZIA DELLO SCHERMO
				scritta_spotify(); //CHIAMATA DELLA PROCEDURA "scritta_spotify" CHE STAMPA A VIDEO LA SCRITTA "SPOTIFY"
				elimina_artista(file_artisti, file_utenti, file_preferenze, utente, artista, preferenza_artista, i, scelta, z); //CHIAMATA DELLA PROCEDURA "elimina_artista" CHE PERMETTE ALL'AMMINISTRATORE DELLA PIATTAFORMA DI ELIMINARE UN DETERMINATO ARTISTA INDICATO
				break;

			case '2': //"scelta"= '2' -> RITORNA AL MENU'
				system("cls"); //PULIZIA DELLO SCHERMO
				scritta_spotify(); //CHIAMATA DELLA PROCEDURA "scritta_spotify" CHE STAMPA A VIDEO LA SCRITTA "SPOTIFY"
				menu_admin(file_artisti, file_utenti, file_preferenze, utente, artista, preferenza_artista, i, scelta, z); //CHIAMATA DELLA PROCEDURA "menu_admin" CHE PERMETTE ALL'AMMINISTRATORE DI RITORNARE AL SUO MENU' PER ESEGUIRE UNA NUOVA OPERAZIONE
				break;
		}
	}

	else
	{
	//APERTUTRA DEL FILE "Artisti.txt" IN MODALITA' DI SCRITTURA ("w")
		if((file_artisti=  fopen("Artisti.txt" , "w")) == NULL)
			printf("Errore nell'apertura!\n");

		else
		{
		//SALVATAGGIO SUL FILE "Artisti.txt" DEI DATI DI TUTTI ARTISTI, ECCETTO L'ARTISTA, INDICATO DALL'AMMINISTRATORE, DA ELIMINARE
			for(i=0; i<count_artisti; i++)
			{
				if(id_artista_ricercato != artista[i].id_artista) //CONDIZIONE CHE VERIFICA SE L'ID DELL'ARTISTA INSERITO (DA ELIMINARE) E' PRESENTE NEL FILE "Artisti.txt"
					fprintf(file_artisti,"\n%d %s %s %s %d %s %d %d %d", artista[i].id_artista, artista[i].nome_artista, artista[i].genere, artista[i].nazionalita, artista[i].anno_inizio, artista[i].canzone, artista[i].count_listen, artista[i].count_like, artista[i].count_dislike); //SALVATAGGIO SUL FILE "Artisti.txt" I DATI DELL'i-ESIMO ARTISTA
			}
		}
		fclose(file_artisti); //CHIUSURA DEL FILE

		count_artisti= 0; //RIPRISTINO DEL VALORE DI PARTENZA DELLA VARIABILE "count_artisti"
		count_artisti= lettura_artisti_da_file(file_artisti, artista, i); //ASSEGNA A "count_artisit" IL VALORE RESTITUITO DALLA FUNZIONE "lettura_artisti_da_file", OSSIA IL NUMERO DEGLI ARTISTI SALVATI NEL FILE "Artisti.txt"

	//APERTURA DEL FILE "Artisti.txt" IN MODALITA' DI SCRITTURA ("w")
		if((file_artisti=  fopen("Artisti.txt" , "w")) == NULL)
			printf("Errore nell'apertura!\n");

		else
		{
		//RI-ASSEGNAZIONE DEGLI ID. AGLI ARTISTI SALVATI SUL FILE "Artisti.txt"
			for(i=0; i<count_artisti; i++)
			{
				artista[i].id_artista= i+1; //RI-ASSEGNAZIONE DEL NUOVO "ID ARTISTA" ALL'i-ESIMO ARTISTA
				fprintf(file_artisti,"\n%d %s %s %s %d %s %d %d %d", artista[i].id_artista, artista[i].nome_artista, artista[i].genere, artista[i].nazionalita, artista[i].anno_inizio, artista[i].canzone, artista[i].count_listen, artista[i].count_like, artista[i].count_dislike); //SALVATAGGIO SUL FILE "Artisti.txt" DEI DATI DELL'i-ESIMO ARTISTA
			}

			printf("\n\n\n***************** ARTISTA ELIMINATO CORRETTAMENTE! *****************\n");
		}
		fclose(file_artisti); //CHIUSURA DEL FILE

		return_menu_admin(file_artisti, file_utenti, file_preferenze, utente, artista, preferenza_artista, i, scelta, z); //CHIAMATA DELLA PROCEDURA "return_menu_admin" CHE PERMETTE ALL'AMMINISTRATORE DI RITORNARE AL SUO MENU' AL TERMINE DELL'OPERAZIONE ESEGUITA
	}
}


/**
 * Procedura return_menu_admin():
 *
 * Al termine di ogni operazione eseguita, verrà richiesto all'admin se desidera ritornare al suo menu' iniziale
 * inserendo un valore di scelta.  Il valore della scelta è un carattere numerico, si richiede, quindi, di inserire un valore
 * uguale a quello impostato "0". Se si inserisce una stringa o un carattere non valido verra' richiesto di reinserire il valore.
 *
 * @param file_artisti
 * @param file_utenti
 * @param file_preferenze
 * @param utente
 * @param artista
 * @param preferenza_artista
 * @param i
 * @param scelta
 * @param z
 */

void return_menu_admin(FILE* file_artisti, FILE* file_utenti,  FILE* file_preferenze, utenti utente[], artisti artista[], preferenze_artisti preferenza_artista[], int i, char scelta, int z)
{
	do
	{
		fflush(stdin); //PULIZIA DEL BUFFER DELLA TASTIERA PRIMA...
		printf("\n\n\n> PREMI '0' PER RITORNARE AL MENU':   ");
		scanf("%c", &scelta); //ACQUISIZIONE DELLA SCELTA
		fflush(stdin); //...E DOPO L'UTILIZZO

		if(scelta != '0')
			printf("\n   * INPUT NON VALIDO, RIPROVA!");

		else
			menu_admin(file_artisti, file_utenti, file_preferenze, utente, artista, preferenza_artista, i, scelta, z); //CHIAMATA DELLA PROCEDURA "menu_admin" CHE PERMETTE ALL'AMMINISTRATORE DI RITORNARE AL SUO MENU' PER ESEGUIRE UNA NUOVA OPERAZIONE

	}while(scelta != '0'); //RIPETE IL CICLO FINCHE' IL CARATTERE INSERITO NON E' VALIDO
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------//
