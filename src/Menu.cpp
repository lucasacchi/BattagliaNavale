#include <iostream>
#include "Menu.h"
#include "PvAI.h"
#include "PvP.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

void printTitolo()
{
	cout << endl
		 << endl
		 << endl;
	cout << "           ╔═════════════════════════════════════════════════════╗" << endl;
	cout << "           ║ ╔═════════════════════════════════════════════════╗ ║" << endl;
	cout << "           ║ ║                                                 ║ ║" << endl;
	cout << "           ║ ║                                                 ║ ║" << endl;
	cout << "           ║ ║                BATTAGLIA NAVALE                 ║ ║" << endl;
	cout << "           ║ ║                                                 ║ ║" << endl;
	cout << "           ║ ║                                                 ║ ║" << endl;
	cout << "           ║ ╚═════════════════════════════════════════════════╝ ║" << endl;
	cout << "           ╚═════════════════════════════════════════════════════╝" << endl
		 << endl;
}

void printMenu()
{
	cout << endl
		 << endl;
	cout << "           ╔═════════════════════════════════════════════════════╗" << endl;
	cout << "           ║                                                     ║" << endl;
	cout << "           ║                   MENU DI GIOCO                     ║" << endl;
	cout << "           ║                                                     ║" << endl;
	cout << "           ║               1. Gioca PvP                          ║" << endl;
	cout << "           ║               2. Gioca PvAI                         ║" << endl;
	cout << "           ║               3. Regole                             ║" << endl;
	cout << "           ║               4. Esci dal gioco                     ║" << endl;
	cout << "           ║                                                     ║" << endl;
	cout << "           ╚═════════════════════════════════════════════════════╝" << endl
		 << endl;
}

bool startMenu()
{
	int input;
	printMenu();
	input = getInt(1, 4);

	if (input == 1)
	{
		PvP battPvP;
		battPvP.gioca();
		return true;
	}

	else if (input == 2)
	{
		PvAI battPvAI;
		battPvAI.gioca();
		return true;
	}

	/*
		else if (input==2)
		{
			Battaglia batt;
			batt.gioca();
			return true;
		}
	*/

	else if (input == 3)
	{
		cout << endl
			 << endl;
		cout << "           ╔═════════════════════════════════════════════════════╗" << endl;
		cout << "           ║                  REGOLE DEL GIOCO                   ║" << endl;
		cout << "           ║                                                     ║" << endl;
		cout << "           ║            Benvenuti in Battaglia Navale!           ║" << endl;
		cout << "           ║ L'obiettivo del gioco è affondare la flotta nemica  ║" << endl;
		cout << "           ║      prima che l'avversario affondi la tua.         ║" << endl;
		cout << "           ║   All'inizio del gioco i giocatori dispongono la    ║" << endl;
		cout << "           ║ propria flotta sulla propria scacchiera in segreto. ║" << endl;
		cout << "           ║  Ogni turno i giocatori scelgono una casella della  ║" << endl;
		cout << "           ║  scacchiera nemica inserendone le coordinate, se    ║" << endl;
		cout << "           ║  sulla casella è presente una nave nemica, allora   ║" << endl;
		cout << "           ║   essa è stata colpita. Ogni nave occupa un certo   ║" << endl;
		cout << "           ║  numero di caselle, quando tutte le caselle di una  ║" << endl;
		cout << "           ║  nave vengono colpite la nave è affondata. Se tutte ║" << endl;
		cout << "           ║  le navi di un giocatore vengono affondate, allora  ║" << endl;
		cout << "           ║          quel giocatore perde la partita.           ║" << endl;
		cout << "           ║                                                     ║" << endl;
		cout << "           ║        Premere INVIO per tornare al menu            ║" << endl;
		cout << "           ╚═════════════════════════════════════════════════════╝" << endl
			 << endl;

		if (cin.get() == '\n')
		{
			cout << string(200, '\n');
			return true;
		}
		cin.ignore(10000, '\n');

		// Ensure return in all cases
		return true;
	}

	else
	{
		cout << string(10, '\n');
		cout << "           ╔═════════════════════════════════════════════════════╗" << endl;
		cout << "           ║ ╔═════════════════════════════════════════════════╗ ║" << endl;
		cout << "           ║ ║                                                 ║ ║" << endl;
		cout << "           ║ ║                                                 ║ ║" << endl;
		cout << "           ║ ║      ARRIVEDERCI ALLA PROSSIMA BATTAGLIA!       ║ ║" << endl;
		cout << "           ║ ║                                                 ║ ║" << endl;
		cout << "           ║ ║                                                 ║ ║" << endl;
		cout << "           ║ ╚═════════════════════════════════════════════════╝ ║" << endl;
		cout << "           ╚═════════════════════════════════════════════════════╝" << endl;
		cout << string(5, '\n');
		return false;
	}
}

// qua metterei i vettori
string getString(int maxLen)
{
    string retString;
    getline(cin, retString);
    while (retString.length() > static_cast<size_t>(maxLen)) // Cast to size_t
    {
        cout << "String too long! Please enter a string with <= " << maxLen << " characters:" << endl;
        std::getline(std::cin, retString);
    }
    cout << endl;
    return retString;
}


// QUA BISOGNA CAMBIARE UN PO TUTTO
//  input validation requires two ints, to indicate the allowed range for input
//  the function will prompt a user to enter an int until
//  an appropriate one is entered
int getInt(int min, int max)
{
	string retString;
	getline(cin, retString);
	bool inputValido = false;
	int nIter = 0;
	char tempChar;
	bool isNeg = false;
	int retInt = 0;

	// io metterei numeri sia su x che su y e via da modificare

	while (!inputValido)
	{
		inputValido = true;
		// prompt fot input again if input was bad
		if (nIter > 0)
		{
			cout << "Bad input! Please enter an integer between " << min;
			cout << " and " << max << "." << endl;
			std::getline(std::cin, retString);
		}
		if (retString.length() > 0)
		{
			// process the string, char by char, to see if it's a numeric
			for (size_t i = 0; i < retString.length(); i++)
			{
				tempChar = static_cast<char>(retString[i]);
				// if the first character is a negatve, note it, and continue
				if (i == 0 & tempChar == '-')
				{
					isNeg = true;
				}
				// if char is numeric, update the integer to be returned
				else
				{
					if (tempChar >= ASCII_INT_MIN && tempChar <= ASCII_INT_MAX)
					{
						retInt = retInt * 10 + (static_cast<int>(tempChar) -
												ASCII_INT_MIN);
					}
					else // if any non-ints encountered, break loop
					{
						inputValido = false;
						break;
					}
				}
			}
		}
		// zero length inputs are bad inputs
		else
		{
			inputValido = false;
		}

		// if negative, mutiply by -1
		if (inputValido && isNeg)
		{
			retInt = (-1) * retInt;
		}
		// check that int is between limits
		if (inputValido && (retInt < min || retInt > max))
		{
			inputValido = false;
		}

		// if input was bad, reset trackers and start over again
		if (!inputValido)
		{
			retInt = 0;
			isNeg = false;
		}

		nIter++;
	}

	cout << endl
		 << endl;
	return retInt;
}
