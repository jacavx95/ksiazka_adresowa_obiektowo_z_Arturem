#ifndef MetodyPomocnicze_H
#define MetodyPomocnicze_H

#include "Uzytkownik.h"
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class MetodyPomocnicze {
public:
    static string konwerjsaIntNaString(int liczba);
    static string wczytajLinie();
    static char wczytajZnak();
    static int wczytajLiczbe();
    static string pobierzLiczbe(string tekst, int pozycjaZnaku);
    static int konwersjaStringNaInt(string liczba);
    static string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    static string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
};

#endif
