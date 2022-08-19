#include "./Game.Manager.h"

unsigned int const FPS = 20;
sf::Color *const BG_COLOR = new sf::Color(255, 255, 255, 255);

GameManager::GameManager(std::unique_ptr<sf::VideoMode> &_size, std::string _name)
{
    this->window = new sf::RenderWindow(*_size, _name, sf::Style::Default);
    this->window->setFramerateLimit(FPS);
    SceneManager::get()->push(this->window, gm::Scene::TestScene);
    BackgrounManager::get(this->window);
}

void GameManager::draw()
{
    sf::Event *event = new sf::Event;
    this->window->clear();
    SceneManager::get()->top()->draw();
    this->window->display();
}

void GameManager::close(sf::Event *event)
{
    if (event->type == sf::Event::Closed)
        this->window->close();
}

void GameManager::events()
{
    sf::Event *event = new sf::Event;
    while (this->window->pollEvent(*event))
    {
        this->close(event);
    }
    if (this->window->hasFocus())
    {
        SceneManager::get()->top()->events(event);
    }
}

void GameManager::render()
{
    while (this->window->isOpen())
    {
        this->events();
        this->draw();
    }
}