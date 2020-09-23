#include <iostream>
#include <cmath>
#include "funkcje.h"

using namespace std;

int if_prime(int A)
{
    bool if_diviser = false;
    for (int i = 2; i<sqrt(A) && if_diviser == false; i++)
    {
        if(A % i == 0)
        {
            if_diviser = true;
        }
    }
    return !if_diviser;
}

double stop_at=0.0001;
double pi(int n)
{
    double acc = 0;

    for (int i = 1; i <=n;i++)
    {
        if (stop_at < abs((pow(-1, i +1)/static_cast<double>(2*i-1))))
        {
        acc = acc + pow(-1, i +1)/static_cast<double>(2*i-1);
        }
    }
    return acc*4;
}
int linia = 0;

void draw_square(int d,bool left_diagonal, bool right_diagonal)
{
    for(int i=1; i<=pow(d,2);i++){

   if(i<=d||i>pow(d,2)-d||i%d==1||i%d==0||(left_diagonal&&i==d*linia+linia+1)||(right_diagonal  && i==d*linia-linia+d))
    {
        cout<<"#";
    }
    else
    {
        cout<<" ";
    }
    if(i%d==0)
    {
        cout<<endl;
        linia++;

    }
    }
}
