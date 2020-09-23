#ifndef DUCH_H
#define DUCH_H

#include "ruchomysprite.h"


class Duch : public RuchomySprite
{
private:
    int velocity_x_;
public:
    Duch(float x, float y, sf::Texture* texture, int velocity_x);
    void animuj(const sf::Time &elapsed, sf::RenderTarget &target);
    void render(sf::RenderTarget &target);
};

#endif // DUCH_H
