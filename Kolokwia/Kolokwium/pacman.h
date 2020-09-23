#ifndef PACMAN_H
#define PACMAN_H

#include "ruchomysprite.h"

struct Edge
{
    int top = 0;
    int bottom = 0;
    int left = 0;
    int right = 0;
};

class PacMan : public RuchomySprite
{
private:
    int velocity_x_;
public:
    Edge edge;
    PacMan(float x, float y,  sf::Texture* texture, int velocity_x);
    void render(sf::RenderTarget& target);
    void animuj(const sf::Time &elapsed, sf::RenderTarget &target);
    void setupEdge(int left_edge_, int right_edge, int top_edge_, int bottom_edge_);
};

#endif // PACMAN_H
