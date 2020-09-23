#include "Entity.h"

Entity::Entity()
{
    this->collision = 1;
}
Entity::~Entity()
{
}
void Entity::move(const float dir_x, const float dir_y)
{
    this->Sprite.move({ dir_x,dir_y });
}

void Entity::setPosition(const float x, const float y)
{
    this->Sprite.setPosition(x, y);
}
void Entity::setTexture(sf::Texture& texture)
{
    this->Sprite.setTexture(texture);
}
