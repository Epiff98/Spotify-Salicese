#ifndef STRUCT_H_
#define STRUCT_H_

//------------------------------------------------------------------- STRUCT PREFERENZE --------------------------------------------------------------------//
typedef struct
{
	int id_preferenza;						//IDENTIFICATIVO NUMERICO DELLA PREFERENZA
	char username_utente[LUNG_USERNAME];	//USERNAME DELL'UTENTE CHE HA ESPRESSO LA PREFERENZA
	char nome_artista[LUNG_NOME];			//NOME DELL'ARTISTA A CUI E' ASSOCIATA LA PREFERENZA
	char preferenza[LUNG_PREFERENZA];		//TIPOLOGIA PREFERENZA (Listen, Like, Dislike)
}preferenze_artisti;
//----------------------------------------------------------------------------------------------------------------------------------------------------------//

//-------------------------------------------------------------------- STRUCT ARTISTI ----------------------------------------------------------------------//
typedef struct
{
	int id_artista;							//IDENTIFICATIVO NUMERICO DELL'ARTISTA
	char nome_artista[LUNG_NOME];			//NOME DELL'ARTISTA
	char genere[LUNG_GENERE];				//GENERE DELL'ARTISTA
	char nazionalita[LUNG_NAZIONALITA];		//NAZIONALITA' DELL'ARTISTA
	int anno_inizio;						//ANNO DI INIZIO PRODUZIONE DELL'ARTISTA
	char canzone[LUNG_CANZONE];				//CANZONE POPOLARE DELL'ARTITSA
	int count_listen;						//NUMERO DI "LISTEN" ASSOCIATI ALL'ARTISTA
	int count_like;							//NUMERO DI "LIKE" ASSOCIATI ALL'ARTISTA
	int count_dislike;						//NUMERO DI "DISLIKE" ASSOCIATI ALL'ARTISTA
}artisti;
//----------------------------------------------------------------------------------------------------------------------------------------------------------//

//--------------------------------------------------------------------- STRUCT UTENTI ----------------------------------------------------------------------//
typedef struct
{
	int id_utente;							//IDENTIFICATIVO NUMERICO DELL'UTENTE
	char nome_utente[LUNG_NOME];			//NOME DELL'UTENTE
	char cognome_utente[LUNG_COGNOME];		//COGNOME DELL'UTENTE
	int giorno_nascita;						//GIORNO DI NASCITA DELL'UTENTE
	int mese_nascita;						//MESE DI NASCITA DELL'UTENTE
	int anno_nascita;						//ANNO DI NASCITA DELL'UTENTE
	char username[LUNG_USERNAME];			//USERNAME DELL'UTENTE
	char password[LUNG_PASSWORD];			//PASSWORD DELL'UTENTE
}utenti;
//----------------------------------------------------------------------------------------------------------------------------------------------------------//

#endif /* STRUCT_H_ */
