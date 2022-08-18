#include "./Background.Manager.h"

BackgrounManager *BackgrounManager::backgrounManager = nullptr;

BackgrounManager::BackgrounManager(sf::RenderWindow *_window) : backgrounds(new std::map<std::string, sf::Sprite *>), window(_window)
{
    std::vector<std::string> _bgs = {"Blue", "Brown", "Gray", "Green", "Pink", "Purple", "Yellow"};
    for (std::string _bg : _bgs)
    {
        sf::Texture *_texture = new sf::Texture;
        _texture->setRepeated(true);
        _texture->loadFromFile("./src/Assets/Textures/Background/" + _bg + ".png");
        sf::Sprite *_sprite = new sf::Sprite(*_texture, this->window->getViewport(this->window->getView()));
        this->backgrounds->insert(std::pair<std::string, sf::Sprite *>(_bg, _sprite));
    }
}

BackgrounManager *BackgrounManager::get(sf::RenderWindow *_window)
{
    if (BackgrounManager::backgrounManager == nullptr)
    {
        BackgrounManager::backgrounManager = new BackgrounManager(_window);
    }
    return BackgrounManager::backgrounManager;
}

BackgrounManager *BackgrounManager::get()
{
    return BackgrounManager::backgrounManager;
}

void BackgrounManager::draw(int _bg)
{
    sf::Sprite *_sprite = nullptr;
    switch (_bg)
    {
    case gm::Background::Blue:
        _sprite = this->backgrounds->at("Blue");
        break;
    case gm::Background::Brown:
        _sprite = this->backgrounds->at("Brown");
        break;
    case gm::Background::Gray:
        _sprite = this->backgrounds->at("Gray");
        break;
    case gm::Background::Green:
        _sprite = this->backgrounds->at("Green");
        break;
    case gm::Background::Pink:
        _sprite = this->backgrounds->at("Pink");
        break;
    case gm::Background::Purple:
        _sprite = this->backgrounds->at("Purple");
        break;
    case gm::Background::Yellow:
        _sprite = this->backgrounds->at("Yellow");
        break;
    default:
        break;
    }

    this->window->draw(*_sprite);

    /*
    if (_sprite != nullptr) {
        _sprite->setOrigin(_sprite->getLocalBounds().width / 2.f,_sprite->getLocalBounds().height / 2.f);
        _sprite->setPosition(_sprite->getLocalBounds().width / 2.f,_sprite->getLocalBounds().height / 2.f);
        _sprite->setTextureRect(sf::IntRect(-_sprite->getLocalBounds().left, _sprite->getLocalBounds().top - 20.f, _sprite->getLocalBounds().width, _sprite->getLocalBounds().height));
        this->window->draw(*_sprite);
    }
    */
}