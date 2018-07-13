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
void login_admin(FILE* file_artisti, FILE* file_utenti,  FILE* file_preferenze, utenti utente[], artisti artista[], preferenze_artisti preferenza_artista[], int i, char scelta, int z); //PROCEDURA CHE PERMETTE ALL'AMMINISTRATORE DELLA PIATTAFORMA DI EFFETTUARE L'ACCESSO ALLA SUA INTERFACCIA RISERVATA, INSERENDO USERNAME E PASSWORD
void menu_admin(FILE* file_artisti, FILE* file_utenti,  FILE* file_preferenze, utenti utente[], artisti artista[], preferenze_artisti preferenza_artista[], int i, char scelta, int z); //PROCEDURA CHE STAMPA A VIDEO IL MENU' CON LE DIVERSE OPERAZIONI CHE L'AMMINISTRATORE DELLA PIATTAFORMA PUO' FAR ESEGUIRE UNA VOLTA EFFETTUATO IL LOGIN
void visualizza_utenti(FILE* file_artisti, FILE* file_utenti,  FILE* file_preferenze, utenti utente[], artisti artista[], preferenze_artisti preferenza_artista[], int i, char scelta, int z); //PROCEDURA CHE STAMPA A VIDEO LA LISTA DEGLI UTENTI SALVATI NEL FILE "Utenti.txt"
void aggiungi_artista(FILE* file_artisti, FILE* file_utenti,  FILE* file_preferenze, utenti utente[], artisti artista[], preferenze_artisti preferenza_artista[], int i, char scelta, int z); //PROCEDURA CHE PERMETTE ALL'AMMINISTRATORE DELLA PIATTAFORMA DI AGGIUNGERE UN NUOVO ARTISTA
void modifica_artista(FILE* file_artisti, FILE* file_utenti,  FILE* file_preferenze, utenti utente[], artisti artista[], preferenze_artisti preferenza_artista[], int i, char scelta, int z); //PROCEDURA CHE PERMETTE ALL'AMMINISTRATORE DELLA PIATTAFORMA DI MODIFICARE I DATI DI UN DETERMINATO ARTISTA
void elimina_artista(FILE* file_artisti, FILE* file_utenti,  FILE* file_preferenze, utenti utente[], artisti artista[], preferenze_artisti preferenza_artista[], int i, char scelta, int z); //PROCEDURA CHE PERMETTE ALL'AMMINISTRATORE DELLA PIATTAFORMA DI ELIMINARE UN DETERMINATO ARTISTA
void return_menu_admin(FILE* file_artisti, FILE* file_utenti,  FILE* file_preferenze, utenti utente[], artisti artista[], preferenze_artisti preferenza_artista[], int i, char scelta, int z); //PROCEDURA CHE PERMETTE ALL'AMMINISTRATORE DELLA PIATTAFORMA DI RITORNARE AL SUO MENU' AL TERMINE DELL'OPERAZIONE ESEGUITA
//----------------------------------------------------------------------------------------------------------------------------------------------------------//

#endif
