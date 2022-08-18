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
    bool isCollitionWith(Entity *);
    std::string getMessage(std::string);
    void setMessage(std::string, std::string);
    virtual void draw(sf::RenderWindow *) = 0;
    virtual void events(sf::Event *) = 0;
};

namespace gm {
    namespace Entity {
        enum {
            VirtualGuyCharacter = 1,
            PinkManCharacter = 2,
            NinjaForgCharacter = 3,
            maskDudeCharacter = 4,

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