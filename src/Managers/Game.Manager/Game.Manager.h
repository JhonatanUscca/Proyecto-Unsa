#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <SFML/Graphics.hpp>
#include <memory>

#include "./../Scene.Manager/Scene.Manager.h"
#include "./../Background.Manager/Background.Manager.h"

class GameManager
{
private:
    sf::RenderWindow *window;
    void close(sf::Event *);

public:
    GameManager(std::unique_ptr<sf::VideoMode> &, std::string);
    ~GameManager();
    void draw();
    void events();
    void render();
};

#include "./Game.Manager.cpp"

#endif