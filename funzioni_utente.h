/**
 * @file funzioni_utente.h
 *
 * @brief Libreria per le funzionalita' a disposizione dell'utente che accede alla piattaforma "Spotify".
 *
 * La libreria funzioni_utente.h è stata implementata per la gestione delle funzionalita' messe a disposizone
 * dell'utente che usufruisce del servizio "Spotify".
 * Ogni utente puo' usufruire del servizio registrandosi alla piattaforma, fornendo i propri dati anagrafici e
 * scegliendo appropriati Username e Password con i quali effettuare l'accesso
 *
 * @authors Andrea De Matteis, Marco Epifani, Giorgio Calcagnile
 */

#ifndef FUNZIONI_UTENTE_H_
#define FUNZIONI_UTENTE_H_

//--------------------------------------------------------------- FUNZIONI DELL'INTERFACCIA UTENTE ---------------------------------------------------------//

///La procedura "login_utente()" permette all'utente di accedere alla piattaforma fornendo le proprie credenziali: Username e Password.
void login_utente(FILE* file_artisti, FILE* file_utenti, FILE* file_preferenze, utenti utente[], artisti artista[], preferenze_artisti preferenza_artista[], int i, char scelta, int z); //PROCEDURA CHE PERMETTE ALL'UTENTE DI EFFETTUARE L'ACCESSO ALLA PIATTAFORMA "SPOTIFY", INSERENDO IL PROPRIO USERNAME E PASSWORD

///La procedura "signup" permette all'utente di iscriversi alla piattaforma fornendo i propri dati anagrafici (nome, cognome, data di nascita) e scegliendo appropriati Username e Password.
void signup(FILE* file_artisti, FILE* file_utenti, FILE* file_preferenze, utenti utente[], artisti artista[], preferenze_artisti preferenza_artista[], int i, char scelta, int z); //PROCEDURA CHE PERMETTE ALL'UTENTE DI REGISTRARSI ALLA PIATTAFORMA "SPOTIFY", FORNENDO I PROPRI DATI ANAGRAFICI E SCEGLIENDO UN USERNAME E UNA PASSWORD PER POTER POI ACCEDERE

///La procedura "salvataggio_utente_loggato" ha il compito di salvare sul file "indice_utente_loggato.txt" l'indice dell'utente che ha effettuato l'accesso alla piattaforma.
void salvataggio_indice_utente_loggato(FILE* file_utenti, utenti utente[], int i, int z); //PROCEDURA CHE PERMETTE DI SALVARE SUL FILE "indice_utente_loggato.txt" L'INDICE CORRISPONDENTE ALL'UTENTE CHE HA EFFETTUATO IL LOGIN

///La procedura "menu_utente" permette di stampare a video un menu' con l'elenco delle operazioni che l'utente potra' far eseguire.
void menu_utente(FILE* file_artisti, FILE* file_utenti,  FILE* file_preferenze, utenti utente[], artisti artista[], preferenze_artisti preferenza_artista[], int i, char scelta, int z); //PROCEDURA CHE STAMPA A VIDEO IL MENU' CON LE DIVERSE OPERAZIONI CHE L'UTENTE PUO' FAR ESEGUIRE UNA VOLTA EFFETTUATO IL LOGIN

///La procedura "visualizza_artisti" permette all'utente di visualizzare la lista di artisti salvati.
void visualizza_artisti(FILE* file_artisti, FILE* file_utenti,  FILE* file_preferenze, utenti utente[], artisti artista[], preferenze_artisti preferenza_artista[], int i, int z); //PROCEDURA CHE STAMPA A VIDEO LA LISTA DEGLI ARTISTI SALVATI SUL FILE "Artisti.txt"

///La procedura "aggiungi_preferenza" permette all'utente di esprimere una preferenza per un determinato artista.
void aggiungi_preferenza(FILE* file_artisti, FILE* file_utenti,  FILE* file_preferenze, utenti utente[], artisti artista[], preferenze_artisti preferenza_artista[], int i, char scelta, int z); //PROCEDURA CHE PERMETTE ALL'UTENTE DI ASSEGNARE UNA PREFERENZA (like, dislike, listen) ALL'ARTISTA DESIDERATO

