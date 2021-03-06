#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "costanti.h"
#include "struct.h"
#include "intestazioni.h"
#include "letture_da_file.h"
#include "interfaccia_iniziale.h"
#include "funzioni_utente.h"

//--------------------------------------------------------------- FUNZIONI DELL'INTERFACCIA UTENTE ---------------------------------------------------------//

/**
 * Procedura signup(): permette all'utente di iscriversi alla piattaforma spotify.
 *
 * Al momento dell'iscrizione si assegna un ID. all'utente che intende registrarsi (identificativo numerico);
 * si acquisisce la stringa del nome dell'utente, verificandone la correttezza (no caratteri numerici!);
 * si acquisisce la stringa del cognome dell'utente, verificandone la correttezza (no caratteri numerici!);
 * si acquisisce il mese di nascita dell'utente, verificando che sia compreso tra i limiti imposti;
 * si acquisisce il giorno di nascita dell'utente, verificando se rispetta i limiti imposti dipendenti dal mese ad esso associato;
 * si acquisisce l'anno di nascita dell'utente, verificando che sia compreso tra i limiti imposti;
 * si acquisisce l'username dell'utente, verificandone il rispetto della lunghezza massima imposta;
 * si acquisisce la password dell'utente, verificandone il rispetto dei vincoli imposti relativi alla lunghezza e il formato dei caratteri.
 *
 * A registrazione effettuata i dati dell'utente saranno memorizzati nel file.
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

void signup(FILE* file_artisti, FILE* file_utenti, FILE* file_preferenze, utenti utente[], artisti artista[], preferenze_artisti preferenza_artista[], int i, char scelta, int z)
{
//APERTURA DEL FILE "Utenti.txt" IN MODALITA' DI SCRITTURA IN CODA ("a")
	if((file_utenti =  fopen("Utenti.txt" , "a")) == NULL)
		printf("Errore nell'apertura!\n");

	else
	{
		int count_utenti= 0; //VARIABILE CONTATORE CHE CONTERRA' IL NUMERO DI UTENTI SALVATI NEL FILE "Utenti.txt", CALCOLATO NELLA FUNZIONE "lettura_utenti_da_file".
		count_utenti= lettura_utenti_da_file(file_utenti, utente, i); //ASSEGNA A "count_utenti" IL VALORE RESTITUITO DALLA FUNZIONE "lettura_utenti_da_file", OSSIA IL NUMERO DEGLI UTENTI SALVATI NEL FILE "Utenti.txt".

		utente[count_utenti].id_utente= count_utenti + 1; //ASSEGNAZIONE DELL'"ID UTENTE" AL NUOVO UTENTE DA REGISTRARE, UN IDENTIFICATIVO NUMERICO CHE DENOTA CIASCUN UTENTE REGISTRATO. SI TRATTA DI UN VALORE PROGRESSIVO CHE PARTE DA '1'.

	//ACQUISIZIONE DEL "NOME" DEL NUOVO UTENTE DA REGISTRARE
		int nome_errato= 0; //FLAG CHE VERRA' IMPOSTATO A '1' NEL CASO IN CUI LA STRINGA DEL NOME, DEL NUOVO UTENTE DA REGISTRARE, CONTENGA AL SUO INTERNO UN CARATTERE NUMERICO (non consentito!).
		do
		{
			nome_errato= 0; //RIPRISTINO DEL VALORE DI PARTENZA DEL FLAG "nome_errato".

			printf("\n\n\n> INSERISCI IL NOME:   ");
			scanf("%s", utente[count_utenti].nome_utente); //ACQUISIZIONE DEL NOME.

		//VERIFICA VALIDITA' NOME
			for(int j=0; j < LUNG_NOME; j++)
			{
				if((isdigit(utente[count_utenti].nome_utente[j])) == 1) //CONDIZIONE CHE VERIFICA SE IL j-CARATTERE DELLA STRINGA INSERITA (NOME UTENTE) E' UN CARATTERE NUMERICO.
				{
					nome_errato= 1; //IMPOSTA IL FLAG "nome_errato" A '1' POICHE' E' STATO RILEVATO UN CARATTERE NUMERICO (non consentito!) ALL'INTERNO DELLA STRINGA INSERITA.
					j= LUNG_NOME;	//NON ABBIAMO BISOGNO DI SCORRERE TUTTI I CICLI, E' SUFFICIENTE FERMARSI ALLA PRIMA OCCORRENZA DEL CARATTERE NUMERICO.
				}

				else
					utente[count_utenti].nome_utente[j]= toupper(utente[count_utenti].nome_utente[j]); //CONVERSIONE DI TUTTI I CARATTERI DELLA STRINGA (NOME UTENTE) IN MAIUSCOLO.
			}

			if(nome_errato != 0)
				printf("\n   * NOME NON VALIDO, RIPROVA!");

		}while(nome_errato != 0); //RIPETE IL CICLO FINCHE' IL VALORE DEL FLAG "nome_errato" RISULTA DIVERSO DA '0', CIO' IMPLICA CHE IL NOME DELL'UTENTE NON E' VALIDO.

	//ACQUISIZIONE DEL "COGNOME" DEL NUOVO UTENTE DA REGISTRARE
		int cognome_errato= 0; //FLAG CHE VERRA' IMPOSTATO A '1' NEL CASO IN CUI LA STRINGA DEL COGNOME, DEL NUOVO UTENTE DA REGISTRARE, CONTENGA AL SUO INTERNO UN CARATTERE NUMERICO (non consentito!).
		do
		{
			cognome_errato= 0; //RIPRISTINO DEL VALORE DI PARTENZA DEL FLAG "cognome_errato".

			printf("\n\n\n> INSERISCI IL COGNOME:   ");
			scanf("%s", utente[count_utenti].cognome_utente); //ACQUISIZIONE DEL COGNOME.

		//VERIFICA VALIDITA' COGNOME
			for(int j=0; j < LUNG_COGNOME; j++)
			{
				if((isdigit(utente[count_utenti].cognome_utente[j])) == 1) //CONDIZIONE CHE VERIFICA SE IL j-CARATTERE DELLA STRINGA INSERITA (COGNOME UTENTE) E' UN CARATTERE NUMERICO.
				{
					cognome_errato= 1; //IMPOSTA IL FLAG "cognome_errato" A '1' POICHE' E' STATO RILEVATO UN CARATTERE NUMERICO (non consentito!) ALL'INTERNO DELLA STRINGA INSERITA.
					j= LUNG_COGNOME; //NON ABBIAMO BISOGNO DI SCORRERE TUTTI I CICLI, E' SUFFICIENTE FERMARSI ALLA PRIMA OCCORRENZA DEL CARATTERE NUMERICO.
				}

				else
					utente[count_utenti].cognome_utente[j]= toupper(utente[count_utenti].cognome_utente[j]); //CONVERSIONE DI TUTTI I CARATTERI DELLA STRINGA (COGNOME UTENTE) IN MAIUSCOLO.
			}

			if(cognome_errato != 0)
				printf("\n   * COGNOME NON VALIDO, RIPROVA!");

		}while(cognome_errato != 0); //RIPETE IL CICLO FINCHE' IL VALORE DEL FLAG "cognome_errato" RISULTA DIVERSO DA '0', CIO' IMPLICA CHE IL COGNOME DELL'UTENTE NON E' VALIDO.

	//ACQUISIZIONE DELLA "DATA DI NASCITA" DEL NUOVO UTENTE DA REGISTRARE
		printf("\n\n\nDATA DI NASCITA: ");
		do
		{
			printf("\n\n\t> INSERISCI IL MESE DI NASCITA:   ");
			scanf("%d", &utente[count_utenti].mese_nascita); //ACQUISIZIONE DEL MESE DI NASCITA

		//VERIFICA VALIDITA' MESE DI NASCITA
			if(utente[count_utenti].mese_nascita < MESE_MIN || utente[count_utenti].mese_nascita > MESE_MAX) //CONDIZIONE CHE VERIFICA SE IL VALORE DEL MESE INSERITO NON E' VALIDO, OSSIA: MINORE DI '1' oppure MAGGIORE DI '12'
				printf("\n\t   * MESE NON VALIDO! INSERISCI UN VALORE COMPRESO TRA %d E %d.\n", MESE_MIN, MESE_MAX);

		}while(utente[count_utenti].mese_nascita < MESE_MIN || utente[count_utenti].mese_nascita > MESE_MAX); //RIPETE IL CICLO FINCHE' IL VALORE DEL MESE INSERITO NON E' VALIDO

	//ACQUISIZIONE DEL "GIORNO DI NASCITA" DEL NUOVO UTENTE DA REGISTRARE
		if(utente[count_utenti].mese_nascita == 2) //CONDIZIONE CHE VERIFICA SE IL VALORE DEL MESE INSERITO E' UGUALE A '2' (= FEBBRAIO: range 1 - 28 gg)
		{
			do
			{
				printf("\n\n\t> INSERISCI IL GIORNO DI NASCITA:   ");
				scanf("%d", &utente[count_utenti].giorno_nascita); //ACQUISIZIONE DEL GIORNO DI NASCITA

			//VERIFICA VALIDITA' GIORNO DI NASCITA
				if(utente[count_utenti].giorno_nascita < 1 || utente[count_utenti].giorno_nascita > 28) //CONDIZIONE CHE VERIFICA SE IL VALORE DEL GIORNO INSERITO NON E' VALIDO, OSSIA: MINORE DI '1' oppure MAGGIORE DI '28'
					printf("\n\t   * GIORNO NON VALIDO! INSERISCI UN VALORE COMPRESO TRA 1 E 28.\n");

			}while(utente[count_utenti].giorno_nascita < 1 || utente[count_utenti].giorno_nascita > 28); //RIPETE IL CICLO FINCHE' IL VALORE DEL GIORNO INSERITO NON E' VALIDO
		}

		else if(utente[count_utenti].mese_nascita == 4 || utente[count_utenti].mese_nascita == 6 || utente[count_utenti].mese_nascita == 9 || utente[count_utenti].mese_nascita == 11) //CONDIZIONE CHE VERIFICA SE IL VALORE DEL MESE INSERITO E' UGUALE A '4' (= APRILE), '6' (= GIUGNO), '9' (= SETTEMBRE) oppure '11' (= NOVEMBRE) (range: 1 - 30 gg)
		{
			do
			{
				printf("\n\n\t> INSERISCI GIORNO DI NASCITA:   ");
				scanf("%d", &utente[count_utenti].giorno_nascita); //ACQUISIZIONE DEL GIORNO DI NASCITA

			//VERIFICA VALIDITA' GIORNO DI NASCITA
				if(utente[count_utenti].giorno_nascita < 1 || utente[count_utenti].giorno_nascita > 30) //CONDIZIONE CHE VERIFICA SE IL VALORE DEL GIORNO INSERITO NON E' VALIDO, OSSIA: MINORE DI '1' oppure MAGGIORE DI '30'
				   printf("\n\t   * GIORNO NON VALIDO! INSERISCI UN VALORE COMPRESO TRA 1 E 30.\n");

			}while(utente[count_utenti].giorno_nascita < 1 || utente[count_utenti].giorno_nascita > 30); //RIPETE IL CICLO FINCHE' IL VALORE DEL GIORNO INSERITO NON E' VALIDO
		}

		else if(utente[count_utenti].mese_nascita == 1 || utente[count_utenti].mese_nascita == 3 || utente[count_utenti].mese_nascita == 5 || utente[count_utenti].mese_nascita == 7 || utente[count_utenti].mese_nascita == 8 || utente[count_utenti].mese_nascita == 10 || utente[count_utenti].mese_nascita == 12) //CONDIZIONE CHE VERIFICA SE IL VALORE DEL MESE INSERITO E' UGUALE A '1' (= GENNAIO), '3' (= MARZO), '5' (= MAGGIO), '7' (= LUGLIO), '8' (= AGOSTO), '10' (= OTTOBRE) oppure "12" (= DICEMBRE) (range: 1 - 31 gg)
		{
			do
			{
				printf("\n\n\t> INSERISCI IL GIORNO DI NASCITA:   ");
				 scanf("%d", &utente[count_utenti].giorno_nascita); //ACQUISIZIONE DEL GIORNO DI NASCITA

			//VERIFICA VALIDITA' GIORNO DI NASCITA
				if(utente[count_utenti].giorno_nascita < 1 || utente[count_utenti].giorno_nascita > 31) //CONDIZIONE CHE VERIFICA SE IL VALORE DEL GIORNO INSERITO NON E' VALIDO, OSSIA: MINORE DI '1' oppure MAGGIORE DI '31'
				   printf("\n\t   * GIORNO NON VALIDO! INSERISCI UN VALORE COMPRESO TRA 1 E 31.\n");

			}while(utente[count_utenti].giorno_nascita < 1 || utente[count_utenti].giorno_nascita > 31); //RIPETE IL CICLO FINCHE' IL VALORE DEL GIORNO INSERITO NON E' VALIDO
		}

	//ACQUISIZIONE DELL'"ANNO DI NASCITA" DEL NUOVO UTENTE DA REGISTRARE
		do
		{
			printf("\n\n\t> INSERISCI L'ANNO DI NASCITA:   ");
			scanf("%d", &utente[count_utenti].anno_nascita); //ACQUISIZIONE DELL'ANNO DI NASCITA

		//VERIFICA VALIDITA' ANNO DI NASCITA
			if(utente[count_utenti].anno_nascita < ANNO_MIN || utente[count_utenti].anno_nascita > ANNO_MAX) //CONDIZIONE CHE VERIFICA SE IL VALORE DELL'ANNO INSERITO NON E' VALIDO, OSSIA: MINORE DI '1901' oppure MAGGIORE DI '2018'
				printf("\n\t   * ANNO NON VALIDO! INSERISCI UN VALORE COMPRESO TRA %d E %d.\n", ANNO_MIN, ANNO_MAX);

		}while(utente[count_utenti].anno_nascita < ANNO_MIN || utente[count_utenti].anno_nascita > ANNO_MAX); //RIPETE IL CICLO FINCHE' IL VALORE DELL'ANNO INSERITO NON E' VALIDO

	//ACQUISIZIONE DELL'"USERNAME" DEL NUOVO UTENTE DA REGISTRARE
		int lung_username_inserito= 0; //VARIABILE CHE CONTERRA' LA LUNGHEZZA EFFETTIVA DELL'USERNAME INSERITO, IL NUMERO DI CARATTERI DI CUI E' COMPOSTA LA STRINGA
		int username_esistente= 0; //FLAG CHE VERRA' IMPOSTATO A '1' NEL CASO IN CUI L'USERNAME INSERITO, DELL'UTENTE DA REGISTRARE, E' GIA' USATO DA UN'ALTRO UTENTE PRECEDENTEMENTE REGISTRATO

		printf("\n\n\n- NOTA USERNAME: Numero max caratteri: %d.", LUNG_USERNAME);
		do
		{
			username_esistente= 0; //RIPRISTINO DEL VALORE DI PARTENZA DEL FLAG "username_esistente"

			printf("\n\n> INSERISCI L'USERNAME:   ");
			scanf("%s",	utente[count_utenti].username); //ACQUISIZIONE DELL'USERNAME

			lung_username_inserito= strlen(utente[count_utenti].username); //DETERMINA IL NUMERO DI CARATTERI DI CUI E' COMPOSTA LA STRINGA INSERITA (USERNAME UTENTE)

		//VERIFICA VALIDITA' USERNAME
			if(lung_username_inserito > LUNG_USERNAME) //CONDIZIONE CHE VERIFICA SE IL NUMERO DI CARATTERI DELL'USERNAME INSERITO E' MAGGIORE DELLA MASSIMA LUNGHEZZA PREDEFINITA (max 15 caratteri)
				printf("\n   * USERNAME NON VALIDO! INSERISCI MAX %d CARATTERI.\n", LUNG_USERNAME);

		//VERIFICA UNIVOCITA' USERNAME
			for(i=0; i<count_utenti; i++)
			{
				if(strcmp(utente[count_utenti].username, utente[i].username) == 0) //CONDIZIONE CHE VERIFICA SE L'USERNAME DEL NUOVO UTENTE DA REGISTRARE E' UGUALE A QUELLO DELL'i-ESIMO UTENTE SALVATO NEL FILE (gia' registrato)
					username_esistente= 1; //IMPOSTA IL FLAG "utente_esistente" A '1' POICHE' L'USERNAME INSERITO E' STATO GIA' IN PRECENDENZA ASSOCIATO AD UN ALTRO UTENTE REGISTRATO
			}

			if(username_esistente != 0)
				printf("\n   * USERNAME GIA' IN USO!\n");

		}while(lung_username_inserito > LUNG_USERNAME || username_esistente != 0); //RIPETE IL CICLO FINCHE' LA LUNGHEZZA DELL'USERNAME INSERITO E' MAGGIORE DELLA LUNGHEZZA PREDEFINITA oppure IL VALORE DEL FLAG "utente_esistente" RISULTA DIVERSO DA '0', OSSIA APPARTIENE AD UN ALTRO UTENTE SALVATO

	//ACQUISIZIONE DELLA "PASSWORD" DEL NUOVO UTENTE DA REGISTRARE
		int count_maiuscole= 0; //VARIABILE CONTATORE CHE CONTERRA' IL NUMERO DI LETTERE MAIUSCOLE PRESENTI NELLA STRINGA "PASSWORD"
		int count_numeri= 0; //VARIABILE CONTATORE CHE CONTERRA' IL NUMERO DI CIFRE NUMERICHE PRESENTI NELLA STRINGA "PASSWORD"
		int lung_password_inserita= 0; //VARIABILE CHE CONTERRA' LA LUNGHEZZA EFFETTIVA DELLA PASSWORD INSERITA, IL NUMERO DI CARATTERI DI CUI E' COMPOSTA LA STRINGA

		printf("\n\n\n- NOTA PASSWORD: Numero caratteri compreso tra %d e %d, con almeno una maiuscola e almeno un numero.", LUNG_PASSWORD/2, LUNG_PASSWORD);
		do
		{
			count_maiuscole= 0; //AZZERAMENTO DELLA VARIABILE "count_maiuscole"
			count_numeri= 0; //AZZERAMENTO DELLA VARIABILE "count_numeri"

			printf("\n\n> INSERISCI LA PASSWORD:   ");
			scanf("%s", utente[count_utenti].password); //ACQUISIZIONE DELLA PASSWORD

			lung_password_inserita= strlen(utente[count_utenti].password);  //DETERMINA IL NUMERO DI CARATTERI DI CUI E' COMPOSTA LA PASSWORD INSERITA

		//VERIFICA VALIDITA' PASSWORD
			for(int j=0; j < lung_password_inserita; j++)
			{
				count_numeri= count_numeri + isdigit(utente[count_utenti].password[j]); //CONTEGGIO DELLE CIFRE NUMERICHE PRESENTI NELLA PASSWORD INSERITA
				count_maiuscole= count_maiuscole + isupper(utente[count_utenti].password[j]); //CONTEGGIO DELLE LETTERE MAIUSCOLE PRESENTI NELLA PASSWORD INSERITA

				if((count_numeri > 0) && (count_maiuscole > 0))
					j= lung_password_inserita; //NON ABBIAMO BISOGNO DI SCORRERE TUTTI I CICLI SE SONO STATE GIA' RILEVATE UNA LETTERA MAIUSCOLA E UNA CIFRA NUMERICA ALL'INTERNO DELLA STRINGA INSERITA (PASSWORD)
			}

			if((lung_password_inserita < (LUNG_PASSWORD / 2)) || (lung_password_inserita > LUNG_PASSWORD)) //CONDIZIONE CHE VERIFICA SE LA LUNGHEZZA DELLA PASSWORD NON E' COMPRESA TRA 5 e 10 CIFRE
				printf("\n   * PASSWORD NON VALIDA! INSERIRE UN NUMERO DI CARATTERI COMPRESO TRA %d E %d.\n", LUNG_PASSWORD/2, LUNG_PASSWORD);

			if(count_numeri	==	0) //CONDIZIONE CHE VERIFICA SE LA PASSWORD INSERITA NON PRESENTA AL SUO INTERNO NEANCHE UNA CIFRA NUMERICA
				printf("\n   * PASSWORD NON VALIDA! INSERIRE ALMENO UN NUMERO.\n");

			if(count_maiuscole == 0) //CONDIZIONE CHE VERIFICA SE LA PASSWORD INSERITA NON PRESENTA AL SUO INTERNO NEANCHE UNA LETTERA MAIUSCOLA
				printf("\n   * PASSWORD NON VALIDA! INSERIRE ALMENO UN CARATTERE MAIUSCOLO.\n");

		}while(!((count_numeri > 0) && (count_maiuscole > 0) && (lung_password_inserita >= (LUNG_PASSWORD / 2)) && (lung_password_inserita <= LUNG_PASSWORD))); //RIPETE IL CICLO FINCHE' I VINCOLI IMPOSTI SULLA SINTASSI DELLA PASSWORD NON SONO RISPETTATI

		fprintf(file_utenti, "\n%d %s %s %d %d %d %s %s", utente[count_utenti].id_utente, utente[count_utenti].nome_utente, utente[count_utenti].cognome_utente, utente[count_utenti].giorno_nascita,  utente[count_utenti].mese_nascita, utente[count_utenti].anno_nascita, utente[count_utenti].username, utente[count_utenti].password); //SALVATAGGIO SUL FILE "Utenti.txt" DI TUTTI I DATI INSERITI E REGISTRAZIONE DEL NUOVO UTENTE EFFETTUATA!

		printf("\n\n\n***************** ISCRIZIONE EFFETTUATA CORRETTAMENTE! *****************\n");
	}
	fclose(file_utenti); //CHIUSURA DEL FILE

//POSSIBILITA' DI EFFETTUARE IL LOGIN
	do
	{
		fflush(stdin); //PULIZIA DEL BUFFER DELLA TASTIERA PRIMA...
		printf("\n\n\n> ORA PREMI '0' PER ACCEDERE:   ");
		scanf("%c", &scelta); //ACQUISIZIONE DELLA SCELTA
		fflush(stdin); //...E DOPO L'UTILIZZO

		if(scelta == '0') //CONDIZIONE CHE VERIFICA SE IL VALORE DELLA SCELTA E' UGUALE A '0'
		{
			system("cls");
			scritta_spotify(); //CHIAMATA DELLA PROCEDURA "scritta_spotify" CHE STAMPA A VIDEO LA SCRITTA "SPOTIFY"
			scritta_login(); //CHIAMATA DELLA PROCEDURA "scritta_login" CHE STAMPA A VIDEO LA SCRITTA "LOGIN"
			login_utente(file_artisti, file_utenti, file_preferenze, utente, artista, preferenza_artista, i, scelta, z); //CHIAMATA DELLA PROCEDURA "login_utente" CHE PERMETTE ALL'UTENTE APPENA REGISTRATO DI EFFETTUARE L'ACCESSO ALLA PIATTAFORMA "SPOTIFY", INSERENDO IL PROPRIO USERNAME E PASSWORD
		}

		else
			printf("\n   * INPUT NON VALIDO, RIPROVA!");

	}while(scelta != '0'); //RIPETE IL CICLO FINCHE' IL CARATTERE INSERITO NON E' VALIDO
}

/**
 * Procedura login_utente(): permette all'utente di accedere alla piattaforma spotify.
 *
 * Si acquisisce l'username dell'utente che intende accedere e, se presente nel file, si acquisisce la password dell'utente,
 * finche' non risulta corretta
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

void login_utente(FILE* file_artisti, FILE* file_utenti,  FILE* file_preferenze, utenti utente[], artisti artista[], preferenze_artisti preferenza_artista[], int i, char scelta, int z)
{
	int count_utenti= 0; //VARIABILE CONTATORE CHE CONTERRA' IL NUMERO DI UTENTI SALVATI NEL FILE "Utenti.txt", CALCOLATO NELLA FUNZIONE "lettura_utenti_da_file"
	count_utenti= lettura_utenti_da_file(file_utenti, utente, i); //ASSEGNA A "count_utenti" IL VALORE RESTITUITO DALLA FUNZIONE "lettura_utenti_da_file", OSSIA IL NUMERO DEGLI UTENTI SALVATI NEL FILE "Utenti.txt"

	char username_ricercato[LUNG_USERNAME]; //USERNAME DELL'UTENTE CHE DESIDERA ACCEDERE ALLA PIATTAFORMA "SPOTIFY"
	char password_ricercata[LUNG_PASSWORD]; //PASSWORD DELL'UTENTE CHE DESIDERA ACCEDERE ALLA PIATTAFORMA "SPOTIFY", ASSOCIATA AL SUO USERNAME.

//ACQUISIZIONE DELL'USERNAME DELL'UTENTE CHE VUOLE EFFETTUARE L'ACCESSO. TALE USERNAME SARA' CONFRONTATO CON QUELLI SALVATI SUL FILE "Utenti.txt"
	printf("\n> INSERISCI USERNAME:  ");
	scanf("%s", username_ricercato); //ACQUISIZIONE DELL'USERNAME DELL'UTENTE CHE VUOLE ACCEDERE ALLA PIATTAFORMA

	int username_trovato= 0; //FLAG CHE VERRA' IMPOSTATO A '1' NEL CASO IN CUI L'USERNAME INSERITO DALL'UTENTE CHE VUOLE EFFETTUARE L'ACCESSO E' STATO TROVATO NEL FILE "Utenti.txt"

//RICERCA NEL FILE "Utenti.txt" DELL'USERNAME APPENA INSERITO
	for(i=0; i<count_utenti; i++)
	{
		if(strcmp(username_ricercato, utente[i].username) == 0) //SE L'USERNAME INSERITO DALL'UTENTE CHE VUOLE EFFETTUARE L'ACCESSO E' STATO TROVATO NEL FILE "Utente.txt", SI RICHIEDE DI INSERIRE LA PASSWORD ASSOCIATA
		{
			username_trovato= 1; //IMPOSTA IL FLAG "username_trovato" A '1' POICHE' L'USERNAME INSERITO E' STATO TROVATO TRA QUELLI PRESENTI NEL FILE

		//ACQUISIZIONE DELLA PASSWORD DELL'UTENTE CHE VUOLE EFFETTUARE L'ACCESSO, ASSOCIATA ALL'USERNAME APPENA INSERITO
			do
			{
				printf("\n> INSERISCI PASSWORD:  ");
				scanf("%s",password_ricercata); //ACQUISIZIONE DELLA PASSWORD DELL'UTENTE CHE VUOLE ACCEDERE ALLA PIATTAFORMA

				if(strcmp(password_ricercata, utente[i].password) != 0)
					printf("\n   * PASSWORD NON VALIDA, RIPROVA!\n\n");

			}while(strcmp(password_ricercata, utente[i].password) != 0); //RIPETE IL CICLO FINCHE' LA PASSWORD, ASSOCIATA ALL'USERNAME INSERITO, NON E' VALIDA.

		//SE IL LOGIN E' ANDATO A BUON FINE (USERNAME E PASSWORD CORRETTI):
			salvataggio_indice_utente_loggato(file_utenti, utente, i, z); //CHIAMATA DELLA PROCEDURA "salvataggio_indice_utente_loggato", LA QUALE PERMETTE DI SALVARE SUL FILE "indice_utente_loggato.txt" L'INDICE CORRISPONDENTE ALL'UTENTE CHE HA EFFETTUATO IL LOGIN
			menu_utente(file_artisti, file_utenti, file_preferenze, utente, artista, preferenza_artista, i, scelta, z); //CHIAMATA DELLA PROCEDURA "menu_utente" CHE STAMPA A VIDEO IL MENU' CON LE DIVERSE OPERAZIONI CHE L'UTENTE PUO' FAR ESEGUIRE UNA VOLTA EFFETTUATO IL LOGIN
		}
	}

	if(username_trovato == 0) //SE AL TERMINE DI TUTTI I CICLI, IL VALORE DEL FLAG "username_trovato" RISULTA ANCORA '0', SIGNIFICA CHE L'USERNAME INSERITO DALL'UTENTE NON E'PRESENTE NEL FILE "Utenti.txt". (USERNAME ERRATO oppure UTENTE NON ISCRITTO)
	{
		printf("\n\n   * UTENTE NON ISCRITTO!\n\n");

		printf("\n\n1. RIPROVA\n");
		printf("\n2. Non sei iscritto? ISCRIVITI ORA!\n");
		printf("\n3. RITORNA ALL'INTERFACCIA INIZIALE");

	//ACQUISISZIONE DELLA "SCELTA" DELL'UTENTE, TRA LE VOCI ELENCATE
		do
		{
			fflush(stdin); //PULIZIA DEL BUFFER DELLA TASTIERA PRIMA...
			printf("\n\n\n> QUALE OPERAZIONE DESIDERI EFFETTUARE?   ");
			scanf("%c", &scelta); //ACQUISIZIONE DELLA SCELTA
			fflush(stdin); //...E DOPO L'UTILIZZO

			if(scelta < '1' || scelta > '3')
				printf("\n\n   * INPUT NON VALIDO, RIPROVA!\n");

		}while(scelta < '1' || scelta > '3'); //RIPETE IL CICLO FINCHE' IL CARATTERE INSERITO NON E' VALIDO

		switch(scelta)
		{
			case '1': //"scelta"= '1' -> RIPROVA: NEL CASO IN CUI L'UTENTE HA SBAGLIATO A DIGITARE QUALCHE CARATTERE DELL'USERNAME
				system("cls"); //PULIZIA DELLO SCHERMO
				scritta_spotify(); //CHIMATA DELLA PROCEDURA "scritta_spotify" CHE STAMPA A VIDEO LA SCRITTA "SPOTIFY"
				scritta_login(); //CHIMATA DELLA PROCEDURA "scritta_login" CHE STAMPA A VIDEO LA SCRITTA "LOGIN"
				login_utente(file_artisti, file_utenti, file_preferenze, utente, artista, preferenza_artista, i, scelta, z); //CHIAMATA DELLA PROCEDURA "login_utente" CHE PERMETTE ALL'UTENTE DI EFFETTUARE L'ACCESSO ALLA PIATTAFORMA "SPOTIFY", INSERENDO IL PROPRIO USERNAME E PASSWORD.
				break;

			case '2': //"scelta"= '2' -> ISCRIVITI: NEL CASO IN CUI L'UTENTE NON E' ANCORA REGISTRATO ALLA PIATTAFORMA "SPOTIFY"
				system("cls"); //PULIZIA DELLO SCHERMO
				scritta_spotify(); //CHIMATA DELLA PROCEDURA "scritta_spotify" CHE STAMPA A VIDEO LA SCRITTA "SPOTIFY"
				scritta_signup(); //CHIMATA DELLA PROCEDURA "scritta_signup" CHE STAMPA A VIDEO LA SCRITTA "SIGNUP"
				signup(file_artisti, file_utenti, file_preferenze, utente, artista, preferenza_artista, i, scelta, z); //CHIAMATA DELLA PROCEDURA "signup" CHE PERMETTE ALL'UTENTE DI REGISTRARSI ALLA PIATTAFORMA "SPOTIFY", FORNENDO I PROPRI DATI ANAGRAFICI E SCEGLIENDO UN USERNAME E UNA PASSWORD PER POTER POI ACCEDERE
				break;

			case '3': //"scelta"= '3' -> EXIT
				interfaccia_iniziale(file_artisti, file_utenti, file_preferenze, utente, artista, preferenza_artista, i, scelta, z); //CHIAMATA DELLA PROCEDURA "interfaccia iniziale" PER RITORNARE ALL'INTERFACCIA INIZIALE
				break;
		}
	}
}

/**
 * Procedura salvataggio_indice_utente_loggato():
 *
 * Viene salvato sul file "indice_utente_loggato.txt" l'indice che corrisponde all'utente che ha effettuato l'accesso.
 * @param file_utenti
 * @param utente
 * @param i
 * @param z
 */

