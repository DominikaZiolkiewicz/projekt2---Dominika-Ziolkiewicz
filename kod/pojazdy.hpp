#ifndef POJAZDY
#define POJAZDY

#include <string>
#include <fstream>

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
    const string get_nr_rej() const;
};

class Osobowy : public Pojazd{
    private:
    bool klimatyzacja;

    public:
    Osobowy(string mar, string mod, int ce, string nr, bool klima);
    const void print(ostream& os) const;
};


class Motor : public Pojazd{
    private:
    int pojemnosc_silnika;

    public:
    Motor(string mar, string mod, int ce, string nr, int poj);
    const void print(ostream& os) const;
};

#endif