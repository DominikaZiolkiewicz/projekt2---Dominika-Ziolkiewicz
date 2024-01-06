#include <variant>
#include <map>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include "pojazdy.hpp"
#include "baza_pojazdow.hpp"

/*konstruktor, który na początku dodaje od razu do bazy dwa pojazdy - motor i osobowy*/
BazaPojazdow::BazaPojazdow(){
    dodaj_pojazd(Motor("BMW", "M 1000 RR", 150000, "WA100", 1000));
    dodaj_pojazd(Osobowy("Toyota", "Corolla", 80000, "WZ200", true));
}

/*metoda sprawdza numer rejestracyjny pojazdu i dodaje na mapę parę [klucz, wartość] = [nr.rejestracyjny, pojazd]*/
void BazaPojazdow::dodaj_pojazd(const v_pojazd& pojazd){
    string nr;
    visit([&nr](const auto& p){
        nr = p.get_nr_rej();
    },pojazd);

    mapa.insert({nr, pojazd});
}

/*metoda usuwa pojazd z mapy, jeśli tylko taki o podanym numerze rejestracyjnym się na niej znajduje*/
void BazaPojazdow::usun_pojazd(string nr){
    if(mapa.find(nr) != mapa.end()){
        mapa.erase(nr);
        cout<<"usunieto!"<<endl;
    }
    else cout<<"Nie ma w bazie pojazdu o tym numerze rejestracyjnym"<<endl;
}

/*przeciązenie operatora << służące łatwiejszemu drukowaniu danych o pojeździe do koncoli*/
ostream& operator<<(ostream& os, BazaPojazdow& bp){
   for (const auto& [key, value] : bp.mapa) {
        visit([&os](const auto& pojazd) {
            pojazd.print(os); 
        }, value);
    }
    return os;
}

/*zapis do pliku .bin - najpierw długość stringa z informacjami o pojeździe a później sam string*/
void BazaPojazdow::zapisz(){
    ofstream file;
    file.open("baza_danych.bin", ios::binary);
    string cont;
    for (const auto& [key, value] : mapa) {
        visit([&cont](const auto& pojazd) {
            cont = pojazd.get_string();
        }, value);
        int size = cont.size();

        if(file.is_open()){
            file.write(reinterpret_cast<char*>(&size), sizeof(size));   
            file.write(cont.c_str(), size);
        }
    }
    file.close();
}

/*wczytywanie bazy danych z pliku .bin do mapy*/
void BazaPojazdow::wczytaj(){
    ifstream file;
    file.open("baza_danych.bin", ios::binary);
    int size;
    
    string marka, model, nr, klima, cena, pojemnosc;
    int k = 0; //zlicza średniki
    if(file.is_open()){
        while(!file.eof()){
            file.read(reinterpret_cast<char*>(&size), sizeof(size));    //wczytuje liczbę oznaczającą długość linijki
            vector<char> vec(size);
            file.read(vec.data(), size);
            
            marka = "", model = "", nr = "", klima = "", cena = "", pojemnosc = "";
            k=0;

            for(int i=1; i<size; i++){
                if(k == 0){                 //wczytanie 'marki'
                    if(vec[i] != ';'){
                        marka += vec[i];
                    }
                    else {
                        k++;
                        continue;
                    } 
                }                           //wczytanie 'modelu'
                if(k == 1){
                    if(vec[i] != ';'){
                        model += vec[i];
                    }
                    else {
                        k++;
                        continue;
                    } 
                }                           //wczytanie 'ceny'
                if(k == 2){
                    if(vec[i] != ';'){
                        cena += vec[i];
                    }
                    else {
                        k++;
                        continue;
                    } 
                }                           //wczytanie numery rejestracyjnego
                if(k == 3){
                    if(vec[i] != ';'){
                        nr += vec[i];
                    }
                    else {
                        k++;
                        continue;
                    } 
                }
                if(k == 4 && vec[0] == 'M'){    //jeśli motor - wczytaj pojemnosc silnika
                    pojemnosc += vec[i]; 
                }
                if(k == 4 && vec[0] == 'O'){    //jeśli osobowy - wczytaj klimatyzację
                    klima += vec[i];
                }
                else continue;    
            }  
            
            if(mapa.find(nr) == mapa.end()){    //jeśli jeszcze pojazd o danym nr. rejestracyjnym nie znajduje się w mapie - dodaj
                if(vec[0] == 'M'){
                    dodaj_pojazd(Motor(marka, model, stoi(cena), nr, stoi(pojemnosc)));
                }
                if(vec[0] == 'O'){
                    bool czy;
                    if(klima == "tak") czy = true;
                    if(klima == "nie") czy = false;
                    dodaj_pojazd(Osobowy(marka, model, stoi(cena), nr, czy));
                }
            }
        }
        file.close();
    }

}