#pragma once
#include "Entity.h"


class Ufo :
    public Entity
{
private:
    sf::Clock Witam;
    sf::Clock Czesc;
    int randomx;
    float velocity_ufo = 100;
    void bounce();
public:
    
    Ufo(float x, float y, sf::Texture* texture);
    virtual ~Ufo();

    void update(const sf::Time &elapsed);

    void render(sf::RenderTarget& target);
};

