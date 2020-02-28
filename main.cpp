#include <iostream>
#include "MenedzerOsob.h"
#include "Osoba.h"
vector <Osoba> osoby;
using namespace std;

int main()
{
MenedzerOsob menedzerOsob;

menedzerOsob.dodajOsobe();
menedzerOsob.dodajOsobe();
menedzerOsob.wyswietlWszystkieOsoby();

return 0;
}
