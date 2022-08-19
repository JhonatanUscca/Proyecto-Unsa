#include "./Mesh.Terrain.h"

MeshTerrain::MeshTerrain() {}

MeshTerrain::~MeshTerrain()
{
    delete this;
}

std::vector<std::vector<Entity *> *> MeshTerrain::getMesh()
{
    return this->terrains;
}

void MeshTerrain::setMesh(int _mesh[16][20])
{
    for (int i = 0; i < 16; ++i)
    {
        this->terrains.push_back(new std::vector<Entity *>);
        for (int y = 0; y < 20; ++y)
        {
            switch (_mesh[i][y])
            {
            case gm::Entity::StoneTerrain1:
                this->terrains[i]->push_back(EntityFactory::getEntity(gm::Entity::StoneTerrain1));
                break;
            case gm::Entity::StoneTerrain2:
                this->terrains[i]->push_back(EntityFactory::getEntity(gm::Entity::StoneTerrain2));
                break;
            case gm::Entity::StoneTerrain3:
                this->terrains[i]->push_back(EntityFactory::getEntity(gm::Entity::StoneTerrain3));
                break;
            case gm::Entity::StoneTerrain4:
                this->terrains[i]->push_back(EntityFactory::getEntity(gm::Entity::StoneTerrain4));
                break;
            case gm::Entity::StoneTerrain5:
                this->terrains[i]->push_back(EntityFactory::getEntity(gm::Entity::StoneTerrain5));
                break;
            case gm::Entity::StoneTerrain6:
                this->terrains[i]->push_back(EntityFactory::getEntity(gm::Entity::StoneTerrain6));
                break;
            case gm::Entity::StoneTerrain7:
                this->terrains[i]->push_back(EntityFactory::getEntity(gm::Entity::StoneTerrain7));
                break;
            case gm::Entity::StoneTerrain8:
                this->terrains[i]->push_back(EntityFactory::getEntity(gm::Entity::StoneTerrain8));
                break;
            case gm::Entity::StoneTerrain9:
                this->terrains[i]->push_back(EntityFactory::getEntity(gm::Entity::StoneTerrain9));
                break;

            default:
                this->terrains[i]->push_back(nullptr);
                continue;
                break;
            }
            this->terrains[i]->at(y)->getSprite()->setPosition(20.f + (y * 40.f), 20.f + (i * 40.f));
        }
    }
}

void MeshTerrain::draw(sf::RenderWindow *_window)
{
    for (auto _row : this->terrains)
    {
        for (auto _terrain : *_row)
        {
            if (_terrain == nullptr)
            {
                continue;
            }
            _terrain->draw(_window);
        }
    }
}