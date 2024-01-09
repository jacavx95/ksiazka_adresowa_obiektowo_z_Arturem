#include "PlikZAdresatami.h"

void PlikZAdresatami::dopiszAdresataDoPliku(Adresat adresat) {
    string liniaZDanymiAdresata = "";
    fstream plikTekstowy;
    plikTekstowy.open(NAZWA_PLIKU.c_str(), ios::out | ios::app);

    if (plikTekstowy.good())
    {
        liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);

        if (czyPlikJestPusty())
        {
            plikTekstowy << liniaZDanymiAdresata;
        }
        else
        {
            plikTekstowy << liniaZDanymiAdresata << endl;
        }
    }
    else
    {
        cout << "Nie udalo sie otworzyc pliku i zapisac w nim danych." << endl;
    }
    plikTekstowy.close();
}

string PlikZAdresatami::zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat) {
    string liniaZDanymiAdresata = "";

    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzId()) + '|';
    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzIdUzytkownika()) + '|';
    liniaZDanymiAdresata += adresat.pobierzImie() + '|';
    liniaZDanymiAdresata += adresat.pobierzNazwisko() + '|';
    liniaZDanymiAdresata += adresat.pobierzNumerTelefonu() + '|';
    liniaZDanymiAdresata += adresat.pobierzEmail() + '|';
    liniaZDanymiAdresata += adresat.pobierzAdres() + '|';

    return liniaZDanymiAdresata;
}

vector<Adresat> PlikZAdresatami::wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika) {
    Adresat adresat;
    vector<Adresat> adresaci;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    fstream plikTekstowy;

    plikTekstowy.open(NAZWA_PLIKU.c_str(), ios::in);

    if (plikTekstowy.good()) {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami)) {
            if (idZalogowanegoUzytkownika == pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami)) {
                adresat = pobierzDaneAdresata(daneJednegoAdresataOddzielonePionowymiKreskami);
                adresaci.push_back(adresat);
            }
        }
        plikTekstowy.close();
        return adresaci;
    }
    else {
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;
        plikTekstowy.close();
        return adresaci;
    }
}

int PlikZAdresatami::pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami) {
    int pozycjaRozpoczeciaIdUzytkownika = daneJednegoAdresataOddzielonePionowymiKreskami.find_first_of('|') + 1;
    int idUzytkownika = MetodyPomocnicze::konwersjaStringNaInt(MetodyPomocnicze::pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdUzytkownika));

    return idUzytkownika;
}

Adresat PlikZAdresatami::pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami) {
    Adresat adresat;
    string pojedynczaDanaAdresata = "";
    int numerPojedynczejDanejAdresata = 1;

    for (unsigned int pozycjaZnaku = 0; pozycjaZnaku < daneAdresataOddzielonePionowymiKreskami.length(); pozycjaZnaku++) {
        if (daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku] != '|') {
            pojedynczaDanaAdresata += daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku];
        }
        else {
            switch(numerPojedynczejDanejAdresata)
            {
            case 1:
                adresat.ustawId(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 2:
                adresat.ustawIdUzytkownika(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 3:
                adresat.ustawImie(pojedynczaDanaAdresata);
                break;
            case 4:
                adresat.ustawNazwisko(pojedynczaDanaAdresata);
                break;
            case 5:
                adresat.ustawNumerTelefonu(pojedynczaDanaAdresata);
                break;
            case 6:
                adresat.ustawEmail(pojedynczaDanaAdresata);
                break;
            case 7:
                adresat.ustawAdres(pojedynczaDanaAdresata);
                break;
            }
            pojedynczaDanaAdresata = "";
            numerPojedynczejDanejAdresata++;
        }
    }
    return adresat;
}

int PlikZAdresatami::pobierzIdOstatniegoAdresataZPliku() {
    int pozycjaRozpoczeciaIdAdresata = 0;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    fstream plikTekstowy;

    plikTekstowy.open(NAZWA_PLIKU.c_str(), ios::in);

    if (plikTekstowy.good()) {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami)) {
            if (daneJednegoAdresataOddzielonePionowymiKreskami != "") daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
        }
    }
    idOstatniegoAdresata = MetodyPomocnicze::konwersjaStringNaInt(MetodyPomocnicze::pobierzLiczbe(daneOstaniegoAdresataWPliku, pozycjaRozpoczeciaIdAdresata));

    return idOstatniegoAdresata;
}

