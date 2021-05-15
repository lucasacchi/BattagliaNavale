#include <string>
using std::string;

#ifndef GIOCATORE_H
#define GIOCATORE_H

class Giocatore
{
	public:
		Giocatore();
		Giocatore(string nome, bool tipo, int num);
		Giocatore(const Giocatore &g0);
		Giocatore& operator = (const Giocatore &gd);
		~Giocatore() {};
		string getName() const;
		bool getTipoGiocatore() const;  //true automatico, false giocatore manuale
		int getNumeroGiocatore() const;
		void setName(string nome);
		void setTipoGiocatore(bool tipo); //true automatico, false giocatore manuale
		void setNumeroGiocatore(int num);

	private: // i data member hanno tutti nomi con "Giocatore" alla fine
		string nomeGiocatore;
		bool tipoGiocatore;  // true se automatico, false se manuale
		int numeroGiocatore;
};

#endif
