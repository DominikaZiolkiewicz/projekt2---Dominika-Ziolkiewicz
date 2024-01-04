#include "pojazdy.hpp"
#include <string>

using namespace std;

Pojazd::Pojazd(string mar, string mod, int ce, string nr) : marka(mar), model(mod), cena(ce), nr_rejestracyjny(nr) {};

Osobowy::Osobowy(string mar, string mod, int ce, string nr, bool klima) : Pojazd(mar, mod, ce, nr), klimatyzacja(klima) {};
Motor::Motor(string mar, string mod, int ce, string nr, int poj) : Pojazd(mar, mod, ce, nr), pojemnosc_silnika(poj) {};