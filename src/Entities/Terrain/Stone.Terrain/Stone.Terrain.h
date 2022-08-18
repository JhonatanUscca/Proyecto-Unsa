#ifndef STONETERRAIN_H
#define STONETERRAIN_H

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <math.h>
#include <iostream>

#include "./../Terrain.h"

class StoneTerrain : public Terrain
{
private:
public:
    StoneTerrain(int);
    ~StoneTerrain();
    void events(sf::Event *);
    void draw(sf::RenderWindow *);
};

#include "./Stone.Terrain.cpp"

#endif