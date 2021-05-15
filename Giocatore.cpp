#include "Giocatore.h"

using std::string;

// costruttore di default
Giocatore::Giocatore()
{
	nomeGiocatore="";
	tipoGiocatore = false;
	numeroGiocatore = 1;
}

//costruttore con nome tipo e numero
Giocatore::Giocatore(string nome, bool tipo, int num)
{
	nomeGiocatore=nome;
	tipoGiocatore = tipo;   //1 se automatico, 0 se manuale
	numeroGiocatore = num;
}

// copy constructor
Giocatore::Giocatore(const Giocatore &g0)
{
	nomeGiocatore=g0.nomeGiocatore;
	tipoGiocatore=g0.tipoGiocatore;
	numeroGiocatore=g0.numeroGiocatore;

}

//overload dell'operatore =
Giocatore& Giocatore::operator=(const Giocatore &gd)
{
	if (this != &gd)
	{
		nomeGiocatore = gd.nomeGiocatore;
		tipoGiocatore = gd.tipoGiocatore;
		numeroGiocatore = gd.numeroGiocatore;
	}

	return *this; // per le chiamate a cascata
}

//funzioni get (nome, tipo, numero)
string Giocatore::getName() const  // qua ho messo const ma non so se serve
{
	return nomeGiocatore;
}

bool Giocatore::getTipoGiocatore() const   // qua ho messo const ma non serve
{
	return tipoGiocatore;  //1 se automatico, 0 se manuale
}

int Giocatore::getNumeroGiocatore() const  // anche qua const
{
	return numeroGiocatore;
}

//funzioni set (nome, tipo, numero)
void Giocatore::setName(string nome)
{
	nomeGiocatore=nome;
	return;
}

void Giocatore::setTipoGiocatore(bool tipo)
{
	tipoGiocatore=tipo;  //1 se automatico, 0 se manuale
	return;
}

void Giocatore::setNumeroGiocatore(int num)
{
	numeroGiocatore = num;
	return;
}
