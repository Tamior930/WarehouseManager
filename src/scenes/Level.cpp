//
// Created by if23b269 on 13.05.24.
//

#include "Level.h"

#include <iostream>
#define PLAYER_SIZE 40

Level::Level() {
    playerCoordinates = Vector2({PLAYER_SIZE * 15, PLAYER_SIZE * 8});
    //player1 = {200, 200, PLAYER_SIZE, PLAYER_SIZE};
    boxesCoordinates.push_back(Vector2({PLAYER_SIZE * 19, PLAYER_SIZE * 8}));
    boxesCoordinates.push_back(Vector2({PLAYER_SIZE * 23, PLAYER_SIZE * 9}));
    finalPositionsCoordinates.push_back(Vector2({(float) PLAYER_SIZE * 7.5, (float) PLAYER_SIZE * 8.5}));

    //wallsCoordinates.push_back(Vector2({PLAYER_SIZE * 23, PLAYER_SIZE * 9}));
    wallsCoordinates.push_back(Vector2({(float) PLAYER_SIZE * 8, (float) PLAYER_SIZE * 6}));
    wallsCoordinates.push_back(Vector2({(float) PLAYER_SIZE * 8, (float) PLAYER_SIZE * 7}));
    wallsCoordinates.push_back(Vector2({(float) PLAYER_SIZE * 8, (float) PLAYER_SIZE * 8}));
    wallsCoordinates.push_back(Vector2({(float) PLAYER_SIZE * 8, (float) PLAYER_SIZE * 9}));
    wallsCoordinates.push_back(Vector2({(float) PLAYER_SIZE * 8, (float) PLAYER_SIZE * 10}));
    wallsCoordinates.push_back(Vector2({(float) PLAYER_SIZE * 22, (float) PLAYER_SIZE * 6}));
    wallsCoordinates.push_back(Vector2({(float) PLAYER_SIZE * 22, (float) PLAYER_SIZE * 7}));
    wallsCoordinates.push_back(Vector2({ (float) PLAYER_SIZE * 22, (float) PLAYER_SIZE * 8}));
    wallsCoordinates.push_back(Vector2({(float) PLAYER_SIZE * 22, (float) PLAYER_SIZE * 9}));
    wallsCoordinates.push_back(Vector2({(float) PLAYER_SIZE * 22, (float) PLAYER_SIZE * 10})); // 880 x 400

    loadImages();
}

void Level::loadImages() {
    Image wallI = LoadImage(ASSETS_PATH"wall/wall example.png");
    Image playerI = LoadImage(ASSETS_PATH"idee1_vorne_farbideen.png");
    Image boxI = LoadImage(ASSETS_PATH"boxes/boxOne_twoRedLabel.png");
    // Load image in CPU memory (RAM)// Flip cropped image horizontally
    ImageResize(&playerI, PLAYER_SIZE, PLAYER_SIZE);
    ImageResize(&wallI, PLAYER_SIZE, PLAYER_SIZE);
    ImageResize(&boxI, PLAYER_SIZE, PLAYER_SIZE);
    this -> wall = LoadTextureFromImage(wallI);
    this -> box_texture = LoadTextureFromImage(boxI);
    this -> player_texture = LoadTextureFromImage(playerI);
    UnloadImage(wallI);
    UnloadImage(boxI);
    UnloadImage(playerI);
}

