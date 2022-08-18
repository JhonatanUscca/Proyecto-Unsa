#include "./Mesh.Manager.h"

MeshManager *MeshManager::meshManager = nullptr;

MeshManager::MeshManager() {}

MeshManager *MeshManager::get()
{
    if (MeshManager::meshManager == nullptr)
    {
        MeshManager::meshManager = new MeshManager();
    }
    return MeshManager::meshManager;
}

std::vector<MeshTerrain *> MeshManager::getMeshs() {
    return this->meshs;
}

void MeshManager::addMesh(int _mesh) {
    switch (_mesh)
    {
    case gm::Mesh::StoneMesh:
        this->meshs.push_back(MeshFactory::getMeshTerrain(_mesh));
        break;
    
    default:
        break;
    }
}