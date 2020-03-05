#ifndef MENEDZEROSOB_H
#define MENEDZEROSOB_H

#include "Osoba.h"
#include "PlikiZOsobami.h"

using namespace std;

class MenedzerOsob
{
    Osoba osoba;
    PlikiZOsobami plikiZOsobami;

    vector <Osoba> osoby;
    int iloscOsob = 0;
    string podaneImie;
    string podaneNazwisko;

    string wczytajLinie();
    void wyswietlDaneAdresata(Osoba osoba);
    string podajImie();
    void wyswietlaniePoImieniu(Osoba osoba, string podaneImie);
    string podajNazwisko();
    void wyswietlaniePoNazwisku(Osoba osoba, string podaneNazwisko);

public:
    void wczytajOsobyZPliku();
    Osoba dodajOsobe();
    void wyszukajPoImieniu();
    void wyszukajPoNazwisku();
    void wyswietlWszystkieOsoby();
};

#endif
