#include "Entity.h"
#include <iostream>
#include "StatekKosmiczny.h"
#include "Meteoryt.h"
#include "Ufo.h"
#include <vector>


int main()
{
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(800, 800), "kolokwium");
    //window.setFramerateLimit(144);
    //kontyner na ufa i meteoryty


    sf::Texture texture;
    sf::Texture meteo;
    sf::Texture ufo;
    if (!texture.loadFromFile("texture.png"))
    {
        std::cout << "cos sie zjebalo" << std::endl;
    }
    if (!meteo.loadFromFile("Meteoryt.png"))
    {
        std::cout << "cos sie zjebalo" << std::endl;
    }
    if (!ufo.loadFromFile("Ufo.png"))
    {
        std::cout << "cos sie zjebalo" << std::endl;
    }

    
    //tworzenie statku
    StatekKosmiczny player(window.getSize().x/2, window.getSize().y, &texture);
    player.setPosition(window.getSize().x / 2 - player.Sprite.getGlobalBounds().width/2 , window.getSize().y - player.Sprite.getGlobalBounds().height);

    player.setupEdge(0, window.getSize().x, 0, window.getSize().y);

    std::vector<Entity*> POTWORY;

    int size_x_meteo = window.getSize().x - meteo.getSize().x;
    int size_x_ufo = window.getSize().x - ufo.getSize().x;
    for (int i = 0; i < 5; i++)
    {
        int randomx = rand() % size_x_meteo;
        int randomy = rand() % 400 + 1;
        POTWORY.push_back(new Meteoryt(0,0,&meteo));
        POTWORY[i]->setPosition(randomx, randomy);
    }

    for (int i = 0; i < 5; i++)
    {
        int randomx = rand() % size_x_ufo;
        int randomy = rand() % 400 + 1;
        POTWORY.push_back(new Ufo(0, 0, &ufo));
        POTWORY[i+5]->setPosition(randomx, randomy);
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

        //rysowanie i obsługa Statku kosmicznego
        player.update(elapsed);
        player.render(window);

        auto mouse_pos = sf::Mouse::getPosition(window);
        auto translated_pos = window.mapPixelToCoords(mouse_pos);
        for (unsigned int i = 0; i < POTWORY.size(); i++)
        {
            //rysowanie ufa i meteorytow + ich movement
            POTWORY[i]->update(elapsed);
            POTWORY[i]->render(window);

            //wykrywanie czy spadly
            if (POTWORY[i]->Sprite.getPosition().y > window.getSize().y && POTWORY[i]->type == 1 )
            {
                delete *(POTWORY.begin()+i);
                POTWORY.erase(POTWORY.begin() + i);
                POTWORY.push_back(new Meteoryt(rand() % size_x_meteo, 0, &meteo));
                player.hp2--;
                std::cout << "HP2:" << player.hp2 << std::endl;
            }
            if (POTWORY[i]->Sprite.getPosition().y > window.getSize().y && POTWORY[i]->type == 2)
            {
                delete *(POTWORY.begin()+i);
                POTWORY.erase(POTWORY.begin() + i);
                POTWORY.push_back(new Ufo(rand() % size_x_ufo, 0, &ufo));

                //hp2 to ile potworow spadlo
                player.hp2--;
                std::cout << "HP2:" << player.hp2 << std::endl;
            }

            //wykrywanie czy wpadły na gracza + ich usuwanie jesli tak
            if (player.Sprite.getGlobalBounds().intersects(POTWORY[i]->Sprite.getGlobalBounds()))
            {

                if (POTWORY[i]->type == 1)
                {
                    delete *(POTWORY.begin()+i);
                    POTWORY.erase(POTWORY.begin() + i);
                    POTWORY.push_back(new Meteoryt(rand() % size_x_meteo, 0, &meteo));
                }
                if (POTWORY[i]->type == 2)
                {
                    delete *(POTWORY.begin()+i);
                    POTWORY.erase(POTWORY.begin() + i);
                    POTWORY.push_back(new Ufo(rand() % size_x_ufo, 0, &ufo));
                }

                //hp gracza jesli wpadnie na niego potwor
                player.hp--;
                std::cout << "HP:" << player.hp << std::endl;
            }


            if (POTWORY[i]->Sprite.getGlobalBounds().contains(translated_pos)&&sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                if (POTWORY[i]->type == 1)
                {
                    delete *(POTWORY.begin()+i);
                    POTWORY.erase(POTWORY.begin() + i);
                    POTWORY.push_back(new Meteoryt(rand() % size_x_meteo, 0, &meteo));
                }
                if (POTWORY[i]->type == 2)
                {
                    delete *(POTWORY.begin()+i);
                    POTWORY.erase(POTWORY.begin() + i);
                    POTWORY.push_back(new Ufo(rand() % size_x_ufo, 0, &ufo));
                }
            }
        }

//        if (player.hp == 0 || player.hp2 == 0)
//        {
//            window.close();
//            std::cout << "Przegrana" << std::endl;
//        }

        window.display();
    }

    return 0;
}
