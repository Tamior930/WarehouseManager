//
// Created by if23b269 on 13.05.24.
//

#include "Level.h"
#include "GraphicsLoader.h"
#include "../LevelManger/LevelManager.h"
#include <iostream>
#include "../util/GUIManager.h"
#define PLAYER_SIZE 40

Level::Level(): wall(), box_texture(), player_texture() {
    screenWidth = 1280;
    screenHeight = 720;
    currentLevel = 1;
    initLevel(currentLevel);

}

Level::~Level() {
    UnloadTextures(textures);
    for (auto p : playersCoordinates)
    {
        delete p;
    }
    playersCoordinates.clear();
    for (auto p : boxesCoordinates)
    {
        delete p;
    }
    boxesCoordinates.clear();
    for (auto p : finalPositionsCoordinates)
    {
        delete p;
    }
    finalPositionsCoordinates.clear();
    for (auto p : wallsCoordinates)
    {
        delete p;
    }
    wallsCoordinates.clear();
}

void Level::initLevel(int currentLevel)
{
    filename = std::string(ASSETS_PATH) + "level" + std::to_string(currentLevel);
    LevelManager lm;
    auto data = lm.readDataFromFile(filename);
    // create a vector
    playersCoordinates = std::vector<Vector2*>(0, nullptr);
    boxesCoordinates = std::vector<Vector2*>(0, nullptr);
    wallsCoordinates = std::vector<Vector2*>(0, nullptr);
    finalPositionsCoordinates = std::vector<Vector2*>(0, nullptr);
    flooringCoordinates = std::vector<Vector2*>(0, nullptr);
    lm.processDataFromVector(data,PLAYER_SIZE, playersCoordinates, boxesCoordinates, wallsCoordinates, flooringCoordinates, finalPositionsCoordinates);
    textures = LoadTextures(ASSETS_PATH, PLAYER_SIZE, currentLevel);
}

bool Level::moveBox(const Vector2& playerCoordinates, std::vector<Vector2*>& boxesCoordinates, int index, float screenWidth, float screenHeight, int key) {
    if ((key == 0 ) && playerCoordinates.y + PLAYER_SIZE < screenHeight -
        PLAYER_SIZE) {
        if (playerCoordinates.x == boxesCoordinates[index]->x && playerCoordinates.y == boxesCoordinates[index]->y) {
            boxesCoordinates[index]->y += PLAYER_SIZE;
            return true;
        }
    } else if ((key == 1) && playerCoordinates.y - PLAYER_SIZE > 0) {
        if (playerCoordinates.x == boxesCoordinates[index]->x && playerCoordinates.y == boxesCoordinates[index]->y) {
            boxesCoordinates[index]->y -= PLAYER_SIZE;
            return true;
        }
    } else if ((key == 2) && playerCoordinates.x + PLAYER_SIZE < screenWidth -
               PLAYER_SIZE) {
        if (playerCoordinates.x == boxesCoordinates[index]->x && playerCoordinates.y == boxesCoordinates[index]->y) {
            boxesCoordinates[index]->x += PLAYER_SIZE;
            return true;
        }
    } else if ((key == 3) && playerCoordinates.x - PLAYER_SIZE > 0) {
        if (playerCoordinates.x == boxesCoordinates[index]->x && playerCoordinates.y == boxesCoordinates[index]->y &&
            boxesCoordinates[index]->x - PLAYER_SIZE >= PLAYER_SIZE) {
            boxesCoordinates[index]->x -= PLAYER_SIZE;
            return true;
        }
    }
    return false;
}

