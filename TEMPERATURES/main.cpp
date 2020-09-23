// https://www.codingame.com/ide/puzzle/temperatures
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
bool sortbysec(const pair<int,float> &a,
              const pair<int,float> &b)
{
    return (a.second < b.second);
}

int main()
{
    int n; // the number of temperatures to analyse
    cin >> n; cin.ignore();
    int result;
    vector<pair<int, float>> temperatures;

    for (int i = 0; i < n; i++) {
        int t; // a temperature expressed as an integer ranging from -273 to 5526
        cin >> t; cin.ignore();
        float b;
        if (t<0)
        b = t-0.5;
        else
        b = t;
        temperatures.push_back( make_pair(t,abs(b)) );

    }
    sort(temperatures.begin(), temperatures.end(), sortbysec);

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    if(!temperatures.empty())
    cout << temperatures.front().first;
    else
    cout << "0" << endl;
}
