#ifndef OPTION_H
#define OPTION_H

#include <cmath>
#include <raylib.h>
#include "../gui/Button.h"
#include "../scenes/Scene.h"
#include "../scenes/SceneMainMenu.h"
#include "keybind/keybinding_screen.h"

class Options : public Scene {
public:
    Options();
    ~Options();

    void render() override;

    static void ButtonMusic();
    static void SetMusic(Music &music);
    static void ButtonVSync();
    static void ButtonResolution();
    static void OpenKeybindings();
    static void ButtonFullscreen();
    static void Back();

    static int GetScreenWidth() { return screenWidth; }
    static int GetScreenHeight() { return screenHeight; }
    static int getIndex();

private:
    void initializeButtons();
    void cleanupButtons();
    void renderButtons();
    static void toggleVSync();
    static void updateResolution();
    static void changeResolution(int width, int height);
    static void updateButtonPositions();

    inline static Button* musicButton = nullptr;
    inline static Button* vsyncButton = nullptr;
    inline static Button* resolutionButton = nullptr;
    inline static Button* keybindingsButton = nullptr;
    inline static Button* backButton = nullptr;
    inline static Button* fullscreenButton = nullptr;
    inline static Music* music = nullptr;

    inline static bool pause = false;
    inline static int index = 1;
    inline static int screenWidth = 1280;
    inline static int screenHeight = 720;
    inline static const char* resolutions[3] = { "800x600", "1280x720", "1920x1080" };
};

#endif // OPTION_H
