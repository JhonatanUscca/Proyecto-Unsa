#include "./Terrain.h"

Terrain::Terrain(bool _canDamage) : canDamage(_canDamage), Entity("Terrain") {
    this->setTexture("./src/Assets/Textures/Terrain/Terrain (16x16).png");
}

Terrain::~Terrain()
{
    delete this;
}

void Terrain::damage(Entity *_entity, std::string _from) {
    if (this->canDamage) {
        _entity->setMessage("damage", _from);
    }
}

void Terrain::draw(sf::RenderWindow * _window) {
    _window->draw(*this->getSprite());
}

void Terrain::events(sf::Event *_event) {
    return;
}