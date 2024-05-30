// Created by if23b269 on 15.04.24

#include "raylib.h"
#include "scenes/SceneMainMenu.h"
#include "option/option.h"
#include "util/SceneManager.h"
#include "util/GUIManager.h"

int main() {
    InitWindow(Options::GetScreenWidth(), Options::GetScreenHeight(), "Warehouse Manager");

    InitAudioDevice();
    Music music = LoadMusicStream(ASSETS_PATH "PixelMusic.mp3");
    PlayMusicStream(music);
    Options::SetMusic(music);

    Image icon = LoadImage(ASSETS_PATH "PixelIcon.png");
    SetWindowIcon(icon);
    UnloadImage(icon);

    SetTargetFPS(60);
    SetExitKey(0);

    SceneMainMenu *menu = new SceneMainMenu("Warehouse Manager");
    SceneManager::LoadScene(menu);

    while (!GUIManager::ShouldClose) {
        UpdateMusicStream(music);

        BeginDrawing();
        ClearBackground(DARKGRAY);

        if (SceneManager::SceneLoaded()) {
            SceneManager::Update();
        }

        if (WindowShouldClose()) {
            GUIManager::ShouldClose = true;
        }

        EndDrawing();
    }

    UnloadMusicStream(music);
    CloseAudioDevice();
    CloseWindow();

    return 0;
}

