#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

enum class TypRosliny { Owoc, Warzywo };

struct Roslina
{
    TypRosliny typ;
    string nazwa;
};

using Koszyk = vector<Roslina>;
Koszyk koszyk;
Koszyk koszyk2;
Koszyk koszyk_wspolne;
Koszyk koszyk_rozne;
Koszyk wielki_koszyk;

std::ostream& operator<<(std::ostream& out, const Roslina& roslina)
{
    vector<string> roslina_str = {"Owoc", "Warzywo"};
    out << roslina_str[static_cast<int>(roslina.typ)] << " - " << roslina.nazwa << endl;
    return out;
}

std::ostream& operator<<(std::ostream& out, const Koszyk &koszyk)
{
    for (auto it=koszyk.begin(); it!=koszyk.end(); it++)
    {
        cout << *it;
    }
    return out;
}

bool operator<(const Roslina& r1, const Roslina& r2)
{
    return r1.typ<r2.typ;
}

void czy_jest_gruszka(const Koszyk& koszyk)
{
    auto f = find_if(koszyk.begin(), koszyk.end(), [](const Roslina& roslina){return roslina.nazwa == "gruszka";});
    if (f != koszyk.end()) cout << "koszyk zawiera gruszke " << endl;
    else cout << "koszyk nie zawiera gruszki " << endl;
}

bool czy_same_owoce(const Koszyk &koszyk)
{
    return all_of(koszyk.begin(), koszyk.end(), [](const Roslina &roslina){ return roslina.typ == TypRosliny::Owoc;});
}

bool czy_same_warzywa(const Koszyk &koszyk)
{
    return all_of(koszyk.begin(), koszyk.end(), [](const Roslina &roslina){ return roslina.typ == TypRosliny::Warzywo;});
}

bool czy_co_najmniej_jeden_owoc(const Koszyk &koszyk)
{
    return any_of(koszyk.begin(), koszyk.end(), [](const Roslina &roslina){ return roslina.typ == TypRosliny::Owoc;});
}

bool czy_co_najmniej_jedno_warzywo(const Koszyk &koszyk)
{
    return any_of(koszyk.begin(), koszyk.end(), [](const Roslina &roslina){ return roslina.typ == TypRosliny::Warzywo;});
}

bool zadnego_owocu(const Koszyk &koszyk)
{
    return none_of(koszyk.begin(), koszyk.end(), [](const Roslina &roslina){ return roslina.typ == TypRosliny::Owoc;});
}

bool zadnego_warzywa(const Koszyk &koszyk)
{
    return none_of(koszyk.begin(), koszyk.end(), [](const Roslina &roslina){ return roslina.typ == TypRosliny::Warzywo;});
}

int zlicz_owoce(const Koszyk &koszyk)
{
    return count_if(koszyk.begin(), koszyk.end(), [](const Roslina& roslina) { return roslina.typ == TypRosliny::Owoc;});
}

int zlicz_warzywa(const Koszyk &koszyk)
{
    return count_if(koszyk.begin(), koszyk.end(), [](const Roslina& roslina) { return roslina.typ == TypRosliny::Warzywo;});
}

void usun_jezeli(Koszyk &koszyk)
{
    koszyk.erase(remove_if(koszyk.begin(), koszyk.end(), [](Roslina& roslina){return roslina.nazwa[0] == 'G'|| roslina.nazwa[0] == 'g';}));
}

void wspolny_koszyk(Koszyk &koszyk, Koszyk &koszyk2)
{
    sort(koszyk.begin(), koszyk.end());
    sort(koszyk2.begin(), koszyk2.end());

    set_intersection(koszyk.begin(), koszyk.end(),
                    koszyk2.begin(), koszyk2.end(),
                    back_inserter(koszyk_wspolne));
    cout << "Wspolny koszyk: " <<koszyk_wspolne << endl;
}

void rozny_koszyk(Koszyk &koszyk, Koszyk &koszyk2)
{
    sort(koszyk.begin(), koszyk.end());
    sort(koszyk2.begin(), koszyk2.end());

    set_difference(koszyk.begin(), koszyk.end(),
                   koszyk2.begin(), koszyk2.end(),
                   inserter(koszyk_rozne, koszyk_rozne.begin()));
    cout << "Rozny koszyk: " <<koszyk_rozne << endl;
}

void koncowy_koszyk(Koszyk &koszyk, Koszyk &koszyk2)
{
    set_union(koszyk.begin(), koszyk.end(),
                           koszyk2.begin(), koszyk2.end(),
                           back_inserter(wielki_koszyk));
    cout << "Wielki koszyk: " << wielki_koszyk << endl;
}

int main()
{
    Roslina jablko;
    jablko.typ = TypRosliny::Owoc;
    jablko.nazwa = "jablko";
    koszyk.push_back(jablko);

    Roslina marchew;
    marchew.typ = TypRosliny::Warzywo;
    marchew.nazwa = "marchew";
    koszyk.push_back(marchew);

    Roslina gruszka;
    gruszka.typ = TypRosliny::Owoc;
    gruszka.nazwa = "gruszka";
    koszyk.push_back(gruszka);

    Roslina pomidor;
    pomidor.typ = TypRosliny::Owoc;
    pomidor.nazwa = "pomidor";
    koszyk.push_back(pomidor);

    koszyk2.push_back(marchew);
    koszyk2.push_back(gruszka);
    koszyk2.push_back(jablko);


    for (auto it=koszyk.begin(); it!=koszyk.end(); it++)
    {
        cout << *it;
    }
    cout << koszyk;
    czy_jest_gruszka(koszyk);
    cout << "Czy sa same owoce: " << czy_same_owoce(koszyk) << endl;
    cout << "Czy sa same warzywa: " << czy_same_warzywa(koszyk) << endl;
    cout << "Czy jest co najmniej jeden owoc: " << czy_co_najmniej_jeden_owoc(koszyk) << endl;
    cout << "Czy jest co najmniej jendo warzywo: " << czy_co_najmniej_jedno_warzywo(koszyk) << endl;
    cout << "Zadnego owocu: " << zadnego_owocu(koszyk) << endl;
    cout << "Zadnego warzywa: " << zadnego_warzywa(koszyk) << endl;
    cout << "Ilosc owocow: " << zlicz_owoce(koszyk) << endl;
    cout << "Ilosc warzyw: " << zlicz_warzywa(koszyk) << endl;
    //usun_jezeli(koszyk);
    cout << koszyk;
    czy_jest_gruszka(koszyk);

    wspolny_koszyk(koszyk, koszyk2);
    rozny_koszyk(koszyk, koszyk2);
    koncowy_koszyk(koszyk, koszyk2);

    return 0;
}
