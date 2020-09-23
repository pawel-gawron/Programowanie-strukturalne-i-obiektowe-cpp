#include "ruchomysprite.h"

RuchomySprite::RuchomySprite()
{

}

RuchomySprite::~RuchomySprite()
{

}

void RuchomySprite::setTexture(sf::Texture &texture)
{
    this->Sprite.setTexture(texture);
}

void RuchomySprite::setPosition(const float x, const float y)
{
    this->Sprite.setPosition(x, y);
}

void RuchomySprite::move(const float x, const float y)
{
    this->Sprite.move({ x, y });
}
