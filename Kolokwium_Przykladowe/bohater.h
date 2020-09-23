#ifndef BOHATER_H
#define BOHATER_H
#include "abstrakt.h"

struct Edge
{
    int top = 0;
    int bottom = 0;
    int left = 0;
    int right = 0;
};

class Bohater : public Abstrakt
{
private:
    void bounce();
public:
    Edge edge;
    Bohater(float x, float y,  sf::Texture* texture);
    void render(sf::RenderTarget& target);
    void update(const sf::Time &elapsed);
    void handleInput(const sf::Time &elapsed);
    int hp;
    void setupEdge(int left_edge_, int right_edge, int top_edge_, int bottom_edge_);
};

#endif // BOHATER_H
