#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

class Translator
{
private:
    list <string> polish_words;
    list <string> english_words;
public:
    Translator(const string &original, const string &translate);
    string translate(string word);
    list<string> synonymus(string synonim);
    int words_count();
    friend std::ostream& operator<<(std::ostream& out, const Translator& words);
};

struct Plant
{
    string name;
    double height;
    int age;
};

bool compare_by_height_and_name(const Plant &a, const Plant &b)
{
    if (a.height!=b.height) {
        return a.height>b.height;
    }
    else
        return a.name<b.name;
}

class Vehicle {
public:
    std::string name() const { return name_; }
    int number_of_wheels() const { return number_of_wheels_; }

    virtual ~Vehicle() = default;

protected:
    Vehicle(const std::string &name, int number_of_wheels)
        : name_(name), number_of_wheels_(number_of_wheels) {}

    std::string name_;
    int number_of_wheels_;
};

class Car : public Vehicle{
public:
    Car(const std::string  &name, int horsepower)
        : Vehicle(name, 4), horsepower_(horsepower) {}

    int horsepower() const { return horsepower_; }

private:
    int horsepower_;
};

class Bike : public Vehicle {
public:
    Bike(const std::string &name, bool has_derailleur)
        : Vehicle(name, 2), has_derailleur_(has_derailleur) {}

    bool has_derailleur() { return has_derailleur_; }

private:
    bool has_derailleur_;
};

void display_vehicle_info(const std::vector<std::unique_ptr<Vehicle>>& vehicles)
{
    for (unsigned int i = 0; i < vehicles.size(); i++)
    {
        Car * some_car = dynamic_cast<Car *>(vehicles[i].get());
        Bike * some_bike = dynamic_cast<Bike *>(vehicles[i].get());
        if(some_car != nullptr){
            cout << i << " Name of car: " << some_car->name() << " Number of wheels: " << some_car->number_of_wheels() << " Horsepower: " << some_car->horsepower()<< endl;
        }
        else if(some_bike != nullptr)
        {
            cout << i << " Name of bike: " << some_bike->name() << " Number of wheels: " << some_bike->number_of_wheels() << " Has derailleur: " << some_bike->has_derailleur() << endl;
        }
        else{
            cout << "ERROR" << endl;
        }
    }
}

//void ex_1()
//{
//    Translator polish2english("pol.dict", "eng.dict");
//    cout << polish2english.translate("kot");
//    list<string> words = polish2english.synonymus("pojemnik");
//    cout << polish2english.words_count();
//    cout << polish2english;
//}

void ex_2()
{
    vector <Plant> plants = {{"daisy", 0.02, 1}, {"oak", 7.0, 80}, {"ash", 5.5, 15}, {"clover", 0.02, 1}, {"a", 0.02, 1}};
    sort(plants.begin(), plants.end(), compare_by_height_and_name);

    for (auto &el : plants)
    {

        cout << el.name << " " << el.height << " " << el.age << endl;
    }
}

void ex_3()
{
    std::vector<std::unique_ptr<Vehicle>> vehicles;

    vehicles.emplace_back(std::make_unique<Bike>("Fixie", false));
    vehicles.emplace_back(std::make_unique<Car>("Porsche", 400));
    vehicles.emplace_back(std::make_unique<Bike>("Road Bike", true));
    vehicles.emplace_back(std::make_unique<Bike>("MTB", true));
    vehicles.emplace_back(std::make_unique<Car>("Passat", 115));

    display_vehicle_info(vehicles);
}

int main()
{
    ex_2();
    //<td class.+>(\d \w{3,3}).+>(\d,\d+).+td>
    //td class="bgt. right">(.{3,6})<\/td> <td class="bgt. right">(.{3,8})<\/td>
    return 0;
}
