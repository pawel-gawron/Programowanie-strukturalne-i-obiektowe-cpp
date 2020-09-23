#pragma once
#include "Entity.h"

struct Edge
{
    int top = 0;
    int bottom = 0;
    int left = 0;
    int right = 0;
};

class StatekKosmiczny : public Entity
{
private:
public:
    StatekKosmiczny(float x, float y, sf::Texture* texture);
    virtual ~StatekKosmiczny();
    Edge edge;
    int hp;
    int hp2;
    void handleInput(const sf::Time &elapsed);
    void update(const sf::Time &elapsed);
    void render(sf::RenderTarget& target);
    void setupEdge(int left_edge_, int right_edge, int top_edge_, int bottom_edge_);
};

