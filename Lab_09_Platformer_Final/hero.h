#ifndef HERO_H
#define HERO_H

#include "elementsceny.h"

class hero : public ElementSceny
{
private:
    Edge edge;
    float velocity_x_ = 400;
    float velocity_y_ = 400;
public:
    
    hero();
    hero(sf::Texture &textures);
    //virtual sf::Texture loadTexture(std::string filename_with_path);
    void animate(const sf::Time &elapsed);
    void setBounds(int l_bound, int r_bound, int t_bound, int b_bound);
};

#endif // HERO_H
