#include "Nave.h"
#include "Costanti.h"
#include <vector>
using std::vector;

#ifndef SCACCHIERA_H
#define SCACCHIERA_H

class Scacchiera
{
	public:
		Scacchiera();
		Scacchiera(const Scacchiera &s0);
		Scacchiera& operator=(const Scacchiera &sd);
		~Scacchiera(){}; // distruttore standard serve davver???
		int getNumColpito();
		void printScacchieraAvversario();
		void printScacchieraGiocatore();
		char getStatoCasella(int x, int y);
		bool naveColpita(int x, int y);
		bool posizionaNave(int numNavi, int x, int y, bool oriz);

  private:
    char theScacchiera[DIM_SCACCHIERA][DIM_SCACCHIERA];
    vector<Nave> vetFlotta;

};

#endif
