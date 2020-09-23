#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include <vector>
#include <map>
#include <iostream>
#include <utility>

class Histogram
{
private:
    using Bin = int;
    using Frequency = int;
    std::map<Bin, Frequency> bins_;
    std::vector<int> points;
    std::string point_str;
    int point;
    //    using BinsVector = std::vector<std::pair<int,int>>;
public:
    Histogram();//
    Histogram(const std::vector<int> &dates);//
    void emplace(int i);//
    void emplace(const std::vector<int> &dates);//
    void from_csv(std::string filename,char delimeter,int column);//
    void clear();//
    std::pair<Bin, Bin> range() const;//
    std::pair<int, int> max() const;//
    std::vector<int> unique_bins() const;//
    std::vector<std::pair<int, int>> unique_items() const;//
    Histogram &operator<<(int val);//
    operator std::vector<std::pair<Bin, Frequency>>();//
    int operator[](int i) const;//
    friend std::istream &operator>>(std::istream &in, Histogram &hist);//
    friend std::ostream &operator<<(std::ostream &out, const Histogram &hist);//
    static Histogram generate(int min, int max);//
};
void print(const std::vector<std::pair<int,int>> &a);//
std::ostream& operator<<(std::ostream& os, const std::pair<int,int> &a);//
std::ostream& operator<<(std::ostream& os, const std::vector<int> &a);//
std::ostream& operator<<(std::ostream& os, const std::vector<std::pair<int, int>> &a);//

#endif // HISTOGRAM_H
