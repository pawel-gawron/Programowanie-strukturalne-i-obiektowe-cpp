#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

struct Temp
{
    string data;
    string czas;
    float pre_dzw;
    float temp_dzw;
    float cisnienie;
    float temp;
    float wilgotnosc;
    int kompas;
    float pre_uv;
    float pre_wiatru;
    float kierunek;
    float wysokosc;
    float temp_wew_pom;

};
std::vector<Temp> dane;
Temp er;
void sort(vector<Temp> &dane)
{
    bool zmiana;
    auto rozmiar = dane.end();
    do
    {
        zmiana = 0;
        for( auto j = dane.begin(); j != dane.end()-1; j++ )
        {
            if( ( * j ).temp > ( * (j+1) ).temp )
            {
                swap( ( * j ), ( * (j+1) ) );
                zmiana  = 1;
            }
        }
        rozmiar--;
    }while(zmiana);
}

int main()
{
    std::fstream file("C:\\Users\\ASUS_PEPE\\Desktop\\STUDIA AiR\\Programowanie strukturalne i obiektowe\\Lab_3_temperatura\\temp02-2020.csv");

    if (file.is_open())
    {
        std::string line;
        std::getline(file, line); // wczytuje pierwszą linię z nagłówkiem i ją ignoruje
        while (std::getline(file, line))//wczytuje kolejne linie aż do końca pliku
        {
            std::stringstream str(line);//tworzy strumień, którego źródłem jest wczytana linia


            std::getline(str, er.data, ','); //wczytuje date (pierwszy element wiersza)
            std::string double_str;
            std::getline(str, double_str, ',');  // wczytuje czas (jako tekst)
            std::getline(str, double_str, ',');  // wczytuje predkosc dzwieku (jako tekst)
            er.pre_dzw = atof(double_str.c_str());      //zamiana na string->double
            std::getline(str, double_str, ','); // wczytuje temp. dzwiekiem
            std::getline(str, double_str, ','); // wczytuje cisnienie atmosferyczne
            er.cisnienie = atof(double_str.c_str()); // zamiana na string ->double
            std::getline(str, double_str, ','); // wczytuje temperature
            er.temp = atof(double_str.c_str()); // zamiana na string ->double
            std::getline(str, double_str, ','); // wczytuje wilgotnosc
            er.wilgotnosc = atof(double_str.c_str()); // zamiana na string ->double
            std::getline(str, double_str, ','); // wczytuje kompas
            er.kompas = atof(double_str.c_str()); // zamiana na string ->double
            std::getline(str, double_str, ','); // wczytuje predkosc uv
            er.pre_uv = atof(double_str.c_str()); // zamiana na string ->double
            std::getline(str, double_str, ','); // wczytuje predkosc wiatru
            er.pre_wiatru = atof(double_str.c_str()); // zamiana na string ->double
            std::getline(str, double_str, ','); // wczytuje kierunek
            er.kierunek = atof(double_str.c_str()); // zamiana na string ->double
            std::getline(str, double_str, ','); // wczytuje wysokosc
            er.wysokosc = atof(double_str.c_str()); // zamiana na string ->double
            std::getline(str, double_str, ','); // wczytuje temperature wewnatrz pomieszczenia
            er.temp_wew_pom = atof(double_str.c_str()); // zamiana na string ->double
            dane.emplace_back(er); //dodaje element do kolekcji
        }
    }
    cout << dane.size() << endl;
    sort(dane);
    cout << "Najwyzsza temperatura: " << (dane.end()-1)->temp << endl;
    cout << "Najnizsza temperatura: " << (dane.begin())->temp << endl;
    cout << "Mediana temperatur: " << (dane[((int)(dane.size()/2)-2)].temp + dane[((int)(dane.size()/2)-1)/2].temp)/2 << endl;

    return 0;
}

