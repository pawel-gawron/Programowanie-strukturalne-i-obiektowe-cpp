// https://www.codingame.com/ide/puzzle/happy-numbers
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int N;
    cin >> N; cin.ignore();
    for (int i = 0; i < N; i++) {
        string x;
        getline(cin, x);
        cerr << x << endl;
        double sum;
        int iterator =0;
        string x1 = x;
        do{
        sum = 0;
        for(int i = 0; i != x1.length(); i++)
        {

            int X = (int)x1[i]-48;
            cerr << "X^2: " << X*X << endl;
            sum += pow(X,2);
        }

        x1 = to_string(sum).substr(0,to_string(sum).size()-7);
        iterator++;
        if(iterator==10)
        {
            break;
        }
        }while(sum!=1);

        if (sum ==1)
        cout << x << " :)" << endl;
        else
        cout << x << " :(" << endl;
    }

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
}
