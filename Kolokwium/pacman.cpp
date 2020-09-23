#include "pacman.h"

PacMan::PacMan(float x, float y, sf::Texture *texture, int velocity_x)
{
    this->setTexture(*texture);
    this->setPosition(x, y);
    this->velocity_x_ = velocity_x;
}

void PacMan::render(sf::RenderTarget &target)
{
    target.draw(this->Sprite);
}

void PacMan::animuj(const sf::Time &elapsed, sf::RenderTarget &target)
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

void PacMan::setupEdge(int left_edge_, int right_edge, int top_edge_, int bottom_edge_)
{
    edge.top = top_edge_;
    edge.bottom = bottom_edge_;
    edge.left = left_edge_;
    edge.right = right_edge;
}
