#include <iostream>
#include "MetodyPomocnicze.h"

using namespace std;

string MetodyPomocnicze::konwerjsaIntNaString(int liczba) {
    ostringstream ss;
    ss << liczba;
    string str = ss.str();
    return str;
}
