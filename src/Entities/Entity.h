#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <map>

class Entity
{
private:
    std::string type;
    sf::Texture *texture;
    sf::Sprite *sprite;
    std::map<std::string, std::string> *messages;
    sf::Vector2f direction;

public:
    Entity(std::string);
    ~Entity();
    std::string getType();
    sf::Sprite *getSprite();
    sf::Texture *getTexture();
    void setTexture(std::string);
    void setSprite(std::string);
    void setSprite(sf::Sprite *);
    void setSprite();
    void setDirection(sf::Vector2f);
    sf::Vector2f getDirection();
    std::string getMessage(std::string);
    void setMessage(std::string, std::string);
    virtual sf::Vector2f isCollitionWith(Entity *, sf::Vector2f);
    virtual void draw(sf::RenderWindow *) = 0;
    virtual void events(sf::Event *) = 0;
};

namespace gm {
    namespace Entity {
        enum {
            VirtualGuyCharacter1 = 1,
            PinkManCharacter1 = 2,
            NinjaForgCharacter1 = 3,
            maskDudeCharacter1 = 4,
            VirtualGuyCharacter2 = 14,
            PinkManCharacter2 = 15,
            NinjaForgCharacter2 = 16,
            maskDudeCharacter2 = 17,

            StoneTerrain1 = 5,
            StoneTerrain2 = 6,
            StoneTerrain3 = 7,
            StoneTerrain4 = 8,
            StoneTerrain5 = 9,
            StoneTerrain6 = 10,
            StoneTerrain7 = 11,
            StoneTerrain8 = 12,
            StoneTerrain9 = 13,
        };
    }
}

#include "./Entity.cpp"

#endif