#include "elementsceny.h"

void ElementSceny::bounce(bool flag){

}

ElementSceny::ElementSceny(){

}

void ElementSceny::reflection(sf::FloatRect borders){
    if(getGlobalBounds().top <= borders.top)
    {
        setPosition(getPosition().x, getPosition().y-1 );
        onGround = true;
        velocity_y_ = 0;
    }

   if(getGlobalBounds().top + getGlobalBounds().height >= borders.top+borders.height)
    {
        setPosition(getPosition().x, getPosition().y+1);
        onGround = true;
        velocity_y_ = 0;
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

sf::Texture ElementSceny::loadTexture(std::string filename_with_path){
    sf::Texture texture;
    if (!texture.loadFromFile(filename_with_path)) {
        std::cout << "Could not load texture" << std::endl;
    }
    return texture;
}
