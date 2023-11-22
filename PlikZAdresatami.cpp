#include "PlikZAdresatami.h"

void PlikZAdresatami::dopiszAdresataDoPliku(Adresat adresat) {
    string liniaZDanymiAdresata = "";
    fstream plikTekstowy;
    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::out | ios::app);

    if (plikTekstowy.good() == true)
    {
        liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);

        if (czyPlikJestPusty() == true)
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

bool PlikZAdresatami::czyPlikJestPusty() {
    fstream plikTekstowy;
    plikTekstowy.seekg(0, ios::end);
    if (plikTekstowy.tellg() == 0)
        return true;
    else
        return false;
}

vector<Adresat> PlikZAdresatami::wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika) {
    Adresat adresat;
    vector<Adresat> adresaci;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    fstream plikTekstowy;
    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);

    if (plikTekstowy.good() == true) {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami)) {
            if (idZalogowanegoUzytkownika == pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami)) {
                adresat = pobierzDaneAdresata(daneJednegoAdresataOddzielonePionowymiKreskami);
                adresaci.push_back(adresat);
            }
            if (daneJednegoAdresataOddzielonePionowymiKreskami != "") daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
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

int PlikZAdresatami::pobierzIdAdresataZDanychOddzielonychPionowymiKreskami() {
    int pozycjaRozpoczeciaIdAdresata = 0;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    fstream plikTekstowy;

    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);

    if (plikTekstowy.good() == true) {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami)) {
            if (daneJednegoAdresataOddzielonePionowymiKreskami != "") daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
        }
    }

    return MetodyPomocnicze::konwersjaStringNaInt(MetodyPomocnicze::pobierzLiczbe(daneOstaniegoAdresataWPliku, pozycjaRozpoczeciaIdAdresata));
}

void PlikZAdresatami::aktualizowaniePlikuZDanymiAdresatow(vector<Adresat> adresaci, int idAdresataDoEdycji) {
    fstream plikTekstowy, plikTymczasowy;
    string liniaZDanymiAdresataWPliku = "";
    string cyfra = "";
    int idAdresataWLiniiZDanymiAdresataWPliku = 0;
    int numerElementuWektora = 0;
    bool sprawdzenieCzyZnajdujeTakiElementWektora = false;


    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI, ios::in);
    if (!plikTekstowy.good()) {
        cout << "Plik nie istnieje" << endl;
        exit(0);
    }

    plikTymczasowy.open("Adresaci_plik_tymczasowy.txt", ios::out);
    if (!plikTymczasowy.good()) {
        cout << "Plik nie istnieje" << endl;
        exit(0);
    }
    for (int i = 0; i < (int) adresaci.size(); i++) {
        if (adresaci[i].pobierzId() == idAdresataDoEdycji) {
            sprawdzenieCzyZnajdujeTakiElementWektora = true; //po usunieciu wpisu z wektora dochodzi do przesuniecia numerow jego elementow
            numerElementuWektora = i;
            break;
        }
    }
    while (getline(plikTekstowy,liniaZDanymiAdresataWPliku)) {
        cyfra = liniaZDanymiAdresataWPliku[0];
        idAdresataWLiniiZDanymiAdresataWPliku = MetodyPomocnicze::konwersjaStringNaInt(cyfra);
        if (idAdresataWLiniiZDanymiAdresataWPliku != idAdresataDoEdycji) {
            plikTymczasowy << liniaZDanymiAdresataWPliku << endl;
        }
        else {
            if (sprawdzenieCzyZnajdujeTakiElementWektora == true) {
                plikTymczasowy << adresaci[numerElementuWektora].pobierzId() << '|';
                plikTymczasowy << adresaci[numerElementuWektora].pobierzIdUzytkownika() << '|';
                plikTymczasowy << adresaci[numerElementuWektora].pobierzImie() << '|';
                plikTymczasowy << adresaci[numerElementuWektora].pobierzNazwisko() << '|';
                plikTymczasowy << adresaci[numerElementuWektora].pobierzNumerTelefonu() << '|';
                plikTymczasowy << adresaci[numerElementuWektora].pobierzEmail() << '|';
                plikTymczasowy << adresaci[numerElementuWektora].pobierzAdres() << '|';
                plikTymczasowy << endl;
            }
            else continue;
        }
    }
    plikTekstowy.close();
    plikTymczasowy.close();
    remove("Adresaci.txt");
    rename("Adresaci_plik_tymczasowy.txt", "Adresaci.txt");
}
