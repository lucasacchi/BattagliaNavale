#include "Battaglia.h"
#include "Menu.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using std::cout;
using std::cin;
using std::string;
using std::endl;

// per giocare
bool Battaglia::gioca()
{
	int primoGiocatore;
	Scacchiera * sPtr;
	Giocatore * gPtr;

	iniziaBattaglia();

	cout<<endl<<"Quale giocatore comincia? (inserire 1 o 2)\n";
	primoGiocatore=getInt(1,2);
	cout<<endl<<endl;


	// si fanno putare i puntatori creati in gioca al primo giocatore
  //i puntatori puntano al giocatore che deve giocare e alla Scacchiera
  // dell'avversario, che viene modificata
	if (primoGiocatore==1)
	{
		gPtr = &g1;
		sPtr = &s2;  //se gioca il giocatore 1, viene modificata la scacchiera 2
	}
	else {
		gPtr = &g2;
		sPtr = &s1;
	}
// si esegue un ciclo while che dura finchè la battaglia ha stato INCOMPLETA
	while(statoBattaglia()==INCOMPLETA)
	{
		if ((*gPtr).getTipoGiocatore())
		{
			azioneGiocatoreAuto(*(sPtr));
		}
		else
		{
			printTurno(*(gPtr));
			azioneGiocatore(*(sPtr));
			printTurno(*(gPtr));
		}


		if ((*gPtr).getNumeroGiocatore()==1)
		{
			if (!g1.getTipoGiocatore() && !g2.getTipoGiocatore()) //se sono entrambi manuali
			{
				invertiGiocatori(g1.getName(), g2.getName()); //da g1 a g2
			}
			gPtr = &g2;
			sPtr = &s1;
    // si cambiano i puntatori per far giocare il giocatore 2
		}
		else {
			if (!g1.getTipoGiocatore() && !g2.getTipoGiocatore()) //se sono entrambi manuali
			{
				invertiGiocatori(g2.getName(), g1.getName());  // da g2 a g1
			}
			gPtr = &g1;
			sPtr = &s2;
		}
	}

	if (statoBattaglia()==P1_VINCE)
		cout<<"La battaglia è stata dura ma alla fine " <<g1.getName()<< " ha vinto!"<<endl;
	else
		cout<<"La battaglia è stata dura ma alla fine " <<g2.getName()<< " ha vinto!"<<endl;

	cout<<"Arrivederci alla prossima battaglia!\n\n";
	return true;

}

// funzioni di partenza
void Battaglia::iniziaBattaglia()
{
	string nomeTemp;
	int autoTemp;

	//inizializzazione numero giocatori
	g1.setNumeroGiocatore(1);
	g2.setNumeroGiocatore(2);

	//inizializzazione nomi giocatori
	cout<<"Qual è il nome del giocatore 1 (<=32 chars)?\n";              //da mettere con i  vettori
	g1.setName(getString(32));
	cout<<"Benvenuto Capitan "<<g1.getName()<<"!"<<endl;

	cout<<"Qual è il nome del giocatore 2 (<=32 chars)?\n";
	g2.setName(getString(32));
	cout<<"Benvenuto Capitan "<<g2.getName()<<"!"<<endl;
	cout<<"Una dura battaglia vi attende!"<<endl<<endl;

	//inizializzazione tipo giocatori
	cout<<"Il giocatore " << g1.getName() << " è un giocatore automatico?"
					<<" (inserisci 0 per manuale, 1 per automatico)\n";
	g1.setTipoGiocatore(getInt(0,1));

  cout<<"Il giocatore " << g2.getName() << " è un giocatore automatico?"
					<<" (inserisci 0 per manuale, 1 per automatico)\n";
	g2.setTipoGiocatore(getInt(0,1));


	//inizializzazione delle scacchiere
	if (g1.getTipoGiocatore())  // è vera se il giocatore è automatico
		inizialScacchieraAuto(s1, false);
	else
	{
		cout<<g1.getName()<<", vuoi inizializzare la scacchiera in modo automatico?"
						<<" (inserisci 0 per manuale, 1 per automatico)\n";
		autoTemp=getInt(0,1);
		if (autoTemp)
			inizialScacchieraAuto(s1, true);
		else inizialScacchiera(s1);

	}

	// se entrambi i giocatori non sono automatici si deve pulire lo schermo
	if (!g2.getTipoGiocatore() && !g1.getTipoGiocatore())
	{
		invertiGiocatori(g1.getName(), g2.getName());
	}

	if (g2.getTipoGiocatore())
		inizialScacchieraAuto(s2, false);
	else
	{

		cout<<g2.getName()<<", vuoi inizializzare la scacchiera in modo automatico?"
						<<" (inserisci 0 per manuale, 1 per automatico)\n";
		autoTemp=getInt(0,1);
		if (autoTemp)
			inizialScacchieraAuto(s2, true);
		else inizialScacchiera(s2);

	}
	if (!g2.getTipoGiocatore() && !g1.getTipoGiocatore())   //entrambi manuali
	{
		cout<<string(100,'\n');  // DA CAMBIARE  QUA con qualcosa di più carino a quanto pare clean screen non va bene
	}

	return;
}

