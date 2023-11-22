#include "AdresatMenedzer.h"

void AdresatMenedzer::dodajAdresata() {
    Adresat adresat;
    //Uzytkownik uzytkownik;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;

    adresat = podajDaneNowegoAdresata();

    adresaci.push_back(adresat);
    plikZAdresatami.dopiszAdresataDoPliku(adresat);

    system("pause");
}

Adresat AdresatMenedzer::podajDaneNowegoAdresata() {
    Adresat adresat;
    int idOstatniegoAdresata = plikZAdresatami.pobierzIdAdresataZDanychOddzielonychPionowymiKreskami();

    adresat.ustawId(++idOstatniegoAdresata);
    adresat.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);

    cout << "Podaj imie: ";
    adresat.ustawImie(MetodyPomocnicze::wczytajLinie());
    adresat.ustawImie(zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.pobierzImie()));

    cout << "Podaj nazwisko: ";
    adresat.ustawNazwisko(MetodyPomocnicze::wczytajLinie());
    adresat.ustawNazwisko(zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.pobierzNazwisko()));

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
    cout << "Podaj imie osoby jaka mamy wyszukac: ";
    imie = MetodyPomocnicze::wczytajLinie();
    for (int i = 0; i < (int)adresaci.size(); i++) {
        if (adresaci[i].pobierzIdUzytkownika() == ID_ZALOGOWANEGO_UZYTKOWNIKA) {
            if (adresaci[i].pobierzImie() == imie) {
                sprawdzenie = true;
                cout << endl;
                cout << "ID: " << adresaci[i].pobierzId() << endl;
                cout << adresaci[i].pobierzImie() << " " << adresaci[i].pobierzNazwisko() << endl;
                cout << "Telefon: " << adresaci[i].pobierzNumerTelefonu() << endl;
                cout << "Email: " << adresaci[i].pobierzEmail() << endl;
                cout << "Adres: " << adresaci[i].pobierzAdres() << endl;
                cout << endl;
            }
        }
    }
    if (!sprawdzenie) cout << endl << "Brak takiego wpisu w ksiazce adresowej" << endl << endl;
    system("pause");
}

void AdresatMenedzer::wyszukajAdresatowPoNazwisku(){
    string nazwisko;
    bool sprawdzenie = false;
    cout << "Poda nazwisko osoby jaka mamy wyszukac: ";
    nazwisko = MetodyPomocnicze::wczytajLinie();
    for (int i = 0; i < (int)adresaci.size(); i++) {
        if (adresaci[i].pobierzIdUzytkownika() == ID_ZALOGOWANEGO_UZYTKOWNIKA) {
            if (adresaci[i].pobierzNazwisko() == nazwisko) {
                sprawdzenie = true;
                cout << endl;
                cout << "ID: " << adresaci[i].pobierzId() << endl;
                cout << adresaci[i].pobierzImie() << " " << adresaci[i].pobierzNazwisko() << endl;
                cout << "Telefon: " << adresaci[i].pobierzNumerTelefonu() << endl;
                cout << "Email: " << adresaci[i].pobierzEmail() << endl;
                cout << "Adres: " << adresaci[i].pobierzAdres() << endl;
                cout << endl;
            }
        }
    }
    if (!sprawdzenie) cout << endl << "Brak takiego wpisu w ksiazce adresowej" << endl << endl;
    system("pause");
}

void AdresatMenedzer::edytujAdresata(){ //rozbic na mniejsze funkcje - najlepiej zeby kazda funkcja wykonywala dobrze jedno polecenie
    char wybor;
    int idAdresataDoEdycji = 0;
    bool sprawdzenieCzyTakiAdresatIstnieje = false;
    bool zakonczenieEdytowaniaAdesata = false;

    cout << "Wpisz ID adresata do edycji" << endl;

    while (zakonczenieEdytowaniaAdesata == false) {
        cin >> idAdresataDoEdycji;
        cin.sync();
        for (int i=0; i < (int) adresaci.size(); i++) {
            if (ID_ZALOGOWANEGO_UZYTKOWNIKA == adresaci[i].pobierzIdUzytkownika()) {
                if (idAdresataDoEdycji == adresaci[i].pobierzId()) {
                    sprawdzenieCzyTakiAdresatIstnieje = true;
                    //rozbic to co ponizej
                    cout << "Znaleziono adresata o ID: " << adresaci[i].pobierzId() << endl << endl;
                    cout << adresaci[i].pobierzImie() << " " << adresaci[i].pobierzNazwisko() << endl;
                    cout << "Telefon: " << adresaci[i].pobierzNumerTelefonu() << endl;
                    cout << "Email: " << adresaci[i].pobierzEmail() << endl;
                    cout << "Adres: " << adresaci[i].pobierzAdres() << endl << endl;

                    //rozbic to co ponizej
                    cout << "Wybierz dana, ktora chcesz edytowac:" << endl << endl;
                    cout << "1. Imie" << endl;
                    cout << "2. Nazwisko" << endl;
                    cout << "3. Numer telefonu" << endl;
                    cout << "4. Email" << endl;
                    cout << "5. Adres" << endl;
                    cout << "6. Powrot do menu glownego" << endl << endl;

                    wybor = MetodyPomocnicze::wczytajZnak();

                    switch (wybor) { //dodac adresaci.push_back(adresat); do kazdej funkcji i ogarn¹æ procedure w plikuZAdresatami.cpp
                        case '1': {
                            cout << "Podaj nowe imie: ";
                            adresaci[i].ustawImie(MetodyPomocnicze::wczytajLinie());
                            plikZAdresatami.aktualizowaniePlikuZDanymiAdresatow(adresaci,idAdresataDoEdycji);
                            break;
                        }
                        case '2': {
                            cout << "Podaj nowe nazwisko: ";
                            adresaci[i].ustawNazwisko(MetodyPomocnicze::wczytajLinie());
                            plikZAdresatami.aktualizowaniePlikuZDanymiAdresatow(adresaci,idAdresataDoEdycji);
                            break;
                        }
                        case '3': {
                            cout << "Podaj nowy numer telefonu: ";
                            adresaci[i].ustawNumerTelefonu(MetodyPomocnicze::wczytajLinie());
                            plikZAdresatami.aktualizowaniePlikuZDanymiAdresatow(adresaci,idAdresataDoEdycji);
                            break;
                        }
                        case '4': {
                            cout << "Podaj nowy email: ";
                            adresaci[i].ustawEmail(MetodyPomocnicze::wczytajLinie());
                            plikZAdresatami.aktualizowaniePlikuZDanymiAdresatow(adresaci,idAdresataDoEdycji);
                            break;
                        }
                        case '5': {
                            cout << "Podaj nowy adres: ";
                            adresaci[i].ustawAdres(MetodyPomocnicze::wczytajLinie());
                            plikZAdresatami.aktualizowaniePlikuZDanymiAdresatow(adresaci,idAdresataDoEdycji);
                            break;
                        }
                        case '6': {
                            cout << "Nastapi powrot do menu glownego" << endl;
                            zakonczenieEdytowaniaAdesata = true;
                            break;
                        }
                    }
                    if (wybor != '6') cout << endl << "Dane zostaly zaktualizowane" << endl;
                    zakonczenieEdytowaniaAdesata = true;
                    system("pause");
                }
            }
        }
        if (sprawdzenieCzyTakiAdresatIstnieje == false) {
            cout << "Nie znaleziono adresata o podanym numerze ID." << endl;
            cout << "1. Podaj inny numer ID." << endl;
            cout << "2. Powroc do menu glownego." << endl;

            wybor = MetodyPomocnicze::wczytajZnak();

            switch (wybor) {
                case '1': {
                    cout << "Podaj inny numer ID: ";
                    break;
                }
                case '2': {
                    zakonczenieEdytowaniaAdesata = true;
                    break;
                }
            }
        }
    }
}

