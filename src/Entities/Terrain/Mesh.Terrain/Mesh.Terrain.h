#ifndef MESHTERRAIN_H
#define MESHTERRAIN_H

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <math.h>
#include <vector>

#include "./../../../Factories/Entity.Factory/Entity.Factory.h"
#include "./../Terrain.h"

class MeshTerrain
{
private:
    std::vector<std::vector<Entity *> *> terrains;
public:
    MeshTerrain();
    ~MeshTerrain();
    std::vector<std::vector<Entity *> *> getMesh();
    void setMesh(int[16][20]);
    void events(sf::Event *);
    void draw(sf::RenderWindow *);
};

namespace gm {
    namespace Mesh {
        enum {
            StoneMesh = 1,
            GlassGreenMesh = 2,
            WoodMesh = 3,
            GlassOrangeMesh = 4,
            TreeMesh = 5,
            GlassPurpleMesh = 6,
        };
    }
}

#include "./Mesh.Terrain.cpp"

#endif