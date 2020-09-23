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

    PacMan pacman(window.getSize().x/2, window.getSize().y/2, &pac, 0, -50);
    pacman.setPosition(window.getSize().x/2, window.getSize().y/2);
    pacman.setupEdge(0, window.getSize().x, 0, window.getSize().y);

    vector<RuchomySprite*> PRZESZKODY;
    int randomx;
    int randomy;
    for (int i = 0; i < 20; i++)
    {
        randomx = rand() % (window.getSize().x -duch.getSize().x);
        randomy = rand() % (window.getSize().y -duch.getSize().y);
        PRZESZKODY.push_back(new Duch(0, 0, &duch, rand()%100-50));
        PRZESZKODY[i]->setPosition(randomx, randomy);
    }
    for (int i = 0; i < 5; i++)
    {
        randomx = rand() % (window.getSize().x -owoc.getSize().x);
        randomy = rand() % (window.getSize().y -owoc.getSize().y);
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

        auto mouse_pos = sf::Mouse::getPosition(window);
        auto translated_pos = window.mapPixelToCoords(mouse_pos);

        for (unsigned int i = 0; i < PRZESZKODY.size(); i++)
        {
            PRZESZKODY[i]->render(window);
            PRZESZKODY[i]->animuj(elapsed, window);

            if (pacman.Sprite.getGlobalBounds().intersects(PRZESZKODY[i]->Sprite.getGlobalBounds()))
            {

                if (PRZESZKODY[i]->type == 1)
                {
                    delete *(PRZESZKODY.begin()+i);
                    PRZESZKODY.erase(PRZESZKODY.begin() + i);
                    pacman.points+= 100;
                    cout << "PUNKTY: " << pacman.points << endl;
                }
                if (PRZESZKODY[i]->type == 2)
                {
                    delete *(PRZESZKODY.begin()+i);
                    PRZESZKODY.erase(PRZESZKODY.begin() + i);
                    pacman.setPosition(window.getSize().x/2, window.getSize().y/2);
                    pacman.hp -=1;
                    cout << "ZYCIE: " << pacman.hp << endl;
                }
            }
            if (PRZESZKODY[i]->Sprite.getGlobalBounds().contains(translated_pos)&&sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                if (PRZESZKODY[i]->type == 1)
                {
                    delete *(PRZESZKODY.begin()+i);
                    PRZESZKODY.erase(PRZESZKODY.begin() + i);
                    randomx = rand() % (window.getSize().x -owoc.getSize().x);
                    randomy = rand() % (window.getSize().y -owoc.getSize().y);
                    PRZESZKODY.push_back(new Owoc(randomx, randomy,&owoc, 50));
                }
            }
        }
        if (pacman.hp <= 0)
        {
            window.close();
            std::cout << "PRZEGRANA" << std::endl;
        }
        if (pacman.points >= 500)
        {
            window.close();
            std::cout << "WYGRANA" << std::endl;
        }
        window.display();
    }
    return 0;
}
