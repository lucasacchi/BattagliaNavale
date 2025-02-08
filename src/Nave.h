#include <string>
using std::string;

#ifndef NAVE_H
#define NAVE_H

class Nave
{
		public:
		Nave (int size, string nome);
		Nave (int size, string nome, int x, int y, bool aff, bool oriz);
		Nave(const Nave &nave1); //copy constructor
		Nave& operator=(const Nave &nave1); // overload operatore di assegnazione
		~Nave();
		int getSize() const;
		int getX() const;
		int getY() const;
		bool affondata() const; // la nave è affondata?
		bool orizzontale() const;  // la nave è orizzontale?
		string getName() const;
		void setPosition(int x, int y, bool oriz);
		void printNave();
		bool naveColpita(int xColpo, int yColpo);  // per segnare le caselle in cui la nave è stata colpita

  private: //tutti i data member si chiamano ***Nave, con Nave alla fine
    char* caselleNave;
    int sizeNave;
    int xNave, yNave; //coordinate estremo in alto a sinistra della nave
    string nomeNave;
    bool affondataNave; // 1 se è affondata, 0 se non è affondata
    bool orizzontaleNave;  // 1 se è orizzontale, 0 se è verticale
};

#endif
