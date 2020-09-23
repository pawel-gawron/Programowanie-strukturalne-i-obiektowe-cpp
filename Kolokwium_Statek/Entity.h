#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include <memory>

class Entity : public sf::Sprite
{
public:
	static std::vector<Entity*> POTWORY;
	sf::Sprite Sprite;
	Entity();
	virtual ~Entity();
	bool collision = 1;
    int velocity = 100;
	void setTexture(sf::Texture& texture);
	int type = 0;
	virtual void setPosition(const float x, const float y);
	virtual void move(const float x, const float y);
    virtual void update(const sf::Time &elapsed) = 0;
	virtual void render(sf::RenderTarget& target) = 0;
};

