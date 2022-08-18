#ifndef TEXTUI_H
#define TEXTUI_H

#include <SFML/Graphics.hpp>

class Text
{
private:
    sf::Font *font;
    sf::Text *text;
    unsigned int type;

public:
    Text();
    ~Text();
    void setText(std::string, std::string, int, sf::Color, sf::Text::Style, int);
    void updateString(sf::String);
    void events(sf::Event *);
    void draw(sf::RenderWindow *);
    sf::Text *getText();
};

#include "./Text.UI.cpp"

#endif