void salvataggio_indice_utente_loggato(FILE* file_utenti, utenti utente[], int i, int z)
{
	FILE* file_indice= NULL; //DICHIARAZIONE & INIZIALIZZAZIONE DELLA VARIABILE "file_indice" PUNTATORE A FILE

//APERTURA DEL FILE "indice_utente_loggato.txt" IN MODALITA' DI SCRITTURA ("w")
	if((file_indice=  fopen("indice_utente_loggato.txt" , "w")) == NULL)
		printf("Errore nell'apertura!\n");

	else
	{
		z= i; //ASSEGNA A "z" L'INDICE DELL'UTENTE CHE HA EFFETTUATO IL LOGIN
		fprintf(file_indice, "%d", z); //STAMPA SUL FILE "indice_utente_loggato.txt" IL VALORE DI "z", L'INDICE DELL'UTENTE CHE HA EFFETTUATO IL LOGIN
	}
	fclose(file_indice); //CHIUSURA DEL FILE
}

/**
 * Procedura menu_utente():
 *
 * Viene stampato il menù con le 7 operazioni a disposizione dell'utente, quest'ultimo sceglierà una voce tra quelle elencate
 * inserendo un valore di scelta. Il valore della scelta è un carattere numerico, si richiede, quindi, di inserire un valore
 * compreso nel range indicato. Se si inserisce una stringa o un carattere non valido verra' richiesto di reinserire il valore.
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

void menu_utente(FILE* file_artisti, FILE* file_utenti,  FILE* file_preferenze, utenti utente[], artisti artista[], preferenze_artisti preferenza_artista[], int i, char scelta, int z)
{
	system("cls"); //PULIZIA DELLO SCHERMO
	scritta_spotify(); //CHIAMATA DELLA PROCEDURA "scritta_spotify" CHE STAMPA A VIDEO LA SCRITTA "SPOTIFY"

	z= lettura_indice_utente_loggato(file_utenti, utente, i, z); //ASSEGNA A "z" IL VALORE RESTITUITO DALLA FUNZIONE "lettura_indice_utente_loggato", L'INDICE DELL'UTENTE CHE HA EFFETTUATO IL LOGIN.
	printf("\n\n\t\t\t\t\t\t\t\t\t\t      Benvenuto %s", utente[z].username);

//MENU' INTERFACCIA UTENTE
	printf("\n\n\t\t\t\t\t\t\t\t\t   _______________________________________");
	printf("\n\t\t\t\t\t\t\t\t\t  |                                       |");
	printf("\n\t\t\t\t\t\t\t\t\t  |      1. VISUALIZZA LISTA ARTISTI      |");
	printf("\n\t\t\t\t\t\t\t\t\t  |_______________________________________|");
	printf("\n\n\t\t\t\t\t\t\t\t\t   _______________________________________");
	printf("\n\t\t\t\t\t\t\t\t\t  |                                       |");
	printf("\n\t\t\t\t\t\t\t\t\t  |       2. AGGIUNGI UNA PREFERENZA      |");
	printf("\n\t\t\t\t\t\t\t\t\t  |_______________________________________|");
	printf("\n\n\t\t\t\t\t\t\t\t\t   _______________________________________");
	printf("\n\t\t\t\t\t\t\t\t\t  |                                       |");
	printf("\n\t\t\t\t\t\t\t\t\t  |           3. RICERCA ARTISTA          |");
	printf("\n\t\t\t\t\t\t\t\t\t  |_______________________________________|");
	printf("\n\n\t\t\t\t\t\t\t\t\t   _______________________________________");
	printf("\n\t\t\t\t\t\t\t\t\t  |                                       |");
	printf("\n\t\t\t\t\t\t\t\t\t  |         4. CLASSIFICHE ARTISTI        |");
	printf("\n\t\t\t\t\t\t\t\t\t  |_______________________________________|");
	printf("\n\n\t\t\t\t\t\t\t\t\t   _______________________________________");
	printf("\n\t\t\t\t\t\t\t\t\t  |                                       |");
	printf("\n\t\t\t\t\t\t\t\t\t  |              5. PROFILO               |");
	printf("\n\t\t\t\t\t\t\t\t\t  |_______________________________________|");
	printf("\n\n\t\t\t\t\t\t\t\t\t   _______________________________________");
	printf("\n\t\t\t\t\t\t\t\t\t  |                                       |");
	printf("\n\t\t\t\t\t\t\t\t\t  |        6. SUGGERIMENTO ARTISTI        |");
	printf("\n\t\t\t\t\t\t\t\t\t  |_______________________________________|");
	printf("\n\n\t\t\t\t\t\t\t\t\t   _______________________________________");
	printf("\n\t\t\t\t\t\t\t\t\t  |                                       |");
	printf("\n\t\t\t\t\t\t\t\t\t  |              7. LOGOUT                |");
	printf("\n\t\t\t\t\t\t\t\t\t  |_______________________________________|");

//ACQUISIZIONE DELLA "SCELTA" DELL'UTENTE, TRA LE VOCI ELENCATE NEL MENU'
	do
	{
		fflush(stdin); //PULIZIA DEL BUFFER DELLA TASTIERA PRIMA...
		printf("\n\n\n\t\t\t\t\t\t\t\t\t   > QUALE OPERAZIONE DESIDERI EFFETTUARE?   ");
		scanf("%c", &scelta); //ACQUISIZIONE DELLA SCELTA
		fflush(stdin); //...E DOPO L'UTILIZZO

		if(scelta < '1' || scelta > '7')
			printf("\n\n\t\t\t\t\t\t\t\t\t       * SCELTA NON VALIDA, RIPROVA!\n");

	}while(scelta < '1' || scelta > '7'); //RIPETE IL CICLO FINCHE' IL CARATTERE INSERITO NON E' VALIDO

	switch(scelta)
	{
		case '1': //"scelta"= '1' -> VISUALIZZAZIONE DEGLI ARTISTI
			system("cls"); //PULIZIA DELLO SCHERMO
			scritta_spotify(); //CHIAMATA DELLA PROCEDURA "scritta_spotify" CHE STAMPA A VIDEO LA SCRITTA "SPOTIFY"
			printf("\n\n\t\t\t\t\t\t\t\t\t   _______________________________________");
			printf("\n\t\t\t\t\t\t\t\t\t  |                                       |");
			printf("\n\t\t\t\t\t\t\t\t\t  |        VISUALIZZA LISTA ARTISTI       |");
			printf("\n\t\t\t\t\t\t\t\t\t  |_______________________________________|");

			visualizza_artisti(file_artisti, file_utenti, file_preferenze, utente, artista, preferenza_artista, i, z); //CHIAMATA DELLA PROCEDURA "visualizza_artisti" CHE STAMPA A VIDEO LA LISTA DEGLI ARTISTI SALVATI NEL FILE "Artisti.txt"
			return_menu_utente(file_artisti, file_utenti, file_preferenze, utente, artista, preferenza_artista, i, scelta, z); //CHIAMATA DELLA PROCEDURA "return_menu_utente" CHE PERMETTE ALL'UTENTE DI RITORNARE AL SUO MENU' AL TERMINE DELL'OPERAZIONE ESEGUITA
			break;


		case '2': //"scelta"= '2' -> AGGIUNGI UNA PREFERENZA
			system("cls"); //PULIZIA DELLO SCHERMO
			scritta_spotify(); //CHIAMATA DELLA PROCEDURA "scritta_spotify" CHE STAMPA A VIDEO LA SCRITTA "SPOTIFY"
			aggiungi_preferenza(file_artisti, file_utenti, file_preferenze, utente, artista, preferenza_artista, i, scelta, z); //CHIAMATA DELLA PROCEDURA "aggiungi_preferenza" CHE PERMETTE ALL'UTENTE DI ASSEGNARE UNA PREFERENZA (like, dislike, listen) ALL'ARTISTA DESIDERATO
			break;

		case '3': //"scelta"= '3' -> RICERCA DEGLI ARTISTI
			system("cls"); //PULIZIA DELLO SCHERMO
			scritta_spotify(); //CHIAMATA DELLA PROCEDURA "scritta_spotify" CHE STAMPA A VIDEO LA SCRITTA "SPOTIFY"
			ricerca_artisti(file_artisti, file_utenti, file_preferenze, utente, artista, preferenza_artista, i, scelta, z); //CHIAMATA DELLA PROCEDURA "ricerca_artisti" CHE STAMPA A VIDEO I 3 PARAMETRI PER CUI E' POSSIBILE RICERCARE GLI ARTISTI. STA ALL'UTENTE INDICARE SE RICERCARE GLI ARTISTI PER GENERE, PER NAZIONALITA' oppure PER ANNO DI INIZIO CARRIERA
			break;

		case '4': //"scelta"= '4' -> VISUALIZZA I TOP 10 ARTISTI (LISTEN/LIKE/DISLIKE)
			system("cls"); //PULIZIA DELLO SCHERMO
			scritta_spotify(); //CHIAMATA DELLA PROCEDURA "scritta_spotify" CHE STAMPA A VIDEO LA SCRITTA "SPOTIFY"
			classifiche_artisti(file_artisti, file_utenti, file_preferenze, utente, artista, preferenza_artista, i, scelta, z);
			break;

		case '5': //"scelta"= '5' -> PROFILO
			system("cls"); //PULIZIA DELLO SCHERMO
			scritta_spotify(); //CHIAMATA DELLA PROCEDURA "scritta_spotify" CHE STAMPA A VIDEO LA SCRITTA "SPOTIFY"
			profilo(file_artisti, file_utenti, file_preferenze, utente, artista, preferenza_artista, i, scelta, z); //CHIAMATA DELLA PROCEDURA "profilo" CHE STAMPA A VIDEO I DATI RELATIVI ALL'UTENTE LOGGATO. INOLTRE PERMETTE DI EFFETTUARE MODIFICHE AI SUOI DATI/PREFERENZE oppure ELIMINARE IL SUO ACCOUNT
			break;

		case '6': //"scelta"= '6' -> SUGGERIMENTO ARTISTI
			system("cls"); //PULIZIA DELLO SCHERMO
			scritta_spotify(); //CHIAMATA DELLA PROCEDURA "scritta_spotify" CHE STAMPA A VIDEO LA SCRITTA "SPOTIFY"
			suggerimento_artisti(file_artisti, file_utenti, file_preferenze, utente, artista, preferenza_artista, i, scelta, z); //CHIAMATA DELLA PROCEDURA "suggerimento_artista" CHE PERMETTE DI SUGGERIRE ALL'UTENTE LOGGATO GLI ARTISTI GRADITI DAGLI UTENTI A LUI SIMILI
			return_menu_utente(file_artisti, file_utenti, file_preferenze, utente, artista, preferenza_artista, i, scelta, z); //CHIAMATA DELLA PROCEDURA "return_menu_utente" CHE PERMETTE ALL'UTENTE DI RITORNARE AL SUO MENU' AL TERMINE DELL'OPERAZIONE ESEGUITA
			break;

		case '7': //"scelta"= '7' -> LOGOUT
			interfaccia_iniziale(file_artisti, file_utenti, file_preferenze, utente, artista, preferenza_artista, i, scelta, z); //CHIAMATA DELLA PROCEDURA "interfaccia_iniziale" CHE PERMETTE ALL'UTENTE DI USCIRE DALLA PIATTAFORMA
			break;
	}
}

/**
 * Procedura visualizza_artisti():
 *
 * Viene stampato a video, in formato tabellare, l'elenco degli artisti memorizzati. Per ogni artista l'utente visualizza:
 *
 * - ID. dell'artista
 * - Nome d'arte (lo spazio è sostituito da un "_")
 * - Genere musicale dell'artista
 * - Nazionalita' dell'artista
 * - Anno di inizio carriera dell'artista
 * - Canzone popolare dell'artista
 * - Il N° ASCOLTI / LIKE / DISLIKE ad esso associati
 *
 * @param file_artisti
 * @param file_utenti
 * @param file_preferenze
 * @param utente
 * @param artista
 * @param preferenza_artista
 * @param i
 * @param z
 */

