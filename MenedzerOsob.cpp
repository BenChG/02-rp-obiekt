#include "MenedzerOsob.h"

string MenedzerOsob::wczytajLinie()
{
    string wejscie = "";
    getline(cin, wejscie);
    return wejscie;
}

Osoba MenedzerOsob::dodajOsobe()
{
    Osoba osoba;
    string imie, nazwisko, numerTelefonu, email, adres;
    int id;
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
    id = osoby.size()+1;

    osoba.ustawId(id);
    osoba.ustawImie(imie);
    osoba.ustawNazwisko(nazwisko);
    osoba.ustawNumerTelefonu(numerTelefonu);
    osoba.ustawEmail(email);
    osoba.ustawAdres(adres);

    osoby.push_back(osoba);

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
    cout << endl << "Osoba zostala dodana" << endl;
    system("pause");

    cout << "Wielkosc wektora osoby: " << osoby.size() << endl;
    system("pause");

    return osoba;
}

void MenedzerOsob::wyswietlDaneAdresata(Osoba osoba)
{
    cout << "Id:         " << osoba.pobierzId() << endl;
    cout << "Imie:               " << osoba.pobierzImie() << endl;
    cout << "Nazwisko:           " << osoba.pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << osoba.pobierzNumerTelefonu() << endl;
    cout << "Email:              " << osoba.pobierzEmail() << endl;
    cout << "Adres:              " << osoba.pobierzAdres() << endl;
}


void MenedzerOsob::wyswietlWszystkieOsoby()
{
    system("cls");

    if (!osoby.empty())
    {
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Osoba> :: iterator itr = osoby.begin(); itr != osoby.end(); itr++)
        {
            wyswietlDaneAdresata(*itr);
        }
        cout << endl;
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}

void MenedzerOsob::wczytajOsobyZPliku()
{
    PlikiZOsobami plikiZOsobami;
    osoby=plikiZOsobami.wczytajOsobyZPliku();
}

void MenedzerOsob::wyszukajPoImieniu()
{
    Osoba osoba;

    string podaneImie = podajImie();

    for (vector <Osoba> :: iterator itr = osoby.begin(); itr != osoby.end(); itr++)
    {
        wyswietlaniePoImieniu(*itr, podaneImie);
    }
    system("pause");
}

string MenedzerOsob::podajImie()
{
    string imie;
    cout << "Podaj imie osoby jaka mamy wyszukac: ";
    imie = wczytajLinie();
    return imie;
}

void MenedzerOsob::wyswietlaniePoImieniu (Osoba osoba, string podaneImie)
{
    if (osoba.pobierzImie() == podaneImie)
    {
        cout << endl;
        cout << "ID: " << osoba.pobierzId()<< endl;
        cout << osoba.pobierzImie() << " " << osoba.pobierzNazwisko() << endl;
        cout << "Telefon: " <<osoba.pobierzNumerTelefonu() << endl;
        cout << "Email: " << osoba.pobierzEmail() << endl;
        cout << "Adres: " << osoba.pobierzAdres() << endl;
        cout << endl;
    }
}

void MenedzerOsob::wyszukajPoNazwisku()
{
    Osoba osoba;

    string podaneNazwisko = podajNazwisko();

    for (vector <Osoba> :: iterator itr = osoby.begin(); itr != osoby.end(); itr++)
    {
        wyswietlaniePoNazwisku(*itr, podaneNazwisko);
    }
    system("pause");
}

string MenedzerOsob::podajNazwisko()
{
    string nazwisko;
    cout << "Podaj nazwisko osoby jaka mamy wyszukac: ";
    nazwisko = wczytajLinie();
    return nazwisko;
}

void MenedzerOsob::wyswietlaniePoNazwisku(Osoba osoba, string podaneNazwisko)
{
    if (osoba.pobierzNazwisko() == podaneNazwisko)
    {
        cout << endl;
        cout << "ID: " << osoba.pobierzId()<< endl;
        cout << osoba.pobierzImie() << " " << osoba.pobierzNazwisko() << endl;
        cout << "Telefon: " <<osoba.pobierzNumerTelefonu() << endl;
        cout << "Email: " << osoba.pobierzEmail() << endl;
        cout << "Adres: " << osoba.pobierzAdres() << endl;
        cout << endl;
    }
}
