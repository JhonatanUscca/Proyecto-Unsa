#include "./Scene.Factory.h"

Scene *SceneFactory::getScene(sf::RenderWindow *_window, int _scene) {
    Scene * scn;
    switch (_scene)
    {
    case gm::Scene::TestScene:
        scn = new TestScene(_window);
        break;
    default:
        break;
    }
    return scn;
}