// prints game state, with player's own board exposed and opponent's board
// mostly obscured, save for moves player has made
void Battaglia::printTurno(Giocatore g0)
{
	cout<<g0.getName()<<"'s GAME STATE:\n\n";
	if (g0.getNumeroGiocatore()==1)
	{
		cout<<endl<<"La tua scacchiera: \n";
		s1.printScacchieraGiocatore();
		cout<<endl<<"La scacchiera nemica: \n";
		s2.printScacchieraAvversario();
		cout<<endl<<endl;
	}
	else
	{
    cout<<endl<<"La tua scacchiera: \n";
		s2.printScacchieraGiocatore();
		cout<<endl<<"La scacchiera nemica: \n";
		s1.printScacchieraAvversario();
		cout<<endl<<endl;
	}


	return;
}

// initializes board based on user input
void Battaglia::inizialScacchiera(Scacchiera &s0)
{
	int x;
  int y;
  int orientamento;
  int attemptCount;
	string entryTemp;                                       // da rivedere
	for (int i=0; i<NUMERO_NAVI; i++)
	{
		attemptCount=0;
		do // check for valid placement of each ship
		{
			s0.printScacchieraGiocatore();
			if (attemptCount>0)
				cout<<"Coordinate non valide. Reinserire le coordinate \n";

			cout<<"Inserisci le coordinate [lettera][numero] per "<<
						"l'estremo in alto a sinistra della nave "<<NOMI_NAVI[i]<<" di lunghezza "
						<<LUNGHEZZA_NAVI[i]<<": \n";
			entryTemp=getSquare();
			x=static_cast<int>(entryTemp[0]);                             //CAST???
			y=static_cast<int>(entryTemp[1]);

			cout<<"Inserire 0 se la nave è orientata verticalmente, "
						<<"1 se è orientata orizzontalmente\n";
			orientamento=getInt(0,1);

			attemptCount++;
		} while (!s0.posizionaNave(i, x-LETTER_CHAR_OFFSET,     // sta roba leviamola e mettiamo due cooordinate numeriche
						y-NUMBER_CHAR_OFFSET, orientamento));

	}

	cout<<endl<<"Ecco la tua flotta: \n";
	s0.printScacchieraGiocatore();

	return;
}


