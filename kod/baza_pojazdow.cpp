#include <variant>
#include <map>
#include <iostream>
#include "pojazdy.hpp"
#include "baza_pojazdow.hpp"


BazaPojazdow::BazaPojazdow(){
    dodaj_pojazd(Motor("BMW", "M 1000 RR", 150000, "WA100", 1000));
    dodaj_pojazd(Osobowy("Toyota", "Corolla", 80000, "WZ200", true));
}

void BazaPojazdow::dodaj_pojazd(const v_pojazd& pojazd){
    string nr;
    visit([&nr](const auto& p){
        nr = p.get_nr_rej();
    },pojazd);

    baza.insert({nr, pojazd});
}


void BazaPojazdow::usun_pojazd(string nr){
    baza.erase(nr);
    cout<<"usunieto!"<<endl;
}

ostream& operator<<(ostream& os, BazaPojazdow& bp){
   for (const auto& [key, value] : bp.baza) {
        visit([&os](const auto& pojazd) {
            pojazd.print(os); 
        }, value);
    }
    return os;
}