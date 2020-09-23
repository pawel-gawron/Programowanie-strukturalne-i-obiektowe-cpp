#include "hero.h"

hero::hero(){

}

hero::hero(sf::Texture &textures){
    setTexture(textures);
}

void hero::animate(const sf::Time &elapsed){
    
    sf::FloatRect hero_bounds = getGlobalBounds();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        if(hero_bounds.left > edge.left)
        {
            move(-velocity_x_*elapsed.asSeconds(), 0);
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        if(hero_bounds.left+hero_bounds.width < edge.right)
        {
            move(velocity_x_*elapsed.asSeconds(), 0);
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) &&
       onGround)
    {
        if(hero_bounds.left+hero_bounds.width < edge.right)
        {
            move(0, -600*elapsed.asSeconds());
        }
    }
        move(0, velocity_y_*elapsed.asSeconds());
   
}

void hero::setBounds(int l_bound, int r_bound, int t_bound, int b_bound){
    edge.top = t_bound;
    edge.bottom = b_bound;
    edge.left = l_bound;
    edge.right = r_bound;
}
