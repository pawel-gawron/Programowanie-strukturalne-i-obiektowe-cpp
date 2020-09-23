#include <iostream>
#include "ruchomysprite.h"
#include "duch.h"
#include "pacman.h"
#include "owoc.h"


using namespace std;

int main()
{
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(800, 800), "kolokwium");

    sf::Texture pac;
    if (!pac.loadFromFile("tekstury\\pacman.png"))
    {
        std::cout << "ERROR" << std::endl;
    }
    sf::Texture owoc;
    if (!owoc.loadFromFile("tekstury\\owoc.png"))
    {
        std::cout << "ERROR" << std::endl;
    }
    sf::Texture duch;
    if (!duch.loadFromFile("tekstury\\duch.png"))
    {
        std::cout << "ERROR" << std::endl;
    }

    PacMan pacman(window.getSize().x/2, window.getSize().y/2, &pac, 50);
    pacman.setPosition(window.getSize().x/2, window.getSize().y/2);
    pacman.setupEdge(0, window.getSize().x, 0, window.getSize().y);

    vector<RuchomySprite*> PRZESZKODY;
    int randomx;
    int randomy;
    int size_x = window.getSize().x - pacman.Sprite.getGlobalBounds().width;
    int size_y = window.getSize().y - pacman.Sprite.getGlobalBounds().height;
    for (int i = 0; i < 20; i++)
    {
        randomx = rand() % size_x + pacman.Sprite.getGlobalBounds().width;
        randomy = rand() % size_y - pacman.Sprite.getGlobalBounds().height;
        PRZESZKODY.push_back(new Duch(0, 0, &duch, rand()%100-50));
        PRZESZKODY[i]->setPosition(randomx, randomy);
    }
    for (int i = 0; i < 5; i++)
    {
        randomx = rand() % size_x + pacman.Sprite.getGlobalBounds().width;
        randomy = rand() % size_y - pacman.Sprite.getGlobalBounds().height;
        PRZESZKODY.push_back(new Owoc(0, 0,&owoc, 50));
        PRZESZKODY[i+20]->setPosition(randomx, randomy);
    }
    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        sf::Time elapsed = clock.restart();

        window.clear(sf::Color::Black);

        pacman.render(window);
        pacman.animuj(elapsed, window);

        for (unsigned int i = 0; i < PRZESZKODY.size(); i++)
        {
            PRZESZKODY[i]->render(window);
            PRZESZKODY[i]->animuj(elapsed, window);

            if (pacman.Sprite.getGlobalBounds().intersects(PRZESZKODY[i]->Sprite.getGlobalBounds()))
            {

                if (PRZESZKODY[i]->type == 1)
                {
                    PRZESZKODY.erase(PRZESZKODY.begin() + i);
                    pacman.points+= 100;
                }
                if (PRZESZKODY[i]->type == 2)
                {
                    PRZESZKODY.erase(PRZESZKODY.begin() + i);
                    pacman.setPosition(window.getSize().x/2, window.getSize().y/2);
                    pacman.hp -=1;
                }
            }
        }
        if (pacman.hp <= 0)
        {
            window.close();
            std::cout << "Przegrales" << std::endl;
        }
        if (pacman.points >= 300)
        {
            window.close();
            std::cout << "Wygrales" << std::endl;
        }
        window.display();
    }
    return 0;
}
