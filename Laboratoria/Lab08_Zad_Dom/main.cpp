#include <iostream>
#include <cmath>
#include <vector>
#include "customrectangleshape.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    sf::Vector2f size(120.0, 60.0);
    sf::Vector2f position(120.0, 60.0);
    CustomRectangleShape my_rectangle(size, position);

    my_rectangle.setFillColor(sf::Color(100, 50, 250));
    my_rectangle.setSpeed(100, 150, 10);
    my_rectangle.setBounds(0, window.getSize().x, 0, window.getSize().y);
    //    sf::IntRect rect1(10, 10, 400, 400);
    //    my_rectangle.setBounds(rect1);

    std::vector<CustomRectangleShape> rectangles;

    for (int i=0; i<10; i++)
    {
        sf::Vector2f size(120.0, 60.0);
        sf::Vector2f position(std::rand() % (window.getSize().x - 120), std::rand() % (window.getSize().y - 60));
        rectangles.emplace_back(CustomRectangleShape(size, position));
    }

    for (auto &rec : rectangles) {
        rec.setFillColor(sf::Color(0, 255, 0));
        rec.setBounds(0, window.getSize().x, 0, window.getSize().y);
        rec.setSpeed(100, 200, 10);
    }

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::Space) {
                    std::cout << "Space released" << std::endl;
                    my_rectangle.select();
                }
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::LShift) {
                    my_rectangle.unselect();
                }
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                if(event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
                    std::cout << "Mouse clicked: " << mouse_pos.x << ", " << mouse_pos.y << std::endl;

                    for(auto &el : rectangles)
                    {
                        if(el.is_clicked(mouse_pos))
                        {
                            el.select();
                            el.setFillColor(sf::Color(
                                                std::rand() % 256,
                                                std::rand() % 256,
                                                std::rand() % 256));
                        }
                    }
                }
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if(event.mouseButton.button == sf::Mouse::Right) {
                    sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
                    std::cout << "Mouse clicked: " << mouse_pos.x << ", " << mouse_pos.y << std::endl;

                    for(auto &el : rectangles)
                    {
                        if(el.is_clicked(mouse_pos))
                        {
                            el.unselect();
                            el.setFillColor(sf::Color(
                                                0,
                                                255,
                                                0));
                        }
                    }
                }
            }
        }

        sf::Time elapsed = clock.restart();
        my_rectangle.animate(elapsed);

        for(auto &el : rectangles)
        {
            el.animate(elapsed);
        }

        window.clear(sf::Color::Black);


        window.draw(my_rectangle);

        for(const auto &rec : rectangles)
        {
            window.draw(rec);
        }

        window.display();
    }

    return 0;
}
