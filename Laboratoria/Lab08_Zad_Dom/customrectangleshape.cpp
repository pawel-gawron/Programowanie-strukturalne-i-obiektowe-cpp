#include "customrectangleshape.h"

CustomRectangleShape::CustomRectangleShape(sf::Vector2f size, sf::Vector2f position)
    : sf::RectangleShape(size)
{
    setPosition(position);
}

void CustomRectangleShape::setSpeed(float velocity_x, float velocity_y, float velocity_o)
{
    velocity_x_ = velocity_x;
    velocity_y_ = velocity_y;
    velocity_o_ = velocity_o;
}

void CustomRectangleShape::animate(const sf::Time &elapsed)
{
    if (is_selected == false)
    {
    move(velocity_x_*elapsed.asSeconds(), velocity_y_*elapsed.asSeconds());
    rotate(velocity_o_*elapsed.asSeconds());
    bounce();
    }
    else
    {
        sf::FloatRect rectangle_bounds = getGlobalBounds();

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            if(rectangle_bounds.top > bounds.top)
            {
            move(0, -400*elapsed.asSeconds());
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            if(rectangle_bounds.top+rectangle_bounds.height < bounds.bottom)
            {
            move(0, 400*elapsed.asSeconds());
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            if(rectangle_bounds.left > bounds.left)
            {
            move(-400*elapsed.asSeconds(), 0);
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            if(rectangle_bounds.left+rectangle_bounds.width < bounds.right)
            {
            move(400*elapsed.asSeconds(), 0);
            }
        }
    }
}

void CustomRectangleShape::setBounds(int l_bound, int r_bound, int t_bound, int b_bound)
{
    bounds.top = t_bound;
    bounds.bottom = b_bound;
    bounds.left = l_bound;
    bounds.right = r_bound;
}

void CustomRectangleShape::setBounds(const sf::IntRect &rect)
{
    setBounds(rect.left, rect.left+rect.width, rect.top, rect.top+rect.height);
}

void CustomRectangleShape::select()
{
    is_selected = true;
}

void CustomRectangleShape::unselect()
{
    is_selected = false;
}

bool CustomRectangleShape::is_clicked(sf::Vector2i mouse_position)
{
    sf::FloatRect rectangle_bounds = getGlobalBounds();

    if(mouse_position.x >= rectangle_bounds.left
       && mouse_position.x <= rectangle_bounds.left+rectangle_bounds.width
       && mouse_position.y >= rectangle_bounds.top
       && mouse_position.y <= rectangle_bounds.top+rectangle_bounds.height)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void CustomRectangleShape::bounce()
{
    sf::FloatRect rectangle_bounds = getGlobalBounds();

    if(rectangle_bounds.top <= bounds.top)
    {
        velocity_y_ = std::abs(velocity_y_);
    }
    if(rectangle_bounds.top + rectangle_bounds.height >= bounds.bottom)
    {
        velocity_y_ = -std::abs(velocity_y_);
    }
    if(rectangle_bounds.left <= bounds.left)
    {
        velocity_x_ = std::abs(velocity_x_);
    }
    if(rectangle_bounds.left + rectangle_bounds.width >= bounds.right)
    {
        velocity_x_ = -std::abs(velocity_x_);
    }
}
