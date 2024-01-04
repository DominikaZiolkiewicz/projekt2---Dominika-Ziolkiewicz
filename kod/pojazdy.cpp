#include "pojazdy.hpp"
#include <string>
#include <iostream>

using namespace std;

Pojazd::Pojazd(string mar, string mod, int ce, string nr) : marka(mar), model(mod), cena(ce), nr_rejestracyjny(nr) {};

Osobowy::Osobowy(string mar, string mod, int ce, string nr, bool klima) : Pojazd(mar, mod, ce, nr), klimatyzacja(klima) {};
Motor::Motor(string mar, string mod, int ce, string nr, int poj) : Pojazd(mar, mod, ce, nr), pojemnosc_silnika(poj) {};

const string Pojazd::get_nr_rej() const {
    return nr_rejestracyjny;
}

void Pojazd::print() const {
    cout<<"Marka: "<<marka<<" Model: "<<model<<" Cena: "<<cena<<" Nr. rejestracyjny: "<<nr_rejestracyjny;
}

void Osobowy::print() const {
    Pojazd::print();
    string czy = klimatyzacja ? "tak" : "nie";
    cout<<" klimatyzacja: "<<czy<<endl;
}

void Motor::print() const {
    Pojazd::print();
    cout<<" poj. silnika: "<<pojemnosc_silnika<<endl;
}