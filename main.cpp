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
        //else {
            /*if (adresaci.empty() == true)
                // Pobieramy idOstatniegoAdresata, po to aby zoptymalizowac program.
                // Dzieki temu, kiedy uztykwonik bedzie dodawal nowego adresata
                // to nie bedziemy musieli jeszcze raz ustalac idOstatniegoAdresata
                idOstatniegoAdresata = wczytajAdresatowZalogowanegoUzytkownikaZPliku(adresaci, idZalogowanegoUzytkownika);
            wybor = wybierzOpcjeZMenuUzytkownika();*/

        //}
    }


    //if (ksiazkaAdresowa.logowanieUzytkownika() == 0) cout << "LOL" << endl;
    //ksiazkaAdresowa.rejestracjaUzytkownika(); //wywolanie metody
    //ksiazkaAdresowa.logowanieUzytkownika();

    return 0;
}
