#ifndef BACKGROUNMANAGER_H
#define BACKGROUNMANAGER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <map>

class BackgrounManager
{
protected:
    BackgrounManager(sf::RenderWindow *);
    std::map<std::string, sf::Sprite *> *backgrounds;
    static BackgrounManager *backgrounManager;
    sf::RenderWindow * window;

public:
    BackgrounManager(BackgrounManager &_other) = delete;
    void operator=(const BackgrounManager &) = delete;
    static BackgrounManager *get(sf::RenderWindow *);
    static BackgrounManager *get();
    void draw(int);
};

namespace gm
{
    namespace Background
    {
        enum
        {
            Blue = 1,
            Brown = 2,
            Gray = 3,
            Green = 4,
            Pink = 5,
            Purple = 6,
            Yellow = 7,
        };
    }
}

#include "./Background.Manager.cpp"

#endif