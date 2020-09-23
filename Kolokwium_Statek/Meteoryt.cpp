#include "Meteoryt.h"
#include <iostream>
Meteoryt::Meteoryt(float x, float y, sf::Texture* texture)
{
		this->setTexture(*texture);
		this->setPosition(x, y);
		this->Sprite.setScale(0.5, 0.5);
		this->Sprite.setRotation(180);
		this->Sprite.scale(-1.f, 1.f);
		this->type = 1;
}

Meteoryt::~Meteoryt()
{
}

void Meteoryt::update(const sf::Time &elapsed)
{

    if (Witam2.getElapsedTime().asSeconds()>2)
    {
        velocity_meteoryt+= 100;
        Witam2.restart();
    }
    this->Sprite.move(0.f, this->velocity_meteoryt * elapsed.asSeconds());
}

void Meteoryt::render(sf::RenderTarget& target)
{
	target.draw(this->Sprite);
}