// initializes a board with random placement of ships on a board
void Battaglia::inizialScacchieraAuto(Scacchiera &s0, bool print)
{
	int x;
	int y;
	int orientamento;   // orizoontale o veticale

	for (int i=0; i<NUMERO_NAVI; i++)
	{
		do // posiziona casualmente le navi
		{
			x=rand()%10;
			y=rand()%10;
			orientamento=rand()%2;
		} while (!s0.posizionaNave(i, x, y, orientamento));
		// quando la funzione place ship ritorna vero allora la nave è stata posizionata con successo
	}

	if (print)
	// print è un bool che dice se bisogna stampare o no la scacchiera randomizzata
	//si stampa la scacchiera randomizzata se si è scelto di compilare la scacchiera in modo automatico
	//Qua potremmo modificare
	{
		cout<<endl<<"Ecco la tua flotta: " <<endl<<endl;
		s0.printScacchieraGiocatore();
	}

	return;
}

// ritorna lo stato overall del gioco
stato Battaglia::statoBattaglia()
{
	if (s1.getNumColpito()==LUNGHEZZA_TOTALE_NAVI)
		return P2_VINCE;

	else if (s2.getNumColpito()==LUNGHEZZA_TOTALE_NAVI)
		return P1_VINCE;

	else
		return INCOMPLETA;
}


// mossa giocatore manuale
void Battaglia::azioneGiocatore(Scacchiera &s0)
{
	int attemptCount=0;
	int x;
	int y;
	bool mossaPermessa=false;
	string entryTemp;

	while (!mossaPermessa)
	{
		if (attemptCount>0)
			cout<<"That move has already been attempted. Try again. \n";

		cout<<"Please enter location [Letter][Number] of desired move:\n";
		entryTemp=getSquare();
		x=static_cast<int>(entryTemp[0]);
		y=static_cast<int>(entryTemp[1]);

		if (s0.getStatoCasella(x-LETTER_CHAR_OFFSET,
						y-NUMBER_CHAR_OFFSET)!=COLPITO
			&& s0.getStatoCasella(x-LETTER_CHAR_OFFSET,
							y-NUMBER_CHAR_OFFSET)!=MANCATO)
		{
			s0.naveColpita(x-LETTER_CHAR_OFFSET, y-NUMBER_CHAR_OFFSET);
			mossaPermessa=true;
		}
		attemptCount++;
	}

	return;
}


// funzione per mossa casuale
void Battaglia::azioneGiocatoreAuto(Scacchiera &s0)
{
	bool mossaPermessa=false;
	int x, y;

	while (!mossaPermessa)  // finchè la mossa non è permessa si itera con il ciclo while
	{
		// la mossa è scelta a caso da 0 a 9 sia su x che su y
		x=rand()%10;
		y=rand()%10;

		if (s0.getStatoCasella(x, y)!=COLPITO
			&& s0.getStatoCasella(x, y)!=MANCATO)
		{
			s0.naveColpita(x, y);
			mossaPermessa=true;
		}
	}
	return;
}

// input validation for square
string Battaglia::getSquare()
{
	string retString;
	std::getline(std::cin, retString);
	bool inputValido=false;

	while (!inputValido)
	{
		// qua controlla che vengano messe lettere e numeri giusti
		if (retString.length()==2 && (retString[0]>=65 && retString[0]<=74)
						&& (retString[1]>=48 && retString[1]<=57))
			inputValido=true;
		else
		{
			cout<<"Bad input! Please enter location [Letter][Number] of "
						<<"your desired move, with capital letters only:\n";
			std::getline(std::cin, retString);
		}
	}

	return retString;
}


// switchPlayers is a function that controls the screen between turns,
// ensuring that the player whose turn it is can control what is visible
// on the screen in case someone else is peeking
void Battaglia::invertiGiocatori(string gIn, string gFin)  // giocatore iniziale e finale
{
	cout<<endl<<gIn<<", press ENTER to finish your turn!";
	std::cin.get();
	cout<<std::flush;
	cout<<string(100,'\n');
	cout<<endl<<gFin<<", press ENTER to start your turn!";
	std::cin.get();
	cout<<std::flush;
	cout<<string(100,'\n');

}
