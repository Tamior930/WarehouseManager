// Created by if23b269 on 15.04.24.

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
    static void ButtonVSync();
    static void ButtonResolution();
    static void ButtonKeybindings();
    static void ButtonFullscreen();
    static void ButtonBack();
    static void SetMusic(Music &music);
    static void UpdateAlpha();
    static void updateButtonPositions();
    static int GetScreenWidth() { return screenWidth; }
    static int GetScreenHeight() { return screenHeight; }

private:
    static Button *musicButton, *vsyncButton, *resolutionButton, *keybindingsButton, *backButton, *fullscreenButton;
    static bool musicOn, vsyncOn;
    static int resolutionIndex, screenWidth, screenHeight;
    static const char* resolutions[3];
    static Music* music;
    static float musicAlpha, vsyncAlpha, resolutionAlpha;
    static float fadeDuration;
    static float musicTimer, vsyncTimer, resolutionTimer;
};

#endif // OPTION_H

