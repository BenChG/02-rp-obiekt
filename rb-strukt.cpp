#include <iostream>
#include <windows.h>
#include <fstream>
#include <sstream>

using namespace std;

struct Osoba
{
   int id;
   string imie, nazwisko, numerTelefonu, email, adres;
};

string wczytajLinie()
{
    string wejscie = "";
    getline(cin, wejscie);
    return wejscie;
}

char wczytajZnak()
{
    string wejscie = "";
    char znak  = {0};

    while (true)
    {
        getline(cin, wejscie);

        if (wejscie.length() == 1)
        {
            znak = wejscie[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return znak;
}

/*
int wczytajLiczbeCalkowita()
{
    string wejscie = "";
    int liczba = 0;

    while (true)
    {
        getline(cin, wejscie);

        stringstream myStream(wejscie);
        if (myStream >> liczba)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return liczba;
}
*/

int dodajOsobe(Osoba osoby[], int iloscOsob)
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

    osoby[iloscOsob].id = iloscOsob + 1;
    osoby[iloscOsob].imie = imie;
    osoby[iloscOsob].nazwisko = nazwisko;
    osoby[iloscOsob].numerTelefonu = numerTelefonu;
    osoby[iloscOsob].email = email;
    osoby[iloscOsob].adres = adres;

    fstream plik;
    plik.open("KsiazkaAdresowa.txt",ios::out | ios::app);

    if (plik.good() == true)
    {
        plik << osoby[iloscOsob].id << endl;
        plik << osoby[iloscOsob].imie << endl;
        plik << osoby[iloscOsob].nazwisko << endl;
        plik << osoby[iloscOsob].numerTelefonu << endl;
        plik << osoby[iloscOsob].email << endl;
        plik << osoby[iloscOsob].adres << endl;
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

int wczytajOsobyZPliku(Osoba osoby[])
{
    string linia; // tworze zmienna do ktorej bede zapisywal odczytane linie z pliku tekstowego
    int nr_linii = 1;
    int iloscOsob = 0;

    fstream plik;
    plik.open("KsiazkaAdresowa.txt",ios::in);  // aby otworzyc plik do odczytu
    if (plik.good() == true)
    {
        // odczytuje linie po kolei. Linie w pliku tekstowym w przeciwienstwie do tablic sa numerowane od 1
        // funkcja getline odczytuje ze zmiennej plikowej plik i zapisuje linie jako stringa do zmiennej linia.
        // funkcja zwraca true dopoki sa linie do odczytania. Zwroci false, gdy plik sie skonczy
        while (getline(plik,linia))
        {
            switch (nr_linii)
            {
            case 1:
                osoby[iloscOsob].id = atoi(linia.c_str());
                break;
            case 2:
                osoby[iloscOsob].imie = linia;
                break;
            case 3:
                osoby[iloscOsob].nazwisko = linia;
                break;
            case 4:
                osoby[iloscOsob].numerTelefonu = linia;
                break;
            case 5:
                osoby[iloscOsob].email = linia;
                break;
            case 6:
                osoby[iloscOsob].adres = linia;
                break;
            }
            if (nr_linii >= 6)
            {
                nr_linii = 1;
                iloscOsob++;
            }
            else
            {
                nr_linii++;
            }
        }
        plik.close();
    }
    return iloscOsob;
}

void wyswietlWszystkieOsoby(Osoba osoby[], int iloscOsob)
{
    for (int i = 0; i < iloscOsob; i++)
    {
        cout << endl;
        cout << "ID: " << osoby[i].id << endl;
        cout << osoby[i].imie << " " << osoby[i].nazwisko << endl;
        cout << "Telefon: " << osoby[i].numerTelefonu << endl;
        cout << "Email: " << osoby[i].email << endl;
        cout << "Adres: " << osoby[i].adres << endl;
        cout << endl;
    }
    system("pause");
}

void wyszukajPoImieniu(Osoba osoby[], int iloscOsob)
{
    string imie;
    cout << "Podaj imie osoby jaka mamy wyszukac: ";
    imie = wczytajLinie();
    for (int i = 0; i < iloscOsob; i++)
    {
        if (osoby[i].imie == imie)
        {
            cout << endl;
            cout << "ID: " << osoby[i].id << endl;
            cout << osoby[i].imie << " " << osoby[i].nazwisko << endl;
            cout << "Telefon: " << osoby[i].numerTelefonu << endl;
            cout << "Email: " << osoby[i].email << endl;
            cout << "Adres: " << osoby[i].adres << endl;
            cout << endl;
        }
    }
    system("pause");
}

void wyszukajPoNazwisku(Osoba osoby[], int iloscOsob)
{
    string nazwisko;
    cout << "Poda nazwisko osoby jaka mamy wyszukac: ";
    nazwisko = wczytajLinie();
    for (int i = 0; i < iloscOsob; i++)
    {
        if (osoby[i].nazwisko == nazwisko)
        {
            cout << endl;
            cout << "ID: " << osoby[i].id << endl;
            cout << osoby[i].imie << " " << osoby[i].nazwisko << endl;
            cout << "Telefon: " << osoby[i].numerTelefonu << endl;
            cout << "Email: " << osoby[i].email << endl;
            cout << "Adres: " << osoby[i].adres << endl;
            cout << endl;
        }
    }
    system("pause");
}


int main()
{
    Osoba osoby[1000];
    int iloscOsob = 0;
    char wybor;

    iloscOsob = wczytajOsobyZPliku(osoby);

    while (true)
    {
        system("cls");
        cout << "1. Dodaj osobe" << endl;
        cout << "2. Wyszukaj po imieniu" << endl;
        cout << "3. Wyszukaj po nazwisku" << endl;
        cout << "4. Wyswietl wszystkie osoby" << endl;
        cout << "9. Zakoncz program" << endl;
        wybor = wczytajZnak();

        if (wybor == '1')
        {
            iloscOsob = dodajOsobe(osoby, iloscOsob);
        }
        else if (wybor == '2')
        {

            wyszukajPoImieniu(osoby, iloscOsob);
        }
        else if (wybor == '3')
        {

            wyszukajPoNazwisku(osoby, iloscOsob);
        }
        else if (wybor == '4')
        {
            wyswietlWszystkieOsoby(osoby, iloscOsob);
        }
        else if (wybor == '9')
        {
            exit(0);
        }
    }
    return 0;
}
