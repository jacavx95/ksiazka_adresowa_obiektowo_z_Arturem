#include "Uzytkownik.h"

//settery - metody do ustawiania wartosci atrybutow
void Uzytkownik::ustawId(int noweId) {
    if (noweId >= 0) id = noweId;
    //walidacja - mechanizm kontroli bledow
}
void Uzytkownik::ustawLogin(string nowyLogin) {
    login = nowyLogin;
}
void Uzytkownik::ustawHaslo(string noweHaslo) {
    haslo = noweHaslo;
}

//gettery - metody do pobierania wartosci atrybutow
int Uzytkownik::pobierzId() {
    return id;
}
string Uzytkownik::pobierzLogin() {
    return login;
}
string Uzytkownik::pobierzHaslo() {
    return haslo;
}
