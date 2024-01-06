#include "pojazdy.hpp"
#include <string>
#include <iostream>

using namespace std;

/*konstruktory*/
Pojazd::Pojazd(string mar, string mod, int ce, string nr) : marka(mar), model(mod), cena(ce), nr_rejestracyjny(nr) {};

Osobowy::Osobowy(string mar, string mod, int ce, string nr, bool klima) : Pojazd(mar, mod, ce, nr), klimatyzacja(klima) {};
Motor::Motor(string mar, string mod, int ce, string nr, int poj) : Pojazd(mar, mod, ce, nr), pojemnosc_silnika(poj) {};

/*implementacja metod*/
const string Pojazd::get_nr_rej() const {
    return nr_rejestracyjny;
}

const void Osobowy::print(ostream& os) const {
    os<<"OSOBOWY, Marka: "<<marka<<", Model: "<<model<<", Cena: "<<cena<<"zl, Nr. rejestracyjny: "<<nr_rejestracyjny;
    string czy = klimatyzacja ? "tak" : "nie";
    os<<", klimatyzacja: "<<czy<<endl;
}

const void Motor::print(ostream& os) const {
    os<<"MOTOR, Marka: "<<marka<<", Model: "<<model<<", Cena: "<<cena<<"zl, Nr. rejestracyjny: "<<nr_rejestracyjny;
    os<<", poj. silnika: "<<pojemnosc_silnika<<endl;
}

/*Generowany string zawiera wszelkie niezbędne informacje o pojeździe. Pierwsza litera identyfikuje czy to Motor czy Osobowy ('M' lub 'O'). Dane są oddzielone średnikami*/
string Osobowy::get_string() const {
    string content;
    string czy = klimatyzacja ? "tak" : "nie";
    content = "O"+marka+";"+model+";"+to_string(cena)+";"+nr_rejestracyjny+";"+czy;
    return content;
}

string Motor::get_string() const {
    string content;
    content = "M"+marka+";"+model+";"+to_string(cena)+";"+nr_rejestracyjny+";"+to_string(pojemnosc_silnika);
    return content;
}