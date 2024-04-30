//
// Created by if23b269 on 30.04.24.
//

#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "../scenes/Scene.h"

class SceneManager {
public:
    static void LoadScene(Scene* _scene);
    static void Update();
    static int SceneLoaded();
private:
    inline static int isSceneLoaded;
    inline static Scene *scene;
};



#endif //SCENEMANAGER_H
