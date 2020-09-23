#include "potwor.h"

void Potwor::bounce()
{
    if(this->Sprite.getGlobalBounds().left < 0)
    {
        randomx = std::abs(randomx);
    }

    if(this->Sprite.getGlobalBounds().left+this->Sprite.getGlobalBounds().width > 800)
    {
        randomx = -std::abs(randomx);
    }
    if(this->Sprite.getGlobalBounds().top < 0)
    {
        randomy = std::abs(randomy);
    }

    if(this->Sprite.getGlobalBounds().top+this->Sprite.getGlobalBounds().height > 800)
    {
        randomy = -std::abs(randomy);
    }
}

Potwor::Potwor(float x, float y, sf::Texture *texture)
{
    this->setTexture(*texture);
    this->setPosition(x, y);
    this->Sprite.setScale(0.1, 0.1);
    this->type = 2;
}

void Potwor::update(const sf::Time &elapsed)
{
    if (Czesc.getElapsedTime().asSeconds() > 1)
    {
        randomx = rand() % 200 - 100;
        Czesc.restart();
    }
    if (Witam.getElapsedTime().asSeconds()> 1)
    {
        randomy = rand() % 200 - 100;
        Witam.restart();
    }
    this->bounce();
    this->Sprite.move(randomx * elapsed.asSeconds(), randomy * elapsed.asSeconds());

}

void Potwor::render(sf::RenderTarget &target)
{
    target.draw(this->Sprite);
}
