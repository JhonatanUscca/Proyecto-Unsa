#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <memory>

#include "./Managers/Game.Manager/Game.Manager.h"

int main(int argc, char *argv[])
{
    std::string name = "No botes la basura!";
    std::unique_ptr<sf::VideoMode> video = std::make_unique<sf::VideoMode>(800, 640, 32);
    GameManager *game = new GameManager(video, name);
    game->render();
    return 0;
}