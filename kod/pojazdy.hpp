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
    const string get_nr_rej() const;
    virtual void print() const;
};

class Osobowy : public Pojazd{
    private:
    bool klimatyzacja;

    public:
    Osobowy(string mar, string mod, int ce, string nr, bool klima);
    void print() const override;
};


class Motor : public Pojazd{
    private:
    int pojemnosc_silnika;

    public:
    Motor(string mar, string mod, int ce, string nr, int poj);
    void print() const override;

};

#endif