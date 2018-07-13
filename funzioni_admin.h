/**
 * @file funzioni_admin.h
 *
 * @brief Libreria per le funzionalita' a disposizione dell'amministratore che accede alla piattaforma "Spotify".
 *
 * La libreria funzioni_admin.h è stata implementata per la gestione delle funzionalita' messe a disposizone
 * dell'amministratore.
 * L'amministratore puo' accedere nella propria area riservata della piattaforma fornendo Username e Password pre-impostati:
 * Username: admin
 * Password: Admin123
 *
 * @authors Andrea De Matteis, Marco Epifani, Giorgio Calcagnile
 */

#ifndef FUNZIONI_ADMIN_H_
#define FUNZIONI_ADMIN_H_

//----------------------------------------------------------- FUNZIONI DELL'INTERFACCIA ADMIN --------------------------------------------------------------//
///La procedura "login_admin" permette all'amministratore della piattaforma di accedere alla propria area riservata, fornendo le proprie credenziali
void login_admin(FILE* file_artisti, FILE* file_utenti,  FILE* file_preferenze, utenti utente[], artisti artista[], preferenze_artisti preferenza_artista[], int i, char scelta, int z); //PROCEDURA CHE PERMETTE ALL'AMMINISTRATORE DELLA PIATTAFORMA DI EFFETTUARE L'ACCESSO ALLA SUA INTERFACCIA RISERVATA, INSERENDO USERNAME E PASSWORD

///La procedura "menu_admin" permette di stampare a video un menu' con l'elenco delle operazioni che l'amministratore potra' far eseguire.
void menu_admin(FILE* file_artisti, FILE* file_utenti,  FILE* file_preferenze, utenti utente[], artisti artista[], preferenze_artisti preferenza_artista[], int i, char scelta, int z); //PROCEDURA CHE STAMPA A VIDEO IL MENU' CON LE DIVERSE OPERAZIONI CHE L'AMMINISTRATORE DELLA PIATTAFORMA PUO' FAR ESEGUIRE UNA VOLTA EFFETTUATO IL LOGIN

///La procedura "visualizza_utenti" permette all'amministratore di visualizzare la lista degli utenti iscritti.
void visualizza_utenti(FILE* file_artisti, FILE* file_utenti,  FILE* file_preferenze, utenti utente[], artisti artista[], preferenze_artisti preferenza_artista[], int i, char scelta, int z); //PROCEDURA CHE STAMPA A VIDEO LA LISTA DEGLI UTENTI SALVATI NEL FILE "Utenti.txt"

///La procedura "aggiungi_artista" permette all'amministratore di aggiungere un artista
void aggiungi_artista(FILE* file_artisti, FILE* file_utenti,  FILE* file_preferenze, utenti utente[], artisti artista[], preferenze_artisti preferenza_artista[], int i, char scelta, int z); //PROCEDURA CHE PERMETTE ALL'AMMINISTRATORE DELLA PIATTAFORMA DI AGGIUNGERE UN NUOVO ARTISTA

///La procedura "modifica_artista" permette all'amministratore di modificare i dati relativi ad un artista salvato
void modifica_artista(FILE* file_artisti, FILE* file_utenti,  FILE* file_preferenze, utenti utente[], artisti artista[], preferenze_artisti preferenza_artista[], int i, char scelta, int z); //PROCEDURA CHE PERMETTE ALL'AMMINISTRATORE DELLA PIATTAFORMA DI MODIFICARE I DATI DI UN DETERMINATO ARTISTA

///La procedura "elimina_artista" permette all'amministratore di eliminare un artista
void elimina_artista(FILE* file_artisti, FILE* file_utenti,  FILE* file_preferenze, utenti utente[], artisti artista[], preferenze_artisti preferenza_artista[], int i, char scelta, int z); //PROCEDURA CHE PERMETTE ALL'AMMINISTRATORE DELLA PIATTAFORMA DI ELIMINARE UN DETERMINATO ARTISTA

///La procedura "return_menu_admin" permette all'amministratore di ritornare al proprio menù di partenza al termine dell'esecuzione di una operazione
void return_menu_admin(FILE* file_artisti, FILE* file_utenti,  FILE* file_preferenze, utenti utente[], artisti artista[], preferenze_artisti preferenza_artista[], int i, char scelta, int z); //PROCEDURA CHE PERMETTE ALL'AMMINISTRATORE DELLA PIATTAFORMA DI RITORNARE AL SUO MENU' AL TERMINE DELL'OPERAZIONE ESEGUITA
//----------------------------------------------------------------------------------------------------------------------------------------------------------//

#endif