bool Level::movePlayer(Vector2& playerCoordinates, const std::vector<Vector2*>& boxesCoordinates, int index, float screenWidth, float screenHeight, int key) {
    if ((key == 0 ) && playerCoordinates.y + PLAYER_SIZE < screenHeight -
        PLAYER_SIZE) {
        if (boxesCoordinates[index]->y!= screenHeight - PLAYER_SIZE * 2 || playerCoordinates.y + PLAYER_SIZE !=
            boxesCoordinates[index]->y ||
            playerCoordinates.x != boxesCoordinates[index]->x) {
            playerCoordinates.y += PLAYER_SIZE;
        }
        return true;
    } else if ((key == 1) && playerCoordinates.y - PLAYER_SIZE > 0) {
        if (boxesCoordinates[index]->y != PLAYER_SIZE || playerCoordinates.y - PLAYER_SIZE != boxesCoordinates[index]->y ||
            playerCoordinates.x != boxesCoordinates[index]->x) {
            playerCoordinates.y -= PLAYER_SIZE;
        }

        return true;
    } else if ((key == 2) && playerCoordinates.x + PLAYER_SIZE < screenWidth -
               PLAYER_SIZE) {
        if (boxesCoordinates[index]->x != screenWidth - PLAYER_SIZE * 2 || playerCoordinates.x + PLAYER_SIZE !=
            boxesCoordinates[index]->x ||
            playerCoordinates.y != boxesCoordinates[index]->y) {
            playerCoordinates.x += PLAYER_SIZE;
        }

        return true;
    } else if ((key == 3) && playerCoordinates.x - PLAYER_SIZE > 0) {
        if (boxesCoordinates[index]->x != PLAYER_SIZE || playerCoordinates.x - PLAYER_SIZE != boxesCoordinates[index]->x ||
            playerCoordinates.y != boxesCoordinates[index]->y) {
            playerCoordinates.x -= PLAYER_SIZE; //2:15, meeting 30 min
        }
        return true;
    }
    return false;
}

bool Level::movePlayerandBox(Vector2& playerCoordinates, std::vector<Vector2*>& boxesCoordinates, int index, float screenWidth, float screenHeight, int key) {
    if ((key == 0 ) && playerCoordinates.y + PLAYER_SIZE < screenHeight -
        PLAYER_SIZE) {
        if (boxesCoordinates[index]->y!= screenHeight - PLAYER_SIZE * 2 || playerCoordinates.y + PLAYER_SIZE !=
            boxesCoordinates[index]->y ||
            playerCoordinates.x != boxesCoordinates[index]->x) {
            playerCoordinates.y += PLAYER_SIZE;
        }

        if (playerCoordinates.x == boxesCoordinates[index]->x && playerCoordinates.y == boxesCoordinates[index]->y) {
            boxesCoordinates[index]->y += PLAYER_SIZE;
            return true;
        }
    } else if ((key == 1) && playerCoordinates.y - PLAYER_SIZE > 0) {
        if (boxesCoordinates[index]->y != PLAYER_SIZE || playerCoordinates.y - PLAYER_SIZE != boxesCoordinates[index]->y ||
            playerCoordinates.x != boxesCoordinates[index]->x) {
            playerCoordinates.y -= PLAYER_SIZE;
        }

        if (playerCoordinates.x == boxesCoordinates[index]->x && playerCoordinates.y == boxesCoordinates[index]->y) {
            boxesCoordinates[index]->y -= PLAYER_SIZE;
            return true;
        }
    } else if ((key == 2) && playerCoordinates.x + PLAYER_SIZE < screenWidth -
               PLAYER_SIZE) {
        if (boxesCoordinates[index]->x != screenWidth - PLAYER_SIZE * 2 || playerCoordinates.x + PLAYER_SIZE !=
            boxesCoordinates[index]->x ||
            playerCoordinates.y != boxesCoordinates[index]->y) {
            playerCoordinates.x += PLAYER_SIZE;
        }

        if (playerCoordinates.x == boxesCoordinates[index]->x && playerCoordinates.y == boxesCoordinates[index]->y) {
            boxesCoordinates[index]->x += PLAYER_SIZE;
            return true;
        }
    } else if ((key == 3) && playerCoordinates.x - PLAYER_SIZE > 0) {
        if (boxesCoordinates[index]->x != PLAYER_SIZE || playerCoordinates.x - PLAYER_SIZE != boxesCoordinates[index]->x ||
            playerCoordinates.y != boxesCoordinates[index]->y) {
            playerCoordinates.x -= PLAYER_SIZE; //2:15, meeting 30 min
        }

        if (playerCoordinates.x == boxesCoordinates[index]->x && playerCoordinates.y == boxesCoordinates[index]->y &&
            boxesCoordinates[index]->x - PLAYER_SIZE >= PLAYER_SIZE) {
            boxesCoordinates[index]->x -= PLAYER_SIZE;
            return true;
        }
    }
    return false;
}

