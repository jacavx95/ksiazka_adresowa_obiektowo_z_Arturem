#ifndef PlikZUzytkownikami_H
#define PlikZUzytkownikami_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "Uzytkownik.h"
#include "MetodyPomocnicze.h"
#include "PlikTekstowy.h"

using namespace std;

class PlikZUzytkownikami : public PlikTekstowy {
    //const string NAZWA_PLIKU_Z_UZYTKOWNIKAMI;
    //nie da siê ustaliæ zmiennej jako const, gdy nadajemy wartosc tego atrybutu poprzez konstruktor - trzeba skorzystac z LISTY INICJALIZACYJNEJ

    bool czyPlikJestPusty();
    Uzytkownik pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);

public:
    //PlikZUzytkownikami(string nazwaPlikuZUzytkownikami) : NAZWA_PLIKU_Z_UZYTKOWNIKAMI(nazwaPlikuZUzytkownikami) {}; //zastosowanie listy inicjalizacyjnej // konstruktor juz niepotrzebny w pliku .cpp // {} cialo konstruktora
    PlikZUzytkownikami(string nazwaPlikuZUzytkownikami) : PlikTekstowy(nazwaPlikuZUzytkownikami) {};
    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
    vector<Uzytkownik> wczytajUzytkownikowZPliku();
    void zapiszWszystkichUzytkownikowDoPliku(vector <Uzytkownik> &uzytkownicy);
};

#endif
