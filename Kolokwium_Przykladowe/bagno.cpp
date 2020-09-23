#include "bagno.h"

Bagno::Bagno(float x, float y, sf::Texture *texture)
{
    this->setTexture(*texture);
    this->setPosition(x, y);
    this->Sprite.setScale(scale, scale);
    this->Sprite.scale(-1.f, 1.f);
    this->type = 1;
}

void Bagno::update(const sf::Time &elapsed)
{
    this->Sprite.setOrigin(this->Sprite.getGlobalBounds().width/2, this->Sprite.getGlobalBounds().height/2);
    if (Witam.getElapsedTime().asSeconds()>1)
    {
        this->scale+= 0.01;
        Witam.restart();
    }
    this->Sprite.setScale(scale, scale);
}

void Bagno::render(sf::RenderTarget &target)
{
    target.draw(this->Sprite);
}
