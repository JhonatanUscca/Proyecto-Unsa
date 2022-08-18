#include "./Stone.Terrain.h"

StoneTerrain::StoneTerrain(int _part) : Terrain(false) {
    sf::Sprite *_sprite = new sf::Sprite;
    int _row = (_part - 1) / 3;
    int _col = (_part - 1) % 3;
    int init_x = 0;
    int init_y = 0;
    _sprite->setTexture(*this->getTexture());
    _sprite->setTextureRect(sf::IntRect((init_x + ((_col) * 16)), (init_y + ((_row) * 16)), 16, 16));
    _sprite->setOrigin(_sprite->getLocalBounds().width / 2.f, _sprite->getLocalBounds().height / 2.f);
    _sprite->setScale(2.5f, 2.5f);
    this->setSprite(_sprite);
}

StoneTerrain::~StoneTerrain()
{
    delete this;
}

void StoneTerrain::draw(sf::RenderWindow * _window) {
    Terrain::draw(_window);
}

void StoneTerrain::events(sf::Event *_event) {
    Terrain::events(_event);
}