#include "owoc.h"

Owoc::Owoc(float x, float y, sf::Texture *texture, int velocity_y)
{
    this->setTexture(*texture);
    this->setPosition(x, y);
    this->velocity_y_ = velocity_y;
    this->type = 1;
}

void Owoc::animuj(const sf::Time &elapsed, sf::RenderTarget &target)
{
    this->move(0, velocity_y_*elapsed.asSeconds());

    if(this->Sprite.getGlobalBounds().top < 0)
    {
        velocity_y_ = std::abs(velocity_y_);
    }
    if(this->Sprite.getGlobalBounds().top+this->Sprite.getGlobalBounds().height > target.getSize().y)
    {
        velocity_y_ = -std::abs(velocity_y_);
    }
}

void Owoc::render(sf::RenderTarget &target)
{
    target.draw(this->Sprite);
}
