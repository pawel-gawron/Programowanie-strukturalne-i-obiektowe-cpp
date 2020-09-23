#include "object.h"

object::object(sf::Texture &textures, float x_, float y_, const sf::IntRect &Bounds_)
{
    setTexture(textures);
    setPosition(x_,y_);
    setTextureRect(Bounds_);
}
