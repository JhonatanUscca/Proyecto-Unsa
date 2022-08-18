#ifndef TESTSCENE_H
#define TESTSCENE_H

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <vector>
#include <map>

#include "./../Scene.h"
#include "./../../Managers/Mesh.Manager/Mesh.Manager.h"
#include "./../../Managers/Scene.Manager/Scene.Manager.h"
#include "./../../Managers/Background.Manager/Background.Manager.h"
#include "./../../UI/Text.UI/Text.UI.h"

class TestScene : public Scene
{
private:
    std::vector<Entity *> stoneTerrain;
public:
    TestScene(sf::RenderWindow *);
    ~TestScene();
    void draw() override;
    void events(sf::Event *) override;
};

#include "./Test.Scene.cpp"

#endif