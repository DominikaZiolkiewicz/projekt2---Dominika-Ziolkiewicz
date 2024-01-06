#ifndef POJAZDY
#define POJAZDY

#include <string>
#include <fstream>

using namespace std;

class Pojazd{   //klasa główna, przechowuje informacje ogólne o pojeździe

    protected:
    string marka;
    string model;
    int cena;
    string nr_rejestracyjny;

    public:
    Pojazd() = default;
    Pojazd(string mar, string mod, int ce, string nr);
    const string get_nr_rej() const;    //zwraca numer rejestracyjny pojazdu
};

class Osobowy : public Pojazd{      //klasa dziedzicząca po klasie Pojazd. Dodatkowo przechowuje informacje czy samochód osobowy ma klimatyzację czy nie
    private:
    bool klimatyzacja;

    public:
    Osobowy(string mar, string mod, int ce, string nr, bool klima);
    const void print(ostream& os) const;    //służy do drukowania informacji w konsoli
    string get_string() const;      //generuje string, który jest później zapisywany do pliku - przechowuje niezbędne informacje o pojeździe
};


class Motor : public Pojazd{        //klasa dziedzicząca po klasie Pojazd. Dodatkowo przechowuje informacje o pojemnosci silnika motoru
    private:
    int pojemnosc_silnika;

    public:
    Motor(string mar, string mod, int ce, string nr, int poj);
    const void print(ostream& os) const;
    string get_string() const;
};

#endif