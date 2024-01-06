#include "baza_pojazdow.hpp"
#include "ui.hpp"

int main(){

    BazaPojazdow bazaPojazdow;
    UI userInterface(bazaPojazdow);
    userInterface.run();
    
    return 0;
}