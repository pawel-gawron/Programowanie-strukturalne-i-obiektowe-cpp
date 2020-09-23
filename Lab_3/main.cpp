#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

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

void sort_eur(vector<Exchange_rate> &rates)
{
    for( auto i = rates.begin(); i != rates.end(); i++ )
    {

        for( auto j = rates.begin(); j != rates.end()-1; j++ )
        {
            if( ( * j ).eur > ( * (j+1) ).eur )
            {
                swap( ( * j ), ( * (j+1) ) );
            }
        }
    }
    cout << "Top 10 najnizszych kursow EUR:" << endl;
    for( auto i = rates.begin()+4; i != rates.begin()+14; i++ )
    {
        cout << ( * i ).date << " " <<  ( * i ).eur << endl;
    }
}

void sort_usd(vector<Exchange_rate> &rates)
{
    for( auto i = rates.begin(); i != rates.end(); i++ )
    {

        for( auto j = rates.begin(); j != rates.end()-1; j++ )
        {
            if( ( * j ).usd > ( * (j+1) ).usd )
            {
                swap( ( * j ), ( * (j+1) ) );
            }
        }
    }
    cout << "Top 10 najwyzszych kursow USD:" << endl;
    for( auto i = rates.end()-1; i != rates.end()-11; i-- )
    {
        cout << ( * i ).date << " " <<  ( * i ).usd << endl;
    }
}

void binary_search(double search,const vector<Exchange_rate> &rates)
{
    int min = 0;
    int max = rates.size()-1;
    int mid;
    while(min <= max)
    {
        mid = (min + max)/2;
        if(rates[mid].usd == search)
        {
            cout << "Data kursu: " << search << " to: " << rates[mid].date << endl;
        }
        if(rates[mid].usd > search)
        {
            max = mid-1;
        }
        else
        {
            min = mid+1;
        }
    }
}

int main()
{
    std::fstream file("C:\\Users\\ASUS_PEPE\\Desktop\\STUDIA AiR\\Programowanie strukturalne i obiektowe\\Lab_3\\kursy_usd_eur.csv");
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
    binary_search(3.9011,rates);
    return 0;
}





