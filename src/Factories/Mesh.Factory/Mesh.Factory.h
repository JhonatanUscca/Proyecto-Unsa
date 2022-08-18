#ifndef MESHFACTORY_H
#define MESHFACTORY_H

#include "./../../Entities/Terrain/Mesh.Terrain/Mesh.Terrain.h"

class MeshFactory
{
protected:
    MeshFactory();

public:
    MeshFactory(MeshFactory &_other) = delete;
    void operator=(const MeshFactory &) = delete;
    static MeshTerrain *getMeshTerrain(int);
};

#include "./Mesh.Factory.cpp"

#endif