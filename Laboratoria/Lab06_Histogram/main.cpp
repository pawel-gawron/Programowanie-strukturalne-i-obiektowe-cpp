#include <iostream>
#include <fstream>
#include <vector>
#include <histogram.h>

using namespace std;

int main()
{
    Histogram hist; //Konstruktor domyślny
    Histogram hist_2(std::vector<int>({10,15,6,9,10,12})); // definiuje obiekt wywołując konstruktor inicjujący go listą wyników w punktach

    hist.emplace(20); //dodaje ocenę 20pkt
cout << hist << endl;
        hist.emplace(std::vector<int>({10, 15, 6, 9, 10, 12}));
cout << hist << endl;
        hist << 10 << 12 << 20 << 21; // kolejne elementy zawierają punktację poszczególnych studentów

        cin >> hist; // pobiera dane od użytkownika (pobierając najpierw liczbę wyników, które chce wprowadzić)

        hist.from_csv("wyniki.csv", ',', 4); //wczytuje plik csv, argumentami są nazwa pliku, separator kolumn oraz index kolumny w której znajdują się dane dla histogramu

        hist_2.clear(); //usuwa wszystkie dane z histogramu // jeśli dane nie zostaną usunięte kolejne wywołania operatora zapisu do strumienia lub

        using Bin = int; // alias typu wartości dla przedziału histogramu
            using Frequency = int; // alias typu wartości dla częstości wystąpień
            std::cout << hist; // zapis histogramu do strumienia tekstowego

            std::ofstream file("histogram.txt");
            file << hist; // zapis histogramu do pliku (identycznie jak dla wyświetlenia go na konsoli)

            int freq = hist[10]; // zwraca częstość dla przedziału do którego należy wartość 10
cout << "freq:" << freq << endl;
            std::pair<Bin, Bin> range = hist.range(); // zwraca początkowy i końcowy przedział.
cout << "range:" << range << endl;
            std::pair<Bin, Frequency> max = hist.max(); // zwraca najczęściej występujący przedział oraz jego częstość
cout << "max:" << max << endl;
            std::vector<Bin> bins = hist.unique_bins(); // zwraca listę unikalnych, niepustych przedziałów
cout << "bins:" << bins << endl;                        // (gdzie dla przedziału o szerokości 5 i wartości
                                                        // elementu 0 jest przedziałem [0-5), 5 -> [5,10), itp.]

            std::vector<std::pair<Bin, Frequency>> items = hist.unique_items(); // zwraca listę niepustych przedziałów oraz częstość wystąpień
cout << "items:" << items << endl;
            //konwersja na inne typy
            using BinsVector = std::vector<std::pair<Bin, Frequency>>;
            BinsVector items_vect = static_cast<BinsVector>(hist); // operator rzutowania działa tak samo jak  Histogram::unique_items
            cout << "print: " << endl;
            print(items_vect); // zewnętrzna funkcja wyświetlająca wektor elementów histogramu
        return 0;
}
