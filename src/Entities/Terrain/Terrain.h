#ifndef TERRAIN_H
#define TERRAIN_H

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <math.h>
#include "./../Entity.h"

class Terrain : public Entity
{
private:
    bool canDamage;
public:
    Terrain(bool);
    ~Terrain();
    void damage(Entity *, std::string);
    virtual void events(sf::Event *);
    virtual void draw(sf::RenderWindow *);
};

#include "./Terrain.cpp"

#endif