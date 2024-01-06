#ifndef UUSER_INTERFACE
#define UUSER_INTERFACE

#include "baza_pojazdow.hpp"
#include "pojazdy.hpp"
#include <memory>

class UI{
    unique_ptr<BazaPojazdow> baza;

    public:
    UI(BazaPojazdow& bp);
    void run();         //pętla główna programu
    void drukuj();      //wypisywanie zawartosci aktualnie trzymanej na mapie bazy danych
    void dodaj_osobowy();   
    void dodaj_motor();
};

#endif