#include "duch.h"

Duch::Duch(float x, float y, sf::Texture *texture, int velocity_x)
{
    this->setTexture(*texture);
    this->setPosition(x, y);
    this->velocity_x_ = velocity_x;
    this->type = 2;
}

void Duch::animuj(const sf::Time &elapsed, sf::RenderTarget &target)
{
    this->move(velocity_x_*elapsed.asSeconds(), 0);
    if(this->Sprite.getGlobalBounds().left < 0)
    {
        velocity_x_ = std::abs(velocity_x_);
    }
    if(this->Sprite.getGlobalBounds().left+this->Sprite.getGlobalBounds().width > target.getSize().x)
    {
        velocity_x_ = -std::abs(velocity_x_);
    }
}

void Duch::render(sf::RenderTarget &target)
{
    target.draw(this->Sprite);
}
