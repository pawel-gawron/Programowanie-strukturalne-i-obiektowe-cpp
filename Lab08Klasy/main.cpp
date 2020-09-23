#include <iostream>
#include "klasy.h"

using namespace std;

int main()
{
    Bike bike;
    cout << bike.max_speed() << endl;
    Car passat("Volkswagen Passat", "Diesel", 200, true);
    std::cout << "Name: " << passat.name() << std::endl;
    std::cout << "Has ABS: " << passat.has_abs() << std::endl;
    Motorcycle motorcycle;
    cout << motorcycle.max_speed() << endl;
    Samolot samolot;
    cout << samolot.max_speed() << endl;
    return 0;
}
