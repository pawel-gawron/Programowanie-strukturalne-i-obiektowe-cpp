#ifndef OBJECT_H
#define OBJECT_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

class object : public sf::Sprite
{
public:
    object(sf::Texture &textures, float x_, float y_, const sf::IntRect &Bounds_);
};

#endif // OBJECT_H
