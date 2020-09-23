// ZADANIE DOMOWE
#include <iostream>
#include <regex>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

//bool Pred(string &a, string &b)
//{
//    if (a == b)
//    {
//        return 1;
//    }
//    else
//    {
//        return 0;
//    }
//}

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
    os << "[";
    for (unsigned int i = 0; i < v.size(); ++i) {
        if(!empty(v[i]))
        {
            os << v[i];
            if (i != v.size() - 1)
                os << ", ";
        }
    }
    os << "]" << endl;
    return os;
}

void homework()
{
    map<string, vector<string>> word_statistics;
    map<string, vector<string>> word_statistics_copy;
    map<string, vector<string>> word_statistics_unique;
    vector <string> stary_klucz;
    vector <string> nowy_klucz;

    smatch match2;
    smatch match;

    fstream plik1("file1.html", ios::in);
    if (plik1.is_open()) {
        stringstream str_stream;
        str_stream << plik1.rdbuf();
        string full_text = str_stream.str();

        regex re(R"(<div class="r"><a href="(https?:\/\/w?w?w?.{1,100})\" ping.{1,5000}((Tel. (\d{2,3} \d{2,3} \d{2,3} \d{2,3}))|(tel.{1,7}(\d{2,3} \d{2,3} \d{2,3} \d{2,3}))))");

        string text = full_text;
        while(regex_search(text, match, re))
        {
            string str1 = match[2];
            string numer_str="";
            for (auto i : str1)
            {
                if(isdigit(i))
                    numer_str+=i;
            }
            str1.clear();
            string key = match[1];
            word_statistics[key].push_back(numer_str);
            text = match.suffix();

        }

        for(auto it = word_statistics.begin(); it != word_statistics.end(); it++)
        {
            stary_klucz.push_back(it->first);
            regex re2(R"(https?:\/\/w{0,}\.?(.+pl))");
            regex_search(it->first, match2, re2);
            string key2 = match2[1];
            vector <string> nowy = it->second;
            for(auto &it : nowy)
            {
                word_statistics_copy[key2].push_back(it);
            }
        }

//        regex re2(R"(https?:\/\/w{0,}\.?(.+pl).+([0-9]{9}))");

//        for(auto &n : stary_klucz){
//            cout << n << endl;
//            string text2 = n;
//            while(regex_search(text2, match2, re2)){
//                nowy_klucz.push_back(match2[1]);
//                text2 = match2.suffix();
//            }
//        }
//        for(auto &it : nowy_klucz)
//        {
//            cout << it << endl;
//        }
    }
    //unique_copy(word_statistics_copy.begin(), word_statistics_copy.end(), word_statistics_unique.begin());

    for(auto it = word_statistics_copy.begin(); it != word_statistics_copy.end(); it++)
    {
        std::cout<< it->first << " - " << it->second<< std::endl;
    }

    std::ofstream output("file1.txt");
    if (output.is_open()) {
        for (auto i = word_statistics_copy.begin(); i != word_statistics_copy.end(); i++)
        {
            output << i->first << " " << i->second;
        }
    }
    output.close();
}
int main() {

    homework();
    return 0;
}
