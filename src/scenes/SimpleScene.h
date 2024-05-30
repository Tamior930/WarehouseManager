//
// Created by if23b269 on 30.04.24.
//

#ifndef SIMPLESCENE_H
#define SIMPLESCENE_H
#include "vector"
#include <iostream>
#include "raylib.h"

#include "Scene.h"

class SimpleScene : public Scene
{

public:
    SimpleScene();
    void render() override;

private:
};



#endif //SIMPLESCENE_H
