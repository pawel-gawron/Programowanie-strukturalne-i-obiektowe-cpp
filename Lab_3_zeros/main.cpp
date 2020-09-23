#include <iostream>
#include <vector>
#include <cmath>
#include <stdlib.h>
using namespace std;

vector <double> p;
void get_poly(int n)
{

    cout << "Prosze podac wspolczynniki wielomianu postaci y(x) = p0 + p1x + p2x^2 + ... + pnx^n" << endl;
    double wspolczynnik;
    for (int i = 0; i<n; i++)
    {
        cout << "p" << i << "=";
        cin >> wspolczynnik;
        p.push_back(wspolczynnik);
    }
}

double poly(double x)
{
    double res = 0;
    for (size_t i = 0; i!=p.size(); i++)
    {
        res+=p[i]*pow(x,i);
    }
    return res;
}

void zero_r(double bottom, double top);

vector <double> zeros;
vector <double> zmiana;
void zero(double x_min, double x_max, double step)
{
    for(double i=x_min; i<=x_max; i = i+step)
    {
        if(poly(i)==0)
        {
            zeros.push_back(i);
        }
        zmiana.push_back(poly(i));
    }

    for(unsigned int j =0; j<zmiana.size();j++)
    {
        if ((zmiana[j]<0+(1e-9) && zmiana[j+1] >0) || (zmiana[j]>0+(1e-9) && zmiana[j+1] <0))
        {
            zero_r(x_min+j,x_min+j+step);
        }
    }
}

void zero_r(double bottom, double top)
{
    double middle;
    while((top>=bottom) && abs(top-bottom)>(1e-9))
    {
        middle = (bottom+top)/2;
        if(poly(middle)==0)
        {
            cout << "Miejsce zerowe: " << middle << endl;
        }
        if(poly(middle) > 0)
        {
            top = middle;
        }
        if(poly(middle) < 0)
        {
            bottom = middle;
        }
    }
    zeros.push_back(middle);
}

int main()
{
    get_poly(5);
    zero(-10,10,0.1);
    for(size_t i=0; i!=zeros.size();i++) cout << zeros[i] << endl;
    return 0;
}