void visualizza_artisti(FILE* file_artisti, FILE* file_utenti,  FILE* file_preferenze, utenti utente[], artisti artista[], preferenze_artisti preferenza_artista[], int i, int z)
{
	int count_artisti= 0; //VARIABILE CONTATORE CHE CONTERRA' IL NUMERO DI ARTISTI SALVATI SUL FILE "Artisti.txt", CALCOLATO NELLA FUNZIONE "lettura_artisti_da_file"
	count_artisti= lettura_artisti_da_file(file_artisti, artista, i); //ASSEGNA A "count_artisit" IL VALORE RESTITUITO DALLA FUNZIONE "lettura_artisti_da_file", OSSIA IL NUMERO DEGLI ARTISTI SALVATI NEL FILE "Artisti.txt"

	printf("\n\n\n\n\t\t   ID. ARTISTA|       NOME ARTISTA|\tGENERE MUSICALE|\tNAZIONALITA'|\t  ANNO INIZIO CARRIERA|\t     CANZONE POPOLARE|\t N.ASCOLTI|    N.LIKE|    N.DISLIKE|\n\n");

//STAMPA DELLA LISTA DI ARTISTI PRESENTI SUL FILE "Artisti.txt"
	for(i=0; i<count_artisti; i++)
		printf("\t  %20d|%19s|%20s|%20s|%25d|%22s|%12d|%10d|%13d|\n", artista[i].id_artista, artista[i].nome_artista, artista[i].genere, artista[i].nazionalita, artista[i].anno_inizio, artista[i].canzone, artista[i].count_listen, artista[i].count_like, artista[i].count_dislike); //STAMPA A VIDEO TUTTI I DATI DELL'i-ESIMO ARTISTA SALVATO SUL FILE "Artisti.txt"
}

