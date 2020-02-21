#ifndef MENEDZEROSOB_H
#define MENEDZEROSOB_H

#include <iostream>
#include <windows.h>
#include <fstream>
#include <sstream>
#include "Osoba.h"

using namespace std;


class MenedzerOsob
{
Osoba osoba;
int iloscOsob = 0;

public:
string wczytajLinie();
int dodajOsobe();
};

#endif
