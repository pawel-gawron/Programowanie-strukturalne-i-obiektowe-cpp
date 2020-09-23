#include <iostream>
#include <vector>

using namespace std;

long long factorial_r(int n)
{
    if(n>0)
    {
        return n*factorial_r(n-1);
    }
    else
    {
        return 1;
    }
}

bool is_palindrome(string napis)
{
    int i = 0;
    int j = napis.size()-1;
            while(i<j)
    {
        if(napis[i]!=napis[j]) return false;

        i++;
        j--;
    }
    return true;
}

vector<string> split(string text, char sep=' ');
vector<string> split(string text, char sep)
{
   vector<string> results;

   do()
   {
       string word = substring(...);
       results.emplace_back(word);
   }while(...)

   return results;
}

int main()
{
    /*
    for (int i=1; i<40; i++)
    {
        if (i!=factorial_r(i)/factorial_r(i-1))
        {
            exit(0);
        }
        else cout << i << " " << factorial_r(i)  << endl;

    }
    */

    string napis= "ala ma kota i kota i kota";
    cout << napis << endl;
    string napis2 = napis;
    //cout << "12345" << napis[0] << endl;
    //napis[0] = "A";
    for (unsigned int i = 0; i < napis.size(); i++)
    {
        cout << napis[i] << endl;
    }

    cout << is_palindrome(napis) << endl;

    size_t position = 0;
    do
    {
        position = napis.find("kota", position);
        cout << position << endl;
        if(position!=string::npos)
        {
            position++;
        }
    }while(position!=string::npos);

    return 0;
}
