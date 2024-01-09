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

    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);

public:
    int idOstatniegoAdresata;
    PlikZAdresatami(string nazwaPlikuZAdresatami) : PlikTekstowy(nazwaPlikuZAdresatami) {};
    void dopiszAdresataDoPliku(Adresat adresat);
    vector<Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    int pobierzIdOstatniegoAdresataZPliku();
    void aktualizowaniePlikuZDanymiAdresatowPoEdycji(Adresat adresat);
    void aktualizowaniePlikuZDanymiAdresatowPoUsunieciu(int idAdresataDoUsuniecia);
};

#endif
