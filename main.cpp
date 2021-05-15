#include "Battaglia.h"
#include "Giocatore.h"
#include "Menu.h"
#include <iostream>

int main()
{
	unsigned seed=time(0);
	srand(seed);

	bool continueGame=true;

  printTitolo();

	while (continueGame)
	{
		continueGame = startMenu();
	}
	return 0;

}
