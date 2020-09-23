#include "StatekKosmiczny.h"

StatekKosmiczny::StatekKosmiczny(float x, float y, sf::Texture* texture)
{
	this->setTexture(*texture);
	this->setPosition(x, y);
	this->hp = 3;
	this->hp2 = 3;
}

StatekKosmiczny::~StatekKosmiczny()
{
}

void StatekKosmiczny::handleInput(const sf::Time &elapsed)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        if(this->Sprite.getGlobalBounds().left > edge.left)
        {
        this->move(-300.f * elapsed.asSeconds(), 0.f);
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        if(this->Sprite.getGlobalBounds().left+this->Sprite.getGlobalBounds().width < edge.right)
        {
        this->move(300.f * elapsed.asSeconds(), 0.f);
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        if(this->Sprite.getGlobalBounds().top > edge.top)
        {
        this->move(0.f, -300.f * elapsed.asSeconds());
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        if(this->Sprite.getGlobalBounds().top+this->Sprite.getGlobalBounds().height < edge.bottom)
        {
        this->move(0.f, 300.f * elapsed.asSeconds());
        }
    }
}

void StatekKosmiczny::update(const sf::Time &elapsed)
{

    this->handleInput(elapsed);
}

void StatekKosmiczny::render(sf::RenderTarget& target)
{
    target.draw(this->Sprite);
}

void StatekKosmiczny::setupEdge(int left_edge_, int right_edge, int top_edge_, int bottom_edge_)
{
    edge.top = top_edge_;
    edge.bottom = bottom_edge_;
    edge.left = left_edge_;
    edge.right = right_edge;
}
