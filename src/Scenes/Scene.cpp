#include "./Scene.h"

Scene::Scene(sf::RenderWindow *_window)
{
    this->window = _window;
}

Scene::~Scene() {}

void Scene::addEntity(std::string _key, int _object)
{
    Entity *obj = EntityFactory::getEntity(_object);
    this->entities.insert(std::make_pair(_key, obj));
}

void Scene::addClock(std::string _key)
{
    sf::Clock *clk = new sf::Clock;
    this->clocks.insert(std::make_pair(_key, clk));
}

void Scene::updateClock(std::string _key, sf::Clock *_value) {
    this->clocks.at(_key) = _value;
}

Entity *Scene::getEntity(std::string _key)
{
    return this->entities.at(_key);
}

sf::Clock *Scene::getClock(std::string _key)
{
    return this->clocks.at(_key);
}

sf::RenderWindow *Scene::getWindow()
{
    return this->window;
}