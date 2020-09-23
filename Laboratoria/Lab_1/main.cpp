#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void print_vector(const vector<int>& tab)
{
    for( int element : tab)
    {
        cout << element << endl;
    }
}

void fill_vector(vector<int>& tab)
{
    for (size_t i=0; i<tab.size(); i++)
        {
            cin >> tab[i];
        }
}

void fill_vector(vector<int>* tab)
{
    for (size_t i=0; i<tab->size(); i++)
        {
            cin >> (*tab)[i];
        }
}

void min_max(const vector<double> &values, double &min, double &max)
{
    min = values[0];
    max = values[0];

    for (size_t i = 0; i<values.size();i++)
    {
    if (min>values[i])
        {
            min = values[i];
        }
    if (max<values[i])
        {
            max = values[i];
        }
    }
}

int silnia(int n)
{
    int acc = 1;

    for (int i = 1; i <=n;i++)
    {
        acc = acc * i;
    }
    return acc;
}

double pi(int n)
{
    double acc = 0;

    for (int i = 1; i <=n;i++)
    {
        acc = acc + pow(-1, i +1)/static_cast<double>(2*i-1);
    }
    return acc*4;
}


int main()
{
    //vector<int> tab(3);
    vector<int> tab = {1,2,7,9};
    vector<string> napisy = {"pies","kot","tata","mama"};
    tab.emplace_back(19);
    print_vector(tab);
    fill_vector(tab);
    //cin >> tab[0];

    //for (size_t i=0; i<tab.size(); i++)
    //{
    //    cin >> tab[i];
    //}


    for (size_t i=0; i<tab.size(); i++)
    {
        cout << tab[i] << endl;
    }

    for (size_t i=0; i<tab.size(); i++)
    {
        cout << napisy[i] << endl;
    }

    for( int element : tab)
    {
        cout << element << endl;
    }

    double min;
    double max;
    std::vector<double> values = {-1.0, 100, 3.14, -999.9, 21.37};

    min_max(values, min, max); // wypisze znalezione wartości do zmiennych min i max
    cout << "wartosc min:" << min << endl << "wartosc max:" << max;
    return 0;

    int wynik = silnia(5);
    cout << wynik;
    cout << pi(500);
}
