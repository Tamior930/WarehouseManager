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
        void loadImages();
private:
    Vector2 playerCoordinates;
    std::vector<Vector2> boxesCoordinates;
    std::vector<Vector2> finalPositionsCoordinates;
    //walls, on the field
    std::vector<Vector2> wallsCoordinates;

    Texture2D wall;
    Texture2D box_texture;
    Texture player_texture;


    Textures textures;
};



#endif //LEVEL_H
