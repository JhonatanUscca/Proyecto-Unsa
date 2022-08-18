#ifndef CHARACTER_H
#define CHARACTER_H

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <math.h>
#include <map>
#include "./../Entity.h"

class Character : public Entity
{
private:
    std::map<std::string, sf::Keyboard::Key> *controls;
    float speed;
    float jump;
    bool canJump;
public:
    Character(float, float, std::map<std::string, sf::Keyboard::Key> *);
    ~Character();
    void move(sf::Event *);
    void collision(sf::Vector2f);
    void die();
    void respawn();
    virtual void events(sf::Event *);
    virtual void draw(sf::RenderWindow *);
};

namespace gm {
    namespace animation {
        enum {
            IdleCharacter = 1,
            JumpCharacter = 2,
            FallCharacter = 3,
            RunCharacter = 4,
        };
    }
}

#include "./Character.cpp"

#endif