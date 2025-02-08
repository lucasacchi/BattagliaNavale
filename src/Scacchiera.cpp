#include <iostream>
#include "Scacchiera.h"
using std::cout;
using std::endl;

// costruttore scacchiera con tutte le caselle acqua e costruzione del vettore flotta
Scacchiera::Scacchiera()
{
	for (int i=0; i<DIM_SCACCHIERA; i++)
		for (int j=0; j<DIM_SCACCHIERA; j++)
			theScacchiera[i][j]=ACQUA;

	for (int i=0; i<NUMERO_NAVI; i++)
		vetFlotta.push_back(Nave(LUNGHEZZA_NAVI[i], NOMI_NAVI[i]));
}

// copy constructor
Scacchiera::Scacchiera(const Scacchiera &s0) //s0 è la scacchiera che viene copiata
{
  for (int i=0; i<DIM_SCACCHIERA; i++)
		for (int j=0; j<DIM_SCACCHIERA; j++)
			theScacchiera[i][j]=s0.theScacchiera[i][j];
	vetFlotta = s0.vetFlotta;
}

// overload operatore =
Scacchiera& Scacchiera::operator=(const Scacchiera &sd)  //sd sta per scacchiera a destra dell'=
{
	if (this!=&sd)
	{
    for (int i=0; i<DIM_SCACCHIERA; i++)
  		for (int j=0; j<DIM_SCACCHIERA; j++)
  			theScacchiera[i][j]=sd.theScacchiera[i][j];
		vetFlotta = sd.vetFlotta;
	}

	return *this; // per le chiamate a cascata

}

// ritorna il numero di colpi andati a segno
int Scacchiera::getNumColpito()
{
	int count=0;

  for (int i=0; i<DIM_SCACCHIERA; i++)
    for (int j=0; j<DIM_SCACCHIERA; j++)
			if (theScacchiera[i][j]==COLPITO)
				count++;

	return count;
}

// stampa la scacchiera dell'avversario, senza far vederre le navi
void Scacchiera::printScacchieraAvversario()
{
	cout<<"  A B C D E F G H I J\n";
	for (int i=0; i<DIM_SCACCHIERA; i++)
	{
		cout<<i<<" ";
		for (int j=0; j<DIM_SCACCHIERA; j++)
		{
			if (theScacchiera[i][j]==COLPITO || theScacchiera[i][j]==MANCATO)
				cout<<theScacchiera[i][j]<<" ";
			else
				std::cout<<SCONOSCIUTO<<" "; // le caselle nè colpite nè mancate sono incognite
		}
		cout<<endl;
	}
}

// stampa la scacchiera del giocatore, facendo vedere le proprie navi
void Scacchiera::printScacchieraGiocatore()
{
	cout<<"  A B C D E F G H I J\n";
	for (int i=0; i<DIM_SCACCHIERA; i++)
	{
		cout<<i<<" ";
		for (int j=0; j<DIM_SCACCHIERA; j++)
		{
			cout<<theScacchiera[i][j]<<" ";
		}
		cout<<endl;
	}

}



//ritorna lo stato di una casella i,j
char Scacchiera::getStatoCasella(int x, int y)
{
	return theScacchiera[y][x];
}



// se viene colpita una nave l'elemento della scacchiera corrispondente viene modificato
// se viene colpita la funzione ritorna true , se non viene colpita nessuna nave false
bool Scacchiera::naveColpita(int x, int y)
{
	for (int i=0; i<NUMERO_NAVI; i++)
	{
		if (vetFlotta[i].naveColpita(x, y))
		{
			theScacchiera[y][x]=COLPITO; //la scacchiera viene modificata se viene colpita una nave

			if (vetFlotta[i].affondata()) // si stampa un messaggio di testo se viene affondata una nave
				cout<< "La nave " << vetFlotta[i].getName()<<" è stata affondata!\n";
			return true;
		}
	}
	theScacchiera[y][x]=MANCATO;
	return false;
}



// posizionamento di una nave sulla scacchiera
bool Scacchiera::posizionaNave(int numNave, int x, int y, bool oriz)
{
	//se x o y sono fuori dai bordi della scacchiera ritorna falso
	if (x>=DIM_SCACCHIERA || y>=DIM_SCACCHIERA)
		return false;

	//se la nave è già stata posizionata ritorna falso
  //se la nave non è stata posizionata x e y sono uguali a -1
	if (vetFlotta[numNave].getX()>=0 && vetFlotta[numNave].getY()>=0)
		return false;

	//si controlla con un ciclo for se la nave occupa posizioni corrette
  //se va ad occupare spazi occupati o fuori dalla scacchiera ritorna falso
	for (int i=0; i<vetFlotta[numNave].getSize(); i++)
	{
    //si controlla che le caselle siano libere
		if ((oriz && theScacchiera[y][x+i]!=ACQUA) ||
							(!oriz && theScacchiera[y+i][x]!=ACQUA))
			return false;
		//si controlla che le caselle siano all'interno della scacchiera
		if ((oriz && (x+i)>=DIM_SCACCHIERA) ||
							(!oriz && (y+i)>=DIM_SCACCHIERA))
			return false;
	}

	//se non ha ritornato falso allora tutte le caselle sono disponibili
  //si posizionano le navi
	for (int i=0; i<vetFlotta[numNave].getSize(); i++)
	{
		if (oriz)
			theScacchiera[y][x+i]=NAVE_INTERA;
		else
			theScacchiera[y+i][x]=NAVE_INTERA;
	}

	//si settano i parametri dell'oggetto nave
	vetFlotta[numNave].setPosition(x, y, oriz);

	// se tutti i posti erano disponibili dopo aver cambiato i valori della
  //scacchiera e della nave si ritorna true
	return true;
}
