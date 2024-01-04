#ifndef UUSER_INTERFACE
#define UUSER_INTERFACE

#include "baza_pojazdow.hpp"
#include "pojazdy.hpp"
#include <memory>

class UI{
    unique_ptr<BazaPojazdow> baza;

    public:
    UI(BazaPojazdow& bp);
    void run();
    void drukuj();
};

#endif