#include <iostream>
#include "funkcje.h"


using namespace std;

int main()
{
    for(;;)
    {
    cout<<"Witam"<< endl << "Wybor:"<< endl << "1. Liczby pierwsze" << endl << "2. Liczba Pi" <<endl << "3. Kwadrat" << endl << "4. Koniec programu" << endl << "wybor: ";
    char wybor;
    cin >> wybor;
    int liczba = 7;
    switch(wybor)
    {
    case '1':

       if_prime(liczba);
        cout << "liczba: " << liczba;
        if (liczba==0){
            cout << "nie";
 }
            cout <<" jest liczba pierwsza. " << endl;
        break;
    case '2':
        cout << pi(1000) << endl;
        break;
    case '3':
        draw_square(7,1,1);
        break;
    case '4':
        exit(0);
        break;
    default:
        cout << "Zly wybor";
        break;
    }
    }
    return 0;
}