///La procedura "modifica_preferenza" permette all'utente di modificare il tipo di preferenza precedentemente espressa per un determinato artista.
void modifica_preferenza(FILE* file_artisti, FILE* file_utenti, FILE* file_preferenze, utenti utente[], artisti artista[], preferenze_artisti preferenza_artista[], int i, char scelta, int z); //PROCEDURA CHE PERMETTE ALL'UTENTE DI MODIFICARE UNA SUA PREFERENZA ESPRESSA PER UN DETERMINATO ARTISTA

///La procedura "elimina_preferenza" permette all'utente di eliminare una preferenza precedentemente espressa per un determinato artista.
void elimina_preferenza(FILE* file_artisti, FILE* file_utenti, FILE* file_preferenze, utenti utente[], artisti artista[], preferenze_artisti preferenza_artista[], int i, char scelta,  int z); //PROCEDURA CHE PERMETTE ALL'UTENTE DI ELIMINARE UNA PREFERENZA ESPRESSA PER UN DETERMINATO ARTISTA

///La procedura "ricerca_artisti" permette di stampare a video i 3 parametri per cui ricercare un artista, l'utente potra' scegliere una delle seguenti opzioni: ricerca per genere, ricerca per nazionalita' e ricerca per anno di inizio produzione
void ricerca_artisti(FILE* file_artisti, FILE* file_utenti, FILE* file_preferenze, utenti utente[], artisti artista[], preferenze_artisti preferenza_artista[], int i, char scelta, int z); //PROCEDURA CHE STAMPA A VIDEO I PARAMETRI PER CUI E'POSSIBILE RICERCARE GLI ARTISTI. L'UTENTE DOVRA' INDICARE SE RICERCARE GLI ARTISTI PER GENERE, PER NAZIONALITA' oppure PER ANNO DI INIZIO CARRIERA

///La procedura "ricerca_per_genere" permette all'utente di ricercare gli artisti di un determinato genere
void ricerca_per_genere(FILE* file_artisti, FILE* file_utenti,  FILE* file_preferenze, utenti utente[], artisti artista[], preferenze_artisti preferenza_artista[], int i, char scelta, int z); //PROCEDURA CHE PERMETTE DI VISUALIZZARE GLI ARTISTI DI UN DETERMINATO GENERE DEFINITO DALL'UTENTE

///La procedura "ricerca_per_nazionalita" permette all'utente di ricercare gli artisti di una determinata nazionalità
void ricerca_per_nazionalita(FILE* file_artisti, FILE* file_utenti,  FILE* file_preferenze, utenti utente[], artisti artista[], preferenze_artisti preferenza_artista[], int i, char scelta, int z); //PROCEDURA CHE PERMETTE DI VISUALIAZZARE GLI ARTISTI DI UNA DETERMINATA NAZIONALITA' DEFINITA DALL'UTENTE

///La procedura "ricerca_per_anno_inizio_produzione" permette all'utente di ricercare gli artisti aventi anno di inizio produzione compreso nel "range" di anni definito dall'utente
void ricerca_per_anno_inizio_produzione(FILE* file_artisti, FILE* file_utenti,  FILE* file_preferenze, utenti utente[], artisti artista[], preferenze_artisti preferenza_artista[], int i, char scelta, int z); //PROCEDURA CHE PERMETTE DI VISUALIZZARE GLI ARTISTI CON ANNO DI PRODUZIONE COMPRESO IN UN RANGE STABILITO IN INPUT DALL'UTENTE

///La procedura "classifica_artisti" permette di stampare a video le 2 classifiche degli artisti, l'utente potra' scegliere una delle seguenti opzioni: classfica top 10 più ascoltati e classifica top 10 più piaciuti
void classifiche_artisti(FILE* file_artisti, FILE* file_utenti,  FILE* file_preferenze, utenti utente[], artisti artista[], preferenze_artisti preferenza_artista[], int i, char scelta, int z); //PROCEDURA CHE PERMETTE DI SCEGLIERE QUALE CLASSIFICA DEGLI ARTISTI VISIONARE TRA: TOP LISTEN e TOP LIKE

