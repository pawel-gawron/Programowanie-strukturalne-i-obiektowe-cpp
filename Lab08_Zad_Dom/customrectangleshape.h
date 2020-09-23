#ifndef CUSTOMRECTANGLESHAPE_H
#define CUSTOMRECTANGLESHAPE_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

struct Bounds
{
    int top = 0;
    int bottom = 0;
    int left = 0;
    int right = 0;
};

class CustomRectangleShape : public sf::RectangleShape
{
private:
    float velocity_x_ = 0;
    float velocity_y_ = 0;
    float velocity_o_ = 0;
    Bounds bounds;
    void bounce();
    bool is_selected = false;
public:
    CustomRectangleShape(sf::Vector2f size, sf::Vector2f position);
    void setSpeed(float velocity_x, float velocity_y, float velocity_o);
    void animate(const sf::Time &elapsed);
    void setBounds(int l_bound, int r_bound, int t_bound, int b_bound);
    void setBounds(const sf::IntRect &rect);
    void select();
    void unselect();
    bool is_clicked(sf::Vector2i mouse_position);
};

#endif // CUSTOMRECTANGLESHAPE_H
