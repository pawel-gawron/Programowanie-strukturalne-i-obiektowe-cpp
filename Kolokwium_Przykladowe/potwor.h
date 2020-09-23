#ifndef POTWOR_H
#define POTWOR_H
#include "abstrakt.h"

class Potwor : public Abstrakt
{
private:
    sf::Clock Witam;
    sf::Clock Czesc;
    int randomx = rand() % 200 - 100;
    int randomy = rand() % 200 - 100;
    void bounce();
public:
    Potwor(float x, float y, sf::Texture* texture);
    void update(const sf::Time &elapsed);
    void render(sf::RenderTarget &target);
};

#endif // POTWOR_H
