#ifndef BAZA_POJAZDOW
#define BAZA_POJAZDOW

#include <variant>
#include <map>
#include <fstream>
#include "pojazdy.hpp"

using v_pojazd = variant<Osobowy, Motor>;

class BazaPojazdow{
    private:
    map<string, v_pojazd> mapa; //mapa służąca do przechowywania bazy pojazdów. Kluczem jest ich numer rejestracyjny a wartością obiekt.

    public:
    BazaPojazdow();
    void dodaj_pojazd(const v_pojazd& pojazd);
    void usun_pojazd(string nr_rej);
    void zapisz();  //zapis bazy do pliku
    void wczytaj(); //wczytanie bazy z pliku

    friend ostream& operator<<(ostream& os, BazaPojazdow& bp);  //przeciążenie operatora <<
};

#endif