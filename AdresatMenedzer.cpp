#include "AdresatMenedzer.h"

void AdresatMenedzer::wyswietlWszystkichAdresatow() {
    system("cls");
    if (!adresaci.empty()) {
        cout << "             >>> ADRESACI <<< " << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Adresat> :: iterator itr = adresaci.begin(); itr != adresaci.end(); itr++) {
            wyswietlDaneAdresata(*itr);
        }
        cout << endl;
    }
    else {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}

void AdresatMenedzer::wyswietlDaneAdresata(Adresat adresat) {
    cout << endl << "ID:                 " << adresat.pobierzId() << endl;
    cout << "Imie:               " << adresat.pobierzImie() << endl;
    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu() << endl;
    cout << "Email:              " << adresat.pobierzEmail() << endl;
    cout << "Adres:              " << adresat.pobierzAdres() << endl;
}

void AdresatMenedzer::dodajAdresata() {
    Adresat adresat;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;

    adresat = podajDaneNowegoAdresata();

    adresaci.push_back(adresat);
    plikZAdresatami.dopiszAdresataDoPliku(adresat);

    system("pause");
}

Adresat AdresatMenedzer::podajDaneNowegoAdresata() {
    Adresat adresat;
    int idOstatniegoAdresata;

    idOstatniegoAdresata = plikZAdresatami.pobierzIdOstatniegoAdresataZPliku();

    adresat.ustawId(++idOstatniegoAdresata);
    adresat.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);

    cout << "Podaj imie: ";
    adresat.ustawImie(MetodyPomocnicze::wczytajLinie());
    adresat.ustawImie(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.pobierzImie()));

    cout << "Podaj nazwisko: ";
    adresat.ustawNazwisko(MetodyPomocnicze::wczytajLinie());
    adresat.ustawNazwisko(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.pobierzNazwisko()));

    cout << "Podaj numer telefonu: ";
    adresat.ustawNumerTelefonu(MetodyPomocnicze::wczytajLinie());

    cout << "Podaj email: ";
    adresat.ustawEmail(MetodyPomocnicze::wczytajLinie());

    cout << "Podaj adres: ";
    adresat.ustawAdres(MetodyPomocnicze::wczytajLinie());

    return adresat;
}

void AdresatMenedzer::wyszukajAdresatowPoImieniu(){
    string imie;
    bool sprawdzenie = false;
    cout << "Podaj imie osoby jaka nalezy wyszukac: ";
    imie = MetodyPomocnicze::wczytajLinie();
    for (int i = 0; i < (int)adresaci.size(); i++) {
        if (adresaci[i].pobierzImie() == imie) {
            sprawdzenie = true;
            wyswietlDaneAdresata(adresaci[i]);
        }
    }
    if (!sprawdzenie) cout << endl << "Brak takiego wpisu w ksiazce adresowej" << endl << endl;
    system("pause");
}

void AdresatMenedzer::wyszukajAdresatowPoNazwisku(){
    string nazwisko;
    bool sprawdzenie = false;
    cout << "Poda nazwisko osoby jaka nalezy wyszukac: ";
    nazwisko = MetodyPomocnicze::wczytajLinie();
    for (int i = 0; i < (int)adresaci.size(); i++) {
        if (adresaci[i].pobierzNazwisko() == nazwisko) {
            sprawdzenie = true;
            wyswietlDaneAdresata(adresaci[i]);
        }
    }
    if (!sprawdzenie) cout << endl << "Brak takiego wpisu w ksiazce adresowej" << endl << endl;
    system("pause");
}

void AdresatMenedzer::edytujAdresata() {
    int idAdresataDoEdycji = 0;
    bool sprawdzenieCzyTakiAdresatIstnieje = false;
    bool zakonczenieEdytowaniaAdesata = false;

    while (zakonczenieEdytowaniaAdesata == false) {
        cout << "Wpisz ID adresata do edycji" << endl;
        idAdresataDoEdycji = MetodyPomocnicze::wczytajLiczbe();
        for (int i=0; i < (int) adresaci.size(); i++) {
                if (idAdresataDoEdycji == adresaci[i].pobierzId()) {
                    sprawdzenieCzyTakiAdresatIstnieje = true;
                    cout << endl << "Znaleziono adresata: " << endl;
                    wyswietlDaneAdresata(adresaci[i]);
                    adresaci[i] = wybierzDaneAdresataDoEdycji(adresaci[i]);
                    plikZAdresatami.aktualizowaniePlikuZDanymiAdresatowPoEdycji(adresaci[i]);
                    zakonczenieEdytowaniaAdesata = true;
                }
        }
        if (sprawdzenieCzyTakiAdresatIstnieje == false) {
            if (menuPrzyBrakuAdresata() == '2') zakonczenieEdytowaniaAdesata = true;
        }
    }
}

