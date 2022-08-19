#include "./Entity.Factory.h"

std::map<std::string, sf::Keyboard::Key> controls_2;

Entity *EntityFactory::getEntity(int _entity) {
    std::map<std::string, sf::Keyboard::Key> controls_1;
    controls_1.insert(std::pair<std::string, sf::Keyboard::Key>("left", sf::Keyboard::A));
    controls_1.insert(std::pair<std::string, sf::Keyboard::Key>("right", sf::Keyboard::D));
    controls_1.insert(std::pair<std::string, sf::Keyboard::Key>("up", sf::Keyboard::W));
    Entity *ent;
    switch (_entity)
    {
    case gm::Entity::VirtualGuyCharacter1:
    {
        ent = new VirtualGuyCharacter(&controls_1);
        break;
    }
    case gm::Entity::StoneTerrain1:
    {
        ent = new StoneTerrain(1);
        break;
    }
    case gm::Entity::StoneTerrain2:
    {
        ent = new StoneTerrain(2);
        break;
    }
    case gm::Entity::StoneTerrain3:
    {
        ent = new StoneTerrain(3);
        break;
    }
    case gm::Entity::StoneTerrain4:
    {
        ent = new StoneTerrain(4);
        break;
    }
    case gm::Entity::StoneTerrain5:
    {
        ent = new StoneTerrain(5);
        break;
    }
    case gm::Entity::StoneTerrain6:
    {
        ent = new StoneTerrain(6);
        break;
    }
    case gm::Entity::StoneTerrain7:
    {
        ent = new StoneTerrain(7);
        break;
    }
    case gm::Entity::StoneTerrain8:
    {
        ent = new StoneTerrain(8);
        break;
    }
    case gm::Entity::StoneTerrain9:
    {
        ent = new StoneTerrain(9);
        break;
    }
    }
    return ent;
}