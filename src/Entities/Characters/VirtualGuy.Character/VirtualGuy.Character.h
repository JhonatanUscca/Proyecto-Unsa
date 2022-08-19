#ifndef VIRTUALGUYCHARACTER_H
#define VIRTUALGUYCHARACTER_H

#include <SFML/Graphics.hpp>
#include <map>

#include "./../Character.h"

class VirtualGuyCharacter : public Character
{
private:
    void animate(int);
public:
    VirtualGuyCharacter(std::map<std::string, sf::Keyboard::Key> *);
    ~VirtualGuyCharacter();
    void draw(sf::RenderWindow *);
    void events(sf::Event *);
};

#include "./VirtualGuy.Character.cpp"

#endif