void AdresatMenedzer::usunAdresata() {
    char wybor;
    int idAdresataDoUsuniecia = 0;
    bool sprawdzenieCzyTakiAdresatIstnieje = false;
    bool zakonczenieUsuwaniaAdesata = false;

    cout << "Wpisz ID adresata do usuniecia" << endl;

    while (zakonczenieUsuwaniaAdesata == false) {
        cin >> idAdresataDoUsuniecia;
        cin.sync();
        for (int i=0; i < (int) adresaci.size(); i++) {
            if (adresaci[i].pobierzIdUzytkownika() == ID_ZALOGOWANEGO_UZYTKOWNIKA) {
                if (idAdresataDoUsuniecia == adresaci[i].pobierzId()) {
                    sprawdzenieCzyTakiAdresatIstnieje = true;
                    cout << "Znaleziono adresata o ID: " << adresaci[i].pobierzId() << endl << endl;
                    cout << adresaci[i].pobierzImie() << " " << adresaci[i].pobierzNazwisko() << endl;
                    cout << "Telefon: " << adresaci[i].pobierzNumerTelefonu() << endl;
                    cout << "Email: " << adresaci[i].pobierzEmail() << endl;
                    cout << "Adres: " << adresaci[i].pobierzAdres() << endl << endl;
                    cout << "Czy na pewno chcesz usunac tego adresata? Wpisz 't', aby potwierdzic lub 'n' aby odrzucic." << endl << endl;

                    wybor = MetodyPomocnicze::wczytajZnak();

                    switch (wybor) {
                        case 't': {
                            for (int i = 0; i < (int) adresaci.size(); i++) {
                                if (adresaci[i].pobierzId() == idAdresataDoUsuniecia) adresaci.erase(adresaci.begin() + i);
                            }
                            plikZAdresatami.aktualizowaniePlikuZDanymiAdresatow(adresaci,idAdresataDoUsuniecia);
                            break;
                        }
                        case 'n': {
                            zakonczenieUsuwaniaAdesata = true;
                            break;
                        }
                    }
                    if (wybor != 'n') cout << endl << "Dane zostaly zaktualizowane" << endl;
                    zakonczenieUsuwaniaAdesata = true;
                    system("pause");
                }
            }
        }

        if (sprawdzenieCzyTakiAdresatIstnieje == false) {
            cout << "Nie znaleziono adresata o podanym numerze ID." << endl;
            cout << "1. Podaj inny numer ID." << endl;
            cout << "2. Powroc do menu glownego." << endl;

            wybor = MetodyPomocnicze::wczytajZnak();

            switch (wybor) {
                case '1': {
                    cout << "Podaj inny numer ID: ";
                    break;
                }
                case '2': {
                    zakonczenieUsuwaniaAdesata = true;
                    break;
                }
            }
        }
    }
}

string AdresatMenedzer::zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst) {
    if (!tekst.empty()) {
        transform(tekst.begin(), tekst.end(), tekst.begin(), ::tolower);
        tekst[0] = toupper(tekst[0]);
    }
    return tekst;
}

void AdresatMenedzer::wyswietlWszystkichAdresatow() {
    system("cls");
    if (!adresaci.empty()) {
        cout << "             >>> ADRESACI <<<" << endl;
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
    cout << endl << "Id:                 " << adresat.pobierzId() << endl;
    cout << "Imie:               " << adresat.pobierzImie() << endl;
    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu() << endl;
    cout << "Email:              " << adresat.pobierzEmail() << endl;
    cout << "Adres:              " << adresat.pobierzAdres() << endl;
}