/**
 * Procedura aggiungi_preferenza():
 *
 * Viene stampata la lista degli artisti memorizzati ai quali l'utente può assegnare una preferenza.
 * Si acquisisce l'ID. numerico associato all'artista desiderato e si sceglie il tipo di preferenza
 * da esprimere: LISTEN, LIKE o DISLIKE. Per scegliere una delle 3 opzioni, si acquisisce un valore di
 * scelta, un carattere numerico, compreso nel range indicato. Se si inserisce una stringa o un carattere
 * non valido verra' richiesto di reinserire il valore.
 *
 * Assegnata la preferenza all'artista desiderato, verra' memorizzato sul file "preferenza.txt" i dati:
 * - username dell'utente che ha esoresso la preferenza;
 * - nome dell'artista a cui è stata assegnata la preferenza
 * - il tipo di preferenza assegnata
 *
 * In base al tipo di preferenza assegnato al determinato artista, verra' incrementato il suo contatore di preferenze
 * ad esso associato.
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

void aggiungi_preferenza(FILE* file_artisti, FILE* file_utenti,  FILE* file_preferenze, utenti utente[], artisti artista[], preferenze_artisti preferenza_artista[], int i, char scelta, int z)
{
	printf("\n\n\t\t\t\t\t\t\t\t\t   _______________________________________");
	printf("\n\t\t\t\t\t\t\t\t\t  |                                       |");
	printf("\n\t\t\t\t\t\t\t\t\t  |        AGGIUNGI UNA PREFERENZA        |");
	printf("\n\t\t\t\t\t\t\t\t\t  |_______________________________________|");

	visualizza_artisti(file_artisti, file_utenti, file_preferenze, utente, artista, preferenza_artista, i, z); //CHIAMATA DELLA PROCEDURA "visualizza_artisti" CHE STAMPA A VIDEO LA LISTA DEGLI ARTISTI SALVATI SUL FILE "Artisti.txt"
	z= lettura_indice_utente_loggato(file_utenti, utente, i, z); //ASSEGNA A "z" IL VALORE RESTITUITO DALLA FUNZIONE "lettura_indice_utente_loggato", L'INDICE DELL'UTENTE CHE HA EFFETTUATO IL LOGIN

	int count_artisti= 0; //VARIABILE CONTATORE CHE CONTERRA' IL NUMERO DI ARTISTI SALVATI SUL FILE "Artisti.txt", CALCOLATO NELLA FUNZIONE "lettura_artisti_da_file"
	count_artisti= lettura_artisti_da_file(file_artisti, artista, i); //ASSEGNA A "count_artisti" IL VALORE RESTITUITO DALLA FUNZIONE "lettura_artisti_da_file", OSSIA IL NUMERO DEGLI ARTISTI SALVATI NEL FILE "Artisti.txt"

	int count_preferenze= 0; //VARIABILE CONTATORE CHE CONTERRA' IL NUMERO DI PREFERENZE SALVATE SUL FILE "Preferenze.txt", CALCOLATO NELLA FUNZIONE "lettura_preferenze_da_file"
	count_preferenze= lettura_preferenze_da_file(file_preferenze, artista, preferenza_artista, i); //ASSEGNA A "count_preferenze" IL VALORE RESTITUITO DALLA FUNZIONE "lettura_preferenze_da_file", OSSIA IL NUMERO DELLE PREFERENZE SALVATE NEL FILE "Preferenze.txt"

//APERTURA DEL FILE "Preferenze.txt" IN MODALITA' DI SCRITTURA IN CODA ("a")
	if((file_preferenze=  fopen("Preferenze.txt" , "a")) == NULL)
		printf("Errore nell'apertura!\n");

	else
	{

	//ACQUISIZIONE DELL'ID DELL'ARTISTA A CUI SI VUOLE ASSEGNARE LA PREFERENZA
		int id_artista_ricercato= 0; //VARIABILE CHE CONTERRA' L'ID DELL'ARTISTA, INSERITO IN INPUT DALL'UTENTE, AL QUALE SI VUOLE ASSEGNARE LA PREFERENZA

		printf("\n\n\n> INSERISCI L'ID DELL'ARTISTA A CUI VUOI DARE UNA PREFERENZA:   ");
		scanf("%d", &id_artista_ricercato); //ACQUISIZIONE DELL'ID DELL'ARTISTA

		int id_artista_trovato= 0; //FLAG CHE VERRA' IMPOSTATO A '1' NEL CASO IN CUI L'ID DELL'ARTISTA INSERITO DALL'UTENTE E' PRESENTE NEL FILE "Artisti.txt"

		for(i=0; i<count_artisti; i++)
		{
			if(id_artista_ricercato == artista[i].id_artista) //CONDIZIONE CHE VERIFICA SE L'ID DELL'ARTISTA INSERITO E' PRESENTE NEL FILE "Artisti.txt"
				id_artista_trovato= 1; //IMPOSTA IL FLAG "id_artista_trovato" A '1' POICHE' L'ID DELL'ARTISTA INSERITO DALL'UTENTE A CUI ASSEGNARE LA PREFERENZA E' STATO TROVATO NEL FILE "Artisti.txt"
		}

		if(id_artista_trovato == 0) //SE AL TERMINE DI TUTTI I CICLI, IL VALORE DEL FLAG "id_artista_trovato" RISULTA ANCORA '0', SIGNIFICA CHE L'ID DELL'ARTISTA INDICATO DALL'UTENTE NON E'PRESENTE NEL FILE "Artisti.txt"
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
					aggiungi_preferenza(file_artisti, file_utenti, file_preferenze, utente, artista, preferenza_artista, i, scelta, z); //CHIAMATA DELLA PROCEDURA "aggiungi_preferenza" CHE PERMETTE ALL'UTENTE DI ASSEGNARE UNA PREFERENZA (like, dislike, listen) ALL'UTENTE DESIDERATO
					break;

				case '2': //"scelta"= 2 -> RITORNA AL MENU
					system("cls"); //RITORNA AL MENU
					scritta_spotify(); //CHIAMATA DELLA PROCEDURA "scritta_spotify" CHE STAMPA A VIDEO LA SCRITTA "SPOTIFY"
					menu_utente(file_artisti, file_utenti, file_preferenze, utente, artista, preferenza_artista, i, scelta, z); //CHIAMATA DELLA PROCEDURA "menu_utente" CHE PERMETTE ALL'UTENTE DI RITORNARE AL SUO MENU' PER ESEGUIRE UNA NUOVA OPERAZIONE
					break;
			}
		}

		else
		{
			int j= 0; //INDICE DELLE PREFERENZE
			int preferenza_esistente= 0; //FLAG CHE VERRA' IMPOSTATO A '1' NEL CASO IN CUI L'UTENTE HA GIA' ESPRESSO UNA PREFERENZA PER UN DETERMINATO ARTISTA

			for(i=0; i<count_artisti; i++)
			{
				if(id_artista_ricercato == artista[i].id_artista) //CONDIZIONE CHE VERIFICA SE L'ID. DELL'i-ESIMO ARTISTA PRESENTE NEL FILE E' UGUALE ALL'ID. DELL'ARTISTA INSERITO (AL QUALE ASSEGNARE LA PREFERENZA)
				{
					for(j=0; j<count_preferenze; j++)
					{
						if(strcmp(preferenza_artista[j].username_utente, utente[z].username) == 0 && strcmp(preferenza_artista[j].nome_artista, artista[i].nome_artista) == 0) //CONDIZIONE CHE VERIFICA SE L'UTENTE LOGGATO HA GIA' ESPRESSO UNA PREFERENZA PER L'i-ESIMO ARTISTA
						{
							preferenza_esistente= 1; //IMPOSTA IL FLAG "preferenza_esistente" a '1' POICHE' L'UTENTE LOGGATO HA GIA' ESPRESSO IN PRECEDENZA UNA PREFERENZA PER L'ARTISTA INDICATO
							break;
						}
					}

					if(preferenza_esistente == 1) //SE IL VALORE DEL FLAG "preferenza_esistente" E' UGUALE A '1', SIGNIFICA CHE L'UTENTE LOGGATO HA GIA' ESPRESSO UNA PREFERENZA PER L'ARTISTA INDICATO
					{
						printf("\n   * HAI GIA' ESPRESSO UNA PREFERENZA PER QUESTO ARTISTA!");
						return_menu_utente(file_artisti, file_utenti, file_preferenze, utente, artista, preferenza_artista, i, scelta, z); //CHIAMATA DELLA PROCEDURA "return_menu_utente" CHE PERMETTE ALL'UTENTE DI RITORNARE AL SUO MENU'
					}

				//ASSEGNAZIONE DELLA PREFERENZA
					else
					{
						printf("\n\nPREFERENZA: \n");
						printf("\n\t1. LISTEN\n");
						printf("\n\t2. LIKE\n");
						printf("\n\t3. DISLIKE");

						do
						{
							fflush(stdin); //PULIZIA DEL BUFFER DELLA TASTIERA PRIMA...
							printf("\n\n\n> QUALE PREFERENZA VUOI ASSEGNARE A '%s'?   ", artista[i].nome_artista);
							scanf("%c", &scelta); //ACQUISIZIONE DELLA SCELTA
							fflush(stdin); //...E DOPO L'UTILIZZO

							if(scelta < '1' || scelta > '3')
								printf("\n   * INPUT NON VALIDO, RIPROVA!");

						}while(scelta < '1' || scelta > '3'); //RIPETE IL CICLO FINCHE' IL CARATTERE INSERITO NON E' VALIDO

						switch(scelta)
						{
							case '1'://"scelta"= 1 -> PREFERENZA: LISTEN
								preferenza_artista[count_preferenze].id_preferenza= count_preferenze+1; //ASSEGNAZIONE DELL'"ID PREFERENZA" ALLA NUOVA PREFERENZA
								strcpy(preferenza_artista[count_preferenze].username_utente, utente[z].username); //COPIA L'USERNAME DELL'UTENTE, CHE HA ESPRESSO LA NUOVA PREFERENZA, NELL'ARRAY "preferenza_artista" NEL CAMPO "username_utente"
								strcpy(preferenza_artista[count_preferenze].nome_artista, artista[i].nome_artista); //COPIA IL NOME DELL'ARTISTA, A CUI E' STATA ASSEGNATA LA NUOVA PREFERENZA, NELL'ARRAY "preferenza_artista" NEL CAMPO "nome_artista"
								strcpy(preferenza_artista[count_preferenze].preferenza, "LISTEN"); //ASSEGNA LA PREFERENZA "LISTEN" ALL'ARTISTA INDICATO DALL'UTENTE
								artista[i].count_listen++; //INCREMENTO UNITARIO DEL NUMERO DI "LISTEN" DELL'i-ESIMO ARTISTA
								break;

							case '2'://"scelta"= '2' -> PREFERENZA: LIKE
								preferenza_artista[count_preferenze].id_preferenza= count_preferenze+1; //ASSEGNAZIONE DELL'"ID PREFERENZA" ALLA NUOVA PREFERENZA
								strcpy(preferenza_artista[count_preferenze].username_utente, utente[z].username);  //COPIA L'USERNAME DELL'UTENTE, CHE HA ESPRESSO LA NUOVA PREFERENZA, NELL'ARRAY "preferenza_artista" NEL CAMPO "username_utente"
								strcpy(preferenza_artista[count_preferenze].nome_artista, artista[i].nome_artista); //COPIA IL NOME DELL'ARTISTA, A CUI E' STATA ASSEGNATA LA NUOVA PREFERENZA, NELL'ARRAY "preferenza_artista" NEL CAMPO "nome_artista"
								strcpy(preferenza_artista[count_preferenze].preferenza, "LIKE"); //ASSEGNA LA PREFERENZA "LIKE" ALL'ARTISTA INDICATO DALL'UTENTE
								artista[i].count_like++;  //INCREMENTO UNITARIO DEL NUMERO DI "LIKE" DELL'i-ESIMO ARTISTA
								break;

							case '3'://"scelta"= '3' -> PREFERENZA: DISLIKE
								preferenza_artista[count_preferenze].id_preferenza= count_preferenze+1; //ASSEGNAZIONE DELL'"ID PREFERENZA" ALLA NUOVA PREFERENZA
								strcpy(preferenza_artista[count_preferenze].username_utente, utente[z].username); //COPIA L'USERNAME DELL'UTENTE, CHE HA ESPRESSO LA NUOVA PREFERENZA, NELL'ARRAY "preferenza_artista" NEL CAMPO "username_utente"
								strcpy(preferenza_artista[count_preferenze].nome_artista, artista[i].nome_artista); //COPIA IL NOME DELL'ARTISTA, A CUI E' STATA ASSEGNATA LA NUOVA PREFERENZA, NELL'ARRAY "preferenza_artista" NEL CAMPO "nome_artista"
								strcpy(preferenza_artista[count_preferenze].preferenza, "DISLIKE"); //ASSEGNA LA PREFERENZA "DISLIKE" ALL'ARTISTA INDICATO DALL'UTENTE
								artista[i].count_dislike++;  //INCREMENTO UNITARIO DEL NUMERO DI "DISLIKE" DELL'i-ESIMO ARTISTA
								break;
						}
					}
					fprintf(file_preferenze,"\n%d %s %s %s", preferenza_artista[count_preferenze].id_preferenza, preferenza_artista[count_preferenze].username_utente, preferenza_artista[count_preferenze].nome_artista, preferenza_artista[count_preferenze].preferenza); //SALVATAGGIO SUL FILE "Preferenze.txt" DEI DATI DELLA NUOVA PREFERENZA AGGIUNTA (USERNAME, NOME ARTISTA e TIPO PREFERENZA)

					fclose(file_preferenze); //CHIUSURA DEL FILE

				//APERTURA DEL FILE "Artisti.txt" IN MODALITA' DI SCRITTURA ("w")
					if((file_artisti=  fopen("Artisti.txt" , "w")) == NULL)
						printf("Errore nell'apertura!\n");

					else
					{
					//SALVATAGGIO SUL FILE "Artisti.txt" DEI DATI DEGLI ARTISTI CON L'AGGIORNAMENTO SULLE PREFERENZE
						for(i=0; i<count_artisti; i++)
							fprintf(file_artisti,"\n%d %s %s %s %d %s %d %d %d", artista[i].id_artista, artista[i].nome_artista, artista[i].genere, artista[i].nazionalita, artista[i].anno_inizio, artista[i].canzone, artista[i].count_listen, artista[i].count_like, artista[i].count_dislike); //SALVATAGGIO SUL FILE "Artisti.txt" DEI DATI DELL'i-ESIMO ARTISTA

						printf("\n\n\n***************** PREFERENZA AGGIUNTA CORRETTAMENTE! *****************\n");
					}
					fclose(file_artisti); //CHIUSURA DEL FILE

					return_menu_utente(file_artisti, file_utenti, file_preferenze, utente, artista, preferenza_artista, i, scelta, z); //CHIAMATA DELLA PROCEDURA "return_menu_utente" CHE PEREMETTE ALL'UTENTE DI RITORNARE AL SUO MENU' AL TERMINE DELL'OPERAZIONE ESEGUITA
					break;
				}
			}
		}
	}
}

/**
 * Procedura ricerca_artisti():
 * Vengono stampati i vari parametri per cui l'utente puo' ricercare gli artisti. L'utente sceglierà una voce tra quelle elencate
 * inserendo un valore di scelta. Il valore della scelta è un carattere numerico, si richiede, quindi, di inserire un valore
 * compreso nel range indicato. Se si inserisce una stringa o un carattere non valido verra' richiesto di reinserire il valore.
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

void ricerca_artisti(FILE* file_artisti, FILE* file_utenti, FILE* file_preferenze, utenti utente[], artisti artista[], preferenze_artisti preferenza_artista[], int i, char scelta, int z)
{
	printf("\n\n\t\t\t\t\t\t\t\t\t   _______________________________________");
	printf("\n\t\t\t\t\t\t\t\t\t  |                                       |");
	printf("\n\t\t\t\t\t\t\t\t\t  |            RICERCA ARTISTA            |");
	printf("\n\t\t\t\t\t\t\t\t\t  |_______________________________________|");
	printf("\n\n\n\t\t\t\t\t\t\t\t\t   _______________________________________");
	printf("\n\t\t\t\t\t\t\t\t\t  |                                       |");
	printf("\n\t\t\t\t\t\t\t\t\t  |           1. GENERE MUSICALE          |");
	printf("\n\t\t\t\t\t\t\t\t\t  |_______________________________________|");
	printf("\n\n\t\t\t\t\t\t\t\t\t   _______________________________________");
	printf("\n\t\t\t\t\t\t\t\t\t  |                                       |");
	printf("\n\t\t\t\t\t\t\t\t\t  |            2. NAZIONALITA'            |");
	printf("\n\t\t\t\t\t\t\t\t\t  |_______________________________________|");
	printf("\n\n\t\t\t\t\t\t\t\t\t   _______________________________________");
	printf("\n\t\t\t\t\t\t\t\t\t  |                                       |");
	printf("\n\t\t\t\t\t\t\t\t\t  |         3. ANNO DI PRODUZIONE         |");
	printf("\n\t\t\t\t\t\t\t\t\t  |_______________________________________|");
	printf("\n\n\t\t\t\t\t\t\t\t\t   _______________________________________");
	printf("\n\t\t\t\t\t\t\t\t\t  |                                       |");
	printf("\n\t\t\t\t\t\t\t\t\t  |                4. EXIT                |");
	printf("\n\t\t\t\t\t\t\t\t\t  |_______________________________________|");

	do
	{
		fflush(stdin); //PULIZIA DEL BUFFER DELLA TASTIERA PRIMA...
		printf("\n\n\n\t\t\t\t\t\t\t\t   > PER QUALE PARAMETRO DESIDERI RICERCARE GLI ARTISTI?   ");
		scanf("%c", &scelta); //ACQUISIZIONE DELLA SCELTA
		fflush(stdin); //...E DOPO L'UTILIZZO

		if(scelta < '1' || scelta > '4')
			printf("\n\n\t\t\t\t\t\t\t\t       * SCELTA NON VALIDA, RIPROVA!\n");

	}while(scelta < '1' || scelta > '4'); //RIPETE IL CICLO FINCHE' IL CARATTERE INSERITO NON E' VALIDO

	switch(scelta)
	{
		case '1': //"scelta"= '1' -> RICERCA PER GENERE
			system("cls"); //PULIZIA DELLO SCHERMO
			scritta_spotify(); //CHIAMATA DELLA PROCEDURA "scritta_spotify" CHE STAMPA A VIDEO LA SCRITTA "SPOTIFY"
			ricerca_per_genere(file_artisti, file_utenti, file_preferenze, utente, artista, preferenza_artista, i, scelta, z); //CHIAMATA DELLA PROCEDURA "ricerca_per_genere" CHE PERMETTE DI STAMPARE GLI ARTISTI DI UN DETERMINATO GENERE DEFINITO DALL'UTENTE
			return_menu_utente(file_artisti, file_utenti, file_preferenze, utente, artista, preferenza_artista, i, scelta, z); //CHIAMATA DELLA PROCEDURA "return_menu_utente" CHE PERMETTE ALL'UTENTE DI RITORNARE AL SUO MENU' AL TERMINE DELL'OPERAZIONE ESEGUITA
			break;

		case '2': //"scelta"= '2' -> RICERCA PER NAZIONALITA'
			system("cls"); //PULIZIA DELLO SCHERMO
			scritta_spotify(); //CHIAMATA DELLA PROCEDURA "scritta_spotify" CHE STAMPA A VIDEO LA SCRITTA "SPOTIFY"
			ricerca_per_nazionalita(file_artisti, file_utenti, file_preferenze, utente, artista, preferenza_artista, i, scelta, z); //CHIAMATA DELLA PROCEDURA "ricerca_per_nazionalita" CHE PERMETTE DI STAMPARE GLI ARTISTI DI UNA DETERMINATA NAZIONALITA' DEFINITA DALL'UTENTE
			return_menu_utente(file_artisti, file_utenti, file_preferenze, utente, artista, preferenza_artista, i, scelta, z); //CHIAMATA DELLA PROCEDURA "return_menu_utente" CHE PERMETTE ALL'UTENTE DI RITORNARE AL SUO MENU' AL TERMINE DELL'OPERAZIONE ESEGUITA
			break;

		case '3': //"scelta"= '3' -> RICERCA PER ANNO DI INIZIO PRODUZIONE
			system("cls"); //PULIZIA DELLO SCHERMO
			scritta_spotify(); //CHIAMATA DELLA PROCEDURA "scritta_spotify" CHE STAMPA A VIDEO LA SCRITTA "SPOTIFY"
			ricerca_per_anno_inizio_produzione(file_artisti, file_utenti, file_preferenze, utente, artista, preferenza_artista, i, scelta, z); //CHIAMATA DELLA PROCEDURA "ricerca_per_anno_inizio_produzione" CHE PERMETTE DI STAMPARE GLI ARTISTI CON ANNO DI PRODUZIONE COMPRESO IN UN RANGE STABILITO IN INPUT DALL'UTENTE
			return_menu_utente(file_artisti, file_utenti, file_preferenze, utente, artista, preferenza_artista, i, scelta, z); //CHIAMATA DELLA PROCEDURA "return_menu_utente" CHE PERMETTE ALL'UTENTE DI RITORNARE AL SUO MENU' AL TERMINE DELL'OPERAZIONE ESEGUITA
			break;

		case '4': //"scelta"= '4' -> EXIT
			system("cls"); //PULIZIA DELLO SCHERMO
			scritta_spotify(); //CHIAMATA DELLA PROCEDURA "scritta_spotify" CHE STAMPA A VIDEO LA SCRITTA "SPOTIFY"
			menu_utente(file_artisti, file_utenti, file_preferenze, utente, artista, preferenza_artista, i, scelta, z); //CHIAMATA DELLA PROCEDURA "menu_utente" CHE PERMETTE ALL'UTENTE DI RITORNARE AL SUO MENU' PER ESEGUIRE UNA NUOVA OPERAZIONE
			break;
	}
}

/**
 * Procedura ricerca_per_genere(): permette di ricercare gli artisti di un determinato genere
 *
 * Si acquisisce la stringa del genere degli artisti da ricercare, verificandone la correttezza (no caratteri numerici!)
 * e se il genere indicato appartiene realmente ad almeno uno degli artisti presenti nel file. In tal caso verrà
 * stampato a video l'elenco degli artisti aventi tale genere. Se il genere indicato
 * non è stato trovato nel file, errato o inesistente, si richiede all'utente di reinserire la stringa.
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

void ricerca_per_genere(FILE* file_artisti, FILE* file_utenti,  FILE* file_preferenze, utenti utente[], artisti artista[], preferenze_artisti preferenza_artista[], int i, char scelta, int z)
{
	printf("\n\n\t\t\t\t\t\t\t\t\t   _______________________________________");
	printf("\n\t\t\t\t\t\t\t\t\t  |                                       |");
	printf("\n\t\t\t\t\t\t\t\t\t  |            GENERE MUSICALE            |");
	printf("\n\t\t\t\t\t\t\t\t\t  |_______________________________________|\n\n");

	int count_artisti= 0; //VARIABILE CONTATORE CHE CONTERRA' IL NUMERO DI ARTISTI SALVATI SUL FILE "Artisti.txt", CALCOLATO NELLA FUNZIONE "lettura_artisti_da_file"
	count_artisti= lettura_artisti_da_file(file_artisti, artista, i); //ASSEGNA A "count_artisit" IL VALORE RESTITUITO DALLA FUNZIONE "lettura_artisti_da_file", OSSIA IL NUMERO DEGLI ARTISTI SALVATI NEL FILE "Artisti.txt"

	char genere_ricercato[LUNG_GENERE]; //GENERE MUSICALE DEGLI ARTISTI DA RICERCARE

	int genere_errato= 0; //FLAG CHE VERRA' IMPOSTATO A '1' NEL CASO IN CUI LA STRINGA DEL GENERE INSERITO CONTENGA AL SUO INTERNO UN CARATTERE NUMERICO (non consentito!)
	int genere_trovato= 0; //FLAG CHE VERRA' IMPOSTATO A '1' NEL CASO IN CUI IL GENERE INSERITO E' STATO TROVATO NEL FILE "Artisti.txt"
	int lung_genere_inserito= 0; //VARIABILE CHE CONTERRA' LA LUNGHEZZA EFFETTIVA DEL GENERE INSERITO, IL NUMERO DI CARATTERI DI CUI E' COMPOSTA LA STRINGA

//ACQUISIZIONE DEL GENERE: PARAMETRO DI RICERCA DEGLI ARTISTI
	do
	{
		genere_errato= 0; //RIPRISTINO DEL VALORE DI PARTENZA DEL FLAG "genere_errato"
		genere_trovato= 0; //RIPRISTINO DEL VALORE DI PARTENZA DEL FLAG "genere_trovato"

		printf("\n\n> INSERISCI IL GENERE:   ");
		scanf("%s", genere_ricercato); //ACQUISIZIONE DEL GENERE

		lung_genere_inserito= strlen(genere_ricercato); //DETERMINA IL NUMERO DI CARATTERI DI CUI E' COMPOSTA LA STRINGA INSERITA (GENERE RICERCATO)

	//VERIFICA VALIDITA' GENERE
		for(int j=0; j < lung_genere_inserito; j++)
		{
			if((isdigit(genere_ricercato[j])) == 1) //CONDIZIONE CHE VERIFICA SE IL j-CARATTERE DELLA STRINGA INSERITA (GENERE RICERCATO) E' UN CARATTERE NUMERICO
			{
				genere_errato= 1; //IMPOSTA IL FLAG "genere_errato" A '1' POICHE' E' STATO RILEVATO UN CARATTERE NUMERICO (non consentito!) ALL'INTERNO DELLA STRINGA INSERITA
				j= lung_genere_inserito; //NON ABBIAMO BISOGNO DI SCORRERE TUTTI I CICLI, E' SUFFICIENTE FERMARSI ALLA PRIMA OCCORRENZA DEL CARATTERE NUMERICO
			}

			else
				genere_ricercato[j]= toupper(genere_ricercato[j]); //CONVERSIONE DI TUTTI I CARATTERI DELLA STRINGA (GENERE RICERCATO) IN MAIUSCOLO
		}

	//VERIFICA PRESENZA DEL GENERE NEL FILE "Artisti.txt"
		for(i=0; i<count_artisti; i++)
		{
			if(strcmp(genere_ricercato, artista[i].genere) == 0) //CONDIZIONE CHE VERIFICA SE IL GENERE INSERITO E' PRESENTE ALL'INTERNO DEL FILE "Artisti.txt"
				genere_trovato= 1; //IMPOSTA IL FLAG "genere_trovato" A '1' POICHE' IL GENERE INDICATO E' STATO TROVATO ALL'INTERNO DEL FILE "Artista.txt"
		}

		if(genere_errato != 0 || genere_trovato == 0)
			printf("\n   * GENERE NON TROVATO, RIPROVA!\n");

	}while(genere_errato != 0 || genere_trovato == 0); //RIPETE IL CICLO FINCHE' IL VALORE DEL FLAG "genere_errato" RISULTA DIVERSO DA '0', CIO' IMPLICA CHE IL GENERE INSERITO NON E' VALIDO oppure IL VALORE DEL FLAG "genere_trovato" RISULTA UGUALE A '0', IN TAL CASO IL GENERE INDICATO NON E' PRESENTE NEL FILE "Artisti.txt"

//VISUALIZZAZIONE DEGLI ARTISTI DEL GENERE INDICATO
	printf("\n\nGENERE %s:", genere_ricercato);
	printf("\n\n\n\n\t\t   ID. ARTISTA|       NOME ARTISTA|\tGENERE MUSICALE|\tNAZIONALITA'|\t  ANNO INIZIO CARRIERA|\t     CANZONE POPOLARE|\t N.ASCOLTI|    N.LIKE|    N.DISLIKE|\n\n");

	for(i=0; i<count_artisti; i++)
	{
		if(strcmp(genere_ricercato, artista[i].genere) == 0) //CONDIZIONE CHE VERIFICA SE IL GENERE INSERITO E' UGUALE AL GENERE DELL'i-ESIMO ARTISTA SALVATO SUL FILE "Artisti.txt"
			printf("\t  %20d|%19s|%20s|%20s|%25d|%22s|%12d|%10d|%13d|\n", artista[i].id_artista, artista[i].nome_artista, artista[i].genere, artista[i].nazionalita, artista[i].anno_inizio, artista[i].canzone, artista[i].count_listen, artista[i].count_like, artista[i].count_dislike); //STAMPA DEI DATI DELL'i-ESIMO ARTISTA DEL GENERE INDICATO
	}
}

/**
 * Procedura ricerca_per_nazionalita(): permette di ricercare gli artisti di una determinata nazionalita
 *
 * Si acquisisce la stringa della nazionalita' degli artisti da ricercare, verificandone la correttezza (no caratteri numerici!)
 * e se la nazionalità indicata appartiene realmente ad almeno uno degli artisti presenti nel file. In tal caso verrà
 * stampato a video l'elenco degli artisti  aventi tale nazionalità. Se la nazionalità indicata
 * non è stata trovata nel file, errata o inesistente, si richiede all'utente di reinserire la stringa.
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

void ricerca_per_nazionalita(FILE* file_artisti, FILE* file_utenti,  FILE* file_preferenze, utenti utente[], artisti artista[], preferenze_artisti preferenza_artista[], int i, char scelta, int z)
{
	printf("\n\n\t\t\t\t\t\t\t\t\t   _______________________________________");
	printf("\n\t\t\t\t\t\t\t\t\t  |                                       |");
	printf("\n\t\t\t\t\t\t\t\t\t  |              NAZIONALITA'             |");
	printf("\n\t\t\t\t\t\t\t\t\t  |_______________________________________|\n\n");

	int count_artisti= 0; //VARIABILE CONTATORE CHE CONTERRA' IL NUMERO DI ARTISTI SALVATI SUL FILE "Artisti.txt", CALCOLATO NELLA FUNZIONE "lettura_artisti_da_file"
	count_artisti= lettura_artisti_da_file(file_artisti, artista, i); //ASSEGNA A "count_artisit" IL VALORE RESTITUITO DALLA FUNZIONE "lettura_artisti_da_file", OSSIA IL NUMERO DEGLI ARTISTI SALVATI NEL FILE "Artisti.txt"

	char nazionalita_ricercata[LUNG_NAZIONALITA]; //NAZIONALITA' DEGLI ARTISTI DA RICERCARE

	int nazionalita_errata= 0; //FLAG CHE VERRA' IMPOSTATO A '1' NEL CASO IN CUI LA STRINGA DELLA NAZIONALITA' INSERITA CONTENGA AL SUO INTERNO UN CARATTERE NUMERICO (non consentito!)
	int nazionalita_trovata= 0; //FLAG CHE VERRA' IMPOSTATO A '1' NEL CASO IN CUI LA NAZIONALITA' INSERITA E' STATA TROVATA NEL FILE "Artisti.txt"
	int lung_nazionalita_inserita= 0; //VARIABILE CHE CONTERRA' LA LUNGHEZZA EFFETTIVA DELLA NAZIONALITA' INSERITA, IL NUMERO DI CARATTERI DI CUI E' COMPOSTA LA STRINGA

//ACQUISIZIONE DELLA NAZIONALITA': PARAMETRO DI RICERCA DEGLI ARTISTI
	do
	{
		nazionalita_errata= 0; //RIPRISTINO DEL VALORE DI PARTENZA DEL FLAG "nazionalita_errata"
		nazionalita_trovata= 0; //RIPRISTINO DEL VALORE DI PARTENZA DEL FLAG "nazionalita_trovata"

		 printf("\n\n> INSERISCI LA NAZIONALITA':   ");
		 scanf("%s", nazionalita_ricercata); //ACQUISIZIONE DELLA NAZIONALITA'

		 lung_nazionalita_inserita= strlen(nazionalita_ricercata); //DETERMINA IL NUMERO DI CARATTERI DI CUI E' COMPOSTA LA STRINGA INSERITA (NAZIONALITA' RICERCATA)

	//VERIFICA VALIDITA' NAZIONALITA'
		 for(int j=0; j < lung_nazionalita_inserita; j++)
		 {
			if((isdigit(nazionalita_ricercata[j])) == 1)//CONDIZIONE CHE VERIFICA SE IL j-CARATTERE DELLA STRINGA INSERITA (NAZIONALITA' RICERCATA) E' UN CARATTERE NUMERICO
			{
				nazionalita_errata= 1; //IMPOSTA IL FLAG "nazionalita_errata" A '1' POICHE' E' STATO RILEVATO UN CARATTERE NUMERICO (non consentito!) ALL'INTERNO DELLA STRINGA INSERITA
				j= lung_nazionalita_inserita; //NON ABBIAMO BISOGNO DI SCORRERE TUTTI I CICLI, E' SUFFICIENTE FERMARSI ALLA PRIMA OCCORRENZA DEL CARATTERE NUMERICO
			}

			else
				nazionalita_ricercata[j]= toupper(nazionalita_ricercata[j]); //CONVERSIONE DI TUTTI I CARATTERI DELLA STRINGA (NAZIONALITA RICERCATA) IN MAIUSCOLO
		 }

	 //VERIFICA PRESENZA DELLA NAZIONALITA' NEL FILE "Artisti.txt"
		 for(i=0; i<count_artisti; i++)
		 {
			 if(strcmp(nazionalita_ricercata, artista[i].nazionalita) == 0) //CONDIZIONE CHE VERIFICA SE LA NAZIONALITA' INSERITA E' PRESENTE ALL'INTERNO DEL FILE "Artisti.txt"
				 nazionalita_trovata= 1; //IMPOSTA IL FLAG "nazionalita_trovata" A '1' POICHE' LA NAZIONALITA' INDICATA E' STATA TROVATA ALL'INTERNO DEL FILE "Artisti.txt"
		 }

		 if(nazionalita_errata != 0 || nazionalita_trovata == 0)
			printf("\n   * NAZIONALITA' NON TROVATA, RIPROVA!\n");

	}while(nazionalita_errata != 0 || nazionalita_trovata == 0); //RIPETE IL CICLO FINCHE' IL VALORE DEL FLAG "nazionalita_errata" RISULTA DIVERSO DA '0', CIO' IMPLICA CHE LA NAZIONALITA' INSERITA NON E' VALIDA oppure IL VALORE DEL FLAG "nazionalita_trovata" RISULTA UGUALE A '0', IN TAL CASO LA NAZIONALITA' INDICATA NON E' PRESENTE NEL FILE "Artisti.txt"

//VISUALIZZAZIONE DEGLI ARTISTI DELLA NAZIONALITA' INDICATA
	printf("\n\nNAZIONALITA' %s:", nazionalita_ricercata);
	printf("\n\n\n\n\t\t   ID. ARTISTA|       NOME ARTISTA|\tGENERE MUSICALE|\tNAZIONALITA'|\t  ANNO INIZIO CARRIERA|\t     CANZONE POPOLARE|\t N.ASCOLTI|    N.LIKE|    N.DISLIKE|\n\n");

	for(i=0; i<count_artisti; i++)
	{
		if(strcmp(nazionalita_ricercata, artista[i].nazionalita) == 0) //CONDIZIONE CHE VERIFICA SE LA NAZIONALITA' INSERITA E' UGUALE ALLA NAZIONALITA' DELL'i-ESIMO ARTISTA SALVATO SUL FILE "Artisti.txt"
			printf("\t  %20d|%19s|%20s|%20s|%25d|%22s|%12d|%10d|%13d|\n", artista[i].id_artista, artista[i].nome_artista, artista[i].genere, artista[i].nazionalita, artista[i].anno_inizio, artista[i].canzone, artista[i].count_listen, artista[i].count_like, artista[i].count_dislike); //STAMPA DEI DATI DELL'i-ESIMO ARTISTA DELLA NAZIONALITA' INDICATO
	}
}

/**
 * Procedura ricerca_per_anno_di_produzione(): peremette di ricercare gli artisti con anno di produzione compreso nel range di valori indicato
 *
 * Si acquisisce l'anno di inizio ricerca, verificando che non risulti maggiore o minore dei limiti imposti.
 * Si acquisise l'anno di fine ricerca, verificando che non risulti maggiore o minore dei vincoli imposti e che non sia
 * maggiore dell'anno di inizio ricerca.
 *
 * Una volta definito tali elementi, verrà stampata la lista degli artisti aventi anno di produzione compreso nel range indicato
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

void ricerca_per_anno_inizio_produzione(FILE* file_artisti, FILE* file_utenti,  FILE* file_preferenze, utenti utente[], artisti artista[], preferenze_artisti preferenza_artista[], int i, char scelta, int z)
{
	printf("\n\n\n\t\t\t\t\t\t\t\t\t   _______________________________________");
	printf("\n\t\t\t\t\t\t\t\t\t  |                                       |");
	printf("\n\t\t\t\t\t\t\t\t\t  |        ANNO INIZIO PRODUZIONE         |");
	printf("\n\t\t\t\t\t\t\t\t\t  |_______________________________________|\n\n\n");

	int count_artisti= 0; //VARIABILE CONTATORE CHE CONTERRA' IL NUMERO DI ARTISTI SALVATI SUL FILE "Artisti.txt", CALCOLATO NELLA FUNZIONE "lettura_artisti_da_file"
	count_artisti= lettura_artisti_da_file(file_artisti, artista, i); //ASSEGNA A "count_artisit" IL VALORE RESTITUITO DALLA FUNZIONE "lettura_artisti_da_file", OSSIA IL NUMERO DEGLI ARTISTI SALVATI NEL FILE "Artisti.txt"

	int primo_anno= 0, secondo_anno= 0; //LA VARIABILE "primo_anno" E' DESTINATA A CONTENERE L'ANNO DI INIZIO RICERCA, LA VARIABILE "secondo_anno" E' DESTINATA A CONTENERE L'ANNO DI FINE RICERCA

//ACQUISIZIONE DEL RANGE DELL'ANNO DI INIZO PRODUZIONE: PARAMETRO PER CUI RICERCARE GLI ARTISTI
	do
	{
	//ACQUISIZIONE DELL'ANNO DI INIZIO RICERCA
		do
		{
			printf("\n> INSERISCI L'ANNO DI INIZIO RICERCA:   ");
			scanf("%d", &primo_anno); //ACQUISIZIONE DEL PRIMO ANNO

			if(primo_anno > ANNO_MAX || primo_anno < ANNO_MIN)
				printf("\n\n   * ANNO NON VALIDO, INSERIRE UN VALORE COMPRESO TRA %d E %d!\n\n", ANNO_MIN, ANNO_MAX);

		}while(primo_anno > ANNO_MAX || primo_anno < ANNO_MIN); //RIPETE IL CICLO FINCHE' L'ANNO INSERITO RISULTA MAGGIORE DELL'ANNO MASSIMO PREDEFINTO (= 2018) oppure RISULTA MINORE DELL'ANNO MINIMO PREDEFINITO (= 1901)

	//ACQUISIZIONE DELL'ANNO DI FINE RICERCA
		do
		{
			printf("\n\n> INSERISCI ANNO FINE RICERCA:   ");
			scanf("%d", &secondo_anno); //ACQUISIZIONE DEL SECONDO ANNO

			if(secondo_anno > ANNO_MAX || secondo_anno < ANNO_MIN)
				printf("\n\n   * ANNO NON VALIDO, INSERIRE UN VALORE COMPRESO TRA %d E %d!\n", ANNO_MIN, ANNO_MAX);

		}while(secondo_anno > ANNO_MAX || secondo_anno < ANNO_MIN); //RIPETE IL CICLO FINCHE' L'ANNO INSERITO RISULTA MAGGIORE DELL'ANNO MASSIMO PREDEFINTO (= 2018) oppure RISULTA MINORE DELL'ANNO MINIMO PREDEFINITO (= 1901)

		if(primo_anno > secondo_anno)
			printf("\n\n   * RANGE NON VALIDO, L'ANNO DI INIZIO RICERCA RISULTA PIU' GRANDE DELL'ANNO DI FINE RICERCA. RIPROVA!\n\n\n");

	}while(primo_anno > secondo_anno); //RIPETE IL CICLO FINCHE' L'ANNO DI INIZIO RICERCA RISULTA MAGGIORE DELL'ANNO DI FINE RICERCA

//VISUALIZZAZIONE DEGLI ARTISTI CON ANNO DI INIZIO PRODUZIONE COMPRESO NEL RANGE INDICATO
	printf("\n\nANNO DI PRODUZIONE: %d -> %d", primo_anno, secondo_anno);
	printf("\n\n\n\n\t\t   ID. ARTISTA|       NOME ARTISTA|\tGENERE MUSICALE|\tNAZIONALITA'|\t  ANNO INIZIO CARRIERA|\t     CANZONE POPOLARE|\t N.ASCOLTI|    N.LIKE|    N.DISLIKE|\n\n");

	for(i=0; i<count_artisti; i++)
	{
		if(artista[i].anno_inizio >= primo_anno && artista[i].anno_inizio <= secondo_anno) //CONDIZIONE CHE VERIFICA SE L'ANNO DI INIZIO PRODUZIONE DELL'i-ESIMO ARTISTA E' COMPRESO NEL RANGE DI ANNI INDICATO
			printf("\t  %20d|%19s|%20s|%20s|%25d|%22s|%12d|%10d|%13d|\n", artista[i].id_artista, artista[i].nome_artista, artista[i].genere, artista[i].nazionalita, artista[i].anno_inizio, artista[i].canzone, artista[i].count_listen, artista[i].count_like, artista[i].count_dislike); //STAMPA I DATI DELL'i-ESIMO ARTISTA CON ANNO DI PRODUZIONE COMPRESO NEL RANGE DI ANNI INDICATO
	}
}

/**
 * Procedura classifiche_artisti()
 *
 * Vengono stampate le 2 classifiche dei top 10 artisti, in base al numero di ascolti e like ad essi associati.
 * L'utente sceglierà quale visionare inserendo un valore di scelta. Il valore della scelta è un carattere numerico,
 * si richiede, quindi, di inserire un valore compreso nel range indicato. Se si inserisce una stringa o un
 * carattere non valido verra' richiesto di reinserire il valore.
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

void classifiche_artisti(FILE* file_artisti, FILE* file_utenti,  FILE* file_preferenze, utenti utente[], artisti artista[], preferenze_artisti preferenza_artista[], int i, char scelta, int z)
{
	printf("\n\n\t\t\t\t\t\t\t\t\t   _______________________________________");
	printf("\n\t\t\t\t\t\t\t\t\t  |                                       |");
	printf("\n\t\t\t\t\t\t\t\t\t  |          CLASSIFICHE ARTISTI          |");
	printf("\n\t\t\t\t\t\t\t\t\t  |_______________________________________|");
	printf("\n\n\n\t\t\t\t\t\t\t\t\t   _______________________________________");
	printf("\n\t\t\t\t\t\t\t\t\t  |                                       |");
	printf("\n\t\t\t\t\t\t\t\t\t  |        1. TOP %d PIU' ASCOLTATI       |", N_TOP);
	printf("\n\t\t\t\t\t\t\t\t\t  |_______________________________________|");
	printf("\n\n\t\t\t\t\t\t\t\t\t   _______________________________________");
	printf("\n\t\t\t\t\t\t\t\t\t  |                                       |");
	printf("\n\t\t\t\t\t\t\t\t\t  |        2. TOP %d PIU' PIACIUTI        |", N_TOP);
	printf("\n\t\t\t\t\t\t\t\t\t  |_______________________________________|");
	printf("\n\n\t\t\t\t\t\t\t\t\t   _______________________________________");
	printf("\n\t\t\t\t\t\t\t\t\t  |                                       |");
	printf("\n\t\t\t\t\t\t\t\t\t  |                3. EXIT                |");
	printf("\n\t\t\t\t\t\t\t\t\t  |_______________________________________|");

//ACQUISIZIONE DELLA SCELTA
	do
	{
		fflush(stdin); //PULIZIA DEL BUFFER DELLA TASTIERA PRIMA...
		printf("\n\n\n\t\t\t\t\t\t\t\t\t   > QUALE CLASSICFICA DESIDERI VISIONARE?   ");
		scanf("%c", &scelta); //ACQUISIZIONE DELLA SCELTA
		fflush(stdin); //...E DOPO L'UTILIZZO

		if(scelta < '1' || scelta > '3')
			printf("\n\n\t\t\t\t\t\t\t\t\t       * SCELTA NON VALIDA, RIPROVA!\n");

	}while(scelta < '1' || scelta > '3'); //RIPETE IL CICLO FINCHE' IL CARATTERE INSERITO NON E' VALIDO

	switch(scelta)
	{
		case '1': //"scelta"= '1' -> TOP ARTISTI PIU' ASCOLTATI
			system("cls"); //PULIZIA DELLO SCHERMO
			scritta_spotify(); //CHIAMATA DELLA PROCEDURA "scritta_spotify" CHE STAMPA A VIDEO LA SCRITTA "SPOTIFY"
			classifica_top_listen(file_artisti, file_utenti, file_preferenze, utente, artista, preferenza_artista, i, scelta, z); //CHIAMATA DELLA PROCEDURA "classifica_top_listen" CHE PERMETTE DI STAMPARE A VIDEO LA CLASSIFICA DEI TOP 10 ARTISTI PIU' ASCOLTATI
			return_menu_utente(file_artisti, file_utenti, file_preferenze, utente, artista, preferenza_artista, i, scelta, z); //CHIAMATA DELLA PROCEDURA "return_menu_utente" CHE PERMETTE ALL'UTENTE DI RITORNARE AL SUO MENU' AL TERMINE DELL'OPERAZIONE ESEGUITA
			break;

		case '2': //"scelta"= '2' -> TOP ARTISTI PIU' PIACIUTI
			system("cls"); //PULIZIA DELLO SCHERMO
			scritta_spotify(); //CHIAMATA DELLA PROCEDURA "scritta_spotify" CHE STAMPA A VIDEO LA SCRITTA "SPOTIFY"
			classifica_top_like(file_artisti, file_utenti, file_preferenze, utente, artista, preferenza_artista, i, scelta, z); //CHIAMATA DELLA PROCEDURA "classifica_top_like" CHE PERMETTE DI STAMPARE A VIDEO LA CLASSIFICA DEI TOP 10 ARTISTI PIU' PIACIUTI
			return_menu_utente(file_artisti, file_utenti, file_preferenze, utente, artista, preferenza_artista, i, scelta, z); //CHIAMATA DELLA PROCEDURA "return_menu_utente" CHE PERMETTE ALL'UTENTE DI RITORNARE AL SUO MENU' AL TERMINE DELL'OPERAZIONE ESEGUITA
			break;

		case '3': //"scelta"= '3' -> EXIT
			system("cls"); //PULIZIA DELLO SCHERMO
			scritta_spotify(); //CHIAMATA DELLA PROCEDURA "scritta_spotify" CHE STAMPA A VIDEO LA SCRITTA "SPOTIFY"
			menu_utente(file_artisti, file_utenti, file_preferenze, utente, artista, preferenza_artista, i, scelta, z); //CHIAMATA DELLA PROCEDURA "menu_utente" CHE PERMETTE ALL'UTENTE DI RITORNARE AL SUO MENU' PER ESEGUIRE UNA NUOVA OPERAZIONE
			break;
	}
}

/**
 * Procedura classifica_top_listen():
 *
 * Verrà stampata la classifica dei top 10 artisti piu' ascoltati.
 * Tale classifica è generata da un ordinamento (bubble sort) che stampa gli artisti in base al numero
 * di ascolti ad essi associati.
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

void classifica_top_listen(FILE* file_artisti, FILE* file_utenti,  FILE* file_preferenze, utenti utente[], artisti artista[], preferenze_artisti preferenza_artista[], int i, char scelta, int z)
{
	printf("\n\n\n\t\t\t\t\t\t\t\t\t   _______________________________________");
	printf("\n\t\t\t\t\t\t\t\t\t  |                                       |");
	printf("\n\t\t\t\t\t\t\t\t\t  |          TOP %d PIU' ASCOLTATI        |", N_TOP);
	printf("\n\t\t\t\t\t\t\t\t\t  |_______________________________________|");

	int count_artisti= 0; //VARIABILE CONTATORE CHE CONTERRA' IL NUMERO DI ARTISTI SALVATI SUL FILE "Artisti.txt", CALCOLATO NELLA FUNZIONE "lettura_artisti_da_file"
	count_artisti= lettura_artisti_da_file(file_artisti, artista, i); //ASSEGNA A "count_artisiti" IL VALORE RESTITUITO DALLA FUNZIONE "lettura_artisti_da_file", OSSIA IL NUMERO DEGLI ARTISTI SALVATI NEL FILE "Artisti.txt"

	artisti temp; //VARIABILE TEMPORANEA D'APPOGGIO UTILIZZATA PER EFFETTUARE L'ORDINAMENTO

//ORDINAMENTO (BUBBLE SORT) DEGLI ARTISTI PRESENTI SUL FILE "Artisti.txt" SULLA BASE DEL NUMERO DI "LISTEN" ESPRESSI PER CIASCUNO DI ESSI
	for(i=count_artisti-1; i>=0; i--)
	{
		for(int j=count_artisti; j>0; j--)
		{
			if(artista[i].count_listen < artista[j].count_listen)
			{
				temp= artista[j];
				artista[j]= artista[i];
				artista[i]= temp;
			}
		}
	}

//STAMPA DEI DATI DEI TOP 10 ARTISTI PIU' ASCOLTATI
	printf("\n\n\n\n\t\t   ID. ARTISTA|       NOME ARTISTA|\tGENERE MUSICALE|\tNAZIONALITA'|\t  ANNO INIZIO CARRIERA|\t     CANZONE POPOLARE|\t N.ASCOLTI|    N.LIKE|    N.DISLIKE|\n\n");

	for(i=0; i<N_TOP; i++)
		printf("\t  %20d|%19s|%20s|%20s|%25d|%22s|%12d|%10d|%13d|\n", artista[i].id_artista, artista[i].nome_artista, artista[i].genere, artista[i].nazionalita, artista[i].anno_inizio, artista[i].canzone, artista[i].count_listen, artista[i].count_like, artista[i].count_dislike); //STAMPA I DATI DELL'i-ESIMO ARTISTA CON MAGGIOR NUMERO DI "LISTEN"
}

/**
 * Procedura classifica_top_like():
 *
 * Verrà stampata la classifica dei top 10 artisti piu' piaciuti.
 * Tale classifica è generata da un ordinamento (bubble sort) che stampa gli artisti in base al numero
 * di like ad essi associati.
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

void classifica_top_like(FILE* file_artisti, FILE* file_utenti,  FILE* file_preferenze, utenti utente[], artisti artista[], preferenze_artisti preferenza_artista[], int i, char scelta, int z)
{
	printf("\n\n\n\t\t\t\t\t\t\t\t\t   _______________________________________");
	printf("\n\t\t\t\t\t\t\t\t\t  |                                       |");
	printf("\n\t\t\t\t\t\t\t\t\t  |           TOP %d PIU' PIACIUTI        |", N_TOP);
	printf("\n\t\t\t\t\t\t\t\t\t  |_______________________________________|");

	int count_artisti= 0; //VARIABILE CONTATORE CHE CONTERRA' IL NUMERO DI ARTISTI SALVATI SUL FILE "Artisti.txt", CALCOLATO NELLA FUNZIONE "lettura_artisti_da_file"
	count_artisti= lettura_artisti_da_file(file_artisti, artista, i); //ASSEGNA A "count_artisiti" IL VALORE RESTITUITO DALLA FUNZIONE "lettura_artisti_da_file", OSSIA IL NUMERO DEGLI ARTISTI SALVATI NEL FILE "Artisti.txt"

	artisti temp; //VARIABILE TEMPORANEA D'APPOGGIO UTILIZZATA PER EFFETTUARE L'ORDINAMENTO

//ORDINAMENTO (BUBBLE SORT) DEGLI ARTISTI PRESENTI SUL FILE "Artisti.txt" SULLA BASE DEL NUMERO DI "LIKE" ESPRESSI PER CIASCUNO DI ESSI
	for(i=count_artisti-1; i>=0; i--)
	{
		for(int j=count_artisti; j>0; j--)
		{
			if(artista[i].count_like < artista[j].count_like)
			{
				temp= artista[j];
				artista[j]= artista[i];
				artista[i]= temp;
			}
		}
	}

//STAMPA DEI DATI DEI TOP 10 ARTISTI PIU' PIACIUTI
	printf("\n\n\n\n\t\t   ID. ARTISTA|       NOME ARTISTA|\tGENERE MUSICALE|\tNAZIONALITA'|\t  ANNO INIZIO CARRIERA|\t     CANZONE POPOLARE|\t N.ASCOLTI|    N.LIKE|    N.DISLIKE|\n\n");

	for(i=0; i<N_TOP; i++)
		printf("\t  %20d|%19s|%20s|%20s|%25d|%22s|%12d|%10d|%13d|\n", artista[i].id_artista, artista[i].nome_artista, artista[i].genere, artista[i].nazionalita, artista[i].anno_inizio, artista[i].canzone, artista[i].count_listen, artista[i].count_like, artista[i].count_dislike); //STAMPA I DATI DELL'i-ESIMO ARTISTA CON MAGGIOR NUMERO DI "LIKE"
}

/**
 * Procedura suggerimento_artista():
 *
 * Tale procedura "suggerimento_artista" stampa a video gli artisti graditi
 * dagli utenti a lui simili in base alle preferenze da lui espresse.
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

void suggerimento_artisti(FILE* file_artisti, FILE* file_utenti,  FILE* file_preferenze, utenti utente[], artisti artista[], preferenze_artisti preferenza_artista[], int i, char scelta, int z)
{
	z= lettura_indice_utente_loggato(file_utenti, utente, i, z);  //ASSEGNA A "z" IL VALORE RESTITUITO DALLA FUNZIONE "lettura_indice_utente_loggato", L'INDICE DELL'UTENTE CHE HA EFFETTUATO IL LOGIN

	int count_preferenze= 0; //VARIABILE CONTATORE CHE CONTERRA' IL NUMERO DI PREFERENZE SALVATE SUL FILE "Preferenze.txt", CALCOLATO NELLA FUNZIONE "lettura_preferenze_da_file"
	count_preferenze= lettura_preferenze_da_file(file_preferenze, artista, preferenza_artista, i); //ASSEGNA A "count_preferenze" IL VALORE RESTITUITO DALLA FUNZIONE "lettura_preferenze_da_file", OSSIA IL NUMERO DELLE PREFERENZE SALVATE NEL FILE "Preferenze.txt"

//PREFERENZE SIMILI
	for(i=0; i<count_preferenze; i++)
	{
		if(strcmp(utente[z].username, preferenza_artista[i].username_utente) == 0) //VERIFICA SE L'USERNAME DELL'i-ESIMA PREFERENZA SALVATA SUL FILE "Preferenze.txt" E'UGUALE ALL'USERNAME DELL'UTENTE LOGGATO
		{
			for(int j=0; j<count_preferenze; j++)
			{
				if(strcmp(preferenza_artista[j].username_utente, preferenza_artista[i].username_utente) != 0)
				{
					if(strcmp(preferenza_artista[i].nome_artista, preferenza_artista[j].nome_artista) == 0 && strcmp(preferenza_artista[i].preferenza, preferenza_artista[j].preferenza) == 0)
					{
						for(int x=0; x<count_preferenze; x++)
						{
							if(strcmp(preferenza_artista[j].username_utente, preferenza_artista[x].username_utente) == 0)
							{
								if(strcmp(preferenza_artista[x].preferenza, "LIKE") == 0 && strcmp(preferenza_artista[x].nome_artista, preferenza_artista[i].nome_artista) != 0 && strcmp(preferenza_artista[x].preferenza, preferenza_artista[i].preferenza) != 0)
									printf("\n\n-> %s TI SUGGERISCE  %s ", preferenza_artista[j].username_utente, preferenza_artista[x].nome_artista); //STAMPA DELL'ARTISTA GRADITO DAL j-ESIMO UTENTE SALVATO NEL FILE "Preferenze.txt"
							}
						}
					}
				}
			}
		}
	}
}

/**
 * Procedura profilo():
 *
 * Verranno stampati i dati dell'utente loggato insieme alle 5 operazioni per effettuare eventuali modifiche al profilo e alle preferenze
 * L'utente sceglierà quale operazione eseguire inserendo un valore di scelta. Il valore della scelta è un carattere numerico,
 * si richiede, quindi, di inserire un valore compreso nel range indicato. Se si inserisce una stringa o un
 * carattere non valido verra' richiesto di reinserire il valore.
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

void profilo(FILE* file_artisti, FILE* file_utenti, FILE* file_preferenze, utenti utente[], artisti artista[], preferenze_artisti preferenza_artista[], int i, char scelta, int z)
{
	printf("\n\n\t\t\t\t\t\t\t\t\t   _______________________________________");
    printf("\n\t\t\t\t\t\t\t\t\t  |                                       |");
    printf("\n\t\t\t\t\t\t\t\t\t  |                PROFILO                |");
    printf("\n\t\t\t\t\t\t\t\t\t  |_______________________________________|");

    z= lettura_indice_utente_loggato(file_utenti, utente, i, z);  //ASSEGNA A "z" IL VALORE RESTITUITO DALLA FUNZIONE "lettura_indice_utente_loggato", L'INDICE DELL'UTENTE CHE HA EFFETTUATO IL LOGIN

    printf("\n\n\n\n\t\t\t\t\tID. UTENTE|\t      NOME|\t     COGNOME|\t      DATA DI NASCITA|\t        USERNAME|\t   PASSWORD|\n\n");
    printf("\t\t\t\t  %16d|%15s|%17s|%12d / %2d / %d|%18s|%18s|  \n", utente[z].id_utente, utente[z].nome_utente, utente[z].cognome_utente, utente[z].giorno_nascita, utente[z].mese_nascita, utente[z].anno_nascita, utente[z].username, utente[z].password);

    printf("\n\n\n\t\t  ______________________________________                   _______________________________________\n"
           "\t\t |              __________              |                 |                                       |\n"
           "\t\t |             |**********|             |                 |          1. MODIFICA PROFILO          |\n"
           "\t\t |            |************|            |                 |_______________________________________|\n"
           "\t\t |           |**************|           |\n"
           "\t\t |          |****************|          |                  _______________________________________\n"
           "\t\t |           |**************|           |                 |                                       |\n"
           "\t\t |            |************|            |                 |     2. VISUALIZZA LISTA PREFERENZE    |\n"
           "\t\t |             |**********|             |                 |_______________________________________|\n"
           "\t\t |       ________|******|________       |\n"
           "\t\t |      |************************|      |                  _______________________________________\n"
           "\t\t |     |******|*************|*****|     |                 |                                       |\n"
           "\t\t |    |*******|*************|******|    |                 |       3. MODIFICA UNA PREFERENZA      |\n"
           "\t\t |                                      |                 |_______________________________________|\n"
           "\t\t |______________________________________|\n");
	printf("\t\t\t\t\t\t\t\t\t   _______________________________________");
	printf("\n\t\t\t\t\t\t\t\t\t  |                                       |");
	printf("\n\t\t\t\t\t\t\t\t\t  |       4. ELIMINA UNA PREFERENZA       |");
	printf("\n\t\t\t\t\t\t\t\t\t  |_______________________________________|\n\n");
	printf("\t\t\t\t\t\t\t\t\t   _______________________________________");
	printf("\n\t\t\t\t\t\t\t\t\t  |                                       |");
	printf("\n\t\t\t\t\t\t\t\t\t  |           5. ELIMINA ACCOUNT          |");
	printf("\n\t\t\t\t\t\t\t\t\t  |_______________________________________|\n\n");
	printf("\t\t\t\t\t\t\t\t\t   _______________________________________");
	printf("\n\t\t\t\t\t\t\t\t\t  |                                       |");
	printf("\n\t\t\t\t\t\t\t\t\t  |                6. EXIT                |");
	printf("\n\t\t\t\t\t\t\t\t\t  |_______________________________________|");

	do
	{
		fflush(stdin); //PULIZIA DEL BUFFER DELLA TASTIERA PRIMA...
		printf("\n\n\n\t\t\t\t\t\t\t\t\t   > QUALE OPERAZIONE DESIDERI EFFETTUARE?   ");
		scanf("%c", &scelta); //ACQUISIZIONE DELLA SCELTA
		fflush(stdin); //...E DOPO L'UTILIZZO

		if(scelta < '1' || scelta > '6')
			printf("\n\n\t\t\t\t\t\t\t\t\t       * SCELTA NON VALIDA, RIPROVA!\n");

	}while(scelta < '1' || scelta > '6'); //RIPETE IL CICLO FINCHE' IL CARATTERE INSERITO NON E' VALIDO

	switch(scelta)
	{
		case '1': //"scelta"= '1' -> MODIFICA PROFILO
			system("cls"); //PULIZIA DELLO SCHERMO
			scritta_spotify(); //CHIAMATA DELLA PROCEDURA "scritta_spotify" CHE STAMPA A VIDEO LA SCRITTA "SPOTIFY"
			modifica_profilo(file_artisti, file_utenti, file_preferenze, utente, artista, preferenza_artista, i, scelta, z); //CHIAMATA DELLA PROCEDURA "modifica_profilo" CHE PERMETTE ALL'UTENTE DI MODIFICARE I SUOI DATI
			return_menu_utente(file_artisti, file_utenti, file_preferenze, utente, artista, preferenza_artista, i, scelta, z); //CHIAMATA DELLA PROCEDURA "return_menu_utente" CHE PERMETTE ALL'UTENTE DI RITORNARE AL SUO MENU' AL TERMINE DELL'OPERAZIONE ESEGUITA
			break;

		case '2': //"scelta"= '2' -> VISUALIZZA PREFERENZE DELL'UTENTE
			system("cls"); //PULIZIA DELLO SCHERMO
			scritta_spotify(); //CHIAMATA DELLA PROCEDURA "scritta_spotify" CHE STAMPA A VIDEO LA SCRITTA "SPOTIFY"
			printf("\n\n\t\t\t\t\t\t\t\t\t   _______________________________________");
			printf("\n\t\t\t\t\t\t\t\t\t  |                                       |");
			printf("\n\t\t\t\t\t\t\t\t\t  |      VISUALIZZA LISTA PREFERENZE      |");
			printf("\n\t\t\t\t\t\t\t\t\t  |_______________________________________|");

			visualizza_preferenze(file_artisti, file_utenti, file_preferenze, utente, artista, preferenza_artista, i, z); //CHIAMATA DELLA PROCEDURA "visualizza_preferenze" CHE STAMPA A VIDEO LA LISTA DELLE PREFERENZE DELL'UTENTE LOGGATO
			return_menu_utente(file_artisti, file_utenti, file_preferenze, utente, artista, preferenza_artista, i, scelta, z); //CHIAMATA DELLA PROCEDURA "return_menu_utente" CHE PERMETTE ALL'UTENTE DI RITORNARE AL SUO MENU' AL TERMINE DELL'OPERAZIONE ESEGUITA
			break;

		case '3': //"scelta"= '3' -> MODIFICA UNA PREFERENZA
			system("cls"); //PULIZIA DELLO SCHERMO
			scritta_spotify(); //CHIAMATA DELLA PROCEDURA "scritta_spotify" CHE STAMPA A VIDEO LA SCRITTA "SPOTIFY"
			modifica_preferenza(file_artisti, file_utenti, file_preferenze, utente, artista, preferenza_artista, i, scelta, z); //CHIAMATA DELLA PROCEDURA "modifica_preferenza" CHE PERMETTE ALL'UTENTE DI MODIFICARE UNA SUA PREFERENZA ESPRESSA PER UN DETERMINATO ARTISTA
			break;

		case '4': //"scelta"= '4' -> ELIMINA UNA PREFERENZA
			system("cls"); //PULIZIA DELLO SCHERMO
			scritta_spotify(); //CHIAMATA DELLA PROCEDURA "scritta_spotify" CHE STAMPA A VIDEO LA SCRITTA "SPOTIFY"
			elimina_preferenza(file_artisti, file_utenti, file_preferenze, utente, artista, preferenza_artista, i, scelta, z); //CHIAMATA DELLA PROCEDURA "eliminaa_preferenza" CHE PERMETTE ALL'UTENTE DI ELIMINARE UNA SUA PREFERENZA ESPRESSA PER UN DETERMINATO ARTISTA
			return_menu_utente(file_artisti, file_utenti, file_preferenze, utente, artista, preferenza_artista, i, scelta, z); //CHIAMATA DELLA PROCEDURA "return_menu_admin" CHE PERMETTE ALL'AMMINISTRATORE DI RITORNARE AL SUO MENU' AL TERMINE DELL'OPERAZIONE ESEGUITA
			break;

		case '5': //"scelta"= '5' -> ELIMINA ACCOUNT
			system("cls"); //PULIZIA DELLO SCHERMO
			scritta_spotify(); //CHIAMATA DELLA PROCEDURA "scritta_spotify" CHE STAMPA A VIDEO LA SCRITTA "SPOTIFY"
			elimina_account(file_artisti, file_utenti, file_preferenze, utente, artista, preferenza_artista, i, scelta, z); //CHIAMATA DELLA PROCEDURA "elimina_account" CHE CONSENTE ALL'UTENTE DI ELIMINARE IL SUO ACCOUNT
			break;

		case '6': //"scelta"= '6' -> EXIT
			system("cls"); //PULIZIA DELLO SCHERMO
			scritta_spotify(); //CHIAMATA DELLA PROCEDURA "scritta_spotify" CHE STAMPA A VIDEO LA SCRITTA "SPOTIFY"
			menu_utente(file_artisti, file_utenti, file_preferenze, utente, artista, preferenza_artista, i, scelta, z); //CHIAMATA DELLA PROCEDURA "menu_utente" CHE PERMETTE ALL'UTENTE DI RITORNARE AL SUO MENU' PER ESEGUIRE UNA NUOVA OPERAZIONE
			break;
	}
}

/**
 * Procedura modifica_profilo():
 *
 * Verranno stampati i dati relativi all'utente loggato
 * L'utente potrà poi scegliere quale campo modificare tra quelli indicati, inserendo un valore di scelta.
 * Il valore della scelta è un carattere numerico, si richiede, quindi, di inserire un valore compreso nel range indicato.
 * Se si inserisce una stringa o un carattere non valido verra' richiesto di reinserire il valore.
 * Si verifica la correttezza di ogni campo modificato.
 * Verranno poi salvati su file i dati dell'utente con le varie modifiche apportate.
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

void modifica_profilo(FILE* file_artisti, FILE* file_utenti, FILE* file_preferenze, utenti utente[], artisti artista[], preferenze_artisti preferenza_artista[], int i, char scelta, int z)
{
	printf("\n\n\t\t\t\t\t\t\t\t\t   _______________________________________");
    printf("\n\t\t\t\t\t\t\t\t\t  |                                       |");
	printf("\n\t\t\t\t\t\t\t\t\t  |            MODIFICA PROFILO           |");
	printf("\n\t\t\t\t\t\t\t\t\t  |_______________________________________|");

    int count_utenti= 0; //VARIABILE CONTATORE CHE CONTERRA' IL NUMERO DI UTENTI SALVATI SUL FILE "Utenti.txt", CALCOLATO NELLA FUNZIONE "lettura_utenti_da_file"
    count_utenti= lettura_utenti_da_file(file_utenti, utente, i);

    z= lettura_indice_utente_loggato( file_utenti, utente, i, z); //ASSEGNA A "z" IL VALORE RESTITUITO DALLA FUNZIONE "lettura_indice_utente_loggato", L'INDICE DELL'UTENTE CHE HA EFFETTUATO IL LOGIN

 //STAMPA DEI DATI DELL'UTENTE LOGGATO
	printf("\n\n\n\n\t\t\t\t\tID. UTENTE|\t      NOME|\t     COGNOME|\t      DATA DI NASCITA|\t        USERNAME|\t   PASSWORD|\n\n");
	printf("\t\t\t\t  %16d|%15s|%17s|%12d / %2d / %d|%18s|%18s|  \n", utente[z].id_utente, utente[z].nome_utente, utente[z].cognome_utente, utente[z].giorno_nascita, utente[z].mese_nascita, utente[z].anno_nascita, utente[z].username, utente[z].password); //STAMPA DEI DATI RELATIVI ALL'UTENTE CHE HA EFFETTUATO L'ACCESSO

//MODIFICA DEL PROFILO UTENTE
    printf("\n\n\nMODIFICA: ");
	printf("\n\n\t1. NOME  |  2. COGNOME  |  3. DATA DI NASCITA  |  4. PASSWORD\n");

	do
	{
		fflush(stdin); //PULIZIA DEL BUFFER DELLA TASTIERA PRIMA...
		printf("\n\n> QUALE CAMPO VUOI MODIFICARE?   ");
		scanf("%c", &scelta); //ACQUISIZIONE DELLA SCELTA
		fflush(stdin); //...E DOPO L'UTILIZZO

		if(scelta < '1' || scelta > '4')
			printf("\n   * INPUT NON VALIDO, RIPROVA!\n");

	}while(scelta < '1' || scelta > '4'); //RIPETE IL CICLO FINCHE' IL CARATTERE INSERITO NON E' VALIDO

	int nome_errato= 0; //FLAG CHE VERRA' IMPOSTATO A '1' NEL CASO IN CUI LA STRINGA DEL NUOVO NOME (MODIFICATO), CONTENGA AL SUO INTERNO UN CARATTERE NUMERICO (non consentito!)
	int cognome_errato= 0; //FLAG CHE VERRA' IMPOSTATO A '1' NEL CASO IN CUI LA STRINGA DEL NUOVO COGNOME (MODIFICATO), CONTENGA AL SUO INTERNO UN CARATTERE NUMERICO (non consentito!)
	int count_maiuscole= 0; //VARIABILE CONTATORE CHE CONTERRA' IL NUMERO DI LETTERE MAIUSCOLE PRESENTI NELLA STRINGA "PASSWORD"
	int count_numeri= 0; //VARIABILE CONTATORE CHE CONTERRA' IL NUMERO DI CIFRE NUMERICHE PRESENTI NELLA STRINGA "PASSWORD"
	int lung_password_inserita=0; //VARIABILE CHE CONTERRA' LA LUNGHEZZA EFFETTIVA DELL'USERNAME INSERITO, IL NUMERO DI CARATTERI DI CUI E' COMPOSTA LA STRINGA

	switch(scelta)
	{
		case '1': //"scelta"= '1' -> MODIFICA "NOME UTENTE"
			do
			{
				nome_errato= 0; //RIPRISTINO DEL VALORE DI PARTENZA DEL FLAG "nome_errato".

				printf("\n\n\n> INSERISCI IL NUOVO NOME:   ");
				scanf("%s", utente[z].nome_utente); //ACQUISIZIONE DEL NUOVO NOME

			//VERIFICA VALIDITA' NOME
				for(int j=0; j < LUNG_NOME; j++)
				{
					if((isdigit(utente[z].nome_utente[j])) == 1) //CONDIZIONE CHE VERIFICA SE IL j-CARATTERE DELLA STRINGA INSERITA (NOME UTENTE) E' UN CARATTERE NUMERICO.
					{
						nome_errato= 1; //IMPOSTA IL FLAG "nome_errato" A '1' POICHE' E' STATO RILEVATO UN CARATTERE NUMERICO (non consentito) ALL'INTERNO DELLA STRINGA INSERITA.
						j= LUNG_NOME;	//NON ABBIAMO BISOGNO DI SCORRERE TUTTI I CICLI, E' SUFFICIENTE FERMARSI ALLA PRIMA OCCORRENZA DEL CARATTERE NUMERICO.
					}

					else
						utente[z].nome_utente[j]= toupper(utente[z].nome_utente[j]); //CONVERSIONE DI TUTTI I CARATTERI DELLA STRINGA (NOME UTENTE) IN MAIUSCOLO.
				}

				if(nome_errato != 0)
					printf("\n   * NOME NON VALIDO, RIPROVA!");

			}while(nome_errato != 0); //RIPETE IL CICLO FINCHE' IL VALORE DEL FLAG "nome_errato" RISULTA DIVERSO DA '0', CIO' IMPLICA CHE IL NOME DELL'UTENTE NON E' VALIDO.

			break;

		case '2': //"scelta"= '2' -> MODIFICA "COGNOME UTENTE"
			do
			{
				cognome_errato= 0; //RIPRISTINO DEL VALORE DI PARTENZA DEL FLAG "cognome_errato".

				printf("\n\n\n> INSERISCI IL NUOVO COGNOME:   ");
				scanf("%s", utente[z].cognome_utente); //ACQUISIZIONE DEL NUOVO COGNOME

			//VERIFICA VALIDITA' COGNOME
				for(int j=0; j < LUNG_COGNOME; j++)
				{
					if((isdigit(utente[z].cognome_utente[j])) == 1) //CONDIZIONE CHE VERIFICA SE IL j-CARATTERE DELLA STRINGA INSERITA (COGNOME UTENTE) E' UN CARATTERE NUMERICO.
					{
						cognome_errato= 1; //IMPOSTA IL FLAG "cognome_errato" A '1' POICHE' E' STATO RILEVATO UN CARATTERE NUMERICO (non consentito) ALL'INTERNO DELLA STRINGA INSERITA.
						j= LUNG_COGNOME; //NON ABBIAMO BISOGNO DI SCORRERE TUTTI I CICLI, E' SUFFICIENTE FERMARSI ALLA PRIMA OCCORRENZA DEL CARATTERE NUMERICO.
					}

					else
						utente[z].cognome_utente[j]= toupper(utente[z].cognome_utente[j]); //CONVERSIONE DI TUTTI I CARATTERI DELLA STRINGA (COGNOME UTENTE) IN MAIUSCOLO.
				}

				if(cognome_errato != 0)
					printf("\n   * COGNOME NON VALIDO, RIPROVA!");

			}while(cognome_errato != 0); //RIPETE IL CICLO FINCHE' IL VALORE DEL FLAG "cognome_errato" RISULTA DIVERSO DA '0', CIO' IMPLICA CHE IL COGNOME DELL'UTENTE NON E' VALIDO.

			break;

		case '3':  //"scelta"= '3' -> MODIFICA DATA DI NASCITA
		//ACQUISIZIONE NUOVA DATA DI NASCITA
			printf("\n\n\nDATA DI NASCITA: ");
			do
			{
				printf("\n\n\t> INSERISCI IL NUOVO MESE DI NASCITA:   ");
				scanf("%d", &utente[z].mese_nascita); //ACQUISIZIONE DEL NUOVO MESE DI NASCITA

			//VERIFICA VALIDITA' MESE DI NASCITA
				if(utente[z].mese_nascita < MESE_MIN || utente[z].mese_nascita > MESE_MAX) //CONDIZIONE CHE VERIFICA SE IL VALORE DEL MESE INSERITO NON E' VALIDO, OSSIA: MINORE DI '1' oppure MAGGIORE DI '12'
					printf("\n\t   * MESE NON VALIDO! INSERISCI UN VALORE COMPRESO TRA %d E %d.\n", MESE_MIN, MESE_MAX);

			}while(utente[z].mese_nascita < MESE_MIN || utente[z].mese_nascita > MESE_MAX); //RIPETE IL CICLO FINCHE' IL VALORE DEL MESE INSERITO NON E' VALIDO

		//ACQUISIZIONE DEL GIORNO DI NASCITA DEL NUOVO UTENTE DA REGISTRARE
			if(utente[z].mese_nascita == 2) //CONDIZIONE CHE VERIFICA SE IL VALORE DEL MESE INSERITO E' UGUALE A '2' (= FEBBRAIO: range 1 - 28 gg)
			{
				do
				{
					printf("\n\n\t> INSERISCI IL NUOVO GIORNO DI NASCITA:   ");
					scanf("%d", &utente[z].giorno_nascita); //ACQUISIZIONE DEL NUOVO GIORNO DI NASCITA

				//VERIFICA VALIDITA' GIORNO DI NASCITA
					if(utente[z].giorno_nascita < 1 || utente[z].giorno_nascita > 28) //CONDIZIONE CHE VERIFICA SE IL VALORE DEL GIORNO INSERITO NON E' VALIDO, OSSIA: MINORE DI '1' oppure MAGGIORE DI '28'
						printf("\n\t   * GIORNO NON VALIDO! INSERISCI UN VALORE COMPRESO TRA 1 E 28.\n");

				}while(utente[z].giorno_nascita < 1 || utente[z].giorno_nascita > 28); //RIPETE IL CICLO FINCHE' IL VALORE DEL GIORNO INSERITO NON E' VALIDO
			}

			else if(utente[z].mese_nascita == 4 || utente[z].mese_nascita == 6 || utente[z].mese_nascita == 9 || utente[z].mese_nascita == 11) //CONDIZIONE CHE VERIFICA SE IL VALORE DEL MESE INSERITO E' UGUALE A '4' (= APRILE), '6' (= GIUGNO), '9' (= SETTEMBRE) oppure '11' (= NOVEMBRE) (range: 1 - 30 gg)
			{
				do
				{
					printf("\n\n\t> INSERISCI IL NUOVO GIORNO DI NASCITA:   ");
					scanf("%d", &utente[z].giorno_nascita); //ACQUISIZIONE DEL GIORNO DI NASCITA

				//VERIFICA VALIDITA' GIORNO DI NASCITA
					if(utente[z].giorno_nascita < 1 || utente[z].giorno_nascita > 30) //CONDIZIONE CHE VERIFICA SE IL VALORE DEL GIORNO INSERITO NON E' VALIDO, OSSIA: MINORE DI '1' oppure MAGGIORE DI '30'
					   printf("\n\t   * GIORNO NON VALIDO! INSERISCI UN VALORE COMPRESO TRA 1 E 30.\n");

				}while(utente[z].giorno_nascita < 1 || utente[z].giorno_nascita > 30); //RIPETE IL CICLO FINCHE' IL VALORE DEL GIORNO INSERITO NON E' VALIDO
			}

			else if(utente[z].mese_nascita == 1 || utente[z].mese_nascita == 3 || utente[z].mese_nascita == 5 || utente[z].mese_nascita == 7 || utente[z].mese_nascita == 8 || utente[z].mese_nascita == 10 || utente[z].mese_nascita == 12) //CONDIZIONE CHE VERIFICA SE IL VALORE DEL MESE INSERITO E' UGUALE A '1' (= GENNAIO), '3' (= MARZO), '5' (= MAGGIO), '7' (= LUGLIO), '8' (= AGOSTO), '10' (= OTTOBRE) oppure "12" (= DICEMBRE) (range: 1 - 31 gg)
			{
				do
				{
					printf("\n\n\t> INSERISCI IL NUOVO GIORNO DI NASCITA:   ");
					 scanf("%d", &utente[z].giorno_nascita); //ACQUISIZIONE DEL NUOVO GIORNO DI NASCITA

				//VERIFICA VALIDITA' GIORNO DI NASCITA
					if(utente[z].giorno_nascita < 1 || utente[z].giorno_nascita > 31) //CONDIZIONE CHE VERIFICA SE IL VALORE DEL GIORNO INSERITO NON E' VALIDO, OSSIA: MINORE DI '1' oppure MAGGIORE DI '31'
					   printf("\n\t   * GIORNO NON VALIDO! INSERISCI UN VALORE COMPRESO TRA 1 E 31.\n");

				}while(utente[z].giorno_nascita < 1 || utente[z].giorno_nascita > 31); //RIPETE IL CICLO FINCHE' IL VALORE DEL GIORNO INSERITO NON E' VALIDO
			}

		//ACQUISIZIONE DELL'ANNO DI NASCITA
			do
			{
				printf("\n\n\t> INSERISCI IL NUOVO ANNO DI NASCITA:   ");
				scanf("%d", &utente[z].anno_nascita); //ACQUISIZIONE DELL'NUOVO ANNO DI NASCITA

			//VERIFICA VALIDITA' ANNO DI NASCITA
				if(utente[z].anno_nascita < ANNO_MIN || utente[z].anno_nascita > ANNO_MAX) //CONDIZIONE CHE VERIFICA SE IL VALORE DELL'ANNO INSERITO NON E' VALIDO, OSSIA: MINORE DI '1901' oppure MAGGIORE DI '2018'
					printf("\n\t   * ANNO NON VALIDO! INSERISCI UN VALORE COMPRESO TRA %d E %d.\n", ANNO_MIN, ANNO_MAX);

			}while(utente[z].anno_nascita < ANNO_MIN || utente[z].anno_nascita > ANNO_MAX); //RIPETE IL CICLO FINCHE' IL VALORE DELL'ANNO INSERITO NON E' VALIDO

			break;

		case '4'://"scelta"= '4' -> MODIFICA PASSWORD
		//ACQUISIZIONE DELLA PASSWORD
			printf("\n\n\n- NOTA PASSWORD: Numero caratteri compreso tra %d e %d, con almeno una maiuscola e almeno un numero.", LUNG_PASSWORD/2, LUNG_PASSWORD);
			do
			{
				count_maiuscole= 0; //AZZERAMENTO DELLA VARIABILE "count_maiuscole"
				count_numeri= 0; //AZZERAMENTO DELLA VARIABILE "count_numeri"

				printf("\n\n> INSERISCI NUOVA PASSWORD:   ");
				scanf("%s", utente[z].password); //ACQUISIZIONE DELLA NUOVA PASSWORD

				lung_password_inserita= strlen(utente[z].password);  //DETERMINA IL NUMERO DI CARATTERI DI CUI E' COMPOSTA LA PASSWORD INSERITA

			//VERIFICA VALIDITA' PASSWORD
				for(int j=0; j < lung_password_inserita; j++)
				{
					count_numeri= count_numeri + isdigit(utente[z].password[j]); //CONTEGGIO DELLE CIFRE NUMERICHE PRESENTI NELLA PASSWORD INSERITA
					count_maiuscole= count_maiuscole + isupper(utente[z].password[j]); //CONTEGGIO DELLE LETTERE MAIUSCOLE PRESENTI NELLA PASSWORD INSERITA

					if((count_numeri > 0) && (count_maiuscole > 0))
						j= lung_password_inserita; //NON ABBIAMO BISOGNO DI SCORRERE TUTTI I CICLI SE SONO STATE GIA' RILEVATE UNA LETTERA MAIUSCOLA E UNA CIFRA NUMERICA ALL'INTERNO DELLA STRINGA INSERITA (PASSWORD)
				}

				if((lung_password_inserita < (LUNG_PASSWORD / 2)) || (lung_password_inserita > LUNG_PASSWORD)) //CONDIZIONE CHE VERIFICA SE LA LUNGHEZZA DELLA PASSWORD NON E'COMPRESA TRA: 5 e 10 CIFRE
					printf("\n   * PASSWORD NON VALIDA! INSERIRE UN NUMERO DI CARATTERI COMPRESO TRA %d E %d.\n", LUNG_PASSWORD/2, LUNG_PASSWORD);

				if(count_numeri	==	0) //CONDIZIONE CHE VERIFICA SE LA PASSWORD INSERITA NON PRESENTA AL SUO INTERNO NEANCHE UNA CIFRA NUMERICA
					printf("\n   * PASSWORD NON VALIDA! INSERIRE ALMENO UN NUMERO.\n");

				if(count_maiuscole == 0) //CONDIZIONE CHE VERIFICA SE LA PASSWORD INSERITA NON PRESENTA AL SUO INTERNO NEANCHE UNA LETTERA MAIUSCOLA
					printf("\n   * PASSWORD NON VALIDA! INSERIRE ALMENO UN CARATTERE MAIUSCOLO.\n");

			}while(!((count_numeri > 0) && (count_maiuscole > 0) && (lung_password_inserita >= (LUNG_PASSWORD / 2)) && (lung_password_inserita <= LUNG_PASSWORD))); //RIPETE IL CICLO FINCHE' I VINCOLI IMPOSTI SULLA SINTASSI DELLA PASSWORD NON SONO RISPETTATI

			break;
	}

//APERTURA DEL FILE "Utenti.txt" IN MODALITA' DI SCRITTURA ("w")
	if((file_utenti=  fopen("Utenti.txt" , "w")) == NULL)
		printf("Errore nell'apertura!\n");

//SALVATAGGIO SUL FILE "Utenti.txt" DELLE MODIFICHE APPORTATE
	else
	{
		for(i=0; i<count_utenti; i++)
			fprintf(file_utenti, "\n%d %s %s %d %d %d %s %s", utente[i].id_utente, utente[i].nome_utente, utente[i].cognome_utente, utente[i].giorno_nascita,  utente[i].mese_nascita, utente[i].anno_nascita, utente[i].username, utente[i].password); //SALVATAGGIO SUL FILE "Utenti.txt" DEI DATI DELL'i-ESIMO UTENTE

		printf("\n\n\n***************** PROFILO MODIFICATO CORRETTAMENTE! *****************\n");
	}
	fclose(file_utenti); //CHIUSURA DEL FILE
}

/**
 * Procedura visualizza_preferenze():
 *
 * Verrà stampata a video, in formato tabellare, la lista delle preferenze espresse dall'utente che ha effettuato l'accesso, presenti
 * nel file "Preferenze.txt"
 *
 * @param file_artisti
 * @param file_utenti
 * @param file_preferenze
 * @param utente
 * @param artista
 * @param preferenza_artista
 * @param i
 * @param z
 */

