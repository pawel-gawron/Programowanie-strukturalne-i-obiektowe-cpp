#include "pacman.h"

PacMan::PacMan(float x, float y, sf::Texture *texture, int velocity_x, int velocity_y)
{
    this->setTexture(*texture);
    this->setPosition(x, y);
    this->velocity_y_ = velocity_y;
    this->velocity_x_ = velocity_x;
    this->hp = 3;
    this->points = 0;
}

void PacMan::render(sf::RenderTarget &target)
{
    target.draw(this->Sprite);
}

void PacMan::animuj(const sf::Time &elapsed, sf::RenderTarget &target)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        velocity_x_ = -150.f;
        velocity_y_ = 0.f;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        velocity_x_ = 150.f;
        velocity_y_ = 0.f;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        velocity_x_ = 0.f;
        velocity_y_ = -150.f;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        velocity_x_ = 0.f;
        velocity_y_ = 150.f;
    }

    if(this->Sprite.getGlobalBounds().left+this->Sprite.getGlobalBounds().width > target.getSize().x)
    {
        velocity_x_ = -std::abs(velocity_x_);
    }
    if(this->Sprite.getGlobalBounds().top < 0)
    {
        velocity_y_ = std::abs(velocity_y_);
    }
    if(this->Sprite.getGlobalBounds().top+this->Sprite.getGlobalBounds().height > target.getSize().y)
    {
        velocity_y_ = -std::abs(velocity_y_);
    }
    this->move(velocity_x_*elapsed.asSeconds(), velocity_y_ * elapsed.asSeconds());
}

void PacMan::setupEdge(int left_edge_, int right_edge, int top_edge_, int bottom_edge_)
{
    edge.top = top_edge_;
    edge.bottom = bottom_edge_;
    edge.left = left_edge_;
    edge.right = right_edge;
}
