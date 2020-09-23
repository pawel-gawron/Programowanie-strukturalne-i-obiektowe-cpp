#include "background.h"

background::background(){

}

background::background(sf::Texture &texture, sf::IntRect &size){
    setTexture(texture);
    setTextureRect(size);
}
