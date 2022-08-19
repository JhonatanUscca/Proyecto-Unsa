#include "./Character.h"

bool flip = false;

Character::Character(float _speed, float _jump, std::string _character, std::map<std::string, sf::Keyboard::Key> *_controls) : Entity("Character")
{
    this->speed = _speed;
    this->jump = _jump;
    this->canJump = true;
    this->controls = _controls;
    this->textures = new std::map<std::string, sf::Texture *>;
    this->animation = 1;
    this->iterAnimation = 0;
    this->gravity = 5.0f;

    sf::Texture *_texture_idle = new sf::Texture;
    sf::Texture *_texture_jump = new sf::Texture;
    sf::Texture *_texture_fall = new sf::Texture;
    sf::Texture *_texture_run = new sf::Texture;

    _texture_idle->loadFromFile("./src/Assets/Textures/Main Characters/" + _character + "/Idle (32x32).png");
    _texture_jump->loadFromFile("./src/Assets/Textures/Main Characters/" + _character + "/Jump (32x32).png");
    _texture_fall->loadFromFile("./src/Assets/Textures/Main Characters/" + _character + "/Fall (32x32).png");
    _texture_run->loadFromFile("./src/Assets/Textures/Main Characters/" + _character + "/Run (32x32).png");

    this->textures->insert(std::pair<std::string, sf::Texture *>("idle", _texture_idle));
    this->textures->insert(std::pair<std::string, sf::Texture *>("jump", _texture_jump));
    this->textures->insert(std::pair<std::string, sf::Texture *>("fall", _texture_fall));
    this->textures->insert(std::pair<std::string, sf::Texture *>("run", _texture_run));

    sf::Sprite *_sprite = new sf::Sprite;
    _sprite->setScale(1.25f, 1.25f);
    _sprite->setTexture(*this->textures->at("idle"));
    _sprite->setTextureRect(sf::IntRect(0, 0, 32, 32));
    _sprite->setOrigin(_sprite->getLocalBounds().width / 2.f, _sprite->getLocalBounds().height / 2.f);
    this->setSprite(_sprite);
}

Character::~Character()
{
    delete this;
}

void Character::animate(int _animation)
{
    int max = 0;
    switch (_animation)
    {
    case gm::Animation::IdleCharacter:
        max = 11;
        this->getSprite()->setTextureRect(sf::IntRect(this->iterAnimation * 32, 0, 32, 32));
        this->getSprite()->setScale(1.25f, 1.25f);
        this->iterAnimation++;
        if (this->iterAnimation == max) {
            this->iterAnimation = 0;
        } 
        break;
    case gm::Animation::RunCharacterL:
        max = 12;
        this->getSprite()->setTextureRect(sf::IntRect(this->iterAnimation * 32, 0, 32, 32));
        this->iterAnimation++;
        if (this->iterAnimation == max) {
            this->iterAnimation = 0;
        } 
        break;
    case gm::Animation::RunCharacterR:
        max = 12;
        this->getSprite()->setTextureRect(sf::IntRect(this->iterAnimation * 32, 0, 32, 32));
        this->iterAnimation++;
        if (this->iterAnimation == max) {
            this->iterAnimation = 0;
        } 
        break;
    }
}

void Character::move(sf::Event *_event)
{
    sf::Vector2f *translate = new sf::Vector2f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        if (this->animation != gm::Animation::RunCharacterL) {
            this->getSprite()->setTexture(*this->textures->at("run"));
            this->animation = gm::Animation::RunCharacterL;
        }
        translate->x -= this->speed;
        this->setDirection(sf::Vector2f(-1.f, 0.f));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        if (this->animation != gm::Animation::RunCharacterR) {
            this->getSprite()->setTexture(*this->textures->at("run"));
            this->animation = gm::Animation::RunCharacterR;
        }
        translate->x += this->speed;
        this->setDirection(sf::Vector2f(1.f, 0.f));
    }

    if (translate->x < 0) {
        flip = true;
    } else if (translate->x > 0) {
        flip = false;
    }

    if (flip) {
        this->getSprite()->setScale(-1.25f, 1.25f);
    } else {
        this->getSprite()->setScale(1.25f, 1.25f);
    }

    if (translate->x != 0.f)
        translate->x /= std::sqrt(2.f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && this->canJump)
    {
        this->canJump = false;
        translate->y = -std::sqrt(2.f * 9.810f * this->jump);
    }

    if (this->fall)
        translate->y += std::sqrt(2.f * this->getGravity() * 5.f);

    this->getSprite()->move(*translate);
}

std::map<std::string, sf::Keyboard::Key> *Character::getControls()
{
    return this->controls;
}

std::map<std::string, sf::Texture *> *Character::getTextures()
{
    return this->textures;
}

void Character::events(sf::Event *_event)
{

    this->move(_event);
}

void Character::draw(sf::RenderWindow *_window)
{
    _window->draw(*this->getSprite());
    this->animate(this->animation);
}

float Character::getGravity() {
    return this->gravity;
}

sf::Vector2f Character::isCollitionWith(Entity *_entity, sf::Vector2f _direction) {
    sf::Vector2f _dir = Entity::isCollitionWith(_entity, _direction);
    if (_dir.y == 0.f) {
        this->fall = true;
        this->setDirection(sf::Vector2f(0.f, 1.f));
    } else {
        this->fall = false;
        this->canJump = true;
    }
}