#include "./Entity.h"

Entity::Entity(std::string _type)
{
    this->type = _type;
    this->sprite = new sf::Sprite;
    this->texture = new sf::Texture;
}

Entity::~Entity()
{
    delete this->sprite;
    delete this->texture;
    delete this;
}

void Entity::setTexture(std::string _image)
{
    this->texture->loadFromFile(_image);
}

void Entity::setSprite(std::string _image)
{
    this->sprite->setTexture(*this->texture);
    this->sprite->setOrigin(this->sprite->getLocalBounds().width / 2.0f, this->sprite->getLocalBounds().height / 2.0f);
}

void Entity::setSprite(sf::Sprite *_sprite)
{
    this->sprite = _sprite;
}

void Entity::setSprite()
{
    this->sprite->setTexture(*this->texture);
    this->sprite->setOrigin(this->sprite->getLocalBounds().width / 2.0f, this->sprite->getLocalBounds().height / 2.0f);
}

std::string Entity::getType()
{
    return this->type;
}

sf::Sprite *Entity::getSprite()
{
    return this->sprite;
}

sf::Texture *Entity::getTexture()
{
    return this->texture;
}

std::string Entity::getMessage(std::string _key) {
    return this->messages->at(_key);
}

void Entity::setMessage(std::string _key, std::string _value) {
    this->messages->insert(std::pair<std::string, std::string>(_key, _value));
}