// ZADANIE KONCOWE
#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <regex>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <locale>

using namespace std;

bool sortbysec(const pair<string,int> &a,
              const pair<string,int> &b)
{
    return (a.second < b.second);
}

int main()
{
    map<string, int> words;
    vector<pair<string,int>> sort_words;
    int licznik;
    smatch match;
    fstream input_file("license.txt", std::ios::in);
    if(input_file.is_open()){
          stringstream str_stream;
          str_stream << input_file.rdbuf();
          string full_text = str_stream.str();
          regex re(R"([A-Za-z]{2,})");

                  string text = full_text;
                  transform(text.begin(), text.end(), text.begin(),
                            [](unsigned char c){return tolower(c);});
                  while(std::regex_search(text, match, re))
                  {

                      licznik = words[match[0]]++;
                      words.emplace(match[0], licznik);
                      text = match.suffix();
                  }
    }

    copy(words.begin(), words.end(),
         back_inserter(sort_words));

        sort(sort_words.begin(), sort_words.end(), sortbysec);
        for(auto it = sort_words.begin(); it != sort_words.end(); it++){ //gdzie it jest iteratorem typu: std::map<std::string,int>::iterator
              std::cout<< it->first << " - " << it->second<< std::endl; //wyświetla klucz i wartosc poszczególnych elementów listy
        }

        std::fstream output("GNU.txt", std::ios::out);
        if (output.is_open()) {
              for (auto x = sort_words.begin(); x != sort_words.end(); x++) {
                    output << x->first << " - " << x->second << std::endl;
              }
              output.close();
        }
    return 0;
}
