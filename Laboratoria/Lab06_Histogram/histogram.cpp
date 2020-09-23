#include "histogram.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

Histogram::Histogram()
{

}

Histogram::Histogram(const std::vector<int> &dates)
{
    for (auto &el:dates)
    {
        bins_[el]++;
    }
}

void Histogram::emplace(int i)
{
    bins_[i]++;
}

void Histogram::emplace(const std::vector<int> &dates)
{
    for(auto &el:dates){
        bins_[el]++;
    }
}

void Histogram::from_csv(std::string filename, char delimeter, int column)
{
    std::fstream file(filename);
    if (file.is_open())
    {
        std::string line;
        std::getline(file, line); // wczytuje pierwszą linię z nagłówkiem i ją ignoruje
        while (std::getline(file, line))//wczytuje kolejne linie aż do końca pliku
        {
            std::stringstream str(line);//tworzy strumień, którego źródłem jest wczytana linia

            for(int i=0; i<=column; i++)
            {
                std::getline(str, point_str , delimeter);
            }
            //std::cout << point_str << std::endl;
            try {
                point = std::stod(point_str);
            } catch (...) {
                ;
            }
            bins_[point]++;
        }
    }
}

void Histogram::clear()
{
    bins_.clear();
    points.clear();
    point_str.clear();
    //delete &point;
}

std::pair<Histogram::Bin, Histogram::Bin> Histogram::range() const
{
    auto min = std::min_element(bins_.begin(), bins_.end(),
                                [](const std::pair<int, int> &l, const std::pair<int, int> &r){return l.first < r.first;});
    auto max = std::min_element(bins_.begin(), bins_.end(),
                                [](const std::pair<int, int> &l, const std::pair<int, int> &r){return l.first > r.first;});
    std::pair<int, int> ret =std::make_pair(min->first,max->first);
    return ret;
}

std::pair<int, int> Histogram::max() const
{
    auto max = std::min_element(bins_.begin(), bins_.end(),
                                [](const std::pair<int, int> &l, const std::pair<int, int> &r){return l.second > r.second;});
    std::pair<int,int> most = (max->first, *max);
    return most;
}

std::vector<int> Histogram::unique_bins() const
{
    std::vector<int> temp;
    for(auto &el : bins_)
    {
        if (el.second!=0)
        {
            temp.emplace_back(el.first);
        }
    }

    std::vector<int>::iterator it = unique(temp.begin(), temp.end());
    temp.resize(distance(temp.begin(), it));
    return temp;
}

std::vector<std::pair<int, int> > Histogram::unique_items() const
{
    std::vector<std::pair<int, int>> temp;
    for(auto &el : bins_)
    {
        if(el.second!=0)
        {
            temp.push_back(std::make_pair(el.first,el.second));
        }
    }
    return temp;
}

Histogram &Histogram::operator<<(int val)
{
    bins_[val]++;
    return *this;
}

Histogram::operator std::vector<std::pair<Bin, Frequency>>()
{
    std::vector<std::pair<int, int>> temp;
    for(auto &el : bins_)
    {
        if(el.second!=0)
        {
            temp.push_back(std::make_pair(el.first,el.second));
        }
    }
    return temp;
}

int Histogram::operator[](int i) const
{
    return bins_.find(i)->second;
}

Histogram Histogram::generate(int min, int max)
{
    Histogram temp;
    for (int i = 0; i<100; i++)
    {
        int sample = min+rand()%(max-min);
        temp.emplace(sample);
    }
    return temp;
}

std::ostream& operator<<(std::ostream& out, const std::vector<std::pair<int, int>> &dates)
{

    for (auto &el :dates)
    {
        out<< "[" << el.first << ", " << el.second <<"]"<<std::endl;
    }

    return out;
}

std::ostream &operator<<(std::ostream &out, const std::vector<int> &dates)
{
    out << "[";
    for(auto &el:dates)
    {
        out << el << ", ";
    }
    out << "]";
    return out;
}

std::ostream &operator<<(std::ostream &out, const std::pair<int, int> &dates)
{
    auto[currency, rate] = dates;
    out << "[" << currency << " , " << rate <<"]" << std::endl;
    //out << "[" << dates.first << " , " << dates.second <<"]" << std::endl;
    return out;
}

std::ostream &operator<<(std::ostream &out, const Histogram &hist)
{
    for(auto &el : hist.bins_)
    {
        out << "[" << el.first << ", " << el.second << "]" << std::endl;
    }
    return out;
}

std::istream &operator>>(std::istream &in, Histogram &hist){
    int el;
    int value;
    std::cout << "Ile wynikow chcesz wprowadzic?:";
    in >> el;
    for (int i = 0; i<el;i++)
    {
        in >> value;
        hist.emplace(value);
    }
    return in;
}

void print(const std::vector<std::pair<int, int> > &a)
{
    for (auto &el :a)
    {
        std::cout<< "[" << el.first << ", " << el.second <<"]"<<std::endl;
    }
}
