#ifndef RUCHOMYSPRITE_H
#define RUCHOMYSPRITE_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include <vector>


class RuchomySprite : public sf::Sprite
{
public:
    int type = 0;
    RuchomySprite();
    virtual ~RuchomySprite();
    sf::Sprite Sprite;
    virtual void setTexture(sf::Texture& texture);
    virtual void setPosition(const float x, const float y);
    virtual void render(sf::RenderTarget& target) = 0;
    virtual void animuj(const sf::Time &elapsed, sf::RenderTarget &target) = 0;
    virtual void move(const float x, const float y);
};

#endif // RUCHOMYSPRITE_H