bool Level::nextIsWall(float x, float y, const std::vector<Vector2*>& wallsCoordinates) {
    for (int i = 0 ; i < wallsCoordinates.size(); i++) {
        //std::cout << x << " == "<< wallsCoordinates[i].x << " && " << y << " == " << wallsCoordinates[i].y << std::endl;
        if (x == wallsCoordinates[i]->x && y == wallsCoordinates[i]->y) {
            return true;
        }
    }
    return false;
}

bool Level::nextIsBox(float x, float y, const std::vector<Vector2*>& boxesCoordinates) {
    for (int i = 0 ; i < boxesCoordinates.size(); i++) {
        //std::cout << x << " == "<< wallsCoordinates[i].x << " && " << y << " == " << wallsCoordinates[i].y << std::endl;
        if (x == boxesCoordinates[i]->x && y == boxesCoordinates[i]->y) {
            return true;
        }
    }
    return false;
}

void Level::drawBorder() {
    //DrawRectangleRec({0, 0, PLAYER_SIZE, PLAYER_SIZE}, BLUE);
    //ImageDrawRectangle(&cat, 0, 0, cat.width, cat.height, RED);
    DrawTexture(textures.wall, 0, 0, WHITE);


    for (int i = 1; i + 1 < screenWidth / PLAYER_SIZE + 1; i++) {
        //DrawRectangleRec({(float) PLAYER_SIZE * i, 0, PLAYER_SIZE, PLAYER_SIZE}, BLUE);
        DrawTexture(textures.wall, float(PLAYER_SIZE) * i, 0, RAYWHITE);
        DrawLineV((Vector2){(float) PLAYER_SIZE * i, PLAYER_SIZE},
                  (Vector2){(float) PLAYER_SIZE * i, (float) screenHeight - PLAYER_SIZE}, LIGHTGRAY);
        //DrawRectangleRec({(float) PLAYER_SIZE * i, (float) screenHeight - PLAYER_SIZE, PLAYER_SIZE, PLAYER_SIZE}, BLUE);
        DrawTexture(textures.wall, (float) PLAYER_SIZE * i, (float) screenHeight - PLAYER_SIZE, RAYWHITE);
    }

    for (int i = 1; i + 1 < screenHeight / PLAYER_SIZE + 1; i++) {
        //DrawRectangleRec({0, (float) PLAYER_SIZE * i, PLAYER_SIZE, PLAYER_SIZE}, BLUE);
        DrawTexture(textures.wall, 0, (float) PLAYER_SIZE * i, RAYWHITE);
        DrawLineV((Vector2){PLAYER_SIZE, (float) PLAYER_SIZE * i},
                  (Vector2){(float) screenWidth - PLAYER_SIZE, (float) PLAYER_SIZE * i}, LIGHTGRAY);
        //DrawRectangleRec({(float) screenWidth - PLAYER_SIZE, (float) PLAYER_SIZE * i, PLAYER_SIZE, PLAYER_SIZE}, BLUE);
        DrawTexture(textures.wall, (float) screenWidth - PLAYER_SIZE, (float) PLAYER_SIZE * i, RAYWHITE);
    }
}

void Level::drawCoordinates() {
    for (int i = 1; i + 1 < screenWidth / PLAYER_SIZE; i++) {
        for (int j = 1; j + 1 < screenHeight / PLAYER_SIZE; j++) {
            DrawText(TextFormat("[%i,%i]", i, j), 10 + PLAYER_SIZE * i, 15 + PLAYER_SIZE * j, 10, LIGHTGRAY);
        }
    }
}

bool Level::checkKeyUp(int index) {
    return IsKeyPressed(keysUp[index]) || IsKeyPressedRepeat(keysUp[index]);
}
bool Level::checkKeyDown(int index) {
    return IsKeyPressed(keysDown[index]) || IsKeyPressedRepeat(keysDown[index]);
}
bool Level::checkKeyRight(int index) {
    return IsKeyPressed(keysRight[index]) || IsKeyPressedRepeat(keysRight[index]);
}
bool Level::checkKeyLeft(int index) {
    return IsKeyPressed(keysLeft[index]) || IsKeyPressedRepeat(keysLeft[index]);
}

