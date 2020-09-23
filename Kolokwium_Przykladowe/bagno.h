#ifndef BAGNO_H
#define BAGNO_H
#include "abstrakt.h"


class Bagno : public Abstrakt
{
private:
    float scale = 0.15;
    sf::Clock Witam;
public:
    Bagno(float x, float y, sf::Texture * texture);
    void update(const sf::Time &elapsed);
    void render(sf::RenderTarget &target);
};

#endif // BAGNO_H
