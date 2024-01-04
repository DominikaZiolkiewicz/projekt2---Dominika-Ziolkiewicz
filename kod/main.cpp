#include "baza_pojazdow.hpp"
#include "pojazdy.hpp"
#include "ui.hpp"
#include <iostream>

using namespace std;

int main(){

    BazaPojazdow bazaPojazdow;
    UI userInterface(bazaPojazdow);
    userInterface.run();
    
    return 0;
}