void Level::render() {
    Scene::render();

    // Update
    //----------------------------------------------------------------------------------
    //std::cout << screenHeight/player1.y + PLAYER_SIZE << " <y " << (screenHeight - PLAYER_SIZE) << std::endl;
    //std::cout << screenWidth/player1.x + PLAYER_SIZE << " < " << (screenWidth - PLAYER_SIZE) << std::endl;
    int playerId = 0;
    for (const auto& player : playersCoordinates) {

        float x = player->x;
        float y = player->y;
        int key = -1;
        bool boxNextWall = false;
        bool boxNextBox = false;

        if (checkKeyDown(playerId)) {
            y = player->y + PLAYER_SIZE;
            key = 0;
            boxNextWall = nextIsWall(x, PLAYER_SIZE + y, wallsCoordinates);
            boxNextBox = nextIsBox(x, PLAYER_SIZE + y, boxesCoordinates);
        } else if (checkKeyUp(playerId)) {
            y = player->y - PLAYER_SIZE;
            key = 1;
            boxNextWall = nextIsWall(x, y - PLAYER_SIZE, wallsCoordinates);
            boxNextBox = nextIsBox(x, y - PLAYER_SIZE, boxesCoordinates);
        } else if (checkKeyRight(playerId)) {
            x = player->x + PLAYER_SIZE;
            key = 2;
            boxNextWall = nextIsWall(x + PLAYER_SIZE, y, wallsCoordinates);
            boxNextBox = nextIsBox(x +  PLAYER_SIZE, y, boxesCoordinates);
        } else if (checkKeyLeft(playerId)) {
            x = player->x - PLAYER_SIZE;
            key = 3;
            boxNextWall = nextIsWall( x - PLAYER_SIZE, y, wallsCoordinates);
            boxNextBox = nextIsBox(x - PLAYER_SIZE, y, boxesCoordinates);
        }
        if (playerId < 4) {
            playerId++;
        }


        //0 && 440 == 440 880 == 920
        if (!nextIsWall(x, y, wallsCoordinates) && key != -1 && !won) {
            if (!nextIsBox(x,y, boxesCoordinates)) {
                movePlayer(*player, boxesCoordinates, 0, screenWidth, screenHeight, key);
            } else {
                if (!boxNextWall && !boxNextBox) {
                    movePlayer(*player, boxesCoordinates, 0, screenWidth, screenHeight, key);
                    for (int i = 0; i < boxesCoordinates.size(); i++)
                    {
                    moveBox(*player, boxesCoordinates, i, screenWidth, screenHeight, key);
                    }
                }
            }
        }
    }

    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    ClearBackground(RAYWHITE);

    // Draw full scene with first camera

    for (const auto& coord : flooringCoordinates) {
        DrawTexture(textures.flooring, coord->x, coord->y, WHITE);
    }
    for (const auto& coord : finalPositionsCoordinates) {
        DrawTexture(textures.target, coord->x, coord->y, WHITE);
    }
    for (const auto& coord : playersCoordinates) {
        DrawTexture(textures.player, coord->x, coord->y, WHITE);
    }
    for (const auto& coord : boxesCoordinates) {
        DrawTexture(textures.box, coord->x, coord->y, WHITE);
    }
    for (const auto& wallCoord : wallsCoordinates) {
        DrawTexture(textures.wall, wallCoord->x, wallCoord->y, RAYWHITE);
    }
    EndMode2D();

    DrawRectangle(0, 0, GetScreenWidth() / 2, 30, Fade(RAYWHITE, 0.6f));
    DrawText("PLAYER1: W/S/A/D to move", 10, 10, 10, MAROON);

    EndTextureMode();

    if (won) {
        WaitTime(0.2);

        currentLevel++;

        initLevel(currentLevel);
        std::cout << "newLevelLoaded";
        won = false;
        return;
    }

    //std::cout << boxesCoordinates[0]-> x << " == "<< finalPositionsCoordinates[0]->x << " && " << boxesCoordinates[0]-> y << " == " << finalPositionsCoordinates[0]->y << std::endl;
    int boxatFinal = 0;
    for (const auto& finalP : finalPositionsCoordinates) {
        for (const auto& box : boxesCoordinates) {
            if (box-> x  == finalP->x && box-> y  == finalP->y) {
                boxatFinal++;
            }
        }
    }
    if (boxatFinal == finalPositionsCoordinates.size()) {
        won = true;
    }
}
