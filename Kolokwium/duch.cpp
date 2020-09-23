#include "duch.h"

Duch::Duch(float x, float y, sf::Texture *texture, int velocity_x)
{
    this->setTexture(*texture);
    this->setPosition(x, y);
    this->velocity_x_ = velocity_x;
}

void Duch::animuj(const sf::Time &elapsed, sf::RenderTarget &target)
{
    this->move(velocity_x_*elapsed.asSeconds(), 0);
    if(this->Sprite.getGlobalBounds().left < 0)
    {
        this->Sprite.setPosition(target.getSize().x, this->Sprite.getPosition().y);
    }
    if(this->Sprite.getGlobalBounds().left+this->Sprite.getGlobalBounds().width > target.getSize().x)
    {
        this->Sprite.setPosition(0, this->Sprite.getPosition().y);
    }
    if(this->Sprite.getGlobalBounds().top < 0)
    {
        this->Sprite.setPosition(this->Sprite.getPosition().x, target.getSize().y);
    }
    if(this->Sprite.getGlobalBounds().top+this->Sprite.getGlobalBounds().height > target.getSize().y)
    {
        this->Sprite.setPosition(this->Sprite.getPosition().x, 0);
    }
}

void Duch::render(sf::RenderTarget &target)
{
    target.draw(this->Sprite);
}