void PlikZAdresatami::aktualizowaniePlikuZDanymiAdresatowPoEdycji(Adresat adresat) {
    fstream plikTekstowy, plikTymczasowy;
    string liniaZDanymiAdresataWPliku = "";
    string cyfra = "";
    int idAdresataWLiniiZDanymiAdresataWPliku = 0;

    plikTekstowy.open(NAZWA_PLIKU, ios::in);
    if (!plikTekstowy.good()) {
        cout << "Plik nie istnieje" << endl;
        exit(0);
    }

    plikTymczasowy.open("Adresaci_plik_tymczasowy.txt", ios::out);
    if (!plikTymczasowy.good()) {
        cout << "Plik nie istnieje" << endl;
        exit(0);
    }

    while (getline(plikTekstowy,liniaZDanymiAdresataWPliku)) {
        cyfra = "";
        for (int i = 0; i < (int) liniaZDanymiAdresataWPliku.length(); i++) {
            if (isdigit(liniaZDanymiAdresataWPliku[i])) {
                cyfra += liniaZDanymiAdresataWPliku[i];
            }
            else break;
        }
        idAdresataWLiniiZDanymiAdresataWPliku = MetodyPomocnicze::konwersjaStringNaInt(cyfra);
        if (idAdresataWLiniiZDanymiAdresataWPliku != adresat.pobierzId()) {
            plikTymczasowy << liniaZDanymiAdresataWPliku << endl;
        }
        else {
                plikTymczasowy << adresat.pobierzId() << '|';
                plikTymczasowy << adresat.pobierzIdUzytkownika() << '|';
                plikTymczasowy << adresat.pobierzImie() << '|';
                plikTymczasowy << adresat.pobierzNazwisko() << '|';
                plikTymczasowy << adresat.pobierzNumerTelefonu() << '|';
                plikTymczasowy << adresat.pobierzEmail() << '|';
                plikTymczasowy << adresat.pobierzAdres() << '|';
                plikTymczasowy << endl;
        }
    }
    plikTekstowy.close();
    plikTymczasowy.close();
    remove("Adresaci.txt");
    rename("Adresaci_plik_tymczasowy.txt", "Adresaci.txt");
}

void PlikZAdresatami::aktualizowaniePlikuZDanymiAdresatowPoUsunieciu(int idAdresataDoUsuniecia) {
    fstream plikTekstowy, plikTymczasowy;
    string liniaZDanymiAdresataWPliku = "";
    string cyfra = "";
    int idAdresataWLiniiZDanymiAdresataWPliku = 0;

    plikTekstowy.open(NAZWA_PLIKU, ios::in);
    if (!plikTekstowy.good()) {
        cout << "Plik nie istnieje" << endl;
        exit(0);
    }

    plikTymczasowy.open("Adresaci_plik_tymczasowy.txt", ios::out);
    if (!plikTymczasowy.good()) {
        cout << "Plik nie istnieje" << endl;
        exit(0);
    }

    while (getline(plikTekstowy,liniaZDanymiAdresataWPliku)) {
        cyfra = "";
        for (int i = 0; i < (int) liniaZDanymiAdresataWPliku.length(); i++) {
            if (isdigit(liniaZDanymiAdresataWPliku[i])) {
                cyfra += liniaZDanymiAdresataWPliku[i];
            }
            else break;
        }
        idAdresataWLiniiZDanymiAdresataWPliku = MetodyPomocnicze::konwersjaStringNaInt(cyfra);
        if (idAdresataWLiniiZDanymiAdresataWPliku != idAdresataDoUsuniecia) {
            plikTymczasowy << liniaZDanymiAdresataWPliku << endl;
        }
        else {
                plikTymczasowy << "";
        }
    }
    plikTekstowy.close();
    plikTymczasowy.close();
    remove("Adresaci.txt");
    rename("Adresaci_plik_tymczasowy.txt", "Adresaci.txt");
}
