#ifndef OSOBA_H
#define OSOBA_H

#include <iostream>
#include <windows.h>
#include <fstream>
#include <sstream>
#include "Osoba.h"

using namespace std;

class Osoba
{
   int id;
   string imie;
   string nazwisko;
   string numerTelefonu;
   string email;
   string adres;

    public:
    void ustawId(int noweId);
    void ustawImie (string noweNazwisko);
    void ustawNazwisko (string noweNazwisko);
    void ustawNumerTelefonu (string nowyNumerTelefonu);
    void ustawEmail(string nowyEmail);
    void ustawAdres (string nowyAdres);

    int pobierzId();
    string pobierzImie();
    string pobierzNazwisko();
    string pobierzNumerTelefonu();
    string pobierzEmail();
    string pobierzAdres();
};
#endif
