#ifndef BUTTONUI_H
#define BUTTONUI_H

#include <SFML/Graphics.hpp>
#include "./../Text.UI/Text.UI.h"

class Button
{
private:
    Text *text;
    sf::RectangleShape *shape;

public:
    Button();
    ~Button();
    void setButton(sf::Color, sf::Vector2f, Text *);
    void events(sf::Event *);
    void draw(sf::RenderWindow *);
    sf::RectangleShape *getShape();
    sf::Text *getText();
};

#include "./Button.UI.cpp"

#endif