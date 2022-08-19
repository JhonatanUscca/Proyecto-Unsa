#ifndef CHARACTER_H
#define CHARACTER_H

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <math.h>
#include <map>
#include <iostream>
#include "./../Entity.h"

class Character : public Entity
{
private:
    std::map<std::string, sf::Texture *> *textures;
    std::map<std::string, sf::Keyboard::Key> *controls;
    float speed;
    float jump;
    bool canJump;
    bool fall;
    int animation;
    int iterAnimation;
    float gravity;
public:
    Character(float, float, std::string, std::map<std::string,sf::Keyboard::Key> *);
    ~Character();
    void move(sf::Event *);
    void collision(sf::Vector2f);
    void die();
    void respawn();
    void animate(int);
    void setAnimation(int);
    int getAnimation();
    float getGravity();
    std::map<std::string, sf::Texture *> *getTextures();
    std::map<std::string, sf::Keyboard::Key> *getControls();
    sf::Vector2f isCollitionWith(Entity *, sf::Vector2f);
    virtual void events(sf::Event *);
    virtual void draw(sf::RenderWindow *);
};

namespace gm {
    namespace Animation {
        enum {
            IdleCharacter = 1,
            JumpCharacter = 2,
            FallCharacter = 3,
            RunCharacterL = 4,
            RunCharacterR = 5,
        };
    }
}

#include "./Character.cpp"

#endif