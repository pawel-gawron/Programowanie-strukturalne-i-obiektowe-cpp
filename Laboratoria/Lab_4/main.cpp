#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <list>
#include <iterator>

using namespace std;

int randomInt(int min, int max) {
    static std::default_random_engine e{};
    std::uniform_int_distribution<int> d{min, max};
    return d(e);
}

void fill_vector(list<int>& list)
{
    for (auto it = list.begin(); it!= list.end(); it++)
    {
        *it = randomInt(-20,20);
    }
}

//void show()//zwykly operator indeksowania
//{
//for (size_t i=0; i<tab.size(); i++)
//    {
//        cout << tab[i] << endl;
//    }
//}

void show(list<int>& list)
{
    for (auto it = list.begin(); it!=list.end();it++)
    {
        cout << *it << endl;
    }
}
void removal(list<int>& list)
{
    cout << "Podaj wartosc do usuniecia: ";
    int usun;
    cin >> usun;
    for (auto it = list.begin(); it!=list.end();it++)
    {
        auto r=find(list.begin(),list.end(),usun);
        if(*it==usun)
        {
            list.erase(r);
            r++;
        }
    }
}

void min(list<int>& list)
{
    auto min = min_element(list.begin(), list.end());
    cout << "Najmniejszy element: " << *min << endl;
}

void max(list<int>& list)
{
    auto max = max_element(list.begin(), list.end());
    cout << "Najwiekszy element: " << *max << endl;
}

void minmax(list<int>& list)
{
    auto [min,max] = minmax_element(list.begin(), list.end());
            cout << "Najwiekszy element: " << *max << endl;
            cout << "Najmniejszy element: " << *min << endl;
}

void sort_up(list<int>& list)
{
        list.sort();
}

void sort_down(list<int>& list)
{
        list.sort(greater<int>());
}

void count(list<int>& list)
{
    for (auto it = list.begin(); it!=list.end();it++)
    {
        int sum = count(list.begin(), list.end(),*it);
        cout << "Liczba: " << *it << "wystapila: " << sum << "razy" << endl;
    }
}
int main()
{
        list<int> list(35);
        fill_vector(list);
        show(list);
        removal(list);
        show(list);
        min(list);
        max(list);
        minmax(list);
        sort_up(list);
        show(list);
        sort_down(list);
        show(list);
        count(list);
        return 0;
    }
