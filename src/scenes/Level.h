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
    bool moveBox(const Vector2 &playerCoordinates, std::vector<Vector2> &boxesCoordinates, int index, float screenWidth, float
                 screenHeight, int key);
    bool movePlayer(Vector2 &playerCoordinates, const std::vector<Vector2> &boxesCoordinates, int index, float screenWidth, float
                    screenHeight, int key);
    bool movePlayerandBox(Vector2 &playerCoordinates, std::vector<Vector2> &boxesCoordinates, int index, float screenWidth, float screenHeight, int
                          key);
    bool nextIsWall(float x, float y, const std::vector<Vector2> &wallsCoordinates);
    bool nextIsBox(float x, float y, const std::vector<Vector2> &boxesCoordinates);

private:
    float screenWidth = 1280;
    float screenHeight = 720;
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
