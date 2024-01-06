#ifndef BAZA_POJAZDOW
#define BAZA_POJAZDOW

#include <variant>
#include <map>
#include <fstream>
#include "pojazdy.hpp"

using v_pojazd = variant<Osobowy, Motor>;

class BazaPojazdow{
    private:
    map<string, v_pojazd> mapa;

    public:
    BazaPojazdow();
    void dodaj_pojazd(const v_pojazd& pojazd);
    void usun_pojazd(string nr_rej);
    void zapisz();
    void wczytaj();

    friend ostream& operator<<(ostream& os, BazaPojazdow& bp);
    //friend ofstream& operator<<(ofstream& os, BazaPojazdow& bp);

};

#endif