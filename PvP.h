#include "Scacchiera.h"
#include "Giocatore.h"
using std::string;

#ifndef PVP_H
#define PVP_H


class PvP  // non abbiamo definito un costruttore qua???
{
	public:
		bool gioca();
		void iniziaBattaglia();
		void inizialScacchiera(Scacchiera &s0);
		void inizialScacchieraAuto(Scacchiera &s0, bool print=true);
		stato statoBattaglia();
		void printTurno(Giocatore g0);
		void azioneGiocatore(Scacchiera &s0);
//		void azioneGiocatoreAuto(Scacchiera &s0);
		string getSquare();
		void invertiGiocatori(string gIn, string gFin);  //si esegue uno scambio da gIn a gFin

  private:
    Giocatore g1;
    Scacchiera s1;
    Giocatore g2;
    Scacchiera s2;
};

#endif
