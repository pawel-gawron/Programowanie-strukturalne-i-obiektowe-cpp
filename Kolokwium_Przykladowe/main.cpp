#include "abstrakt.h"
#include "bagno.h"
#include "bohater.h"
#include "potwor.h"

using namespace std;

int main()
{
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(800, 800), "kolokwium");

    sf::RectangleShape rectangle(sf::Vector2f(120.0, 60.0));
    rectangle.setPosition(window.getSize().x - rectangle.getSize().x, window.getSize().y/2 - rectangle.getSize().y);
    rectangle.setFillColor(sf::Color(100, 50, 250));

    sf::Texture hero;
    if (!hero.loadFromFile("hero.png"))
    {
        std::cout << "ERROR" << std::endl;
    }

    sf::Texture swamp;
    if (!swamp.loadFromFile("swamp.jpg"))
    {
        std::cout << "ERROR" << std::endl;
    }

    sf::Texture monster;
    if (!monster.loadFromFile("monster.png"))
    {
        std::cout << "ERROR" << std::endl;
    }

    Bohater bohater(window.getSize().x/2, window.getSize().y, &hero);
    bohater.setPosition(0, window.getSize().y - bohater.Sprite.getGlobalBounds().height);
    bohater.setupEdge(0, window.getSize().x, 0, window.getSize().y);

    vector<Abstrakt*> PRZESZKODY;
    int randomx;
    int randomy;
    int size_x = window.getSize().x - bohater.Sprite.getGlobalBounds().width;
    int size_y = window.getSize().y - bohater.Sprite.getGlobalBounds().height;
    for (int i = 0; i < 10; i++)
    {
        randomx = rand() % size_x + bohater.Sprite.getGlobalBounds().width;
        randomy = rand() % size_y - bohater.Sprite.getGlobalBounds().height;
        PRZESZKODY.push_back(new Bagno(0, 0, &swamp));
        PRZESZKODY[i]->setPosition(randomx, randomy);
    }
    for (int i = 0; i < 10; i++)
    {
        randomx = rand() % size_x + bohater.Sprite.getGlobalBounds().width;
        randomy = rand() % size_y - bohater.Sprite.getGlobalBounds().height;
        PRZESZKODY.push_back(new Potwor(0, 0,&monster));
        PRZESZKODY[i+10]->setPosition(randomx, randomy);
    }

    sf::Clock clock;
    sf::Clock points;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            {
                bohater.setPosition(0, window.getSize().y - bohater.Sprite.getGlobalBounds().height);
            }
        }
        sf::Time elapsed = clock.restart();

        window.clear(sf::Color::Black);

        window.draw(rectangle);
        bohater.render(window);
        bohater.update(elapsed);

        for (unsigned int i = 0; i < PRZESZKODY.size(); i++)
        {
            PRZESZKODY[i]->render(window);
            PRZESZKODY[i]->update(elapsed);
            if (bohater.Sprite.getGlobalBounds().intersects(PRZESZKODY[i]->Sprite.getGlobalBounds()))
            {

                if (PRZESZKODY[i]->type == 1)
                {
                    PRZESZKODY.erase(PRZESZKODY.begin() + i);
                    delete *(PRZESZKODY.begin()+i);
                }
                if (PRZESZKODY[i]->type == 2)
                {
                    PRZESZKODY.erase(PRZESZKODY.begin() + i);
                    delete *(PRZESZKODY.begin()+i);
                }

                //hp gracza jesli wpadnie na niego potwor
                bohater.hp-= 30;
                std::cout << "HP:" << bohater.hp << std::endl;
            }

        }
        if(points.getElapsedTime().asSeconds() > 1)
        {
            bohater.hp--;
            points.restart();
            std::cout << "HP:" << bohater.hp << std::endl;
        }

        if (bohater.hp <= 0)
        {
            window.close();
            std::cout << "Przegrales" << std::endl;
        }
        if (bohater.Sprite.getGlobalBounds().intersects(rectangle.getGlobalBounds()))
        {
            window.close();
            std::cout << "Wygrales" << std::endl;
        }

        window.display();
    }
    return 0;
}
