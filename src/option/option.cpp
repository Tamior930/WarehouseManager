// Created by if23b269 on 15.04.24.

#include "option.h"

bool Options::musicOn = true;
bool Options::vsyncOn = true;
int Options::resolutionIndex = 1;
int Options::screenWidth = 1280;
int Options::screenHeight = 720;
const char* Options::resolutions[3] = { "800x600", "1280x720", "1920x1080" };
Music* Options::music = nullptr;

Button* Options::musicButton = nullptr;
Button* Options::vsyncButton = nullptr;
Button* Options::resolutionButton = nullptr;
Button* Options::keybindingsButton = nullptr;
Button* Options::backButton = nullptr;
Button* Options::fullscreenButton = nullptr;

float Options::musicAlpha = 0.0f;
float Options::vsyncAlpha = 0.0f;
float Options::resolutionAlpha = 0.0f;

float Options::fadeDuration = 1.0f;
float Options::musicTimer = 0.0f;
float Options::vsyncTimer = 0.0f;
float Options::resolutionTimer = 0.0f;

Options::Options() {
    musicButton = new Button("Toggle Music", screenWidth / 2 - 150, screenHeight - 600);
    vsyncButton = new Button("Toggle VSync", screenWidth / 2 - 150, screenHeight - 500);
    resolutionButton = new Button("Change Resolution", screenWidth / 2 - 150, screenHeight - 400);
    keybindingsButton = new Button("Keybindings", screenWidth / 2 - 150, screenHeight - 300);
    fullscreenButton = new Button("Toggle Fullscreen", screenWidth / 2 - 150, screenHeight - 200);
    backButton = new Button("Back", screenWidth / 2 - 150, screenHeight - 100);
}

Options::~Options() {
    delete musicButton;
    delete vsyncButton;
    delete resolutionButton;
    delete keybindingsButton;
    delete fullscreenButton;
    delete backButton;
}

void Options::render() {
    ClearBackground(DARKGRAY);

    DrawText("Options", screenWidth / 2 - MeasureText("Options", 40) / 2, 50, 40, BLACK);

    musicButton->render(ButtonMusic);
    vsyncButton->render(ButtonVSync);
    resolutionButton->render(ButtonResolution);
    keybindingsButton->render(ButtonKeybindings);
    fullscreenButton->render(ButtonFullscreen);
    backButton->render(ButtonBack);

    UpdateAlpha();

    DrawTextEx(GetFontDefault(), musicOn ? "Music: On" : "Music: Off",
               { (float)screenWidth / 2 + 150, (float)screenHeight - 600 },
               20, 1, Fade(WHITE, musicAlpha));

    DrawTextEx(GetFontDefault(), vsyncOn ? "VSync: On" : "VSync: Off",
               { (float)screenWidth / 2 + 150, (float)screenHeight - 500 },
               20, 1, Fade(WHITE, vsyncAlpha));

    DrawTextEx(GetFontDefault(), TextFormat("Resolution: %s", resolutions[resolutionIndex]),
               { (float)screenWidth / 2 + 150, (float)screenHeight - 400 },
               20, 1, Fade(WHITE, resolutionAlpha));

    DrawTextEx(GetFontDefault(), "Keybindings",
               { (float)screenWidth / 2 + 150, (float)screenHeight - 300 },
               20, 1, Fade(WHITE, resolutionAlpha));

    DrawTextEx(GetFontDefault(), IsWindowFullscreen() ? "Fullscreen: On" : "Fullscreen: Off",
               { (float)screenWidth / 2 + 150, (float)screenHeight - 200 },
               20, 1, Fade(WHITE, resolutionAlpha));
}

void Options::UpdateAlpha() {
    musicAlpha = fmin(1.0f, musicTimer / fadeDuration);
    vsyncAlpha = fmin(1.0f, vsyncTimer / fadeDuration);
    resolutionAlpha = fmin(1.0f, resolutionTimer / fadeDuration);

    musicTimer += GetFrameTime();
    vsyncTimer += GetFrameTime();
    resolutionTimer += GetFrameTime();

    if (musicAlpha == 1.0f) musicTimer = fadeDuration;
    if (vsyncAlpha == 1.0f) vsyncTimer = fadeDuration;
    if (resolutionAlpha == 1.0f) resolutionTimer = fadeDuration;
}

void Options::ButtonMusic() {
    musicOn = !musicOn;
    musicTimer = 0.0f;
    if (musicOn) {
        ResumeMusicStream(*music);
    } else {
        PauseMusicStream(*music);
    }
}

void Options::ButtonVSync() {
    vsyncOn = !vsyncOn;
    vsyncTimer = 0.0f;
    if (vsyncOn) {
        SetWindowState(FLAG_VSYNC_HINT);
    } else {
        ClearWindowState(FLAG_VSYNC_HINT);
    }
}

void Options::ButtonResolution() {
    resolutionIndex = (resolutionIndex + 1) % 3;
    resolutionTimer = 0.0f;
    const char* res = resolutions[resolutionIndex];

    if (strcmp(res, "800x600") == 0) {
        screenWidth = 800;
        screenHeight = 600;
    } else if (strcmp(res, "1280x720") == 0) {
        screenWidth = 1280;
        screenHeight = 720;
    } else if (strcmp(res, "1920x1080") == 0) {
        screenWidth = 1920;
        screenHeight = 1080;
    }

    SetWindowSize(screenWidth, screenHeight);
    updateButtonPositions();
    //SceneMainMenu::updateButtonPositions();
}

void Options::ButtonKeybindings() {
    SceneManager::LoadScene(new KeybindingScreen());
}

void Options::ButtonBack() {
    SceneMainMenu* menu = new SceneMainMenu("Warehouse Manager");
    SceneManager::LoadScene(menu);
}

void Options::ButtonFullscreen() {
    int display = GetCurrentMonitor();
    if (IsWindowFullscreen()) {
        SetWindowSize(screenWidth, screenHeight);
    } else {
        SetWindowSize(GetMonitorWidth(display), GetMonitorHeight(display));
    }
    ToggleFullscreen();
    updateButtonPositions();
    //SceneMainMenu::updateButtonPositions();
}

void Options::SetMusic(Music& musicRef) {
    music = &musicRef;
}

void Options::updateButtonPositions() {
    musicButton->SetPosition(screenWidth / 2 - 150, screenHeight - 600);
    vsyncButton->SetPosition(screenWidth / 2 - 150, screenHeight - 500);
    resolutionButton->SetPosition(screenWidth / 2 - 150, screenHeight - 400);
    keybindingsButton->SetPosition(screenWidth / 2 - 150, screenHeight - 300);
    fullscreenButton->SetPosition(screenWidth / 2 - 150, screenHeight - 200);
    backButton->SetPosition(screenWidth / 2 - 150, screenHeight - 100);
}

