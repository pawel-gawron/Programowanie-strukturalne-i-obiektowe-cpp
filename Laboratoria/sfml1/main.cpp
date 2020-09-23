#include <iostream>
#include <cmath>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

int main()
{
    std::cout<< "sdsfsdfsdfsdf" << std::endl;
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    sf::SoundBuffer buffer;
    if(!buffer.loadFromFile("videoplayback (online-audio-converter.com).wav")) std::cout << "ERROR" << std::endl;
    sf::Sound sound;
    sound.setBuffer(buffer);

    // create some shapes
    sf::CircleShape circle(100.0);
    circle.setPosition(100.0, 300.0);
    circle.setFillColor(sf::Color(100, 250, 50));
    sf::RectangleShape rectangle(sf::Vector2f(120.0, 60.0));
    rectangle.setPosition(500.0, 400.0);
    rectangle.setFillColor(sf::Color(100, 50, 250));
    //std::cout << circle.getPosition().x << " " << circle.getPosition().y << std::endl;
    //    std::cout << rectangle.getPosition().x << " " << rectangle.getPosition().y << std::endl;
    //  std::cout << circle.getRadius() << std::endl;
    float rectangle_velocity_x = 350;
    float rectangle_velocity_y = 200;
    float rectangle_angular_velocity_x = 10;


    sf::ConvexShape triangle;
    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(0.0, 0.0));
    triangle.setPoint(1, sf::Vector2f(0.0, 100.0));
    triangle.setPoint(2, sf::Vector2f(140.0, 40.0));
    triangle.setOutlineColor(sf::Color::Red);
    triangle.setOutlineThickness(5);
    triangle.setPosition(600.0, 100.0);

    sf::Clock clock;

    int clock_counter = 0;
    //window.setFramerateLimit(60);

    // run the program as long as the window is open
    while (window.isOpen()) {
        //EVENTS

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        //LOGIC
        sf::Time elapsed = clock.restart();

        rectangle.move(rectangle_velocity_x*elapsed.asSeconds(),
                       rectangle_velocity_y*elapsed.asSeconds());

        rectangle.rotate(rectangle_angular_velocity_x*elapsed.asSeconds());

        sf::FloatRect rectangle_bounds = rectangle.getGlobalBounds();

        if(rectangle_bounds.top <= 0)
        {
            rectangle_velocity_y = std::abs(rectangle_velocity_y);
            rectangle.setFillColor(sf::Color(255, 0, 255));
        }
        if(rectangle_bounds.top + rectangle_bounds.height >= window.getSize().y)
        {
            rectangle_velocity_y = -std::abs(rectangle_velocity_y);
            rectangle.setFillColor(sf::Color(0, 255, 0));
        }
        if(rectangle_bounds.left <= 0)
        {
            rectangle_velocity_x = std::abs(rectangle_velocity_x);
            rectangle.setFillColor(sf::Color(100, 100, 100));
        }
        if(rectangle_bounds.left + rectangle_bounds.width >= window.getSize().x)
        {
            rectangle_velocity_x = -std::abs(rectangle_velocity_x);
            rectangle.setFillColor(sf::Color(50, 100, 150));
        }

        //COLLISION RECTANGLE - CIRCLE
        if(rectangle.getGlobalBounds().intersects(circle.getGlobalBounds())
                && rectangle_velocity_x < 0
                && rectangle_velocity_y > 0
                && rectangle.getPosition().x >= circle.getPosition().x + circle.getRadius()
                && rectangle.getPosition().y <= circle.getPosition().y + 2*circle.getRadius()
                && (rectangle.getPosition().y >= circle.getPosition().y || rectangle.getPosition().y + rectangle.getSize().y >= circle.getPosition().y))
        {
            rectangle_velocity_x = std::abs(rectangle_velocity_x);
            sound.play();
            std::cout << "kolizja" << std::endl;
        }
        if(rectangle.getGlobalBounds().intersects(circle.getGlobalBounds())
                && rectangle_velocity_x < 0
                && rectangle_velocity_y > 0
                && rectangle.getPosition().y <= circle.getPosition().y
                && (rectangle.getPosition().x >= circle.getPosition().x || rectangle.getPosition().x + rectangle.getSize().x >= circle.getPosition().x)
                && rectangle.getPosition().x <= circle.getPosition().x + 2*circle.getRadius())
        {
            rectangle_velocity_y = -std::abs(rectangle_velocity_y);
            sound.play();
            std::cout << "kolizja" << std::endl;
        }
        if(rectangle.getGlobalBounds().intersects(circle.getGlobalBounds())
                && rectangle_velocity_x < 0
                && rectangle_velocity_y < 0
                && rectangle.getPosition().x <= circle.getPosition().x + 2*circle.getRadius()
                && (rectangle.getPosition().x >= circle.getPosition().x || rectangle.getPosition().x + rectangle.getSize().x >= circle.getPosition().x)
                && rectangle.getPosition().y >= circle.getPosition().y + circle.getRadius())
        {
            rectangle_velocity_y = std::abs(rectangle_velocity_y);
            sound.play();
            std::cout << "kolizja" << std::endl;
        }
        if(rectangle.getGlobalBounds().intersects(circle.getGlobalBounds())
                && rectangle_velocity_x < 0
                && rectangle_velocity_y < 0
                && (rectangle.getPosition().y >= circle.getPosition().y || rectangle.getPosition().y + rectangle.getSize().y >= circle.getPosition().y )
                && rectangle.getPosition().y <= circle.getPosition().y + 2*circle.getRadius()
                && rectangle.getPosition().x >= circle.getPosition().x + circle.getRadius())
        {
            rectangle_velocity_x = std::abs(rectangle_velocity_x);
            sound.play();
            std::cout << "kolizja" << std::endl;
        }
        if(rectangle.getGlobalBounds().intersects(circle.getGlobalBounds())
                && rectangle_velocity_x > 0
                && rectangle_velocity_y < 0
                && (rectangle.getPosition().x >= circle.getPosition().x || rectangle.getPosition().x + rectangle.getSize().x >= circle.getPosition().x)
                && rectangle.getPosition().y >= circle.getPosition().y + circle.getRadius()
                && rectangle.getPosition().x <= circle.getPosition().x + 2*circle.getRadius())
        {
            rectangle_velocity_y = std::abs(rectangle_velocity_y);
            sound.play();
            std::cout << "kolizja" << std::endl;
        }
        if(rectangle.getGlobalBounds().intersects(circle.getGlobalBounds())
                && rectangle_velocity_x > 0
                && rectangle_velocity_y < 0
                && rectangle.getPosition().x <= circle.getPosition().x
                && (rectangle.getPosition().y >= circle.getPosition().y || rectangle.getPosition().y + rectangle.getSize().y >= circle.getPosition().y)
                && rectangle.getPosition().y <= circle.getPosition().y + 2*circle.getRadius())
        {
            rectangle_velocity_x = -std::abs(rectangle_velocity_x);
            sound.play();
            std::cout << "kolizja" << std::endl;
        }
        if(rectangle.getGlobalBounds().intersects(circle.getGlobalBounds())
                && rectangle_velocity_x > 0
                && rectangle_velocity_y > 0
                && rectangle.getPosition().x <= circle.getPosition().x
                && (rectangle.getPosition().y >= circle.getPosition().y || rectangle.getPosition().y + rectangle.getSize().y >= circle.getPosition().y)
                && rectangle.getPosition().y <= circle.getPosition().y + 2*circle.getRadius())
        {
            rectangle_velocity_x = -std::abs(rectangle_velocity_x);
            sound.play();
            std::cout << "kolizja" << std::endl;
        }
        if(rectangle.getGlobalBounds().intersects(circle.getGlobalBounds())
                && rectangle_velocity_x > 0
                && rectangle_velocity_y > 0
                && rectangle.getPosition().y <= circle.getPosition().y
                && (rectangle.getPosition().x >= circle.getPosition().x || rectangle.getPosition().x + rectangle.getSize().x >= circle.getPosition().x)
                && rectangle.getPosition().x <= circle.getPosition().x + 2*circle.getRadius())
        {
            rectangle_velocity_y = -std::abs(rectangle_velocity_y);
            sound.play();
            std::cout << "kolizja" << std::endl;
        }
//        if(rectangle.getGlobalBounds().intersects(triangle.getGlobalBounds()))
//        {
//            std::cout << "kolizja" << std::endl;
//        }

        //COLLISION RECTANGLE - TRIANGLE
        if(rectangle.getGlobalBounds().intersects(triangle.getGlobalBounds())
                && rectangle_velocity_x < 0
                && rectangle_velocity_y < 0
                && rectangle.getPosition().y >= triangle.getPosition().y
                && (rectangle.getPosition().x >= triangle.getPosition().x || rectangle.getPosition().x + rectangle.getSize().x >= triangle.getPosition().x)
                && rectangle.getPosition().x <= triangle.getPosition().x + std::abs(triangle.getPoint(2).x - triangle.getPosition().x))
        {
            rectangle_velocity_y = std::abs(rectangle_velocity_y);
            sound.play();
            std::cout << "kolizja" << std::endl;
        }
        if(rectangle.getGlobalBounds().intersects(triangle.getGlobalBounds())
                && rectangle_velocity_x > 0
                && rectangle_velocity_y < 0
                && rectangle.getPosition().y >= triangle.getPosition().y
                && (rectangle.getPosition().x >= triangle.getPosition().x || rectangle.getPosition().x + rectangle.getSize().x >= triangle.getPosition().x)
                && rectangle.getPosition().x <= triangle.getPosition().x + std::abs(triangle.getPoint(2).x - triangle.getPosition().x))
        {
            rectangle_velocity_y = std::abs(rectangle_velocity_y);
            sound.play();
            std::cout << "kolizja" << std::endl;
        }
        if(rectangle.getGlobalBounds().intersects(triangle.getGlobalBounds())
                && rectangle_velocity_x > 0
                && rectangle_velocity_y < 0
                && rectangle.getPosition().x <= triangle.getPosition().x
                && (rectangle.getPosition().y >= triangle.getPosition().y || rectangle.getPosition().y + rectangle.getSize().y >= triangle.getPosition().y)
                && rectangle.getPosition().y <= triangle.getPosition().y + std::abs(triangle.getPoint(1).y - triangle.getPosition().y))
        {
            rectangle_velocity_x = -std::abs(rectangle_velocity_x);
            sound.play();
            std::cout << "kolizja" << std::endl;
        }
        if(rectangle.getGlobalBounds().intersects(triangle.getGlobalBounds())
                && rectangle_velocity_x > 0
                && rectangle_velocity_y > 0
                && rectangle.getPosition().x <= triangle.getPosition().x
                && (rectangle.getPosition().y >= triangle.getPosition().y || rectangle.getPosition().y + rectangle.getSize().y >= triangle.getPosition().y)
                && rectangle.getPosition().y <= triangle.getPosition().y + std::abs(triangle.getPoint(1).y - triangle.getPosition().y))
        {
            rectangle_velocity_x = -std::abs(rectangle_velocity_x);
            sound.play();
            std::cout << "kolizja" << std::endl;
        }
        if(rectangle.getGlobalBounds().intersects(triangle.getGlobalBounds())
                && rectangle_velocity_x > 0
                && rectangle_velocity_y > 0
                && rectangle.getPosition().y <= triangle.getPosition().y
                && (rectangle.getPosition().x >= triangle.getPosition().x || rectangle.getPosition().x + rectangle.getSize().x >= triangle.getPosition().x)
                && rectangle.getPosition().x <= triangle.getPosition().x + std::abs(triangle.getPoint(2).x - triangle.getPosition().x))
        {
            rectangle_velocity_y = -std::abs(rectangle_velocity_y);
            sound.play();
            std::cout << "kolizja" << std::endl;
        }
        if(rectangle.getGlobalBounds().intersects(triangle.getGlobalBounds())
                && rectangle_velocity_x < 0
                && rectangle_velocity_y > 0
                && rectangle.getPosition().y <= triangle.getPosition().y
                && (rectangle.getPosition().x >= triangle.getPosition().x || rectangle.getPosition().x + rectangle.getSize().x >= triangle.getPosition().x)
                && rectangle.getPosition().x <= triangle.getPosition().x + std::abs(triangle.getPoint(2).x - triangle.getPosition().x))
        {
            rectangle_velocity_y = -std::abs(rectangle_velocity_y);
            sound.play();
            std::cout << "kolizja" << std::endl;
        }
        if(rectangle.getGlobalBounds().intersects(triangle.getGlobalBounds())
                && rectangle_velocity_x < 0
                && rectangle_velocity_y > 0
                && rectangle.getPosition().x >= triangle.getPosition().x
                && (rectangle.getPosition().y >= triangle.getPosition().y || rectangle.getPosition().y + rectangle.getSize().y >= triangle.getPosition().y)
                && rectangle.getPosition().y <= triangle.getPosition().y + std::abs(triangle.getPoint(1).y - triangle.getPosition().y))
        {
            rectangle_velocity_x = std::abs(rectangle_velocity_x);
            sound.play();
            std::cout << "kolizja" << std::endl;
        }
        if(rectangle.getGlobalBounds().intersects(triangle.getGlobalBounds())
                && rectangle_velocity_x < 0
                && rectangle_velocity_y < 0
                && rectangle.getPosition().x >= triangle.getPosition().x
                && (rectangle.getPosition().y >= triangle.getPosition().y || rectangle.getPosition().y + rectangle.getSize().y >= triangle.getPosition().y)
                && rectangle.getPosition().y <= triangle.getPosition().y + std::abs(triangle.getPoint(1).y - triangle.getPosition().y))
        {
            rectangle_velocity_x = std::abs(rectangle_velocity_x);
            sound.play();
            std::cout << "kolizja" << std::endl;
        }

        if(clock_counter == 200)
        {
            std::cout << "Elapsed time: " << elapsed.asMicroseconds() << ", fps: " << 1/elapsed.asSeconds() << std::endl;

            std::cout << rectangle_bounds.top << " " << rectangle_bounds.left << " " ;
            std::cout << rectangle_bounds.width << " " << rectangle_bounds.height << std::endl;

            clock_counter = 0;
        }
        else
        {
            clock_counter++;
        }
        //DRAW

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        window.draw(circle);
        window.draw(rectangle);
        window.draw(triangle);

        // end the current frame
        window.display();
    }

    return 0;
}
