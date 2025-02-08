#include <iostream>
#include "Nave.h"
#include "Costanti.h"

using std::cout;
using std::string;

// costruttore nave di base
Nave::Nave(int size, string  nome)
{
	sizeNave = size;
	nomeNave = nome;
	caselleNave = new char[size];
	for (int i=0; i<size; i++)
		caselleNave[i] = NAVE_INTERA; // inizializza tutte le caselle della nave a #
	xNave = -1; //la nave occupa caselle negative se non è stata ancora posizionata
	yNave = -1; //la nave occupa caselle negative se non è stata ancora posizionata
	affondataNave = false; //si inizializza la nave come non affondata
	orizzontaleNave = true; // si inizializza la nave come orizzontale
}

// costruttore nave completo
Nave::Nave(int size, string nome, int x, int y, bool aff, bool oriz)
{
  sizeNave = size;
	nomeNave = nome;
	caselleNave = new char[size];
	for (int i=0; i<size; i++)
		caselleNave[i]=NAVE_INTERA; // inizializza tutte le caselle della nave a #
	xNave = x;
	yNave = y;
	affondataNave = aff;
	orizzontaleNave = oriz;
}



// copy constructor SERVE DAVVERO??
Nave::Nave(const Nave &n0)
{
	sizeNave=n0.getSize();
	nomeNave = n0.getName();
	caselleNave=new char[sizeNave];
	for (int i=0; i<sizeNave; i++)
		caselleNave[i]=n0.caselleNave[i];
	xNave=n0.getX();
	yNave=n0.getY();
	affondataNave=n0.affondata();
	orizzontaleNave=n0.orizzontale();
}


// overload operatore =
Nave& Nave::operator=(const Nave & nd)  // nd sta per nave di destra
{
	if (this != &nd)
	{
		sizeNave=nd.getSize();
		nomeNave = nd.getName();
		xNave=nd.getX();
		yNave=nd.getY();
		affondataNave=nd.affondata();
		orizzontaleNave=nd.orizzontale();

		if (sizeNave>0) // elimina vecchia memoria prima di farne di nuova
			delete [] caselleNave;
		caselleNave = new char[sizeNave];
		for (int i=0; i<sizeNave; i++)
			caselleNave[i]=nd.caselleNave[i];
	}

	return *this;
}




// distruttore per memoria heap
Nave::~Nave()
{
	if (sizeNave > 0)
		delete [] caselleNave;
}




int Nave::getSize() const
{
	return sizeNave;
}

int Nave::getX() const
{
	return xNave;
}

int Nave::getY() const
{
	return yNave;
}

bool Nave::affondata() const
{
	return affondataNave;
}

bool Nave::orizzontale() const
{
	return orizzontaleNave;
}

string Nave::getName() const
{
	return nomeNave;
}


void Nave::setPosition(int x, int y, bool oriz)
{
	xNave = x;
	yNave = y;
	orizzontaleNave = oriz;
	return;
}


// funzione per tener conto dei colpi subiti dalle navi, 0 se non colpite, 1 se colpite
// x su lettere e y su numeri
bool Nave::naveColpita(int xColpo, int yColpo)
{
	//si controlla se il colpo ha colpito la nave
	if ((orizzontaleNave & (xColpo<xNave || xColpo>=xNave+sizeNave
														|| yColpo!=yNave))
		|| (!orizzontaleNave & (yColpo<yNave || yColpo>=yNave+sizeNave
														|| xColpo!=xNave)))
		return false; //non è stata colpita la nave
	else // se è stata colpita la nave
	{
		if (orizzontaleNave)
			caselleNave[xColpo-xNave]=COLPITO;
		else
			caselleNave[yColpo-yNave]=COLPITO;
	}

	// se la nave è stata affondata
	affondataNave=true;
	for (int i=0; i<sizeNave; i++)
		if (caselleNave[i]==NAVE_INTERA)
			affondataNave=false;

	return true;
}



// STAMPA NAVE SOLO PER TEST
void Nave::printNave()
{
	for (int i=0; i<sizeNave; i++)
		cout<<caselleNave[i]<<" ";
		cout<<std::endl;
		cout<< affondata()<< std::endl << orizzontale()<< std::endl << getX()<< std::endl << getY() << std::endl;
	return;
}
