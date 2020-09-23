#include <iostream>
#include <cmath>
#include <vector>
#include <math.h>
#include "funkcje.h"

using namespace std;

void gcd(int a, int b)
{
    do
    {
        int c = a % b;
        a=b;
        b=c;

    }while(b!=0);
    cout << "Najwiekszy wspolny dzielnik: " << a << endl;
}

void find_and_replace(string napis, string wyraz_szukaj, string wyraz_zamien)
{
    size_t pozycja=napis.find(wyraz_szukaj);
    if (pozycja==string::npos) //ten warunek da falsz jesli znaleziono taki wyraz
    {
        cout << "Nie znaleziono" << endl;
        return;
    }
    do
    {
        napis.replace(pozycja,wyraz_szukaj.size(),wyraz_zamien); //funkcja zastepujaca znaki, pierwszy argument - od ktorego znaku rozpoczac zastepowanie
        cout << "Fraza zostala odnaleziona na pozycji " << pozycja << endl;
        pozycja = napis.find(wyraz_szukaj, pozycja + wyraz_szukaj.size());
    }while(pozycja!=string::npos);

    cout << napis << endl;
}


void find(const string &napis, const string &wyraz_szukaj)
{
    for (unsigned int i = 1 ; i <= napis.size(); i++)
    {
        unsigned int zgodnosc = 0;
        if(napis[i] == wyraz_szukaj[0])
        {
            for(unsigned int j = 0 ; j <= wyraz_szukaj.size()-1; j++)
            {
                if(napis[i+j] == wyraz_szukaj[j])
                {
                    zgodnosc++;
                }
            }
        }
        if(zgodnosc==wyraz_szukaj.size())
        {
            cout << "Znaleziono na pozycji:" << i << endl;
            i+=wyraz_szukaj.size();
        }
    }
}

void okrag(int r)
{
    int dlugosc = r;
    int szerokosc = r;

    for (int y=szerokosc; y>= -szerokosc; y-=2)
    {
        for (int x=-dlugosc; x<=dlugosc; x++)
        {
            if((int)sqrt(pow(x,2)+pow(y,2))==r) cout << "#";
            else cout << " ";
        }
        cout << endl;
    }
}

vector <string> split(const string &napis, char znak)
{
    size_t position = napis.find(znak);
    size_t start_position = 0;
    vector <string> split_txt;

    while(position != string::npos)
    {
        split_txt.push_back(napis.substr(start_position, position - start_position));
        start_position = position + 1;
        position = napis.find(znak, start_position);
    }
    split_txt.push_back( napis.substr(start_position, min(position, napis.size()) - start_position + 1));

//    for(size_t i = 0; i < split_txt.size(); i++)
//    {
//            cout << split_txt[ i ] << endl;
//    }
    return split_txt;
}

int ilosc_wyrazow(const string &sentence)
{
    int ilosc = 0;
    for (unsigned int i=0; i<sentence.length() ; i++)
    {
        if (sentence[0]!=' ' && sentence[i]==' ' && sentence[i+1]!=' ') {
            ilosc++;
        }
    }
    return ilosc+1;
}

void najdluzszy(const string &txt)
{
    char znak = ' ';
    size_t position = txt.find(znak);
    size_t start_position = 0;
    vector <string> split_txt;

    while(position != string::npos)
    {
        split_txt.push_back(txt.substr(start_position, position - start_position));
        start_position = position + 1;
        position = txt.find(znak, start_position);
    }
    split_txt.push_back( txt.substr(start_position, min(position, txt.size()) - start_position + 1));

    unsigned int m;

    m=split_txt[0].size();

    for (unsigned int i = 0; i < split_txt.size(); i++)
    {
        if(split_txt[i].size() > m) m=split_txt[i].size();
    }
    for (unsigned int i = 0; i < split_txt.size(); i++)
    {
        if(split_txt[i].size() == m)
        {
            cout << "Najdluzszym wyrazem jest:" << split_txt[i];
        }
    }
}