bool moveBox(Vector2& playerCoordinates, std::vector<Vector2>& boxesCoordinates, int index, int screenWidth, int screenHeight, int key) {
    if ((key == 0 ) && playerCoordinates.y + PLAYER_SIZE < screenHeight -
        PLAYER_SIZE) {
        if (playerCoordinates.x == boxesCoordinates[index].x && playerCoordinates.y == boxesCoordinates[index].y) {
            boxesCoordinates[index].y += PLAYER_SIZE;
            return true;
        }
    } else if ((key == 1) && playerCoordinates.y - PLAYER_SIZE > 0) {
        if (playerCoordinates.x == boxesCoordinates[index].x && playerCoordinates.y == boxesCoordinates[index].y) {
            boxesCoordinates[index].y -= PLAYER_SIZE;
            return true;
        }
    } else if ((key == 2) && playerCoordinates.x + PLAYER_SIZE < screenWidth -
               PLAYER_SIZE) {
        if (playerCoordinates.x == boxesCoordinates[index].x && playerCoordinates.y == boxesCoordinates[index].y) {
            boxesCoordinates[index].x += PLAYER_SIZE;
            return true;
        }
    } else if ((key == 3) && playerCoordinates.x - PLAYER_SIZE > 0) {
        if (playerCoordinates.x == boxesCoordinates[index].x && playerCoordinates.y == boxesCoordinates[index].y &&
            boxesCoordinates[index].x - PLAYER_SIZE >= PLAYER_SIZE) {
            boxesCoordinates[index].x -= PLAYER_SIZE;
            return true;
        }
    }
    return false;
}

bool movePlayer(Vector2& playerCoordinates, std::vector<Vector2>& boxesCoordinates, int index, int screenWidth, int screenHeight, int key) {
    if ((key == 0 ) && playerCoordinates.y + PLAYER_SIZE < screenHeight -
        PLAYER_SIZE) {
        if (boxesCoordinates[index].y!= screenHeight - PLAYER_SIZE * 2 || playerCoordinates.y + PLAYER_SIZE !=
            boxesCoordinates[index].y ||
            playerCoordinates.x != boxesCoordinates[index].x) {
            playerCoordinates.y += PLAYER_SIZE;
        }
        return true;
    } else if ((key == 1) && playerCoordinates.y - PLAYER_SIZE > 0) {
        if (boxesCoordinates[index].y != PLAYER_SIZE || playerCoordinates.y - PLAYER_SIZE != boxesCoordinates[index].y ||
            playerCoordinates.x != boxesCoordinates[index].x) {
            playerCoordinates.y -= PLAYER_SIZE;
        }

        return true;
    } else if ((key == 2) && playerCoordinates.x + PLAYER_SIZE < screenWidth -
               PLAYER_SIZE) {
        if (boxesCoordinates[index].x != screenWidth - PLAYER_SIZE * 2 || playerCoordinates.x + PLAYER_SIZE !=
            boxesCoordinates[index].x ||
            playerCoordinates.y != boxesCoordinates[index].y) {
            playerCoordinates.x += PLAYER_SIZE;
        }

        return true;
    } else if ((key == 3) && playerCoordinates.x - PLAYER_SIZE > 0) {
        if (boxesCoordinates[index].x != PLAYER_SIZE || playerCoordinates.x - PLAYER_SIZE != boxesCoordinates[index].x ||
            playerCoordinates.y != boxesCoordinates[index].y) {
            playerCoordinates.x -= PLAYER_SIZE; //2:15, meeting 30 min
        }
        return true;
    }
    return false;
}

