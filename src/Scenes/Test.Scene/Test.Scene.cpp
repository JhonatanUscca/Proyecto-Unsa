#include "./Test.Scene.h"

TestScene::TestScene(sf::RenderWindow *_window) : Scene(_window)
{
    MeshManager::get()->addMesh(gm::Mesh::StoneMesh);
}

TestScene::~TestScene() {}

void TestScene::draw()
{
    BackgrounManager::get()->draw(gm::Background::Blue);
    for (auto _mesh : MeshManager::get()->getMeshs()) {
        _mesh->draw(this->getWindow());
    }
}

void TestScene::events(sf::Event *_event)
{
    
}