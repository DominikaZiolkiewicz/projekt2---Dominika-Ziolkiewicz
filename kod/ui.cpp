#include "ui.hpp"
#include <iostream>
#include <string>

using namespace std;

UI::UI(BazaPojazdow& bp){
    baza = make_unique<BazaPojazdow>(bp);
};

void UI::run(){
    string komenda = "";
    while(1){
        cout<<"Dostepne opcje to:"<<endl;
        cout<<" 'do' - dodaj samochod osobowy,"<<endl;
        cout<<" 'dm' - dodaj motor,"<<endl;
        cout<<" 'lb' - wydrukuj zawartosc bazy,"<<endl;
        cout<<" 'us' - usun pojazd"<<endl;
        cout<<" 'zapisz' - zapis bazy do pliku"<<endl;
        cout<<" 'odczytaj' - odczyt bazy z pliku"<<endl<<endl;

        cin>>komenda;

        if(komenda == "lb"){
            UI::drukuj();
            cout<<endl;
        }
        else //komenda != "do" || komenda != "dm" || komenda != "lb" || komenda != "us" || komenda != "zapisz" || komenda != "odczytaj"
        {
            cout<<komenda<<" Wpisano niepoprawna komende!"<<endl;
        }


        komenda = "";
    }
}

void UI::drukuj(){
    cout<<*baza;
}