void visualizza_preferenze(FILE* file_artisti, FILE* file_utenti, FILE* file_preferenze, utenti utente[], artisti artista[], preferenze_artisti preferenza_artista[], int i,  int z)
{
	z= lettura_indice_utente_loggato(file_utenti, utente, i, z); //ASSEGNA A "z" IL VALORE RESTITUITO DALLA FUNZIONE "lettura_indice_utente_loggato", L'INDICE DELL'UTENTE CHE HA EFFETTUATO IL LOGIN

	int count_preferenze= 0; //VARIABILE CONTATORE CHE CONTERRA' IL NUMERO DI PREFERENZE SALVATE SUL FILE "Preferenze.txt", CALCOLATO NELLA FUNZIONE "lettura_preferenze_da_file"
	count_preferenze= lettura_preferenze_da_file(file_preferenze, artista, preferenza_artista, i); //ASSEGNA A "count_preferenze" IL VALORE RESTITUITO DALLA FUNZIONE "lettura_preferenze_da_file", OSSIA IL NUMERO DELLE PREFERENZE SALVATE NEL FILE "Preferenze.txt"

//STAMPA DELLA LISTA DI PREFERENZE ESPRESSE DALL'UTENTE LOGGATO
	printf("\n\n\n\n\t\t\t\t\t\t\t     ID. PREFERENZA|       USERNAME|\t      NOME ARTISTA|\t  PREFERENZA|\n\n");
	for(i=0; i<count_preferenze; i++)
	{
		if(strcmp(preferenza_artista[i].username_utente, utente[z].username) == 0) //CONDIZIONE CHE VERIFICA SE L'USERNAME DELL'UTENTE, SALVATO SUL FILE "Preferenze.txt", E' UGUALE ALL'USERNAME DELL'UTENTE LOGGATO
			printf("\t\t\t\t\t\t       %20d|%15s|%22s|%17s|\n", preferenza_artista[i].id_preferenza, preferenza_artista[i].username_utente, preferenza_artista[i].nome_artista, preferenza_artista[i].preferenza); //STAMPA DELL'i-ESIMAPREFERENZA ESPRESSA DALL'UTENTE LOGGATO
	}
}

