//
// Created by if23b269 on 13.05.24.
//

#ifndef LEVEL_H
#define LEVEL_H
#include <vector>

#include "Scene.h"
#include "GraphicsLoader.h"
#include "../option/option.h"
#include "raylib.h"



class Level  : public Scene{
    public:
        Level();
        std::string filename;
        int currentLevel;
        ~Level();
        void initLevel(int currentLevel);
        void render() override;
    bool moveBox(const Vector2 &playerCoordinates, std::vector<Vector2*> &boxesCoordinates, int index, float screenWidth, float
                 screenHeight, int key);
    bool movePlayer(Vector2 &playerCoordinates, const std::vector<Vector2*> &boxesCoordinates, int index, float screenWidth, float
                    screenHeight, int key);
    bool movePlayerandBox(Vector2 &playerCoordinates, std::vector<Vector2*> &boxesCoordinates, int index, float screenWidth, float screenHeight, int
                          key);
    bool nextIsWall(float x, float y, const std::vector<Vector2*> &wallsCoordinates);
    bool nextIsBox(float x, float y, const std::vector<Vector2*> &boxesCoordinates);
    void drawCoordinates();
    void drawBorder();
    bool checkKeyUp(int index);
    bool checkKeyDown(int index);
    bool checkKeyRight(int index);
    bool checkKeyLeft(int index);
    void drawPlayerMovementKeyText(const char *text, int _posX, int _posY, int _width, int _height, int _fontSize, int textResolution);

private:
    float screenWidth;
    float screenHeight;
    float PLAYER_SIZE;
    std::vector<Vector2*> playersCoordinates;
    //ToDo: boxesCoordinates, finalPositionsCoordinates, wallsCoordinates umbauen mit Pointer wie playersCoordinates
    std::vector<Vector2*> boxesCoordinates;
    std::vector<Vector2*> finalPositionsCoordinates;
    //walls, on the field
    std::vector<Vector2*> wallsCoordinates;
    std::vector<Vector2*> flooringCoordinates;
    bool won = false;

    Texture2D wall;
    Texture2D box_texture;
    Texture player_texture;
    KeyboardKey keysUp[4] = {KEY_W, KEY_UP, KEY_T, KEY_I};
    KeyboardKey keysDown[4] = {KEY_S, KEY_DOWN, KEY_G, KEY_K};
    KeyboardKey keysRight[4] = {KEY_D, KEY_RIGHT, KEY_H, KEY_L};
    KeyboardKey keysLeft[4] = {KEY_A, KEY_LEFT, KEY_F, KEY_J};


    Textures textures;
};



#endif //LEVEL_H
