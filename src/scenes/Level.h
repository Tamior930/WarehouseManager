//
// Created by if23b269 on 13.05.24.
//

#ifndef LEVEL_H
#define LEVEL_H
#include <vector>

#include "Scene.h"
#include "GraphicsLoader.h"
#include "raylib.h"



class Level  : public Scene{
    public:
        Level();
        ~Level();
        void render() override;
private:
    Vector2 playerCoordinates;
    std::vector<Vector2> boxesCoordinates;
    Textures textures;
};



#endif //LEVEL_H
