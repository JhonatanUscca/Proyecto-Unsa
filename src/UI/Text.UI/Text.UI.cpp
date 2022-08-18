#include "./Text.UI.h"

Text::Text()
{
    this->font = new sf::Font;
    this->text = new sf::Text;
}

Text::~Text() {}

void Text::setText(std::string _font, std::string _string, int _size, sf::Color _color, sf::Text::Style _style, int _type = 0)
{
    if (_font != "")
    {
        this->font->loadFromFile(_font);
    }
    else
    {
        if (this->font->loadFromFile("./src/Assets/Fonts/hannover-messe-sans/Hannover Messe Sans.otf"))
        {
            this->text->setFont(*this->font);
        }
    }

    this->text->setString(_string);

    if (_size != 0)
    {
        this->text->setCharacterSize(_size);
    }
    else
    {
        this->text->setCharacterSize(12);
    }

    this->text->setFillColor(_color);
    this->text->setStyle(_style);

    this->text->setOrigin(this->text->getLocalBounds().width / 2.0f, this->text->getLocalBounds().height / 2.0f);

    this->type = _type;
}

void Text::updateString(sf::String str)
{
    this->text->setString(str);
}

void Text::events(sf::Event *_events)
{
}

void Text::draw(sf::RenderWindow *_window)
{
    if (this->type == 1)
    {
        this->text->setOrigin(this->text->getLocalBounds().width / 2.0f, this->text->getLocalBounds().height / 2.0f);
    }
    _window->draw(*this->text);
}

sf::Text *Text::getText()
{
    return this->text;
}