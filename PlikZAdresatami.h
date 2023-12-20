#ifndef PlikZAdresatami_H
#define PlikZAdresatami_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include "MetodyPomocnicze.h"
#include "Adresat.h"
#include "PlikTekstowy.h"

using namespace std;

class PlikZAdresatami : public PlikTekstowy {
    //const string NAZWA_PLIKU_Z_ADRESATAMI; //stworzyc nowa klase PlikTekstowy i w niej stworzyc atrybut NAZWA_PLIKU

    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    bool czyPlikJestPusty();
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);

public:
    //PlikZAdresatami(string nazwaPlikuZAdresatami) : NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami) {};
    PlikZAdresatami(string nazwaPlikuZAdresatami) : PlikTekstowy(nazwaPlikuZAdresatami) {};
    void dopiszAdresataDoPliku(Adresat adresat);
    vector<Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami();
    void aktualizowaniePlikuZDanymiAdresatowPoEdycji(Adresat adresat);
    void aktualizowaniePlikuZDanymiAdresatowPoUsunieciu(int idAdresataDoUsuniecia);
};

#endif
