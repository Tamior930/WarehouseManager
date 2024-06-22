//
// Created by melvi on 2024-06-22.
//

#include "GraphicsLoader.h"


Textures LoadTextures(const std::string& assetsPath, const int playerSize) {
    Textures textures;
    int PLAYER_SIZE = playerSize;
    // Load images
    Image wallI = LoadImage((assetsPath + "wall/wall_example.png").c_str());
    Image playerI = LoadImage((assetsPath + "idee1_vorne_farbideen.png").c_str());
    Image boxI = LoadImage((assetsPath + "boxes/boxOne_twoRedLabel.png").c_str());

    // Resize images
    ImageResize(&playerI, PLAYER_SIZE, PLAYER_SIZE);
    ImageResize(&wallI, PLAYER_SIZE, PLAYER_SIZE);
    ImageResize(&boxI, PLAYER_SIZE, PLAYER_SIZE);

    // Load textures from images
    textures.wall = LoadTextureFromImage(wallI);
    textures.box = LoadTextureFromImage(boxI);
    textures.player = LoadTextureFromImage(playerI);

    // Unload images from memory
    UnloadImage(wallI);
    UnloadImage(boxI);
    UnloadImage(playerI);

    return textures;
}

void UnloadTextures(Textures& textures) {
    UnloadTexture(textures.wall);
    UnloadTexture(textures.box);
    UnloadTexture(textures.player);
}