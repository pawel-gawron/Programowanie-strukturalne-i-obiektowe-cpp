#include "abstrakt.h"

Abstrakt::~Abstrakt()
{

}

Abstrakt::Abstrakt()
{

}

void Abstrakt::setTexture(sf::Texture &texture)
{
    this->Sprite.setTexture(texture);
}

void Abstrakt::setPosition(const float x, const float y)
{
    this->Sprite.setPosition(x, y);
}

void Abstrakt::move(const float x, const float y)
{
    this->Sprite.move({ x, y });
}
