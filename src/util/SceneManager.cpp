//
// Created by if23b269 on 30.04.24.
//

#include "SceneManager.h"

void SceneManager::LoadScene(Scene *_scene)
{
    delete scene;
    scene = _scene;
    isSceneLoaded = 1;
}

void SceneManager::Update() {
    scene->render();
}

int SceneManager::SceneLoaded() {
    return isSceneLoaded;
}
