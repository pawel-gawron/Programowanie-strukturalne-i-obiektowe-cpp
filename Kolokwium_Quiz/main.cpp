#include <iostream>
#include <map>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>

using namespace std;

std::map<char, int> letter_stats(const string &napis)
{
    std::map<char, int> letters;
    for(auto &el :napis)
    {
        letters[el]++;
    }
    return letters;
}

struct Item
{
    std::string name;
    float quantity;
    float price;
};

class Store
{
private:
    Item item;
public:
    Store(vector<Item> atrybuty);
    void change_price(const string &nazwa, float cena);
    float get_price(const string &nazwa);
    Store operator+=(Item &item);
};

struct point{
 float x;
 float y;
};

bool by_distance(const point &a, const point &b)
{
    return sqrt(pow(b.x-a.x,2) + pow(b.y-a.y,2)) > 0;
}

struct Point
{
    float x;
    float y;
};
class Regression
{
private:
    Point a;
public:

    Regression(std::vector<Point> reg);
    void add_point(Point);
    friend std::ostream& operator<<(std::ostream& os, const Point);
    std::pair<float, float> calculate_coefs();
    int get_a();
};

int zrob (const int &z)
{
    if (z+2)
    {
        return 2 + zrob(z-2);
    }
    else return 1;
}

int main()
{

//    Regression reg({{1, 3}, {2, 5}, {3, 9}, {-1, 2}});
//         reg.add_point({1, 3}); //dodanie punktu do zbioru
//         reg << Point({1, 4}); //inny sposób dodania punktu
//         std::pair<float, float> coefs = reg.calculate_coefs();
//         std::cout << "angular coefficient: " << reg.get_a();
//    std::map<char, int> stats = letter_stats("Ala ma kota");

//        /* stats:
//        'A' -> 4
//        'a' -> 3
//        'k' -> 1
//        'l' -> 1
//        'm' -> 1
//        'o' -> 1
//        't' -> 1
//        */

////    Store shop({{"nuts", 10, 20}, {"potatoes", 100, 3}, {"butter", 50, 9}});
////        shop += std::pair<std::string, float>("potatoes", 10); //dostawa towaru
////        shop.change_price("nuts", 22);
////        std::cout << shop.get_price("potatoes");


//    std::vector<point> v = {{1,2.5}, {2,4}, {-1,2.5}, {-1,-2.5}, {0.3, 0.3}};
//    std::sort(v.begin(),v.end(), by_distance);
//    for (auto &el:v)
//    {
//        cout << el.x << " " << el.y << endl;
//    }
    cout << zrob(6) << endl;
        return 0;
}
