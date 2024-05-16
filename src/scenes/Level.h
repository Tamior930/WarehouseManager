//
// Created by if23b269 on 13.05.24.
//

#ifndef LEVEL_H
#define LEVEL_H
#include <vector>

#include "Scene.h"

#include "raylib.h"



class Level  : public Scene{
    public:
        Level();
        void render() override;
private:
    Vector2 playerCoordinates;
    std::vector<Vector2> boxesCoordinates;

};



#endif //LEVEL_H
