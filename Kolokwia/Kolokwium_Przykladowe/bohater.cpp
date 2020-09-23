#include "bohater.h"

void Bohater::bounce()
{
    if(this->Sprite.getGlobalBounds().left < edge.left)
    {
        this->Sprite.setPosition(0, edge.right - this->Sprite.getGlobalBounds().height);
    }
    if(this->Sprite.getGlobalBounds().left+this->Sprite.getGlobalBounds().width > edge.right)
    {
        this->Sprite.setPosition(0, edge.right - this->Sprite.getGlobalBounds().height);
    }
    if(this->Sprite.getGlobalBounds().top < edge.top)
    {
        this->Sprite.setPosition(0, edge.right - this->Sprite.getGlobalBounds().height);
    }
    if(this->Sprite.getGlobalBounds().top+this->Sprite.getGlobalBounds().height > edge.bottom)
    {
        this->Sprite.setPosition(0, edge.right - this->Sprite.getGlobalBounds().height);
    }
}

Bohater::Bohater(float x, float y, sf::Texture *texture)
{
    this->setTexture(*texture);
    this->setPosition(x, y);
    this->hp = 100;
    std::cout << "HP:" << this->hp << std::endl;
}

void Bohater::render(sf::RenderTarget &target)
{
    target.draw(this->Sprite);
}

void Bohater::update(const sf::Time &elapsed)
{
    this->handleInput(elapsed);
}

void Bohater::handleInput(const sf::Time &elapsed)
{
    this->bounce();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        this->move(-300.f * elapsed.asSeconds(), 0.f);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        this->move(300.f * elapsed.asSeconds(), 0.f);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        this->move(0.f, -300.f * elapsed.asSeconds());
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        this->move(0.f, 300.f * elapsed.asSeconds());
    }
}

void Bohater::setupEdge(int left_edge_, int right_edge, int top_edge_, int bottom_edge_)
{
    edge.top = top_edge_;
    edge.bottom = bottom_edge_;
    edge.left = left_edge_;
    edge.right = right_edge;
}
