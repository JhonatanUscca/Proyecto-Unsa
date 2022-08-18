#ifndef SCENEFACTORY_H
#define SCENEFACTORY_H

#include <SFML/Graphics.hpp>

#include "./../../Scenes/Scene.h"
#include "./../../Scenes/Test.Scene/Test.Scene.h"

class SceneFactory
{
protected:
    SceneFactory();

public:
    SceneFactory(SceneFactory &_other) = delete;
    void operator=(const SceneFactory &) = delete;
    static Scene *getScene(sf::RenderWindow *, int);
};

#include "./Scene.Factory.cpp"

#endif