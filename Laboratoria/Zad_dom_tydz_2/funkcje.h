#ifndef FUNKCJE_H
#define FUNKCJE_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void okrag(int r);
void gcd(int a, int b);
void find_and_replace(string napis, string wyraz_szukaj, string wyraz_zamien);
void find(const string &napis, const string &wyraz_szukaj);
vector <string> split(const string &napis, char znak=' ');
vector <string> split(const string &napis, char znak);
int ilosc_wyrazow(const string &sentence);
void najdluzszy(const string &txt);

#endif // FUNKCJE_H
