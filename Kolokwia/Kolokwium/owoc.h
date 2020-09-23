#ifndef OWOC_H
#define OWOC_H

#include "ruchomysprite.h"


class Owoc : public RuchomySprite
{
private:
    int velocity_y_;
public:
    Owoc(float x, float y, sf::Texture * texture, int velocity_y);
    void animuj(const sf::Time &elapsed, sf::RenderTarget &target);
    void render(sf::RenderTarget &target);
};

#endif // OWOC_H
