#include "./VirtualGuy.Character.h"

VirtualGuyCharacter::VirtualGuyCharacter(std::map<std::string, sf::Keyboard::Key> *_controls): Character(16.f, 140.f, _controls) {
    sf::Texture *_texture = new sf::Texture;
}

VirtualGuyCharacter::~VirtualGuyCharacter() {}

void VirtualGuyCharacter::draw(sf::RenderWindow * _window) {
    Character::draw(_window);
}

void VirtualGuyCharacter::events(sf::Event * _event) {
    Character::events(_event);
}