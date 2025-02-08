#include <string>
using std::string;

#ifndef COSTANTI_H
#define COSTANTI_H

// caratteri che riempono la scacchiera
const char COLPITO = 'X';
const char MANCATO = 'O';
const char ACQUA = '-';
const char NAVE_INTERA = '#';
const char SCONOSCIUTO = '-';

// costanti che descrivono il numero di navi e le loro caratteristiche
const int NUMERO_NAVI = 5;
const int DIM_SCACCHIERA = 10;
const int CASELLE_SCACCHIERA = 100;
const int LUNGHEZZA_NAVI[NUMERO_NAVI] = {5, 4, 3, 3, 2};
const int LUNGHEZZA_TOTALE_NAVI = 17;
const string NOMI_NAVI[NUMERO_NAVI] =
			{"Portaerei","Corazzata","Sottomarino","Incrociatore","Cacciatorpediniere"};

// to convert char to board position DAFARE
const int LETTER_CHAR_OFFSET=65;
const int NUMBER_CHAR_OFFSET=48;

// consts for input validation DAFARE
const int ASCII_INT_MIN=48;
const int ASCII_INT_MAX=57;

enum stato {P1_VINCE, P2_VINCE, INCOMPLETA};

#endif
