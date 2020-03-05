#include "MenedzerOsob.h"
#include "MetodyPomocnicze.h"

using namespace std;

int main()
{
    MenedzerOsob menedzerOsob;
    MetodyPomocnicze metodyPomocnicze;

    char wybor;
    while (true)
    {
        wybor = metodyPomocnicze.wybierzOpcjeZMenuGlownego();

        menedzerOsob.wczytajOsobyZPliku();
        switch (wybor)
        {
        case '1':
            menedzerOsob.dodajOsobe();
            break;
        case '2':
            menedzerOsob.wyszukajPoImieniu();
            break;
        case '3':
            menedzerOsob.wyszukajPoNazwisku();
            break;
        case '4':
            menedzerOsob.wyswietlWszystkieOsoby();
            break;
        case '9':
            exit(0);
            break;
        default:
            cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
            system("pause");
            break;
        }
    }
    return 0;
}
