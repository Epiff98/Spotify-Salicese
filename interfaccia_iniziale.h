/**
 * @file interfaccia_iniziale.h
 *
 * @brief Interfaccia iniziale del programma.
 *
 * La libreria interfaccia.h è stata implementata per permettere all'utente e all'amministratore
 * della piattaforma di interagire con il programma mediante un menu' iniziale che elenca
 * le 4 possibili operazioni da poter far eseguire: 1 è riservata solo all'amministratore per accedere
 * alla sua area riservata, le restanti permettono all'utente di accedere o registrarsi alla piattaforma.
 *
 * @authors Andrea De Matteis, Marco Epifani, Giorgio Calcagnile
 */

#ifndef INTERFACCIA_INIZIALE_H_
#define INTERFACCIA_INIZIALE_H_

///La procedura "interfaccia_iniziale" permette di stampare a video il menu' iniziale del programma con l'elenco delle operazioni attraverso le quali l'utente o amministratore possono accedere e iscriversi alla piattaforma
void interfaccia_iniziale(FILE* file_artisti, FILE* file_utenti,  FILE* file_preferenze, utenti utente[], artisti artista[], preferenze_artisti preferenza_artista[], int i, char scelta, int z); //PROCEDURA CHE STAMPA A VIDEO IL MENU' INIZIALE DELLA PIATTAFORMA "SPOTIFY"

#endif
