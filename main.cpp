#include "MenedzerOsob.h"
using namespace std;

int main()
{
MenedzerOsob menedzerOsob;

menedzerOsob.wczytajOsobyZPliku();
//menedzerOsob.wyswietlWszystkieOsoby();
//menedzerOsob.dodajOsobe();
//menedzerOsob.wyswietlWszystkieOsoby();
menedzerOsob.wyszukajPoImieniu();
menedzerOsob.wyszukajPoNazwisku();

return 0;
}
