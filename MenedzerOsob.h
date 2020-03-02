#ifndef MENEDZEROSOB_H
#define MENEDZEROSOB_H

#include <iostream>
#include <windows.h>
#include <fstream>
#include <sstream>
#include "Osoba.h"
#include "PlikiZOsobami.h"
#include <vector>

using namespace std;


class MenedzerOsob
{
Osoba osoba;
int iloscOsob = 0;
vector <Osoba> osoby;
PlikiZOsobami plikiZOsobami;;

public:
string wczytajLinie();
Osoba dodajOsobe();

void wyswietlWszystkieOsoby();
void wyswietlDaneAdresata(Osoba osoba);
void wczytajOsobyZPliku();

};

#endif
