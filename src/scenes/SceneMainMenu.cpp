// Created by if23b269 on 30.04.24.

#include "SceneMainMenu.h"
#include <utility>

SceneMainMenu::SceneMainMenu() {
    initButtons();
    _backgroundTexture = LoadBackgroundImage(ASSETS_PATH);
}

SceneMainMenu::SceneMainMenu(std::string title) : title(std::move(title)) {
    initButtons();
    _backgroundTexture = LoadBackgroundImage(ASSETS_PATH);
}

SceneMainMenu::~SceneMainMenu() {
    UnloadTexture(_backgroundTexture);
}

void SceneMainMenu::initButtons() {
    int screenWidth = Options::GetScreenWidth();
    int screenHeight = Options::GetScreenHeight();
    int buttonWidth = screenWidth * 0.3; // 30% of screen width
    int buttonHeight = screenHeight * 0.1; // 10% of screen height
    int buttonX = screenWidth / 2 - buttonWidth / 2;

    int buttonYIncrement = screenHeight * 0.15; // 15% of screen height for vertical spacing
    int startY = screenHeight * 0.2; // Start at 30% down the screen

    Play = new Button("Play", buttonX, startY, buttonWidth, buttonHeight);
    Option = new Button("Options", buttonX, startY + buttonYIncrement, buttonWidth, buttonHeight);
    Credit = new Button("Credits", buttonX, startY + 2 * buttonYIncrement, buttonWidth, buttonHeight);
    Quit = new Button("Quit", buttonX, startY + 3 * buttonYIncrement, buttonWidth, buttonHeight);
}

Texture2D SceneMainMenu::LoadBackgroundImage(const std::string& assetsPath)
{
    Image background = LoadImage((assetsPath + "background.png").c_str());
    ImageResize(&background, Options::GetScreenWidth(), Options::GetScreenHeight());
    Texture2D backgroundImage = LoadTextureFromImage(background);
    UnloadImage(background);
    return backgroundImage;
}

void SceneMainMenu::updateButtonPositions() {
    int screenWidth = Options::GetScreenWidth();
    int screenHeight = Options::GetScreenHeight();
    int buttonWidth = screenWidth * 0.3; // 30% of screen width
    int buttonHeight = screenHeight * 0.1; // 10% of screen height
    int buttonX = screenWidth / 2 - buttonWidth / 2;

    int buttonYIncrement = screenHeight * 0.15; // 15% of screen height for vertical spacing
    int startY = screenHeight * 0.3; // Start at 30% down the screen

    Play->SetPosition(buttonX, startY);
    Option->SetPosition(buttonX, startY + buttonYIncrement);
    Credit->SetPosition(buttonX, startY + 2 * buttonYIncrement);
    Quit->SetPosition(buttonX, startY + 3 * buttonYIncrement);
}

void SceneMainMenu::ButtonQuit() {
    std::cout << "Button QUIT was pressed" << std::endl;
    GUIManager::ShouldClose = true;
}

void SceneMainMenu::BacktoMenu() {
    GUIManager::ShouldClose = true;
}

void SceneMainMenu::EmptyFunctionTMP() {
    // Placeholder function, no implementation needed
}

void SceneMainMenu::_LoadScene() {
    auto* level = new Level();
    SceneManager::LoadScene(level);
}

void SceneMainMenu::_LoadOption() {
    auto* config = new Options();
    SceneManager::LoadScene(config);
}

void SceneMainMenu::render() {
    GUIManager::WriteText(title, 0, 40, 45, 1);

    DrawText("", 2, Options::GetScreenHeight() - 22, 20, WHITE);
    DrawRectangle(Options::GetScreenWidth() / 3, 90, Options::GetScreenWidth() / 3, 2, BLACK);
    DrawTexture(_backgroundTexture, 0, 0, WHITE);

    Play->render(_LoadScene);
    Option->render(_LoadOption);
    Credit->render(EmptyFunctionTMP);
    Quit->render(ButtonQuit);
}
