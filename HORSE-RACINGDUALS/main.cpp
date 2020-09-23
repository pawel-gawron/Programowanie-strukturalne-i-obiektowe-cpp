// https://www.codingame.com/ide/puzzle/horse-racing-duals
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int N;
    cin >> N; cin.ignore();
    vector <int> difference;
    vector <int> final;
    int value;
    for (int i = 0; i < N; i++) {
        int Pi;
        cin >> Pi; cin.ignore();
        difference.push_back(Pi);
    }
    sort(difference.begin(),difference.end());

    for (auto i = difference.begin()+1; i!=difference.end(); i++)
    {
           value = abs(*i-*(i-1));
           final.push_back(value);
    }

    auto min = min_element(final.begin(), final.end());

    //std::vector<int>::iterator result = min_element(final.begin(), final.end());

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << *min << endl;
}
