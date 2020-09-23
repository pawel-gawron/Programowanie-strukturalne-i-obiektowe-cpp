#include "guy.h"
#include "object.h"

sf::Texture loadTexture(std::string texture_path)
{
    sf::Texture texture;
    if (!texture.loadFromFile(texture_path)) {
        std::cout << "Could not load texture" << std::endl;
    }
    return texture;
}


int main() {

    sf::RenderWindow window(sf::VideoMode(800, 600), "Lab09 Labirynt");

    std::vector<sf::Texture> textures;
    textures.emplace_back(loadTexture("wall.png"));
    
    std::vector<object> walls;
    object wall_1_(textures[0], 125, 100, sf::IntRect(0,0,58,97));
    object wall_2_(textures[0], 509, 138, sf::IntRect(10,15,100,29));
    object wall_3_(textures[0], 12, 450, sf::IntRect(45,13,50,250));
    object wall_4_(textures[0], 450, 12, sf::IntRect(0,0,50,100));
    object wall_5_(textures[0], 300,300, sf::IntRect(0,0,100,50));
    object wall_6_(textures[0], window.getSize().x/2, window.getSize().y/2-100, sf::IntRect(0,0,35,200));


    walls.emplace_back(wall_1_);
    walls.emplace_back(wall_2_);
    walls.emplace_back(wall_3_);
    walls.emplace_back(wall_4_);
    walls.emplace_back(wall_5_);
    walls.emplace_back(wall_6_);
    



    sf::Texture texture_grass_;
    if(!texture_grass_.loadFromFile("grass.png")) { return 1; }
    texture_grass_.setRepeated(true);

    sf::Sprite grass_;
    grass_.setTexture(texture_grass_);
    grass_.setTextureRect(sf::IntRect(0, 0, window.getSize().x, window.getSize().y));

    sf::Texture texture_guy_;
    if(!texture_guy_.loadFromFile("guy.png")) { return 1; }

    guy guy_(texture_guy_);

    guy_.setupEdge(0, window.getSize().x, 0, window.getSize().y);
    
    sf::Clock clock;

    // run the program as long as the window is open
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        sf::Time elapsed = clock.restart();

        guy_.modification(elapsed);
        
        for (auto &el : walls)
        {
            if(guy_.getGlobalBounds().intersects(el.getGlobalBounds()))
            {
                std::cout<< "kolizja" <<std::endl;
                guy_.reflection(el.getGlobalBounds());
            }
        }
        
        
        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        window.draw(grass_);
        window.draw(guy_);

        
        for (auto &w : walls) {
            window.draw(w);
        }
        
        // end the current frame

        window.display();

    }
    return 0;
}