bool movePlayerandBox(Vector2& playerCoordinates, std::vector<Vector2>& boxesCoordinates, int index, int screenWidth, int screenHeight, int key) {
    if ((key == 0 ) && playerCoordinates.y + PLAYER_SIZE < screenHeight -
        PLAYER_SIZE) {
        if (boxesCoordinates[index].y!= screenHeight - PLAYER_SIZE * 2 || playerCoordinates.y + PLAYER_SIZE !=
            boxesCoordinates[index].y ||
            playerCoordinates.x != boxesCoordinates[index].x) {
            playerCoordinates.y += PLAYER_SIZE;
        }

        if (playerCoordinates.x == boxesCoordinates[index].x && playerCoordinates.y == boxesCoordinates[index].y) {
            boxesCoordinates[index].y += PLAYER_SIZE;
            return true;
        }
    } else if ((key == 1) && playerCoordinates.y - PLAYER_SIZE > 0) {
        if (boxesCoordinates[index].y != PLAYER_SIZE || playerCoordinates.y - PLAYER_SIZE != boxesCoordinates[index].y ||
            playerCoordinates.x != boxesCoordinates[index].x) {
            playerCoordinates.y -= PLAYER_SIZE;
        }

        if (playerCoordinates.x == boxesCoordinates[index].x && playerCoordinates.y == boxesCoordinates[index].y) {
            boxesCoordinates[index].y -= PLAYER_SIZE;
            return true;
        }
    } else if ((key == 2) && playerCoordinates.x + PLAYER_SIZE < screenWidth -
               PLAYER_SIZE) {
        if (boxesCoordinates[index].x != screenWidth - PLAYER_SIZE * 2 || playerCoordinates.x + PLAYER_SIZE !=
            boxesCoordinates[index].x ||
            playerCoordinates.y != boxesCoordinates[index].y) {
            playerCoordinates.x += PLAYER_SIZE;
        }

        if (playerCoordinates.x == boxesCoordinates[index].x && playerCoordinates.y == boxesCoordinates[index].y) {
            boxesCoordinates[index].x += PLAYER_SIZE;
            return true;
        }
    } else if ((key == 3) && playerCoordinates.x - PLAYER_SIZE > 0) {
        if (boxesCoordinates[index].x != PLAYER_SIZE || playerCoordinates.x - PLAYER_SIZE != boxesCoordinates[index].x ||
            playerCoordinates.y != boxesCoordinates[index].y) {
            playerCoordinates.x -= PLAYER_SIZE; //2:15, meeting 30 min
        }

        if (playerCoordinates.x == boxesCoordinates[index].x && playerCoordinates.y == boxesCoordinates[index].y &&
            boxesCoordinates[index].x - PLAYER_SIZE >= PLAYER_SIZE) {
            boxesCoordinates[index].x -= PLAYER_SIZE;
            return true;
        }
    }
    return false;
}

bool nextIsWall(int x, int y, std::vector<Vector2>& wallsCoordinates) {
    for (int i = 0 ; i < wallsCoordinates.size(); i++) {
        //std::cout << x << " == "<< wallsCoordinates[i].x << " && " << y << " == " << wallsCoordinates[i].y << std::endl;
        if (x == wallsCoordinates[i].x && y == wallsCoordinates[i].y) {
            return true;
        }
    }
    return false;
}

bool nextIsBox(int x, int y, std::vector<Vector2>& boxesCoordinates) {
    for (int i = 0 ; i < boxesCoordinates.size(); i++) {
        //std::cout << x << " == "<< wallsCoordinates[i].x << " && " << y << " == " << wallsCoordinates[i].y << std::endl;
        if (x == boxesCoordinates[i].x && y == boxesCoordinates[i].y) {
            return true;
        }
    }
    return false;
}

