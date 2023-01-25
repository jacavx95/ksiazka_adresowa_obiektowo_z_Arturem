#ifndef KsiazkaAdresowa_H
#define KsiazkaAdresowa_H

#include <iostream>
#include "UzytkownikMenedzer.h"
#include "AdresatMenedzer.h"

using namespace std;

class KsiazkaAdresowa {
    UzytkownikMenedzer uzytkownikMenedzer;
    //AdresatMenedzer adresatMenedzer;
    char wybor;

private:
    void zmianaHaslaZalogowanegoUzytkownika();

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami) : uzytkownikMenedzer(nazwaPlikuZUzytkownikami) {
        uzytkownikMenedzer.wczytajUzytkownikowZPliku();
    }
    void rejestracjaUzytkownika();
    int logowanieUzytkownika(); //int poniewaz bede tu przekazywac idZalogowanegoUzytkownika
    void wypiszWszystkichUzytkownikow();
    char wybierzOpcjeZMenuGlownego();
    char wybierzOpcjeZMenuUzytkownika();
};

#endif
