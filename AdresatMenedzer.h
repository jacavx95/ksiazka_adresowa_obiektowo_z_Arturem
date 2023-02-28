#ifndef AdresatMenedzer_H
#define AdresatMenedzer_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <algorithm>
#include "Adresat.h"
#include "PlikZAdresatami.h"
#include "MetodyPomocnicze.h"
#include "UzytkownikMenedzer.h"

using namespace std;

class AdresatMenedzer {
    vector <Adresat> adresaci;
    PlikZAdresatami plikZAdresatami;
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;

    Adresat podajDaneNowegoAdresata();
    void wyswietlDaneAdresata(Adresat adresat);

public:
    AdresatMenedzer(string nazwaPlikuZAdresatami, int idZalogowanegoUzytkownika) : plikZAdresatami(nazwaPlikuZAdresatami), ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika) {
        adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    };
    void dodajAdresata();
    string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    void wyswietlWszystkichAdresatow();
};

#endif
