#ifndef SCENE_H
#define SCENE_H

#include <SFML/Graphics.hpp>
#include <map>

#include "./../Entities/Entity.h"
#include "./../Factories/Entity.Factory/Entity.Factory.h"

class Scene
{
private:
    sf::RenderWindow *window;
    std::map<std::string, Entity *> entities;
    std::map<std::string, sf::Clock *> clocks;
public:
    Scene(sf::RenderWindow *);
    ~Scene();
    void addEntity(std::string, int);
    void addClock(std::string);
    Entity *getEntity(std::string);
    sf::Clock *getClock(std::string);
    void updateClock(std::string, sf::Clock *);
    sf::RenderWindow *getWindow();
    virtual void draw() = 0;
    virtual void events(sf::Event *) = 0;
};

namespace gm
{
    namespace Scene
    {
        enum
        {
            TestScene = 0,
            MainScene = 1,
            ModeScene = 2,
            ConnectScene = 3,
            NameScene = 4,
            CharacterScene = 5,
            GameScene = 6,
        };
    }
}

#include "./Scene.cpp"

#endif