#ifndef GUY_H
#define GUY_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

struct Edge
{
    int top = 0;
    int bottom = 0;
    int left = 0;
    int right = 0;
};

class guy : public sf::Sprite
{
private:
    float velocity_x_ = 0;
    float velocity_y_ = 0;
    float velocity_o_ = 0;
    
    
public:
    void reflection(sf::FloatRect borders);
    Edge edge;
    guy(sf::Texture &texture);
    void modification(const sf::Time &elapsed);
    void setupEdge(int left_edge_, int right_edge, int top_edge_, int bottom_edge_);
};
#endif // GUY_H