void Level::render() {
    Scene::render();

    const int screenWidth = 1280;
    const int screenHeight = 720;

    // Update
    //----------------------------------------------------------------------------------
    //std::cout << screenHeight/player1.y + PLAYER_SIZE << " <y " << (screenHeight - PLAYER_SIZE) << std::endl;
    //std::cout << screenWidth/player1.x + PLAYER_SIZE << " < " << (screenWidth - PLAYER_SIZE) << std::endl;

    float x = playerCoordinates.x;
    float y = playerCoordinates.y;
    int key = -1;
    bool boxNextWall = false;

    if ((IsKeyPressed(KEY_S) || IsKeyPressedRepeat(KEY_S))) {
        y = playerCoordinates.y + PLAYER_SIZE;
        key = 0;
        boxNextWall = nextIsWall(x, PLAYER_SIZE + y, wallsCoordinates);
    } else if ((IsKeyPressed(KEY_W) || IsKeyPressedRepeat(KEY_W))) {
        y = playerCoordinates.y - PLAYER_SIZE;
        key = 1;
        boxNextWall = nextIsWall(x, y-PLAYER_SIZE, wallsCoordinates);
    } else if ((IsKeyPressed(KEY_D) || IsKeyPressedRepeat(KEY_D))) {
        x = playerCoordinates.x + PLAYER_SIZE;
        key = 2;
        boxNextWall = nextIsWall(x+PLAYER_SIZE, y, wallsCoordinates);
    } else if ((IsKeyPressed(KEY_A) || IsKeyPressedRepeat(KEY_A))) {
        x = playerCoordinates.x - PLAYER_SIZE;
        key = 3;
        boxNextWall = nextIsWall(x-PLAYER_SIZE, y, wallsCoordinates);
    }

    //0 && 440 == 440 880 == 920
    if (!nextIsWall(x, y, wallsCoordinates) && key != -1) {
        if (!nextIsBox(x,y, boxesCoordinates)) {
            movePlayer(playerCoordinates, boxesCoordinates, 0, screenWidth, screenHeight, key);
        } else {
            if (!boxNextWall) {
                movePlayer(playerCoordinates, boxesCoordinates, 0, screenWidth, screenHeight, key);
                moveBox(playerCoordinates, boxesCoordinates, 0, screenWidth, screenHeight, key);
            }
        }
    }

    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    ClearBackground(RAYWHITE);

    //DrawRectangleRec({0, 0, PLAYER_SIZE, PLAYER_SIZE}, BLUE);
    //ImageDrawRectangle(&cat, 0, 0, cat.width, cat.height, RED);
    DrawTexture(wall, 0, 0, WHITE);

    // Draw full scene with first camera
    for (int i = 1; i + 1 < screenWidth / PLAYER_SIZE + 1; i++) {
        //DrawRectangleRec({(float) PLAYER_SIZE * i, 0, PLAYER_SIZE, PLAYER_SIZE}, BLUE);
        DrawTexture(wall, (float) PLAYER_SIZE * i, 0, RAYWHITE);
        DrawLineV((Vector2){(float) PLAYER_SIZE * i, PLAYER_SIZE},
                  (Vector2){(float) PLAYER_SIZE * i, (float) screenHeight - PLAYER_SIZE}, LIGHTGRAY);
        //DrawRectangleRec({(float) PLAYER_SIZE * i, (float) screenHeight - PLAYER_SIZE, PLAYER_SIZE, PLAYER_SIZE}, BLUE);
        DrawTexture(wall, (float) PLAYER_SIZE * i, (float) screenHeight - PLAYER_SIZE, RAYWHITE);
    }

    for (int i = 1; i + 1 < screenHeight / PLAYER_SIZE + 1; i++) {
        //DrawRectangleRec({0, (float) PLAYER_SIZE * i, PLAYER_SIZE, PLAYER_SIZE}, BLUE);
        DrawTexture(wall, 0, (float) PLAYER_SIZE * i, RAYWHITE);
        DrawLineV((Vector2){PLAYER_SIZE, (float) PLAYER_SIZE * i},
                  (Vector2){(float) screenWidth - PLAYER_SIZE, (float) PLAYER_SIZE * i}, LIGHTGRAY);
        //DrawRectangleRec({(float) screenWidth - PLAYER_SIZE, (float) PLAYER_SIZE * i, PLAYER_SIZE, PLAYER_SIZE}, BLUE);
        DrawTexture(wall, (float) screenWidth - PLAYER_SIZE, (float) PLAYER_SIZE * i, RAYWHITE);
    }

    /*
    for (int i = 1; i + 1 < screenWidth / PLAYER_SIZE; i++) {
        for (int j = 1; j + 1 < screenHeight / PLAYER_SIZE; j++) {
            DrawText(TextFormat("[%i,%i]", i, j), 10 + PLAYER_SIZE * i, 15 + PLAYER_SIZE * j, 10, LIGHTGRAY);
        }
    }
    */

    Rectangle player = {
        playerCoordinates.x, playerCoordinates.y, static_cast<float>(PLAYER_SIZE), static_cast<float>(PLAYER_SIZE)
    };
    Rectangle box = {
        boxesCoordinates[0].x, boxesCoordinates[0].y, static_cast<float>(PLAYER_SIZE), static_cast<float>(PLAYER_SIZE)
    };
    Rectangle box2 = {
        boxesCoordinates[1].x, boxesCoordinates[1].y, static_cast<float>(PLAYER_SIZE), static_cast<float>(PLAYER_SIZE)
    };
    //void DrawTextureRec(Texture2D texture, Rectangle source, Vector2 position, Color tint);
    DrawCircleV(finalPositionsCoordinates[0], 15, RED);
    DrawTextureRec(player_texture, player, playerCoordinates, WHITE);
    DrawTextureRec(box_texture, box, boxesCoordinates[0], WHITE);
    //DrawTextureRec(box_texture, box, boxesCoordinates[1], WHITE);
    DrawTexture(wall, (float) PLAYER_SIZE * 8, (float) PLAYER_SIZE * 6, RAYWHITE);
    DrawTexture(wall, (float) PLAYER_SIZE * 8, (float) PLAYER_SIZE * 7, RAYWHITE);
    DrawTexture(wall, (float) PLAYER_SIZE * 8, (float) PLAYER_SIZE * 8, RAYWHITE);
    DrawTexture(wall, (float) PLAYER_SIZE * 8, (float) PLAYER_SIZE * 9, RAYWHITE);
    DrawTexture(wall, (float) PLAYER_SIZE * 8, (float) PLAYER_SIZE * 10, RAYWHITE);
    DrawTexture(wall, (float) PLAYER_SIZE * 22, (float) PLAYER_SIZE * 6, RAYWHITE);
    DrawTexture(wall, (float) PLAYER_SIZE * 22, (float) PLAYER_SIZE * 7, RAYWHITE);
    DrawTexture(wall, (float) PLAYER_SIZE * 22, (float) PLAYER_SIZE * 8, RAYWHITE);
    DrawTexture(wall, (float) PLAYER_SIZE * 22, (float) PLAYER_SIZE * 9, RAYWHITE);
    DrawTexture(wall, (float) PLAYER_SIZE * 22, (float) PLAYER_SIZE * 10, RAYWHITE);

    //DrawTextureV(player_texture, playerCoordinates, WHITE);
    //DrawTexture(box, 400, 400, WHITE);

    EndMode2D();

    DrawRectangle(0, 0, GetScreenWidth() / 2, 30, Fade(RAYWHITE, 0.6f));
    DrawText("PLAYER1: W/S/A/D to move", 10, 10, 10, MAROON);

    EndTextureMode();

    //std::cout << playerCoordinates.x << " == "<< finalPositionsCoordinates[0].x << " && " << playerCoordinates.y << " == " << finalPositionsCoordinates[0].y << std::endl;
    if (playerCoordinates.x + PLAYER_SIZE/2 == finalPositionsCoordinates[0].x && playerCoordinates.y - PLAYER_SIZE/2 == finalPositionsCoordinates[0].y) {
        bool exitWindowRequested = false;   // Flag to request window to exit
        bool exitWindow = false;    // Flag to set window to exit
        // Update
        //----------------------------------------------------------------------------------
        // Detect if X-button or KEY_ESCAPE have been pressed to close window
        if (WindowShouldClose() || IsKeyPressed(KEY_ESCAPE)) exitWindowRequested = true;

        if (exitWindowRequested)
        {
            // A request for close window has been issued, we can save data before closing
            // or just show a message asking for confirmation

            if (IsKeyPressed(KEY_Y)) exitWindow = true;
            else if (IsKeyPressed(KEY_N)) exitWindowRequested = false;
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        if (exitWindowRequested)
        {
            DrawRectangle(0, 100, screenWidth, 200, BLACK);
            DrawText("Are you sure you want to exit program? [Y/N]", screenWidth/2, screenHeight/2, 30, WHITE);
        }
        else DrawText("First level won!", screenWidth/2-100, screenHeight/2.5, 20, BLACK);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }
}