///La procedura "classifica_top_listen" permette all'utente di visionare la classifica dei top 10 artisti più ascoltati
void classifica_top_listen(FILE* file_artisti, FILE* file_utenti,  FILE* file_preferenze, utenti utente[], artisti artista[], preferenze_artisti preferenza_artista[], int i, char scelta, int z); //PROCEDURA CHE PERMETTE DI VISUALIZZARE LA CLASSIFICA DEI TOP 10 ARTISTI PIU' ASCOLTATI

///La procedura "classifica_top_like" permette all'utente di visionare la classifica dei top 10 artisti più piaciuti
void classifica_top_like(FILE* file_artisti, FILE* file_utenti,  FILE* file_preferenze, utenti utente[], artisti artista[], preferenze_artisti preferenza_artista[], int i, char scelta, int z); //PROCEDURA CHE PERMETTE DI VISUALIZZARE LA CLASSIFICA DEI TOP 10 ARTISTI PIU' PIACIUTI

///La procedura "suggerimento_artisti" permette all'utente di visionare gli artisti graditi dagli utenti a lui simili
void suggerimento_artisti(FILE* file_artisti, FILE* file_utenti,  FILE* file_preferenze, utenti utente[], artisti artista[], preferenze_artisti preferenza_artista[], int i, char scelta, int z);

///La procedura "profilo" permette di stampare a video i dati dell'utente loggato, il quale potra' scegliere se modificare i propri dati, modificare/eliminare una preferenza o eliminare il proprio account
void profilo(FILE* file_artisti, FILE* file_utenti, FILE* file_preferenze, utenti utente[], artisti artista[], preferenze_artisti preferenza_artista[], int i, char scelta, int z); //PROCEDURA CHE STAMPA A VIDEO I DATI RELATIVI ALL'UTENTE LOGGATO. INOLTRE PERMETTE DI EFFETTUARE MODIFICHE AI SUOI DATI/PREFERENZE oppure ELIMINARE IL SUO ACCOUNT

///La procedura "modifica_profilo" permette all'utente di modificare i propri dati: nome, cognome, data di nascita o password
void modifica_profilo(FILE* file_artisti, FILE* file_utenti, FILE* file_preferenze, utenti utente[], artisti artista[], preferenze_artisti preferenza_artista[], int i, char scelta, int z); //PROCEDURA CHE PERMETTE ALL'UTENTE DI MODIFICARE I SUOI DATI

///La procedura  "visualizza_preferenze" permette all'utente di visualizzare la lista delle proprie preferenze assegnate
void visualizza_preferenze(FILE* file_artisti, FILE* file_utenti, FILE* file_preferenze, utenti utente[], artisti artista[], preferenze_artisti preferenza_artista[], int i, int z); //PROCEDURA CHE STAMPA A VIDEO LA LISTA DELLE PREFERENZE DELL'UTENTE LOGGATO

///La procedura "elimina_account" permette all'utente di eliminare il proprio account
void elimina_account(FILE* file_artisti, FILE* file_utenti, FILE* file_preferenze, utenti utente[], artisti artista[], preferenze_artisti preferenza_artista[], int i, char scelta, int z); //PROCEDURA CHE CONSENTE ALL'UTENTE DI ELIMINARE IL SUO ACCOUNT

///La procedura "return_menu_utente" permette all'utente di ritornare al proprio menù di partenza al termine dell'esecuzione di una operazione
void return_menu_utente(FILE* file_artisti, FILE* file_utenti, FILE* file_preferenze, utenti utente[], artisti artista[], preferenze_artisti preferenza_artista[], int i, char scelta, int z); //PROCEDURA CHE PERMETTE ALL'UTENTE DI RITORNARE AL SUO MENU' AL TERMINE DELL'OPERAZIONE ESEGUITA
//---------------------------------------------------------------------------------------------------------------------------------------------------------//

#endif
