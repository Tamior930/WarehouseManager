//
// Created by melvi on 2024-06-22.
//

#include "GraphicsLoader.h"


Textures LoadTextures(const std::string& assetsPath, const int playerSize, int currentLevel) {
    Textures textures;
    int PLAYER_SIZE = playerSize;
    // Load images
    currentLevel = currentLevel % 3;
    if(currentLevel == 0)
    {currentLevel = 3;}

    Image wallI = LoadImage((assetsPath + "wall/" + std::to_string(currentLevel) + "/wall.png").c_str());
    Image playerI = LoadImage((assetsPath + "character/" + std::to_string(currentLevel) + "/character.png").c_str());
    Image boxI = LoadImage((assetsPath + "boxes/" + std::to_string(currentLevel) + "/box.png").c_str());
    Image targetI = LoadImage((assetsPath + "target/" + std::to_string(currentLevel) + "/target.png").c_str());
    Image flooringI = LoadImage((assetsPath + "flooring/" + std::to_string(currentLevel) + "/flooring.png").c_str());

    // Resize images
    ImageResize(&playerI, PLAYER_SIZE, PLAYER_SIZE);
    ImageResize(&wallI, PLAYER_SIZE, PLAYER_SIZE);
    ImageResize(&boxI, PLAYER_SIZE, PLAYER_SIZE);
    ImageResize(&targetI, PLAYER_SIZE, PLAYER_SIZE);
    ImageResize(&flooringI, PLAYER_SIZE, PLAYER_SIZE);

    // Load textures from images
    textures.wall = LoadTextureFromImage(wallI);
    textures.box = LoadTextureFromImage(boxI);
    textures.player = LoadTextureFromImage(playerI);
    textures.target = LoadTextureFromImage(targetI);
    textures.flooring = LoadTextureFromImage(flooringI);

    // Unload images from memory
    UnloadImage(wallI);
    UnloadImage(boxI);
    UnloadImage(playerI);
    UnloadImage(targetI);
    UnloadImage(flooringI);

    return textures;
}

void UnloadTextures(Textures& textures) {
    UnloadTexture(textures.wall);
    UnloadTexture(textures.box);
    UnloadTexture(textures.player);
    UnloadTexture(textures.target);
    UnloadTexture(textures.flooring);
}