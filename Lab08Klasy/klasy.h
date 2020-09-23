#ifndef KLASY_H
#define KLASY_H

#endif // KLASY_H
#include <iostream>

class Vehicle {
public:
    std::string name() { return name_; }
    int number_of_wheels() { return number_of_wheels_; }
    std::string propulsion_type() { return propulsion_type_; }
    double max_speed() { return max_speed_; }

protected:
    Vehicle(const std::string &name, int number_of_wheels,
            const std::string &propulsion_type, double max_speed)
        : name_(name), number_of_wheels_(number_of_wheels),
          propulsion_type_(propulsion_type), max_speed_(max_speed) {}

    std::string name_;
    int number_of_wheels_;
    std::string propulsion_type_;
    double max_speed_;
};

class Bike : public Vehicle {
public:
    Bike() : Vehicle("Bike", 2, "Muscles", 30) {}
};

class Car : public Vehicle {
public:
    Car(const std::string &name, const std::string &propulsion_type,
        double max_speed, bool has_abs)
        : Vehicle(name, 4, propulsion_type, max_speed),
          has_abs_(has_abs) {}

    bool has_abs() { return has_abs_; }

private:
    bool has_abs_;
};

class Traktor : public Vehicle
{
public:
    Traktor(const std::string &name_, const int &wheels,
            const std::string engine_type, double max_speed) : Vehicle(name_, wheels, engine_type, max_speed) {}
};

class Motorcycle : public Vehicle
{
public :
    Motorcycle() : Vehicle("Yamaha", 2, "engine", 300) {}
};

class Flying_Vehicle : public Vehicle
{
public:
    Flying_Vehicle(const std::string &name_, int wheels,
                   const std::string &engine_type, double max_speed) : Vehicle(name_, wheels, engine_type, max_speed) {}
};

class Helikopter : public Flying_Vehicle
{
    Helikopter() : Flying_Vehicle("Helikopter", 0, "engine", 400) {}
};

class Samolot : public Flying_Vehicle
{
public:
    Samolot() : Flying_Vehicle("Samolot", 3, "engine", 1900){}
};
