#include "guy.h"

void guy::setupEdge(int left_edge_, int right_edge, int top_edge_, int bottom_edge_)
{
    edge.top = top_edge_;
    edge.bottom = bottom_edge_;
    edge.left = left_edge_;
    edge.right = right_edge;
}

void guy::reflection(sf::FloatRect borders)
{
        
    if(getGlobalBounds().top <= borders.top)
    {
        setPosition(getPosition().x, getPosition().y-1 );
    }

   if(getGlobalBounds().top + getGlobalBounds().height >= borders.top+borders.height)
    {
        setPosition(getPosition().x, getPosition().y+1);
    }

    
    if(getGlobalBounds().left + getGlobalBounds().width >= borders.left  && sf::Keyboard::isKeyPressed(sf::Keyboard::Right ))
    {
        setPosition(getPosition().x-1, getPosition().y);
    }
    
    if(getGlobalBounds().left <= borders.left+borders.width && sf::Keyboard::isKeyPressed(sf::Keyboard::Left) )
    {
        velocity_x_ = -velocity_x_;
        setPosition(getPosition().x+1, getPosition().y);
    }
}

guy::guy(sf::Texture &texture)
{
    setTexture(texture);
}

void guy::modification(const sf::Time &elapsed)
{

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        if(getGlobalBounds().top > edge.top)
        {
            move(0, -200*elapsed.asSeconds());
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        if(getGlobalBounds().top+getGlobalBounds().height < edge.bottom)
        {
            move(0, 200*elapsed.asSeconds());
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        if(getGlobalBounds().left > edge.left)
        {
            move(-200*elapsed.asSeconds(), 0);
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        if(getGlobalBounds().left+getGlobalBounds().width < edge.right)
        {
            move(200*elapsed.asSeconds(), 0);
        }
    }
}
