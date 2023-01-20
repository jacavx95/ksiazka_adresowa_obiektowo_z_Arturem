#include <iostream>
#include "KsiazkaAdresowa.h"

using namespace std;

int main() {
    int idZalogowanegoUzytkownika = 0;
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy2.txt"); //pierwszy obiekt
    //.wypiszWszystkichUzytkownikow();

    while (true) {
        if (idZalogowanegoUzytkownika == 0) {
            switch (ksiazkaAdresowa.wybierzOpcjeZMenuGlownego()) {
                case '1':
                    ksiazkaAdresowa.rejestracjaUzytkownika();
                    break;
                case '2':
                    idZalogowanegoUzytkownika = ksiazkaAdresowa.logowanieUzytkownika();
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
        else {
            /*if (adresaci.empty() == true)
                // Pobieramy idOstatniegoAdresata, po to aby zoptymalizowac program.
                // Dzieki temu, kiedy uztykwonik bedzie dodawal nowego adresata
                // to nie bedziemy musieli jeszcze raz ustalac idOstatniegoAdresata
                idOstatniegoAdresata = wczytajAdresatowZalogowanegoUzytkownikaZPliku(adresaci, idZalogowanegoUzytkownika);
            wybor = wybierzOpcjeZMenuUzytkownika();*/

            switch (ksiazkaAdresowa.wybierzOpcjeZMenuUzytkownika()) {
                case '1':
                    //idOstatniegoAdresata = dodajAdresata(adresaci, idZalogowanegoUzytkownika, idOstatniegoAdresata);
                    break;
                case '2':
                    //wyszukajAdresatowPoImieniu(adresaci);
                    break;
                case '3':
                    //wyszukajAdresatowPoNazwisku(adresaci);
                    break;
                case '4':
                    //wyswietlWszystkichAdresatow(adresaci);
                    break;
                case '5':
                    //idUsunietegoAdresata = usunAdresata(adresaci);
                    //idOstatniegoAdresata = podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(idUsunietegoAdresata, idOstatniegoAdresata);
                    break;
                case '6':
                    //edytujAdresata(adresaci);
                    break;
                case '7':
                    //zmianaHaslaZalogowanegoUzytkownika(uzytkownicy, idZalogowanegoUzytkownika);
                    break;
                case '8':
                    idZalogowanegoUzytkownika = 0;
                    //adresaci.clear();
                    break;
            }
        }
    }


    //if (ksiazkaAdresowa.logowanieUzytkownika() == 0) cout << "LOL" << endl;
    //ksiazkaAdresowa.rejestracjaUzytkownika(); //wywolanie metody
    //ksiazkaAdresowa.logowanieUzytkownika();

    return 0;
}
