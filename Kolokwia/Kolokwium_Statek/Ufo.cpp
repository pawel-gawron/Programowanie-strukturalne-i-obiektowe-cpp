#include "Ufo.h"

void Ufo::bounce()
{
    if(this->Sprite.getGlobalBounds().left < 0)
    {
        randomx = std::abs(randomx);
    }

    if(this->Sprite.getGlobalBounds().left+this->Sprite.getGlobalBounds().width > 800)
    {
        randomx = -std::abs(randomx);
    }
}

Ufo::Ufo(float x, float y, sf::Texture* texture)
{
    this->setTexture(*texture);
    this->setPosition(x, y);
    //this->Sprite.setOrigin(85, 0);
    this->Sprite.setScale(0.5, 0.5);
    this->type = 2;
}

Ufo::~Ufo()
{
}

void Ufo::update(const sf::Time &elapsed)
{
    if (Czesc.getElapsedTime().asMilliseconds() > 250)
    {
        randomx = rand() % 200 - 100;
        Czesc.restart();
    }
    if (Witam.getElapsedTime().asSeconds()> 2)
    {
        velocity_ufo+= 100;
        Witam.restart();
    }
    this->bounce();
    this->Sprite.move(randomx * elapsed.asSeconds(), this->velocity_ufo * elapsed.asSeconds());
}

void Ufo::render(sf::RenderTarget& target)
{
    target.draw(this->Sprite);
}
