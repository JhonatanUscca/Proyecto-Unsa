#ifndef ENTITYFACTORY_H
#define ENTITYFACTORY_H

#include "./../../Entities/Entity.h"
#include "./../../Entities/Terrain/Stone.Terrain/Stone.Terrain.h"

class EntityFactory
{
protected:
    EntityFactory();

public:
    EntityFactory(EntityFactory &_other) = delete;
    void operator=(const EntityFactory &) = delete;
    static Entity *getEntity(int);
};

#include "./Entity.Factory.cpp"

#endif