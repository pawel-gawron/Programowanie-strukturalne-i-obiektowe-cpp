// https://www.codingame.com/ide/puzzle/credit-card-verifier-luhns-algorithm
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
    int n;
    cin >> n; cin.ignore();

    for (int i = 0; i < n; i++) {
        string card;
        getline(cin, card);
        for(int it=0; it!=card.size(); it++)
        {
        if(card[it]==' ')
        card.erase(it,1);
        }
        cerr<<card<<endl;
        int sum=0;
        for(int xt=card.size()-2; xt>=0; xt-=2)
        {

            int X = ((int)card[xt]-48)*2;
            int Y = 1*(X/10)+X%10;

             cerr << Y << " ";
             sum+=Y;
             sum+=((int)card[xt+1])-48;
        }
        if(sum%10==0)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
    }

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

}
