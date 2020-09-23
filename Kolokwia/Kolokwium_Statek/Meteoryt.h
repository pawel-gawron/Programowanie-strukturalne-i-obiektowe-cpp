#pragma once
#include "Entity.h"
class Meteoryt :
        public Entity
{
private:
    sf::Clock Witam2;
    float velocity_meteoryt = 100;
public:
    Meteoryt(float x, float y, sf::Texture* texture);

    virtual ~Meteoryt();

    void update(const sf::Time &elapsed);

    void render(sf::RenderTarget& target);
};

