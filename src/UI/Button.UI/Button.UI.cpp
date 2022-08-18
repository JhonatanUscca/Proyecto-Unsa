#include "./Button.UI.h"

Button::Button()
{
    this->text = new Text;
    this->shape = new sf::RectangleShape;
}

Button::~Button() {}

void Button::setButton(sf::Color _color, sf::Vector2f _size, Text *_text)
{
    this->text = _text;
    this->shape->setFillColor(_color);
    this->shape->setSize(_size);
    this->shape->setOrigin(this->shape->getLocalBounds().width / 2.0f, this->shape->getLocalBounds().height / 2.0f);
}

void Button::events(sf::Event *_events)
{
}

void Button::draw(sf::RenderWindow *_window)
{
    this->text->getText()->setPosition(this->shape->getPosition());
    _window->draw(*this->shape);
    this->text->draw(_window);
}

sf::RectangleShape *Button::getShape()
{
    return this->shape;
}

sf::Text *Button::getText()
{
    return this->text->getText();
}