/**
 * Procedura modifica_preferenza():
 *
 * Verranno stampate le preferenze dell'utente che ha effettuato il login, il quale potrà scegliere di modificare una determinata preferenza
 * da lui precedentemente espressa indicando l'id della preferenza, verificandone l'esistenza di tale id nella lista.
 * L'utente potrà scegliere la nuova preferenza da assegnare all'artista, inserendo un valore di scelta.
 * Il valore della scelta è un carattere numerico, si richiede, quindi, di inserire un valore compreso nel range indicato.
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

void modifica_preferenza(FILE* file_artisti, FILE* file_utenti, FILE* file_preferenze, utenti utente[], artisti artista[], preferenze_artisti preferenza_artista[], int i, char scelta,  int z)
{
	printf("\n\n\t\t\t\t\t\t\t\t\t   _______________________________________");
	printf("\n\t\t\t\t\t\t\t\t\t  |                                       |");
	printf("\n\t\t\t\t\t\t\t\t\t  |        MODIFICA UNA PREFERENZA        |");
	printf("\n\t\t\t\t\t\t\t\t\t  |_______________________________________|");

	z= lettura_indice_utente_loggato(file_utenti, utente, i, z); //ASSEGNA A "z" IL VALORE RESTITUITO DALLA FUNZIONE "lettura_indice_utente_loggato", L'INDICE DELL'UTENTE CHE HA EFFETTUATO IL LOGIN
	visualizza_preferenze(file_artisti, file_utenti, file_preferenze, utente, artista, preferenza_artista, i, z); //CHIAMATA DELLA PROCEDURA "visualizza_preferenze" CHE STAMPA A VIDEO LA LISTA DELLE PREFERENZE DELL'UTENTE LOGGATO

	int count_preferenze= 0; //VARIABILE CONTATORE CHE CONTERRA' IL NUMERO DI PREFERENZE SALVATE SUL FILE "Preferenze.txt", CALCOLATO NELLA FUNZIONE "lettura_preferenze_da_file"
	count_preferenze= lettura_preferenze_da_file(file_preferenze, artista, preferenza_artista, i); //ASSEGNA A "count_preferenze" IL VALORE RESTITUITO DALLA FUNZIONE "lettura_preferenze_da_file", OSSIA IL NUMERO DELLE PREFERENZE SALVATE NEL FILE "Preferenze.txt"

	int j= 0; //INDICE DELL'ARRAY DELLE PREFERENZE
//ACQUISIZIONE DELL'ID DELLA PREFERENZA DA MODIFICARE
	int id_preferenza_ricercata= 0; //VARIABILE CHE CONTERRA' L'ID. DELLA PREFERENZA, ESPRESSA DALL'UTENTE, DA MODIFICARE

	printf("\n\n\n> INSERISCI L'ID DELLA PREFERENZA CHE VUOI MODIFICARE:   ");
	scanf("%d", &id_preferenza_ricercata); //ACQUISIZIONE ID. DELLA PREFERENZA

	int id_preferenza_trovata= 0; //FLAG CHE VERRA' IMPOSTATO A '1' NEL CASO IN CUI L'ID DELLA PREFERENZA INSERITA DALL'UTENTE E' PRESENTE NEL FILE "Preferenze.txt"

//VERIFICA ESISTENZA PREFERENZA
	for(j=0; j<count_preferenze; j++)
	{
		if(strcmp(preferenza_artista[j].username_utente, utente[z].username) == 0 && preferenza_artista[j].id_preferenza == id_preferenza_ricercata) //CONDIZIONE CHE VERIFICA SE LA j-ESIMA PREFERENZA SALVATA SUL FILE "Preferenze.txt" E' STATA ESPRESSA DALL'UTENTE LOGGATO
			id_preferenza_trovata= 1; //IMPOSTA IL FLAG "id_preferenza_trovata" A '1' POICHE' L'ID DELLA PREFERENZA DA MODIFICARE, INSERITO DALL'UTENTE, E' STATA TROVATA NEL FILE Preferenze.txt"
	}

	if(id_preferenza_trovata == 0) //SE AL TERMINE DI TUTTI I CICLI, IL VALORE DEL FLAG "id_preferenza_trovata" RISULTA ANCORA '0', SIGNIFICA CHE L'ID DELLA PREFERENZA INDICATA DALL'UTENTE NON E'PRESENTE NEL FILE "Preferenze.txt"
	{
		printf("\n\n   * PREFERENZA NON TROVATA!\n\n");

		printf("\n\n1. RIPROVA\n");
		printf("\n2. RITORNA AL MENU'");

	//ACQUISIZIONE DELLA SCELTA
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
				modifica_preferenza(file_artisti, file_utenti, file_preferenze, utente, artista, preferenza_artista, i, scelta, z); //CHIAMATA DELLA PROCEDURA "modifica_preferenza" CHE PEREMETTE ALL'UTENTE DI MODIFICARE UNA SUA PREFERENZA ESPRESSA PER UN DETERMINATO ARTISTA
				break;

			case '2': //"scelta"= '2' -> RITORNA AL MENU'
				system("cls"); //PULIZIA DELLO SCHERMO
				scritta_spotify(); //CHIAMATA DELLA PROCEDURA "scritta_spotify" CHE STAMPA A VIDEO LA SCRITTA "SPOTIFY"
				menu_utente(file_artisti, file_utenti, file_preferenze, utente, artista, preferenza_artista, i, scelta, z); //CHIAMATA DELLA PROCEDURA "menu_utente" CHE PEREMETTE ALL'UTENTE DI RITORNARE AL SUO MENU'
				break;
		}
	}

	else
	{
		for(j=0; j<count_preferenze; j++)
		{
			if(preferenza_artista[j].id_preferenza == id_preferenza_ricercata) //CONDIZIONE CHE VERIFICA SE L'ID. DELLA j-ESIMA PREFERENZA PRESENTE NEL FILE E' UGUALE ALL'ID. DELLA PREFERENZA INSERITO (DA MODIFICARE)
			{
				printf("\n\nPREFERENZA: \n");
				printf("\n\t1. LISTEN\n");
				printf("\n\t2. LIKE\n");
				printf("\n\t3. DISLIKE");

			//ACQUISIZIONE DELLA SCELTA
				do
				{
					fflush(stdin); //PULIZIA DEL BUFFER DELLA TASTIERA PRIMA...
					printf("\n\n\n> QUALE PREFERENZA VUOI ASSEGNARE A '%s'?   ", preferenza_artista[j].nome_artista);
					scanf("%c", &scelta); //ACQUISIZIONE DELLA SCELTA
					fflush(stdin); //...E DOPO L'UTILIZZO

					if(scelta < '1' || scelta > '3')
						printf("\n   * INPUT NON VALIDO, RIPROVA!");

				}while(scelta < '1' || scelta > '3'); //RIPETE IL CICLO FINCHE' IL CARATTERE INSERITO NON E' VALIDO

				int count_artisti= 0; //VARIABILE CONTATORE CHE CONTERRA' IL NUMERO DI ARTISTI SALVATI SUL FILE "Artisti.txt", CALCOLATO NELLA FUNZIONE "lettura_artisti_da_file"
				count_artisti= lettura_artisti_da_file(file_artisti, artista, i); //ASSEGNA A "count_artisti" IL VALORE RESTITUITO DALLA FUNZIONE "lettura_artisti_da_file", OSSIA IL NUMERO DEGLI ARTISTI SALVATI NEL FILE "Artisti.txt"

			//VERIFICA IL TIPO (like, dislike o listen) DELLA j-ESIMA PREFERENZA DA MODIFICARE
				if(strcmp(preferenza_artista[j].preferenza, "LISTEN") == 0) //CONDIZIONE CHE VERIFICA SE IL TIPO DELLA PREFERENZA DA MODIFICARE E' "LISTEN"
				{
				//MODIFICA DEL NUMERO DI "LISTEN" ASSOCIATI ALL'ARTISTA
					for(i=0; i<count_artisti; i++)
					{
						if(strcmp(preferenza_artista[j].nome_artista, artista[i].nome_artista) == 0) //CONDIZIONE CHE VERIFICA SE IL NOME DELL'ARTSITA ASSOCIATO ALLA j-ESIMA PREFERENZA SALVATA SUL FILE "Preferenze.txt" E' UGUALE AL NOME DELL'i-ESIMO ARTISTA SALVATO SUL FILE "Artisti.txt"
							artista[i].count_listen--; //DECREMENTO UNITARIO DEL NUMERO DI "LISTEN", ASSOCIATI ALL'i-ESIMO ARTISTA, POICHE' IL TIPO DI PREFERENZA ESPRESSA PER TALE ARTISTA VERRA' MODIFICATO DALL'UTENTE
					}
				}

				else if(strcmp(preferenza_artista[j].preferenza, "LIKE") == 0) //CONDIZIONE CHE VERIFICA SE IL TIPO DELLA PREFERENZA DA MODIFICARE E' "LIKE"
				{
				//MODIFICA DEL NUMERO DI "LIKE" ASSOCIATI ALL'ARTISTA
					for(i=0; i<count_artisti; i++)
					{
						if(strcmp(preferenza_artista[j].nome_artista, artista[i].nome_artista) == 0) //CONDIZIONE CHE VERIFICA SE IL NOME DELL'ARTSITA ASSOCIATO ALLA j-ESIMA PREFERENZA SALVATA SUL FILE "Preferenze.txt" E' UGUALE AL NOME DELL'i-ESIMO ARTISTA SALVATO SUL FILE "Artisti.txt"
							artista[i].count_like--; //DECREMENTO UNITARIO DEL NUMERO DI "LIKE" ASSOCIATI ALL'i-ESIMO ARTISTA, POICHE' IL TIPO DI PREFERENZA ESPRESSA PER TALE ARTISTA VERRA' MODIFICATO DALL'UTENTE
					}
				}

				else if(strcmp(preferenza_artista[j].preferenza, "DISLIKE") == 0) //CONDIZIONE CHE VERIFICA SE IL TIPO DELLA PREFERENZA DA MODIFICARE E' "DISLIKE"
				{
				//MODIFICA DEL NUMERO DI "DISLIKE" ASSOCIATI ALL'ARTISTA
					for(i=0; i<count_artisti; i++)
					{
						if(strcmp(preferenza_artista[j].nome_artista, artista[i].nome_artista) == 0) //CONDIZIONE CHE VERIFICA SE IL NOME DELL'ARTSITA ASSOCIATO ALLA j-ESIMA PREFERENZA SALVATA SUL FILE "Preferenze.txt" E' UGUALE AL NOME DELL'i-ESIMO ARTISTA SALVATO SUL FILE "Artisti.txt"
							artista[i].count_dislike--; //DECREMENTO UNITARIO DEL NUMERO DI "DISLIKE", ASSOCIATI ALL'i-ESIMO ARTISTA POICHE' IL TIPO DI PREFERENZA, ESPRESSA PER TALE ARTISTA VERRA' MODIFICATO DALL'UTENTE
					}
				}

				switch(scelta)
				{
					case '1'://"scelta"= 1 -> PREFERENZA: LISTEN
						strcpy(preferenza_artista[j].preferenza, "LISTEN"); //ASSEGNA LA PREFERENZA "LISTEN" ALL'ARTISTA

					//MODIFICA DEL NUMERO DI "LISTEN" ASSOCIATI ALL'ARTISTA
						for(i=0; i<count_artisti; i++)
						{
							if(strcmp(preferenza_artista[j].nome_artista, artista[i].nome_artista) == 0) //CONDIZIONE CHE VERIFICA SE IL NOME DELL'ARTSITA ASSOCIATO ALLA j-ESIMA PREFERENZA SALVATA SUL FILE "Preferenze.txt" E' UGUALE AL NOME DELL'i-ESIMO ARTISTA SALVATO SUL FILE "Artisti.txt"
								artista[i].count_listen++; //INCREMENTO UNITARIO DEL NUMERO DI "LISTEN" ASSOCIATI ALL'i-ESIMO ARTISTA
						}
						break;

					case '2'://"scelta"= '2' -> PREFERENZA: LIKE
						strcpy(preferenza_artista[j].preferenza, "LIKE"); //ASSEGNA LA PREFERENZA "LIKE" ALL'ARTISTA

					//MODIFICA DEL NUMERO DI "LIKE" ASSOCIATI ALL'ARTISTA
						for(i=0; i<count_artisti; i++)
						{
							if(strcmp(preferenza_artista[j].nome_artista, artista[i].nome_artista) == 0) //CONDIZIONE CHE VERIFICA SE IL NOME DELL'ARTSITA ASSOCIATO ALLA j-ESIMA PREFERENZA SALVATA SUL FILE "Preferenze.txt" E' UGUALE AL NOME DELL'i-ESIMO ARTISTA SALVATO SUL FILE "Artisti.txt"
								artista[i].count_like++; //INCREMENTO UNITARIO DEL NUMERO DI "LIKE" ASSOCIATI ALL'i-ESIMO ARTISTA
						}
						break;

					case '3'://"scelta"= '3' -> PREFERENZA: DISLIKE
						strcpy(preferenza_artista[j].preferenza, "DISLIKE"); //ASSEGNA LA PREFERENZA "DISLIKE" ALL'ARTISTA

					//MODIFICA DEL NUMERO DI "LIKE" ASSOCIATI ALL'ARTISTA
						for(i=0; i<count_artisti; i++)
						{
							if(strcmp(preferenza_artista[j].nome_artista, artista[i].nome_artista) == 0) //CONDIZIONE CHE VERIFICA SE IL NOME DELL'ARTSITA ASSOCIATO ALLA j-ESIMA PREFERENZA SALVATA SUL FILE "Preferenze.txt" E' UGUALE AL NOME DELL'i-ESIMO ARTISTA SALVATO SUL FILE "Artisti.txt"
								artista[i].count_dislike++; //INCREMENTO UNITARIO DEL NUMERO DI "DISLIKE" ASSOCIATI ALL'i-ESIMO ARTISTA
						}
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
				}
				fclose(file_artisti); //CHIUSURA DEL FILE

			//APERTURA DEL FILE "Preferenze.txt" IN MODALITA' DI SCRITTURA ("w")
				if((file_preferenze=  fopen("Preferenze.txt" , "w")) == NULL)
					printf("Errore nell'apertura!\n");

				else
				{
				//SALVATAGGIO SUL FILE "Preferenze.txt" DELLE MODIFICHE APPORTATE
					for(j=0; j<count_preferenze; j++)
						fprintf(file_preferenze,"\n%d %s %s %s", preferenza_artista[j].id_preferenza, preferenza_artista[j].username_utente, preferenza_artista[j].nome_artista, preferenza_artista[j].preferenza); //SALVATAGGIO SUL FILE "Preferenze.txt" DEI DATI DELLA j-ESIMA PREFERENZA (USERNAME, NOME ARTISTA e TIPO PREFERENZA)

					printf("\n\n\n***************** PREFERENZA MODIFICATA CORRETTAMENTE! *****************\n");
				}
				fclose(file_preferenze); //CHIUSURA DEL FILE

				return_menu_utente(file_artisti, file_utenti, file_preferenze, utente, artista, preferenza_artista, i, scelta, z); //CHIAMATA DELLA PROCEDURA "return_menu_menu" CHE PERMETTE ALL'UTENTE DI RITORNARE AL SUO MENU' AL TERMINE DELL'OPERAZIONE ESEGUITA
				break;
			}
		}
	}
}

/**
 * Procedura elimina_preferenza();
 *
 * Verranno stampate le preferenze dell'utente che ha effettuato il login, il quale potrà scegliere di eliminare una determinata preferenza
 * da lui precedentemente espressa indicando l'id della preferenza, verificandone l'esistenza di tale id nella lista.
 * L'utente potrà scegliere la nuova preferenza da assegnare all'artista, inserendo un valore di scelta.
 * Il valore della scelta è un carattere numerico, si richiede, quindi, di inserire un valore compreso nel range indicato.
 * Se si inserisce una stringa o un carattere non valido verra' richiesto di reinserire il valore.
 *
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

void elimina_preferenza(FILE* file_artisti, FILE* file_utenti, FILE* file_preferenze, utenti utente[], artisti artista[], preferenze_artisti preferenza_artista[], int i, char scelta,  int z)
{
	printf("\n\n\t\t\t\t\t\t\t\t\t   _______________________________________");
	printf("\n\t\t\t\t\t\t\t\t\t  |                                       |");
	printf("\n\t\t\t\t\t\t\t\t\t  |         ELIMINA UNA PREFERENZA        |");
	printf("\n\t\t\t\t\t\t\t\t\t  |_______________________________________|");

	z= lettura_indice_utente_loggato(file_utenti, utente, i, z); //ASSEGNA A "z" IL VALORE RESTITUITO DALLA FUNZIONE "lettura_indice_utente_loggato", L'INDICE DELL'UTENTE CHE HA EFFETTUATO IL LOGIN
	visualizza_preferenze(file_artisti, file_utenti, file_preferenze, utente, artista, preferenza_artista, i, z); //CHIAMATA DELLA PROCEDURA "visualizza_preferenze" CHE STAMPA A VIDEO LA LISTA DELLE PREFERENZE DELL'UTENTE LOGGATO

	int count_preferenze= 0; //VARIABILE CONTATORE CHE CONTERRA' IL NUMERO DI PREFERENZE SALVATE SUL FILE "Preferenze.txt", CALCOLATO NELLA FUNZIONE "lettura_preferenze_da_file"
	count_preferenze= lettura_preferenze_da_file(file_preferenze, artista, preferenza_artista, i); //ASSEGNA A "count_preferenze" IL VALORE RESTITUITO DALLA FUNZIONE "lettura_preferenze_da_file", OSSIA IL NUMERO DELLE PREFERENZE SALVATE NEL FILE "Preferenze.txt"

	int j= 0; //INDICE DELL'ARRAY DELLE PREFERENZE

//ACQUISIZIONE DELL'ID DELLA PREFERENZA DA ELIMINARE
	int id_preferenza_ricercata= 0; //VARIABILE CHE CONTERRA' L'ID. DELLA PREFERENZA, ESPRESSA DALL'UTENTE, DA ELIMINARE

	printf("\n\n\n> INSERISCI L'ID DELLA PREFERENZA CHE VUOI ELIMINARE:   ");
	scanf("%d", &id_preferenza_ricercata); //ACQUISIZIONE ID. DELLA PREFERENZA

	int id_preferenza_trovata= 0; //FLAG CHE VERRA' IMPOSTATO A '1' NEL CASO IN CUI L'ID DELLA PREFERENZA INSERITA DALL'UTENTE E' PRESENTE NEL FILE "Preferenze.txt"

//VERIFICA ESISTENZA PREFERENZA
	for(j=0; j<count_preferenze; j++)
	{
		if(strcmp(preferenza_artista[j].username_utente, utente[z].username) == 0 && preferenza_artista[j].id_preferenza == id_preferenza_ricercata) //CONDIZIONE CHE VERIFICA SE L'i-ESIMA PREFERENZA SALVATA SUL FILE "Preferenze.txt" E' STATA ESPRESSA DALL'UTENTE LOGGATO
			id_preferenza_trovata= 1; //IMPOSTA IL FLAG "id_preferenza_trovata" A '1' POICHE' L'ID DELLA PREFERENZA DA MODIFICARE, INSERITO DALL'UTENTE, E' STATA TROVATA NEL FILE Preferenze.txt"
	}

	if(id_preferenza_trovata == 0) //SE AL TERMINE DI TUTTI I CICLI, IL VALORE DEL FLAG "id_preferenza_trovata" RISULTA ANCORA '0', SIGNIFICA CHE L'ID DELLA PREFERENZA INDICATA DALL'UTENTE NON E'PRESENTE NEL FILE "Preferenze.txt"
	{
		printf("\n\n   * PREFERENZA NON TROVATA!\n\n");

		printf("\n\n1. RIPROVA\n");
		printf("\n2. RITORNA AL MENU'");

	//ACQUISIZIONE DELLA SCELTA
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
				elimina_preferenza(file_artisti, file_utenti, file_preferenze, utente, artista, preferenza_artista, i, scelta, z); //CHIAMATA DELLA PROCEDURA "elimina_preferenza" CHE PEREMETTE ALL'UTENTE DI ELIMINARE UNA SUA PREFERENZA ESPRESSA PER UN DETERMINATO ARTISTA
				break;

			case '2': //"scelta"= '2' -> RITORNA AL MENU'
				system("cls"); //PULIZIA DELLO SCHERMO
				scritta_spotify(); //CHIAMATA DELLA PROCEDURA "scritta_spotify" CHE STAMPA A VIDEO LA SCRITTA "SPOTIFY"
				menu_utente(file_artisti, file_utenti, file_preferenze, utente, artista, preferenza_artista, i, scelta, z); //CHIAMATA DELLA PROCEDURA "menu_utente" CHE PEREMETTE ALL'UTENTE DI RITORNARE AL SUO MENU'
				break;
		}
	}

	else
	{
	//APERTURA DEL FILE "Preferenze.txt" IN MODALITA' DI SCRITTURA ("w")
		if((file_preferenze=  fopen("Preferenze.txt" , "w")) == NULL)
			printf("Errore nell'apertura!\n");

		else
		{
		//SALVATAGGIO SUL FILE "Preferenze.txt" DI TUTTE LE PREFERENZE, ECCETTO LA PREFERENZA CHE L'UTENTE HA DECISO DI ELIMINARE
			for(j=0; j<count_preferenze; j++)
			{
				if(preferenza_artista[j].id_preferenza != id_preferenza_ricercata) //CONDIZIONE CHE VERIFICA SE L'ID DELLA j-ESIMA PREFERENZA SALVATA SUL FILE "Prefererenze.txt" E' DIVERSO DALL'ID. DELLA PREFERENZA INDICATO DALL'UTENTE (DA ELIMINARE)
					fprintf(file_preferenze,"\n%d %s %s %s", preferenza_artista[j].id_preferenza, preferenza_artista[j].username_utente, preferenza_artista[j].nome_artista, preferenza_artista[j].preferenza); //SALVATAGGIO SUL FILE "Preferenze.txt" DEI DATI DELLA j-ESIMA PREFERENZA (USERNAME, NOME ARTISTA e TIPO PREFERENZA)
			}
		}
		fclose(file_preferenze); //CHIUSURA DEL FILE

		count_preferenze= 0; //VARIABILE CONTATORE CHE CONTERRA' IL NUMERO DI PREFERENZE SALVATE SUL FILE "Preferenze.txt", CALCOLATO NELLA FUNZIONE "lettura_preferenze_da_file"
		count_preferenze= lettura_preferenze_da_file(file_preferenze, artista, preferenza_artista, i); //ASSEGNA A "count_preferenze" IL VALORE RESTITUITO DALLA FUNZIONE "lettura_preferenze_da_file", OSSIA IL NUMERO DELLE PREFERENZE SALVATE NEL FILE "Preferenze.txt"

	//APERTURA DEL FILE "Preferenze.txt" IN MODALITA' DI SCRITTURA ("w")
		if((file_preferenze=  fopen("Preferenze.txt" , "w")) == NULL)
			printf("Errore nell'apertura!\n");

		else
		{
		//RI-ASSEGNAZIONE DEGLI ID. ALLE PREFERENZE SALVATE SUL FILE "Preferenze.txt"
			for(j=0; j<count_preferenze; j++)
			{
				preferenza_artista[j].id_preferenza= j+1; //RI-ASSEGNAZIONE DEL NUOVO "ID PREFERENZA" ALL'i-ESIMA PREFERENZA
				fprintf(file_preferenze,"\n%d %s %s %s", preferenza_artista[j].id_preferenza, preferenza_artista[j].username_utente, preferenza_artista[j].nome_artista, preferenza_artista[j].preferenza); //SALVATAGGIO SUL FILE "Preferenze.txt" DEI DATI DELLA j-ESIMA PREFERENZA (USERNAME, NOME ARTISTA e TIPO PREFERENZA)
			}

			printf("\n\n\n***************** PREFERENZA ELIMINATA CORRETTAMENTE! *****************\n");
		}
		fclose(file_preferenze); //CHIUSURA DEL FILE
	}
}

/**
 * Procedura elimina_account():
 *
 * Verranno stampati i dati dell'utente che ha effettuato l'accesso
 * L'utente poi potrà scegliere se eliminare definitivamente il suo account.
 * Prima che venga rimosso definitivamente l'account, per questioni di "sicurezza", si acquisisce la password dell'utente
 * finchè quest'ultima non risulta corretta.
 * Verranno salvati nuovamente tutti gli utenti sul file, eccetto l'utente che ha deciso di rimuovere il proprio account.
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

void elimina_account(FILE* file_artisti, FILE* file_utenti, FILE* file_preferenze, utenti utente[], artisti artista[], preferenze_artisti preferenza_artista[], int i, char scelta, int z)
{
	printf("\n\n\t\t\t\t\t\t\t\t\t   _______________________________________");
	printf("\n\t\t\t\t\t\t\t\t\t  |                                       |");
	printf("\n\t\t\t\t\t\t\t\t\t  |            ELIMINA ACCOUNT            |");
	printf("\n\t\t\t\t\t\t\t\t\t  |_______________________________________|");

	z= lettura_indice_utente_loggato(file_utenti, utente, i, z); //ASSEGNA A "z" IL VALORE RESTITUITO DALLA FUNZIONE "lettura_indice_utente_loggato", L'INDICE DELL'UTENTE CHE HA EFFETTUATO IL LOGIN

//STAMPA DEI DATI DELL'UTENTE LOGGATO
	printf("\n\n\n\n\t\t\t\t\tID. UTENTE|\t      NOME|\t     COGNOME|\t      DATA DI NASCITA|\t        USERNAME|\t   PASSWORD|\n\n");
	printf("\t\t\t\t  %16d|%15s|%17s|%12d / %2d / %d|%18s|%18s|  \n", utente[z].id_utente, utente[z].nome_utente, utente[z].cognome_utente, utente[z].giorno_nascita, utente[z].mese_nascita, utente[z].anno_nascita, utente[z].username, utente[z].password); //STAMPA DEI DATI RELATIVI ALL'UTENTE CHE HA EFFETTUATO L'ACCESSO

//ELIMINAZIONE ACCOUNT
	printf("\n\n\n\n1. ELIMINA ACCOUNT\n");
	printf("\n2. RITORNA AL MENU");

	do
	{
		fflush(stdin); //PULIZIA DEL BUFFER DELLA TASTIERA PRIMA...
		printf("\n\n\n> QUALE OPERAZIONE DESIDERI EFFETTUARE?   ");
		scanf("%c", &scelta); //ACQUISIZIONE DELLA SCELTA
		fflush(stdin); //...E DOPO L'UTILIZZO

		if(scelta < '1' || scelta > '2')
			printf("\n   * INPUT NON VALIDO, RIPROVA!");

	}while(scelta < '1' || scelta > '2'); //RIPETE IL CICLO FINCHE' IL CARATTERE INSERITO NON E' VALIDO

	int count_utenti= 0; //VARIABILE CONTATORE CHE CONTERRA' IL NUMERO DI UTENTI SALVATI SUL FILE "Utenti.txt", CALCOLATO NELLA FUNZIONE "lettura_utenti_da_file"
	int count_preferenze= 0; //VARIABILE CONTATORE CHE CONTERRA' IL NUMERO DI PREFERENZE SALVATE SUL FILE "Preferenze.txt", CALCOLATO NELLA FUNZIONE "lettura_preferenze_da_file"

	char password_ricercata[LUNG_PASSWORD]; //PASSWORD DELL'UTENTE CHE DESIDERA ELIMINARE IL PROPRIO ACCOUNT

	switch(scelta)
	{
		case '1': //"scelta"= '1' -> ELIMINA ACCOUNT
			do
			{
			//ACQUISIZIONE DELLA PASSWORD DELL'UTENTE CHE VUOLE ELIMINARE IL PROPRIO ACCOUNT
				printf("\n\n> INSERISCI LA PASSWORD:  ");
				scanf("%s", password_ricercata); //ACQUISIZIONE PASSWORD

				if(strcmp(password_ricercata, utente[z].password) != 0)
					printf("\n   * PASSWORD NON VALIDA, RIPROVA!\n");

			}while(strcmp(password_ricercata, utente[z].password) != 0); //RIPETE IL CICLO FINCHE' LA PASSWORD INSERITA NON E' VALIDA

			count_preferenze= lettura_preferenze_da_file(file_preferenze, artista, preferenza_artista, i); //ASSEGNA A "count_preferenze" IL VALORE RESTITUITO DALLA FUNZIONE "lettura_preferenze_da_file", OSSIA IL NUMERO DELLE PREFERENZE SALVATE NEL FILE "Preferenze.txt"

			//APERTURA DEL FILE "Preferenze.txt" IN MODALITA' DI SCRITTURA ("w")
			if((file_preferenze=  fopen("Preferenze.txt" , "w")) == NULL)
				printf("Errore nell'apertura!\n");

			else
			{
			//SALVATAGGIO SUL FILE "Preferenze.txt" DI TUTTE LE PREFERENZE, ECCETTO LE PREFERENZE DELL'UTENTE CHE DESIDERA ELIMINARE IL PROPRIO ACCOUNT
				for(i=0; i<count_preferenze; i++)
				{
					if(strcmp(preferenza_artista[i].username_utente, utente[z].username) != 0)//CONDIZIONE CHE VERIFICA SE L'USERNAME DELL'UTENTE ASSOCIATO ALL'i-ESIMA PREFERENZA SALVATA SUL FILE "Prefererenze.txt" E' DIVERSO DALL'USERNAME DELL'UTENTE LOGGATO
						fprintf(file_preferenze,"\n%d %s %s %s", preferenza_artista[i].id_preferenza, preferenza_artista[i].username_utente, preferenza_artista[i].nome_artista, preferenza_artista[i].preferenza); //SALVATAGGIO SUL FILE "Preferenze.txt" DEI DATI DELL'i-ESIMA PREFERENZA (USERNAME, NOME ARTISTA e TIPO PREFERENZA)
				}
			}
			fclose(file_preferenze); //CHIUSURA DEL FILE

			count_preferenze= 0; //VARIABILE CONTATORE CHE CONTERRA' IL NUMERO DI PREFERENZE SALVATE SUL FILE "Preferenze.txt", CALCOLATO NELLA FUNZIONE "lettura_preferenze_da_file"
			count_preferenze= lettura_preferenze_da_file(file_preferenze, artista, preferenza_artista, i); //ASSEGNA A "count_preferenze" IL VALORE RESTITUITO DALLA FUNZIONE "lettura_preferenze_da_file", OSSIA IL NUMERO DELLE PREFERENZE SALVATE NEL FILE "Preferenze.txt"

		//APERTURA DEL FILE "Preferenze.txt" IN MODALITA' DI SCRITTURA ("w")
			if((file_preferenze=  fopen("Preferenze.txt" , "w")) == NULL)
				printf("Errore nell'apertura!\n");

			else
			{
			//RI-ASSEGNAZIONE DEGLI ID. ALLE PREFERENZE SALVATE SUL FILE "Preferenze.txt"
				for(i=0; i<count_preferenze; i++)
				{
					preferenza_artista[i].id_preferenza= i+1; //RI-ASSEGNAZIONE DEL NUOVO "ID PREFERENZA" ALL'i-ESIMA PREFERENZA
					fprintf(file_preferenze,"\n%d %s %s %s", preferenza_artista[i].id_preferenza, preferenza_artista[i].username_utente, preferenza_artista[i].nome_artista, preferenza_artista[i].preferenza); //SALVATAGGIO SUL FILE "Preferenze.txt" DEI DATI DELL' i-ESIMA PREFERENZA (USERNAME, NOME ARTISTA e TIPO PREFERENZA)
				}
			}
			fclose(file_preferenze); //CHIUSURA DEL FILE

			count_utenti= lettura_utenti_da_file(file_utenti, utente, i);  //ASSEGNA A "count_utenti" IL VALORE RESTITUITO DALLA FUNZIONE "lettura_utenti_da_file", OSSIA IL NUMERO DEGLI UTENTI SALVATI NEL FILE "Utenti.txt"

		//APERTURA DEL FILE "Utenti.txt" IN MODALITA' DI SCRITTURA ("w")
			if((file_utenti=  fopen("Utenti.txt" , "w")) == NULL)
				printf("Errore nell'apertura!\n");

			else
			{
			//SALVATAGGIO SUL FILE "Utenti.txt" DEI DATI DI TUTTI GLI UTENTI, ECCETTO L'UTENTE "z" CHE HA DECISO DI RIMUOVERE IL SUO ACCOUNT
				for(i=0; i<count_utenti; i++)
				{
					if(i != z) //CONDIZIONE CHE VERIFICA SE L'INDICE DELL'i-ESIMO UTENTE SALVATO SUL FILE E' DIVERSO DALL'INDICE "z" DELL'UTENTE LOGGATO, IL QUALE VUOLE RIMUOVERE IL SUO ACCOUNT
						fprintf(file_utenti,"\n%d %s %s %d %d %d %s %s", utente[i].id_utente, utente[i].nome_utente, utente[i].cognome_utente, utente[i].giorno_nascita, utente[i].mese_nascita, utente[i].anno_nascita, utente[i].username, utente[i].password); //SALVATAGGIO SUL FILE "Utenti.txt" DEI DATI DELL'i-ESIMO UTENTE
				}
			}
			fclose(file_utenti); //CHIUSURA DEL FILE

			count_utenti= 0; //RIPRISTINO DEL VALORE DI PARTENZA DELLA VARIABILE "count_utenti"
			count_utenti= lettura_utenti_da_file(file_utenti, utente, i); //ASSEGNA A "count_utenti" IL VALORE RESTITUITO DALLA FUNZIONE "lettura_utenti_da_file", OSSIA IL NUMERO DEGLI UTENTI SALVATI NEL FILE "Utenti.txt"

		//APERTURA DEL FILE "Utenti.txt" IN MODALITA' DI SCRITTURA ("w")
			if((file_utenti =  fopen("Utenti.txt" , "w")) == NULL)
				printf("Errore nell'apertura!\n");

			else
			{
			//RI-ASSEGNAZIONE DEGLI ID. AGLI UTENTI SALVATI SUL FILE "Utenti.txt"
				for(i=0; i<count_utenti; i++)
				{
					utente[i].id_utente= i+1; //RI-ASSEGNAZIONE DEL NUOVO "ID UTENTE" ALL'i-ESIMO UTENTE
					fprintf(file_utenti,"\n%d %s %s %d %d %d %s %s", utente[i].id_utente, utente[i].nome_utente, utente[i].cognome_utente, utente[i].giorno_nascita, utente[i].mese_nascita, utente[i].anno_nascita, utente[i].username, utente[i].password); //SALVATAGGIO SUL FILE "Utenti.txt" DEI DATI DELL'i-ESIMO UTENTE
				}
			}
			fclose(file_utenti); //CHIUSURA DEL FILE

			interfaccia_iniziale(file_artisti, file_utenti, file_preferenze, utente, artista, preferenza_artista, i, scelta, z); //CHIAMATA DELLA PROCEDURA "interfaccia_iniziale" CHE PERMETTE ALL'UTENTE DI RITORNARE ALL'INTERFACCIA INIZIALE
			break;

		case '2': //"scelta"= '2'-> RITORNA AL MENU'
			menu_utente(file_artisti, file_utenti, file_preferenze, utente, artista, preferenza_artista, i, scelta, z);  //CHIAMATA DELLA PROCEDURA "menu_utente" CHE PERMETTE ALL'UTENTE DI RITORNARE AL SUO MENU' PER ESEGUIRE UNA NUOVA OPERAZIONE
			break;
	}
}

/**
 * Procedura return_menu_utente():
 *
 * Al termine di ogni operazione eseguita, verrà richiesto all'utente se desidera ritornare al suo menu' iniziale
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

void return_menu_utente(FILE* file_artisti, FILE* file_utenti, FILE* file_preferenze, utenti utente[], artisti artista[], preferenze_artisti preferenza_artista[], int i, char scelta, int z)
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
			menu_utente(file_artisti, file_utenti, file_preferenze, utente, artista, preferenza_artista, i, scelta, z);  //CHIAMATA DELLA PROCEDURA "menu_utente" CHE PERMETTE ALL'UTENTE DI RITORNARE AL SUO MENU' PER ESEGUIRE UNA NUOVA OPERAZIONE

	}while(scelta != '0'); //RIPETE IL CICLO FINCHE IL CARATTERE INSERITO NON E' VALIDO
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------//