Adresat AdresatMenedzer::wybierzDaneAdresataDoEdycji(Adresat adresat) {
    char wybor;

    cout << endl << "Wybierz dana, ktora chcesz edytowac:" << endl << endl;
    cout << "1. Imie" << endl;
    cout << "2. Nazwisko" << endl;
    cout << "3. Numer telefonu" << endl;
    cout << "4. Email" << endl;
    cout << "5. Adres" << endl;
    cout << "6. Powrot do menu glownego" << endl << endl;

    wybor = MetodyPomocnicze::wczytajZnak();

    switch (wybor) {
        case '1': {
            cout << "Podaj nowe imie: ";
            adresat.ustawImie(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(MetodyPomocnicze::wczytajLinie()));
            cout << "nowe imie to: " << adresat.pobierzImie() << endl;
            cout << "nazwisko to: " << adresat.pobierzNazwisko() << endl;
            break;
        }
        case '2': {
            cout << "Podaj nowe nazwisko: ";
            adresat.ustawNazwisko(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(MetodyPomocnicze::wczytajLinie()));
            break;
        }
        case '3': {
            cout << "Podaj nowy numer telefonu: ";
            adresat.ustawNumerTelefonu(MetodyPomocnicze::wczytajLinie());
            break;
        }
        case '4': {
            cout << "Podaj nowy email: ";
            adresat.ustawEmail(MetodyPomocnicze::wczytajLinie());
            break;
        }
        case '5': {
            cout << "Podaj nowy adres: ";
            adresat.ustawAdres(MetodyPomocnicze::wczytajLinie());
            break;
        }
        case '6': {
            cout << "Nastapi powrot do menu glownego" << endl;
            break;
        }
    }
    if (wybor != '6') cout << endl << "Dane zostana zaktualizowane" << endl;
    system("pause");
    return adresat;
}

void AdresatMenedzer::usunAdresata() {
    char wybor;
    int idAdresataDoUsuniecia = 0;
    bool sprawdzenieCzyTakiAdresatIstnieje = false;
    bool zakonczenieUsuwaniaAdesata = false;

    while (zakonczenieUsuwaniaAdesata == false) {
        cout << "Wpisz ID adresata do usuniecia" << endl;
        idAdresataDoUsuniecia = MetodyPomocnicze::wczytajLiczbe();
        for (int i=0; i < (int) adresaci.size(); i++) {
                if (idAdresataDoUsuniecia == adresaci[i].pobierzId()) {
                    sprawdzenieCzyTakiAdresatIstnieje = true;
                    cout << "Znaleziono adresata: " << adresaci[i].pobierzId() << endl << endl;
                    wyswietlDaneAdresata(adresaci[i]);

                    cout << endl << "Czy na pewno chcesz usunac tego adresata? Wpisz 't', aby potwierdzic lub 'n' aby odrzucic." << endl << endl;

                    wybor = MetodyPomocnicze::wczytajZnak();

                    switch (wybor) {
                        case 't': {
                            adresaci.erase(adresaci.begin() + i);
                            break;
                        }
                        case 'n': {
                            break;
                        }
                    }
                    if (wybor != 'n') {
                        cout << endl << "Dane zostaly zaktualizowane" << endl;
                        plikZAdresatami.aktualizowaniePlikuZDanymiAdresatowPoUsunieciu(idAdresataDoUsuniecia);
                        system("pause");
                    }
                    zakonczenieUsuwaniaAdesata = true;
                }
        }
        if (sprawdzenieCzyTakiAdresatIstnieje == false) {
            if (menuPrzyBrakuAdresata() == '2') zakonczenieUsuwaniaAdesata = true;
        }
    }
}

char AdresatMenedzer::usunWpisKsiazkiAdresowej(int numerElementuWektora) {

    cout << endl << "Czy na pewno chcesz usunac tego adresata? Wpisz 't', aby potwierdzic lub 'n' aby odrzucic." << endl << endl;

    char wybor = MetodyPomocnicze::wczytajZnak();

    switch (wybor) {
        case 't': {
            adresaci.erase(adresaci.begin() + numerElementuWektora);
            break;
        }
        case 'n': {
            break;
        }
    }
    if (wybor != 'n') cout << endl << "Dane zostaly zaktualizowane" << endl;
    system("pause");
    return wybor;
}

char AdresatMenedzer::menuPrzyBrakuAdresata() {

    cout << "Nie znaleziono adresata o podanym numerze ID." << endl;
    cout << "1. Podaj inny numer ID." << endl;
    cout << "2. Powroc do menu glownego." << endl;

    char wybor = MetodyPomocnicze::wczytajZnak();

    switch (wybor) {
        case '1': {
            break;
        }
        case '2': {
            break;
        }
    }
    return wybor;
}

