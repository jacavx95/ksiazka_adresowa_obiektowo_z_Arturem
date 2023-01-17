#include <iostream>

using namespace std;

class Uzytkownik {
    int id;
    string login;
    string haslo;

public:
    //settery - metody do ustawiania wartosci atrybutow
    void ustawId(int noweId);
    void ustawLogin(string nowyLogin);
    void ustawHaslo(string noweHaslo);

    //gettery - metody do pobierania wartosci atrybutow
    int pobierzId();
    string pobierzLogin();
    string pobierzHaslo();
};
