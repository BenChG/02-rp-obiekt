#include "MenedzerOsob.h"

string MenedzerOsob::wczytajLinie()
{
    string wejscie = "";
    getline(cin, wejscie);
    return wejscie;
}

int MenedzerOsob::dodajOsobe()
{
    string imie, nazwisko, numerTelefonu, email, adres;
    cout << "Podaj imie: ";
    imie = wczytajLinie();
    cout << "Podaj nazwisko: ";
    nazwisko = wczytajLinie();
    cout << "Podaj numer telefonu: ";
    numerTelefonu = wczytajLinie();
    cout << "Podaj email: ";
    email = wczytajLinie();
    cout << "Podaj adres: ";
    adres = wczytajLinie();

    osoba.ustawId(iloscOsob+1);
    osoba.ustawImie(imie);
    osoba.ustawNazwisko(nazwisko);
    osoba.ustawNumerTelefonu(numerTelefonu);
    osoba.ustawEmail(email);
    osoba.ustawAdres(adres);

    fstream plik;
    plik.open("KsiazkaAdresowa.txt",ios::out | ios::app);

    if (plik.good() == true)
    {
        plik << osoba.pobierzId() << endl;
        plik << osoba.pobierzImie() << endl;
        plik << osoba.pobierzNazwisko() << endl;
        plik << osoba.pobierzNumerTelefonu() << endl;
        plik << osoba.pobierzEmail() << endl;
        plik << osoba.pobierzAdres() << endl;
        plik.close();
    }
    else
    {
        cout << "Nie udalo sie otworzyc pliku i zapisac do niego danych." << endl;
        system("pause");
    }
    cout << endl << "Osoba zostala dodana" << endl; system("pause");
    return iloscOsob + 1;
}
