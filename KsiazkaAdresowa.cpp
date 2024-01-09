#include "KsiazkaAdresowa.h"

int KsiazkaAdresowa::sprawdzenieIdUzytkownika () {
    return uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::rejestracjaUzytkownika() {
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow() {
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa::logowanieUzytkownika() {
    uzytkownikMenedzer.logowanieUzytkownika();
    if (uzytkownikMenedzer.czyUzytkownikJestZalogowany()) {
        adresatMenedzer = new AdresatMenedzer(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
    }
}

void KsiazkaAdresowa::dodajAdresata() {
    if (uzytkownikMenedzer.czyUzytkownikJestZalogowany())
        adresatMenedzer->dodajAdresata();
    else {
        cout << "Aby dodac adresata, nalezy sie najpierw zalogowac" << endl;
        system("pause");
    }
}

void KsiazkaAdresowa::wyszukajAdresatowPoImieniu(){
    if (uzytkownikMenedzer.czyUzytkownikJestZalogowany())
        adresatMenedzer->wyszukajAdresatowPoImieniu();
    else {
        cout << "Aby wyszukac adresata, nalezy sie najpierw zalogowac" << endl;
        system("pause");
    }
}

void KsiazkaAdresowa::wyszukajAdresatowPoNazwisku(){
    if (uzytkownikMenedzer.czyUzytkownikJestZalogowany())
    adresatMenedzer->wyszukajAdresatowPoNazwisku();
    else {
        cout << "Aby wyszukac adresata, nalezy sie najpierw zalogowac" << endl;
        system("pause");
    }
}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow() {
    if (uzytkownikMenedzer.czyUzytkownikJestZalogowany())
        adresatMenedzer->wyswietlWszystkichAdresatow();
    else {
        cout << "Aby zobaczyc adresatow danego uzytkownika, nalezy sie najpierw zalogowac" << endl;
        system("pause");
    }
}

void KsiazkaAdresowa::edytujAdresata() {
    if (uzytkownikMenedzer.czyUzytkownikJestZalogowany())
    adresatMenedzer->edytujAdresata();
    else {
        cout << "Aby edytowac adresata, nalezy sie najpierw zalogowac" << endl;
        system("pause");
    }
}

void KsiazkaAdresowa::usunAdresata() {
    if (uzytkownikMenedzer.czyUzytkownikJestZalogowany())
    adresatMenedzer->usunAdresata();
    else {
        cout << "Aby usunac adresata, nalezy sie najpierw zalogowac" << endl;
        system("pause");
    }
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika() {
    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::wylogowanie() {
    uzytkownikMenedzer.wylogowanie();
    delete adresatMenedzer;
    adresatMenedzer = NULL;
}

char KsiazkaAdresowa::wybierzOpcjeZMenuGlownego() {
    char wybor;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
}

char KsiazkaAdresowa::wybierzOpcjeZMenuUzytkownika() {
    char wybor;

    system("cls");

    cout << "ID uzytkownika: " << uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika() << endl;

    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj adresata" << endl;
    cout << "2. Wyszukaj po imieniu" << endl;
    cout << "3. Wyszukaj po nazwisku" << endl;
    cout << "4. Wyswietl adresatow" << endl;
    cout << "5. Edytuj adresata" << endl;
    cout << "6. Usun adresata" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Zmien haslo" << endl;
    cout << "8. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
}


