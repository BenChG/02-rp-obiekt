#ifndef PLIKIZOSOBAMI_H
#define PLIKIZOSOBAMI_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include "Osoba.h"

using namespace std;

class PlikiZOsobami
{
vector <Osoba> osoby;
Osoba osoba;


public:
vector <Osoba> wczytajOsobyZPliku();
};

#endif
