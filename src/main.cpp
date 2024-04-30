//
// Created by if23b269 on 15.04.24.
//

#include "raylib.h"
#include "scenes/SceneMainMenu.h"
//#define ASSETS_PATH "./assets/"
constexpr auto SCREEN_WIDTH  = 800;
constexpr auto SCREEN_HEIGHT = 450;

//Buttons: 2 - 150, GetScreenHeight() - 100
const int screenWidth = 1280;
const int screenHeight = 720;
int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Window title");
    SetTargetFPS(60);

    Texture2D texture = LoadTexture(ASSETS_PATH"test.png");

    /*
    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        const int texture_x = SCREEN_WIDTH / 2 - texture.width / 2;
        const int texture_y = SCREEN_HEIGHT / 2 - texture.height / 2;
        DrawTexture(texture, texture_x, texture_y, WHITE);

        const char* text = "OMG! IT WORKS!";
        const Vector2 text_size = MeasureTextEx(GetFontDefault(), text, 20, 1);
        DrawText(text, SCREEN_WIDTH / 2 - text_size.x / 2, texture_y + texture.height + text_size.y + 10, 20, BLACK);

        EndDrawing();
    }
    */
    InitWindow(screenWidth, screenHeight, "Warehouse Manager");
    InitAudioDevice();
    SetTargetFPS(60);
    SetExitKey(0);

    SceneMainMenu *menu = new SceneMainMenu("Warehouse Manager");

    SceneManager::LoadScene(menu);

    while (!GUIManager::ShouldClose)
    {
        BeginDrawing();

        ClearBackground(DARKGRAY);

        if(SceneManager::SceneLoaded())
        {
            SceneManager::Update();
        }

        if(WindowShouldClose())
        {
            GUIManager::ShouldClose = true;
        }

        EndDrawing();
    }
    CloseAudioDevice();
    CloseWindow();

    UnloadTexture(texture);

    CloseWindow();
    return 0;
}