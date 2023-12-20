#ifndef PLIKTEKSTOWY_H
#define PLIKTEKSTOWY_H

#include <iostream>
#include <fstream>

using namespace std;

class PlikTekstowy {
    //const string NAZWA_PLIKU;

public:
    const string NAZWA_PLIKU;

    PlikTekstowy(string nazwaPliku) : NAZWA_PLIKU(nazwaPliku) {
    }

    bool czyPlikJestPusty() {
        fstream plikTekstowy;
        plikTekstowy.seekg(0, ios::end);
        if (plikTekstowy.tellg() == 0)
            return true;
        else
            return false;
    }
};

#endif // PLIKTEKSTOWY_H
