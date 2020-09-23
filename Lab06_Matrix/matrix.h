#ifndef MATRIX_H
#define MATRIX_H
#include <vector>
#include <tuple>
#include <utility>
#include <random>
#include <iostream>
#include <algorithm>

template <typename T>
class Matrix
{
private:
    unsigned rows;
    unsigned columns;
    int it = 0;
    std::vector<std::vector<T> > mat;
    std::vector<std::vector<T>> res;
public:
    Matrix()
    {

    }
    Matrix(std::vector<std::vector<T>> numbers_arg)
    {
        mat=numbers_arg;
        for (auto &col : numbers_arg)
        {

            std::cout << "| ";

            for (auto &row : col)
            {
                it++;
                std::cout << row << " ";
            }
            std::cout << "|"<< std::endl;

        }
        if(numbers_arg.size())
        it = it / numbers_arg.size();
        std::cout <<"rozmiar wierszy: " << it << std::endl;
        std::cout <<"rozmiar kolumny: " << numbers_arg.size() << std::endl;
    }

    Matrix(int rows, int columns)
    {
        mat.resize(rows);
        for (auto &el:mat)
        {
            el.resize(columns,0);
        }
    }
    friend Matrix &operator>>(std::istream &in, Matrix &mat)
    {
        T el;
        int col, row;
        std::cout << "liczba wierszy " << std::endl;
        in >> col;
        std::cout << "liczba kolumn: " << std::endl;
        in >> row;
        std::vector<T> temp;
        std::vector<std::vector<T>> Temp2;

        for (int j=0; j<col; j++) {
            temp.clear();
            for (int k=0; k<row; k++){
                std::cout << j+1 <<" , " << k+1 << ":"<< std::endl;
                in>>el;
                temp.push_back(el);

            }
            Temp2.push_back(temp);
        }
        std::cout<<"Twoja macierz: "<<std::endl;
        Matrix temp_mat(Temp2);
        temp.clear();
        Temp2.clear();
        return temp_mat;
    }
    friend std::ostream &operator<<(std::ostream &out, Matrix &mat)
    {
        for(auto &el : mat.mat)
        {
            out << "|";

            for(auto &val : el)
            {
                out << val << " ";
            }
            out << "|" << std::endl;
        }
        return out;
    }
    static Matrix eye(const int &rows, const int &columns)
    {
        std::vector<int> temp;
        std::vector<std::vector<int>> Temp2;
        for (int j=0; j<rows; j++) {

            temp.clear();
            for (int k=0; k<rows; k++){

                if(j==k) {
                    temp.push_back(1);
                }
                else {
                    temp.push_back(0);
                }
            }
            Temp2.push_back(temp);
        }
        Matrix temp_mat(Temp2);
        temp.clear();
        Temp2.clear();
        return temp_mat;
    }
    static Matrix fill(const int &rows, const int &columns, bool rand);
    friend Matrix &operator*(int val, Matrix &m)
    {
        for(auto &col: m.mat)
        {
            for(auto &row :col)
            {
                row=row*val;
            }
        }
        return m;
    }
    //    friend Matrix &operator*(Matrix &n, Matrix &m)
    //    {
    //        for(auto &coln: n.mat)
    //        {
    //            for(auto &rown:coln)
    //            {
    //                for(auto &colm: m.mat)
    //                {
    //                    for(auto &rowm: colm)
    //                    {
    //                        Matrix sum(3,3);

    //                    }
    //                }
    //            }
    //        }
    //        return m;
    //    }
    friend Matrix &operator*(Matrix &n, int val)
    {
        for(auto &col: n.mat)
        {
            for(auto &row :col)
            {
                row=row*val;
            }
        }
        return n;
    }
    friend Matrix &operator+(Matrix &n, int val)
    {
        for(auto &col: n.mat)
        {
            for(auto &row :col)
            {
                row=row+val;
            }
        }
        return n;
    }

    friend Matrix &operator+(int val, Matrix &n)
    {
        for(auto &col: n.mat)
        {
            for(auto &row :col)
            {
                row=row+val;
            }
        }
        return n;
    }
};

#endif // MATRIX_H
