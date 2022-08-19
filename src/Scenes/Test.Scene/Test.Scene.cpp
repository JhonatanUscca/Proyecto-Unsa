#include "./Test.Scene.h"

TestScene::TestScene(sf::RenderWindow *_window) : Scene(_window)
{
    MeshManager::get()->addMesh(gm::Mesh::StoneMesh);
    this->addEntity("character_virtualguy", gm::Entity::VirtualGuyCharacter1);
    this->getEntity("character_virtualguy")->getSprite()->setPosition(20.f, 200.f);
}

TestScene::~TestScene() {}

void TestScene::draw()
{
    BackgrounManager::get()->draw(gm::Background::Blue);
    for (auto _mesh : MeshManager::get()->getMeshs()) {
        _mesh->draw(this->getWindow());
        auto _aux = _mesh->getMesh();
        for (auto _aux_aux : _aux) {
            for (auto _aux_aux_aux : *_aux_aux) {
                this->getEntity("character_virtualguy")->isCollitionWith(_aux_aux_aux, this->getEntity("character_virtualguy")->getDirection());
            }
        }
    }
    this->getEntity("character_virtualguy")->draw(this->getWindow());
}

void TestScene::events(sf::Event *_event)
{

    this->getEntity("character_virtualguy")->events(_event);
}