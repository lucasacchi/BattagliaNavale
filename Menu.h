#include <string>
using std::string;

#ifndef MENU_H
#define MENU_H

void printTitolo();
void printMenu();
bool startMenu();
string getString(int maxLen);
int getInt(int min, int max);

#endif
