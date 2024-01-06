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


const void Osobowy::print(ostream& os) const {
    os<<"OSOBOWY, Marka: "<<marka<<", Model: "<<model<<", Cena: "<<cena<<"zl, Nr. rejestracyjny: "<<nr_rejestracyjny;
    string czy = klimatyzacja ? "tak" : "nie";
    os<<", klimatyzacja: "<<czy<<endl;
}

// const void Osobowy::zapis(ofstream& os) const {
//     string content;
//     string czy = klimatyzacja ? "tak" : "nie";
//     content = marka+model+to_string(cena)+nr_rejestracyjny+czy;
//     int size = content.size();
//     os<<size<<content;
// }

const void Motor::print(ostream& os) const {
    os<<"MOTOR, Marka: "<<marka<<", Model: "<<model<<", Cena: "<<cena<<"zl, Nr. rejestracyjny: "<<nr_rejestracyjny;
    os<<", poj. silnika: "<<pojemnosc_silnika<<endl;
}

// const void Motor::zapis(ofstream& os) const {
//     os<<"M "<<marka<<" "<<model<<" "<<cena<<" "<<nr_rejestracyjny;
//     os<<" "<<pojemnosc_silnika<<endl;
// }

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