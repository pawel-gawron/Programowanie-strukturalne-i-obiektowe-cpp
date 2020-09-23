#ifndef ABSTRAKT_H
#define ABSTRAKT_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include <vector>

class Abstrakt : public  sf::Sprite
{
public:
    //static std::vector<Abstrakt*> PRZESZKODY;
    sf::Sprite Sprite;
    int velocity = 1;
    virtual ~Abstrakt();
    Abstrakt();
    virtual void setTexture(sf::Texture& texture);
    int type = 0;
    virtual void setPosition(const float x, const float y);
    virtual void move(const float x, const float y);
    virtual void update(const sf::Time &elapsed) = 0;
    virtual void render(sf::RenderTarget& target) = 0;
};

#endif // ABSTRAKT_H
