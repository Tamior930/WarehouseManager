//
// Created by melvi on 2024-06-22.
//

#ifndef WAREHOUSEMANAGER_GRAPHICSLOADER_H
#define WAREHOUSEMANAGER_GRAPHICSLOADER_H


#include "raylib.h"
#include <string>

struct Textures {
    Texture2D wall;
    Texture2D box;
    Texture player;
    Texture2D target;
    Texture2D flooring;

};

Textures LoadTextures(const std::string& assetsPath, const int playerSize, int currentLevel);
void UnloadTextures(Textures& textures);

#endif //WAREHOUSEMANAGER_GRAPHICSLOADER_H
