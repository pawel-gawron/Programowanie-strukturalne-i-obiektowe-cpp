#include <iostream>
#include <memory>
#include <vector>
#include <map>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace std;

void zad_1()
{
    const int number_of_elements = 100000000;
    for (int i = 0; i < number_of_elements; i++) {
        int *number = new int;
        delete number;
    }
    std::cout << "Utworzono " << number_of_elements << " wskaznikow na wartosc typu int. Nacisnij jakis klawisz aby kontynuowac." << std::endl;
    std::getchar();
}

void zad_2()
{
    const int number_of_elements = 100000000;
    for (int i = 0; i < number_of_elements; i++) {
        auto number = std::make_unique<int>();
    }
    std::cout << "Umieszczono " << number_of_elements << " elementow w std::unique_ptr<int>. Nacisnij jakis klawisz aby kontynuowac." << std::endl;
    std::getchar();
}

void zad_3()
{
    std::vector<std::unique_ptr<int>> some_pointers;
    const int number_of_elements = 100000000;
    for (int i = 0; i < number_of_elements; i++) {
        auto number = std::make_unique<int>();
        some_pointers.emplace_back(move(number));
    }
    std::cout << "Umieszczono " << number_of_elements << " elementow w std::vector<std::unique_ptr<int>>. Nacisnij jakis klawisz aby kontynuowac." << std::endl;
    std::getchar();
}

enum TextureType
{
    Grass = 0,
    Wall = 1,
    Guy = 2,
    Character = 3
};

std::vector<std::unique_ptr<sf::Drawable>> create_shapes(
        const vector<sf::Texture> &textures)
{
    std::vector<std::unique_ptr<sf::Drawable>> shapes;

    auto circle = make_unique<sf::CircleShape>(100.0);
    circle->setPosition(100.0, 300.0);
    circle->setFillColor(sf::Color(100, 250, 50));
    shapes.emplace_back(move(circle));

    auto rectangle =  make_unique<sf::RectangleShape>(sf::Vector2f(120.0, 60.0));
    rectangle->setPosition(500.0, 400.0);
    rectangle->setFillColor(sf::Color(100, 50, 250));
    shapes.emplace_back(move(rectangle));

    auto triangle =  make_unique<sf::ConvexShape>();
    triangle->setPointCount(3);
    triangle->setPoint(0, sf::Vector2f(0.0, 0.0));
    triangle->setPoint(1, sf::Vector2f(0.0, 100.0));
    triangle->setPoint(2, sf::Vector2f(140.0, 40.0));
    triangle->setOutlineColor(sf::Color::Red);
    triangle->setOutlineThickness(5);
    triangle->setPosition(600.0, 100.0);
    shapes.emplace_back(move(triangle));

    {
        auto sprite = make_unique<sf::Sprite>();
        sprite->setTexture(textures[TextureType::Grass]);
        sprite->setPosition(100,100);
        shapes.emplace_back(move(sprite));
    }

    {
        auto sprite = make_unique<sf::Sprite>();
        sprite->setTexture(textures[TextureType::Wall]);
        sprite->setPosition(100,100);
        shapes.emplace_back(move(sprite));
    }

    {
        auto sprite = make_unique<sf::Sprite>();
        sprite->setTexture(textures[TextureType::Guy]);
        sprite->setPosition(100,100);
        shapes.emplace_back(move(sprite));
    }

    return shapes;
}

sf::Texture loadTexture(std::string filename_with_path)
{
    sf::Texture texture;
    if (!texture.loadFromFile(filename_with_path)) {
        std::cerr << "Could not load texture" << std::endl;
    }
    return texture;
}

class AnimatedSprite : public sf::Sprite
{
public:
    AnimatedSprite() : sf::Sprite()
    {
        current_frame_index_ = 0;
    }

    void add_animation_frame(const sf::IntRect &frame)
    {
        frames_.emplace_back(frame);
        current_frame_itr_ = frames_.begin();
    }

    void step(sf::Time elapsed)
    {
        if(current_frame_index_ < frames_.size()-1)
        {
            current_frame_index_++;
        }
        else
        {
            current_frame_index_ = 0;
        }
        setTextureRect(frames_[current_frame_index_]);
    }

    void step_itr()
    {
        if(current_frame_itr_ < frames_.end()-1)
        {
            current_frame_itr_++;
        }
        else
        {
            current_frame_itr_ = frames_.begin();
        }
        setTextureRect(*current_frame_itr_);
    }

private:
    vector<sf::IntRect> frames_;
    vector<sf::IntRect>::iterator current_frame_itr_;
    size_t current_frame_index_;
    sf::Time elapsed;

};

void zad_4()
{
    srand(time(nullptr));

    vector<sf::Texture> textures;
    textures.emplace_back(loadTexture("grass.png"));
    textures.emplace_back(loadTexture("wall.png"));
    textures.emplace_back(loadTexture("guy.png"));
    textures.emplace_back(loadTexture("character.png"));

    sf::RenderWindow window(sf::VideoMode(800,600), "Lab09");
    window.setFramerateLimit(60);

    auto shapes = create_shapes(textures);

    AnimatedSprite hero;
    hero.setTexture(textures[TextureType::Character]);
    hero.setPosition(400,400);
    hero.setScale(4,4);

    /* add texture, set parameters, etc. */

    for(int i = 0; i<(9*50); i+=50)
    {
        hero.add_animation_frame(sf::IntRect(i, 0, 50, 37));
    }

    sf::Clock clock;

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
//        hero.step();
        hero.step_itr();

        //DRAW



        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...

        //        window.draw(circle);
        //        window.draw(rectangle);
        //        window.draw(triangle);

        for(const auto &s : shapes) {
            window.draw(*s);
        }
        window.draw(hero);

        // end the current frame
        window.display();
    }
}

int main()
{
    cout << "Hello World!" << endl;

    //    zad_1();
    //    zad_2();
    //    zad_3();

    zad_4();

    return 0;
}
