#include <stdio.h>
#include <stdlib.h>

#include "costanti.h"
#include "struct.h"
#include "intestazioni.h"
#include "funzioni_admin.h"
#include "funzioni_utente.h"

void interfaccia_iniziale(FILE* file_artisti, FILE* file_utenti,  FILE* file_preferenze, utenti utente[], artisti artista[], preferenze_artisti preferenza_artista[], int i, char scelta, int z)
{
	system("cls"); //PULIZIA DELLO SCHERMO
	scritta_spotify(); //CHIAMATA DELLA PROCEDURA "scritta_spotify" CHE STAMPA A VIDEO LA SCRITTA "SPOTIFY"

//MENU' INTERFACCIA INIZIALE
	printf("\n\n\t\t\t\t\t\t\t\t\t   _______________________________________");
	printf("\n\t\t\t\t\t\t\t\t\t  |                                       |");
	printf("\n\t\t\t\t\t\t\t\t\t  |            1. LOGIN UTENTE            |");
	printf("\n\t\t\t\t\t\t\t\t\t  |_______________________________________|");
	printf("\n\n\t\t\t\t\t\t\t\t\t   _______________________________________");
	printf("\n\t\t\t\t\t\t\t\t\t  |                                       |");
	printf("\n\t\t\t\t\t\t\t\t\t  |             2. LOGIN ADMIN            |");
	printf("\n\t\t\t\t\t\t\t\t\t  |_______________________________________|");
	printf("\n\n\t\t\t\t\t\t\t\t\t   _______________________________________");
	printf("\n\t\t\t\t\t\t\t\t\t  |                                       |");
	printf("\n\t\t\t\t\t\t\t\t\t  |              3. SIGN UP               |");
	printf("\n\t\t\t\t\t\t\t\t\t  |_______________________________________|");
	printf("\n\n\t\t\t\t\t\t\t\t\t   _______________________________________");
	printf("\n\t\t\t\t\t\t\t\t\t  |                                       |");
	printf("\n\t\t\t\t\t\t\t\t\t  |                4. EXIT                |");
	printf("\n\t\t\t\t\t\t\t\t\t  |_______________________________________|");
	printf("\n\n\n\n\t\t\t\t\t\t- NOTA SCELTA: Se si inserisce una stringa, viene considerato solo il PRIMO CARATTERE della stringa.");

//ACQUISIZIONE DELLA "SCELTA" DELL'UTENTE, TRA LE VOCI ELENCATE NEL MENU'
	do
	{
		fflush(stdin); //PULIZIA DEL BUFFER DELLA TASTIERA PRIMA...
		printf("\n\n\n\t\t\t\t\t\t\t\t\t   > QUALE OPERAZIONE DESIDERI EFFETTUARE?   ");
		scanf("%c", &scelta); //ACQUISIZIONE DELLA SCELTA
		fflush(stdin); //...E DOPO L'UTILIZZO

		if(scelta < '1' || scelta > '4')
			printf("\n\n\t\t\t\t\t\t\t\t\t       * SCELTA NON VALIDA, RIPROVA!\n");


	}while(scelta < '1' || scelta > '4'); //RIPETE IL CICLO FINCHE' IL CARATTERE INSERITO NON E' VALIDO

	switch(scelta)
	{
		case '1': //"scelta"= '1' -> LOGIN UTENTE
			system("cls"); //PULIZIA DELLO SCHERMO
			scritta_spotify(); //CHIAMATA DELLA PROCEDURA "scritta_spotify" CHE STAMPA A VIDEO LA SCRITTA "SPOTIFY"
			scritta_login(); //CHIAMAMTA DELLA PROCEDURA "scritta_login" CHE STAMPA A VIDEO LA SCRITTA "LOGIN"
			login_utente(file_artisti, file_utenti, file_preferenze, utente, artista, preferenza_artista, i, scelta, z); //CHIAMATA DELLA PROCEDURA "login_utente" CHE PERMETTE ALL'UTENTE DI EFFETTUARE L'ACCESSO ALLA PIATTAFORMA "SPOTIFY", INSERENDO IL PROPRIO USERNAME E PASSWORD
			break;

		case '2': //"scelta"= '2' -> LOGIN ADMIN
			system("cls"); //PULIZIA DELLO SCHERMO
			scritta_spotify(); //CHIAMATA DELLA PROCEDURA "scritta_spotify" CHE STAMPA A VIDEO LA SCRITTA "SPOTIFY"
			scritta_login(); //CHIAMAMTA DELLA PROCEDURA "scritta_login" CHE STAMPA A VIDEO LA SCRITTA "LOGIN"
			login_admin(file_artisti, file_utenti, file_preferenze, utente, artista, preferenza_artista, i, scelta, z); //CHIAMATA DELLA PROCEDURA "login_admin" CHE PERMETTE ALL'AMMINISTRATORE DELLA PIATTAFORMA DI EFFETTUARE L'ACCESSO ALLA SUA INTERFACCIA RISERVATA, INSERENDO USERNAME E PASSWORD
			break;

		case '3': //"scelta"= '3' -> SIGNUP
			system("cls"); //PULIZIA DELLO SCHERMO
			scritta_spotify(); //CHIAMATA DELLA PROCEDURA "scritta_spotify" CHE STAMPA A VIDEO LA SCRITTA "SPOTIFY"
			scritta_signup(); //CHIAMAMTA DELLA PROCEDURA "scritta_signup" CHE STAMPA A VIDEO LA SCRITTA "SIGNUP"
			signup(file_artisti, file_utenti, file_preferenze, utente, artista, preferenza_artista, i, scelta, z); //CHIAMATA DELLA PROCEDURA "signup" CHE PERMETTE ALL'UTENTE DI REGISTRARSI ALLA PIATTAFORMA "SPOTIFY", FORNENDO I PROPRI DATI ANAGRAFICI E SCEGLIENDO UN USERNAME E UNA PASSWORD PER POTER POI ACCEDERE
			break;

		case '4': //"scelta"= '4' -> EXIT
			break;
	}
}
