#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

struct Exchange_rate
{
    std::string date;
    double usd;
    double eur;
    std::string table_id;
};

vector<Exchange_rate> rates;
Exchange_rate er;

struct Comp
{
    bool operator() ( const Exchange_rate& x, double i ) { return x.usd < i; }
    bool operator() ( double i, const Exchange_rate& x ) { return i < x.usd; }
};

bool cmp_eur(const Exchange_rate &a, const Exchange_rate &b)
{
    return a.eur < b.eur;
}

void sort_eur(vector<Exchange_rate> &rates)
{
    sort(rates.begin(), rates.end(), cmp_eur);

    cout << "Top 10 najnizszych kursow EUR:" << endl;
    for( auto i = rates.begin()+4; i != rates.begin()+14; i++ )
    {
        cout << ( * i ).date << " " <<  ( * i ).eur << endl;
    }
}

void sort_usd(vector<Exchange_rate> &rates)
{
    sort(rates.begin(), rates.end(), [](const Exchange_rate &a, const Exchange_rate &b){return a.usd < b.usd;});

    cout << "Top 10 najwyzszych kursow USD:" << endl;
    for( auto i = rates.end()-1; i != rates.end()-11; i-- )
    {
        cout << ( * i ).date << " " <<  ( * i ).usd << endl;
    }
}

void search(vector<Exchange_rate> rates)
{
    auto sea = equal_range(rates.begin(), rates.end(), 3.9011, Comp{});

    for (auto i = sea.first; i!=sea.second; i++)
        cout << "Data: " << i->date << " Kurs: " << i->usd << endl;
}

int main()
{
    std::fstream file("kursy_usd_eur.csv");
    if (file.is_open())
    {
        std::string line;
        std::getline(file, line); // wczytuje pierwszą linię z nagłówkiem i ją ignoruje
        while (std::getline(file, line))//wczytuje kolejne linie aż do końca pliku
        {
            std::stringstream str(line);//tworzy strumień, którego źródłem jest wczytana linia

            std::getline(str, er.date, ','); //wczytuje date (pierwszy element wiersza)
            std::string double_str;
            std::getline(str, double_str, ',');  // wczytuje kurs USD (jako tekst)
            er.usd = atof(double_str.c_str());      //zamiana na string->double
            std::getline(str, double_str, ',');  // wczytuje kurs EUR (jako tekst)
            er.eur = atof(double_str.c_str());      //zamiana na string->double
            std::getline(str, er.table_id, ','); // wczytuje ostatnią kolumnę z numerem tabeli NBP
            rates.emplace_back(er); //dodaje element do kolekcji
        }
    }

    sort_eur(rates);
    sort_usd(rates);
    search(rates);
    return 0;
}
