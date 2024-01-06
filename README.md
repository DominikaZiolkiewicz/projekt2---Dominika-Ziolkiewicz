# projekt2 - Dominika Ziółkiewicz
### Baza danych pojazdów 
W folderze */kod* został stworzony projekt, którego zadaniem jest pokazanie działania bazy danych pojazdów. Możliwe do przetrzymywania są dwa rodzaje pojazdów - Motor i Osobowy. Dziedziczą one po klasie głównej Pojazd. 

Klasa BazaPojazdow służy do przetrzymywania chwilowej bazy na swojej mapie. Niestety po zamknięciu programu mapa oczywiście staje się pusta a dane giną. Dlatego aby tego uniknąć stworzono metody do zapisu bazy do pliku a także wczytania jej z pliku do programu. 

Mapa przetrzymuje jako klucz - numer rejestracyjny pojazdu, a jako wartośc - odpowiedni obiekt (użycie variantu).

Możliwe do zrobienia akcje to

- 'lb' - wydrukowanie aktualnie trzymanej bazy w mapie do konsoli
- 'dm' - dodanie motoru. Następnie program prosi o potrzebne dane (marka, model, cena, nr. rejestracyjny i pojemność silnika)
- 'do' - dodanie samochodu osobowego. Następnie program prosi o potrzebne dane (marka, model, cena, nr. rejestracyjny i czy posiada klimatyzację)
- 'us' - usunięcie pojazdu. Program prosi o podanie numeru rejestracyjnego pojazdu, który użytkownik chce usunąć
- 'zapisz' - zapisanie bazy do pliku binarnego
- 'wczytaj' - wczytanie bazy z pliku binarnego

Całość aplikacji może być uruchomiona poprzez *make* i *./all* dzięki pikowi Makefile będącemu w folderze */kod*.