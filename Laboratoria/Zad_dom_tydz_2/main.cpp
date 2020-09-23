#include <iostream>
#include <vector>
#include <windows.h>
#include "funkcje.h"

using namespace std;

int main()
{
    cout << "Wybor:" << endl << "0. Najwiekszy wspolny dzielnik" << endl << "1. Znajdz i zamien" << endl << "2. Znajdz" << endl << "3. Okrag" << endl;
    cout << "4. Ilosc wyrazow" << endl << "5. Najdluzszy wyraz" << endl << "6. Podziel" << endl << "7. Wyjdz" << endl;
    char wybor;
    cin >> wybor;
    switch(wybor)
    {
    case '0':
    gcd(16,16);
        break;
    case '1':
    find_and_replace("Ala ma kota i kota i kota i kota", "kota","psa");
        break;
    case '2':
    find("Ala ma kota i kota i kota i kota", "kota");
        break;
    case '3':
    okrag(10);
        break;
    case '4':
    cout << ilosc_wyrazow("Ale ma kota a kot ma Ale");
        break;
    case '5':
    najdluzszy("Ala ma kota");
        break;
    case '7':
    exit(0);
        break;
    default:
        cout << "Niepoprawny wybor" << endl;
        break;
    case '6':
    vector <string> words = split("Ala ma kota");
    for (unsigned int i = 0; i<= words.size(); i++) cout << words[i] << endl;
        break;
    }
    return 0;
}
