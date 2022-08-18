#include "./Character.h"

Character::Character(float _speed, float _jump, std::map<std::string, sf::Keyboard::Key> *_controls) : Entity("Character")
{
    this->speed = _speed;
    this->jump = _jump;
    this->canJump = true;
    this->controls = _controls;
}

Character::~Character() {
    delete this;
}

void Character::move(sf::Event *_event)
{
    sf::Vector2f *translate = new sf::Vector2f;

    if (sf::Keyboard::isKeyPressed(this->controls->at("left")))
        translate->x -= this->speed;
    if (sf::Keyboard::isKeyPressed(this->controls->at("right")))
        translate->x += this->speed;

    if (translate->x != 0.f)
        *translate /= std::sqrt(2.f);

    if (sf::Keyboard::isKeyPressed(this->controls->at("up")) && canJump) {
        canJump = false;
        translate->y = -std::sqrt(2.f * 981.0f * this->jump);
	}

    if (translate->y != 0.f)
        *translate /= std::sqrt(2.f);

    this->getSprite()->move(*translate);
}

void Character::events(sf::Event *_event)
{
    
    this->move(_event);
    //std::cout << this->translate->x << " " << this->translate->y << std::endl;
    //printf("\e[1;1H\e[2J");
    /*
    std::cout << _event->type << std::endl;
    std::cout << sf::Event::GainedFocus << std::endl;
    std::cout << sf::Event::LostFocus << std::endl;
    */
}

void Character::draw(sf::RenderWindow * _window) {
    _window->draw(*this->getSprite());
    
}