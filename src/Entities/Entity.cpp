#include "./Entity.h"

Entity::Entity(std::string _type)
{
    this->type = _type;
    this->sprite = new sf::Sprite;
    this->texture = new sf::Texture;
    this->direction = sf::Vector2f(0.f , 0.f);
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

std::string Entity::getMessage(std::string _key)
{
    return this->messages->at(_key);
}

void Entity::setMessage(std::string _key, std::string _value)
{
    this->messages->insert(std::pair<std::string, std::string>(_key, _value));
}

sf::Vector2f Entity::isCollitionWith(Entity *_entity, sf::Vector2f _direction)
{
    if (_entity != nullptr) {
        if (_entity->getType() == "Terrain")
        {
            if (this->getSprite()->getGlobalBounds().intersects(_entity->getSprite()->getGlobalBounds()))
            {
                if (this->getSprite()->getGlobalBounds().left - (this->getSprite()->getGlobalBounds().width / 2.f) >
                _entity->getSprite()->getGlobalBounds().left + (_entity->getSprite()->getGlobalBounds().width / 2.f) &&
                _direction.x < 0.f && _direction.y == 0.f )
                {
                    this->getSprite()->setPosition(_entity->getSprite()->getGlobalBounds().left + (_entity->getSprite()->getGlobalBounds().width / 2.f), this->getSprite()->getPosition().y);
                    return sf::Vector2f(-1.f, 0.f);
                }

                if (this->getSprite()->getGlobalBounds().left + (this->getSprite()->getGlobalBounds().width / 2.f) >
                _entity->getSprite()->getGlobalBounds().left - (_entity->getSprite()->getGlobalBounds().width / 2.f) &&
                _direction.x > 0.f && _direction.y == 0.f )
                {
                    this->getSprite()->setPosition(_entity->getSprite()->getGlobalBounds().left - (_entity->getSprite()->getGlobalBounds().width / 2.f), this->getSprite()->getPosition().y);
                    return sf::Vector2f(1.f, 0.f);
                }

                if (this->getSprite()->getGlobalBounds().top - (this->getSprite()->getGlobalBounds().height / 2.f) >
                _entity->getSprite()->getGlobalBounds().top + (_entity->getSprite()->getGlobalBounds().height / 2.f) &&
                _direction.x == 0.f && _direction.y < 0.f )
                {
                    this->getSprite()->setPosition(this->getSprite()->getPosition().x, _entity->getSprite()->getGlobalBounds().top + (_entity->getSprite()->getGlobalBounds().height / 2.f));
                    return sf::Vector2f(0.f, -1.f);
                }

                if (this->getSprite()->getGlobalBounds().top + (this->getSprite()->getGlobalBounds().height / 2.f) >
                _entity->getSprite()->getGlobalBounds().top - (_entity->getSprite()->getGlobalBounds().height / 2.f) &&
                _direction.x == 0.f && _direction.y > 0.f )
                {
                    this->getSprite()->setPosition(this->getSprite()->getPosition().x, _entity->getSprite()->getGlobalBounds().top - (_entity->getSprite()->getGlobalBounds().height / 2.f));
                    return sf::Vector2f(0.f, 1.f);
                }
            } else {
                return sf::Vector2f(0.f, 0.f);
            }
        }
    }
}

void Entity::setDirection(sf::Vector2f _direction) {
    this->direction = _direction;
}

sf::Vector2f Entity::getDirection() {
    return this->direction;
}