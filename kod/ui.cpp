#include "ui.hpp"
#include <iostream>
#include <string>
#include <limits>
#include <fstream>

using namespace std;

UI::UI(BazaPojazdow& bp){
    baza = make_unique<BazaPojazdow>(bp);
};

void UI::run(){
    string komenda = "";
    string nr = "";

    while(1){
        komenda = "";

        cout<<"Dostepne komendy to:"<<endl;
        cout<<" 'do' - dodaj samochod osobowy,"<<endl;
        cout<<" 'dm' - dodaj motor,"<<endl;
        cout<<" 'lb' - wydrukuj zawartosc bazy,"<<endl;
        cout<<" 'us' - usun pojazd"<<endl;
        cout<<" 'zapisz' - zapis bazy do pliku"<<endl;
        cout<<" 'wczytaj' - odczyt bazy z pliku"<<endl<<endl;

        cin>>komenda;
        if(komenda == "lb"){
            drukuj();
            cout<<endl;
        }
        else if(komenda == "do"){
            try{
                dodaj_osobowy();
            }
            catch(const exception& e){
                cout<<e.what()<<endl;
                cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout<<endl;
                continue;
            }
        }
        else if(komenda == "dm"){
           try{
                dodaj_motor();
            }
            catch(const exception& e){
                cout<<e.what()<<endl;
                cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout<<endl;
                continue;
            } 
        }
        else if(komenda == "us"){
            cout<<"Podaj numer rejestracyjny pojazdu, ktory chcesz usunac z bazy"<<endl;
            cin>>nr;
            baza->usun_pojazd(nr);
            nr = "";
        }
        else if(komenda == "zapisz"){
            baza->zapisz();
        }
        else if(komenda == "wczytaj"){
            baza->wczytaj();
        }
        else
        {
            cout<<komenda<<" Wpisano niepoprawna komende!"<<endl;
        }
        komenda = "";
    }
}

void UI::drukuj(){
    cout<<*baza;
}

void UI::dodaj_osobowy(){
    string marka = "";
    string model = "";
    int cena = 0;
    string nr = "";
    string tn = "";
    bool klima = false;

    cout<<"Wpisz kolejno: MARKA MODEL CENA NR.REJESTRACYJNY i tak/nie jesli jest KLIMATYZACJA badz nie"<<endl;
    cin>>marka;
    cin>>model;
    cin>>cena;
    if(cin.fail()) throw invalid_argument("Podano nieprawidlowa wartosc dla 'cena'");
    cin>>nr;
    cin>>tn;

    if(tn == "tak") klima = true;
    else if(tn == "nie") klima = false;
    else{
        throw invalid_argument("Podano nieprawidlowa wartosc dla 'klimatyzacja'");
    } 
    baza->dodaj_pojazd(Osobowy(marka, model, cena, nr, klima));
}

void UI::dodaj_motor(){
    string marka = "";
    string model = "";
    int cena = 0;
    string nr = "";
    string tn = "";
    int pojemnosc = 0;

    cout<<"Wpisz kolejno: MARKA MODEL CENA NR.REJESTRACYJNY i POJEMNOSC SILNIKA"<<endl;
    cin>>marka;
    cin>>model;
    cin>>cena;
    if(cin.fail()) throw invalid_argument("Podano nieprawidlowa wartosc dla 'cena'");
    cin>>nr;
    cin>>pojemnosc;
    if(cin.fail()) throw invalid_argument("Podano nieprawidlowa wartosc dla 'pojemnosc silnika'");
 
    baza->dodaj_pojazd(Motor(marka, model, cena, nr, pojemnosc));
}