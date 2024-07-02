#include "raylib.h"
#include "scenes/SceneMainMenu.h"
#include "option/option.h"
#include "util/SceneManager.h"
#include "util/GUIManager.h"
//#define ASSETS_PATH "./assets/"


int main() {
    std::cout.sync_with_stdio(false); // otherwise cout will murder the game for some reason, more info (last accesssed 2024-07-02) here https://www.reddit.com/r/cpp_questions/comments/14okbgn/bizarre_problem_with_cout_in_c/ and here https://cplusplus.com/forum/beginner/140381/ .
    SetConfigFlags(FLAG_VSYNC_HINT);
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
        //ClearBackground(DARKGRAY);

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
    delete menu;

    return 0;
}