// Created by if23b269 on 15.04.24.

#include "option.h"

Options::Options()
{
    std::cout << "create options\n";
    initializeButtons();
    _backgroundImage = Options::LoadBackgroundImage(ASSETS_PATH);
}

Options::~Options()
{
    std::cout << "delete options\n";
    cleanupButtons();
    UnloadTexture(_backgroundImage);
}

void Options::initializeButtons()
{
    updateButtonPositions();
}

void Options::cleanupButtons()
{
    delete musicButton;
    delete vsyncButton;
    delete resolutionButton;
    delete keybindingsButton;
    delete fullscreenButton;
    delete backButton;
}

void Options::render()
{
    ClearBackground(BLUE);
    DrawTexture(_backgroundImage, 0, 0, WHITE);
    DrawText("Options", screenWidth / 2 - MeasureText("Options", 40) / 2, 50, 40, BLACK);

    if (_reloadImage == 1)
    {
        UnloadTexture(_backgroundImage);
        _backgroundImage = Options::LoadBackgroundImage(ASSETS_PATH);
        _reloadImage = 0;
    }

    renderButtons();
    }
    Texture2D Options::LoadBackgroundImage(const std::string& assetsPath)
    {
        Image background = LoadImage((assetsPath + "background.png").c_str());
        ImageResize(&background, Options::GetScreenWidth(), Options::GetScreenHeight());
        Texture2D backgroundImage = LoadTextureFromImage(background);
        UnloadImage(background);
        return backgroundImage;

}

void Options::renderButtons()
{
    musicButton->render(ButtonMusic);
    vsyncButton->render(ButtonVSync);
    resolutionButton->render(ButtonResolution);
    keybindingsButton->render(OpenKeybindings);
    fullscreenButton->render(ButtonFullscreen);
    backButton->render(Back);
}

void Options::ButtonMusic()
{
    pause = !pause;
    if (pause)
    {
        PauseMusicStream(*music);
    }
    else
    {
        ResumeMusicStream(*music);
    }
}

void Options::SetMusic(Music& musicRef)
{
    music = &musicRef;
}

void Options::ButtonVSync()
{
    bool wasFullscreen = IsWindowFullscreen();
    toggleVSync();
    if (wasFullscreen)
    {
        if (!IsWindowFullscreen())
        {
            ToggleFullscreen();
        }
    }
}

void Options::toggleVSync()
{
    if (IsWindowState(FLAG_VSYNC_HINT))
    {
        ClearWindowState(FLAG_VSYNC_HINT);
        SetTargetFPS(60);
    }
    else
    {
        SetWindowState(FLAG_VSYNC_HINT);
    }
}

void Options::ButtonResolution()
{
    index = (index + 1) % 3;
    updateResolution();
}

int Options::getIndex() {
    return index;
}

void Options::updateResolution()
{
    switch (index)
    {
        case 0:
            changeResolution(800, 450); break;
        case 1:
            changeResolution(1280, 720); break;
        case 2:
            changeResolution(1920, 1080); break;
        default: break;
    }
}

void Options::changeResolution(int width, int height)
{
    screenWidth = width;
    screenHeight = height;
    CloseWindow();
    InitWindow(screenWidth, screenHeight, "Warehouse Manager");
    _reloadImage = 1;
    updateButtonPositions();
}

void Options::updateButtonPositions()
{
    int buttonWidth = screenWidth * 0.3;
    int buttonHeight = screenHeight * 0.1;
    int buttonX = screenWidth / 2 - buttonWidth / 2;

    int buttonYIncrement = screenHeight * 0.15;
    int startY = screenHeight / 2 - (buttonYIncrement * 2.5);

    musicButton = new Button("Toggle Music", buttonX, startY, buttonWidth, buttonHeight);
    vsyncButton = new Button("Toggle VSync", buttonX, startY + buttonYIncrement, buttonWidth, buttonHeight);
    resolutionButton = new Button("Change Resolution", buttonX, startY + 2 * buttonYIncrement, buttonWidth, buttonHeight);
    keybindingsButton = new Button("Keybindings", buttonX, startY + 3 * buttonYIncrement, buttonWidth, buttonHeight);
    fullscreenButton = new Button("Toggle Fullscreen", buttonX, startY + 4 * buttonYIncrement, buttonWidth, buttonHeight);
    backButton = new Button("Back", buttonX, startY + 5 * buttonYIncrement, buttonWidth, buttonHeight);
}

void Options::OpenKeybindings()
{
    SceneManager::LoadScene(new KeybindingScreen());
}

void Options::ButtonFullscreen()
{
    if (IsWindowFullscreen())
    {
        ToggleFullscreen();
        SetWindowSize(screenWidth, screenHeight);
    }
    else
    {
        //int display = GetCurrentMonitor();
        //SetWindowSize(GetMonitorWidth(display), GetMonitorHeight(display));
        ToggleFullscreen();
    }
    updateButtonPositions();
}


void Options::Back()
{
    SceneManager::LoadScene(new SceneMainMenu ("Warehouse Manager"));
}
