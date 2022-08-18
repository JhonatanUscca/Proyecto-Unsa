#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <SFML/Graphics.hpp>
#include <stack>

#include "./../../Scenes/Scene.h"

class SceneManager
{
protected:
    SceneManager();
    std::stack<Scene *> *scenes;
    int sceneSave;
    static SceneManager *sceneManager;

public:
    SceneManager(SceneManager &_other) = delete;
    void operator=(const SceneManager &) = delete;
    static SceneManager *get();
    Scene *top();
    void setSceneSave(int);
    void push(sf::RenderWindow *, int);
    void pushSave(sf::RenderWindow *);
    void pop();
    void home();
    Scene *getScene(int);
};

#include "./../../Factories/Scene.Factory/Scene.Factory.h"
#include "./Scene.Manager.cpp"

#endif