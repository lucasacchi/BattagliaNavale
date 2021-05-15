#include<iostream>
#include<string>
#include "Nave.h"
#include "Costanti.h"
#include "Scacchiera.h"

using namespace std;

int main()
{
  Nave n1(4, "stocazzo" , 3, 4, 0, 1);
  n1.printNave();
  cout<<endl;
  Scacchiera s1;
  s1.printScacchieraGiocatore();
  cout<<endl;
  s1.printScacchieraAvversario();
  cout<<endl;
  s1.posizionaNave(1,1,1,1);
  s1.posizionaNave(2,1,2,1);
  cout<<endl;
  s1.printScacchieraGiocatore();
  cout<<endl;
  s1.printScacchieraAvversario();
}
