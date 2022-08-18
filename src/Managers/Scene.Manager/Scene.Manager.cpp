#include "./Scene.Manager.h"

SceneManager *SceneManager::sceneManager = nullptr;

SceneManager::SceneManager() : scenes(new std::stack<Scene *>) {}

SceneManager *SceneManager::get()
{
    if (sceneManager == nullptr)
    {
        sceneManager = new SceneManager();
    }
    return sceneManager;
}

void SceneManager::setSceneSave(int _scene)
{
    this->sceneSave = _scene;
}

void SceneManager::push(sf::RenderWindow *_window, int _scene)
{
    this->scenes->push(SceneFactory::getScene(_window, _scene));
}

void SceneManager::pushSave(sf::RenderWindow *_window)
{
    this->pop();
    this->scenes->push(SceneFactory::getScene(_window, this->sceneSave));
}

void SceneManager::pop()
{
    this->scenes->pop();
}

Scene *SceneManager::top()
{
    return this->scenes->top();
}