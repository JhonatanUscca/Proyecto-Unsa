#ifndef MESHMANAGER_H
#define MESHMANAGER_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "./../../Factories/Mesh.Factory/Mesh.Factory.h"

class MeshManager
{
protected:
    MeshManager();
    std::vector<MeshTerrain *> meshs;
    static MeshManager *meshManager;

public:
    MeshManager(MeshManager &_other) = delete;
    void operator=(const MeshManager &) = delete;
    static MeshManager *get();
    std::vector<MeshTerrain *> getMeshs();
    void addMesh(int);
};

#include "./../../Factories/Scene.Factory/Scene.Factory.h"
#include "./Mesh.Manager.cpp"

#endif