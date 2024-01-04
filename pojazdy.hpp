#ifndef POJAZDY
#define POJAZDY

#include <string>

using namespace std;

class Pojazd{

    protected:
    string marka;
    string model;
    int cena;
    string nr_rejestracyjny;

    public:
    Pojazd() = default;
    Pojazd(string mar, string mod, int ce, string nr);
};

class Osobowy : public Pojazd{
    private:
    bool klimatyzacja;

    public:
    Osobowy(string mar, string mod, int ce, string nr, bool klima);
};


class Motor : public Pojazd{
    private:
    int pojemnosc_silnika;

    public:
    Motor(string mar, string mod, int ce, string nr, int poj);
};

#endif