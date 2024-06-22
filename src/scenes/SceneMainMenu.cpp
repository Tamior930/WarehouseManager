//
// Created by if23b269 on 30.04.24.
//

#include "SceneMainMenu.h"

#include <utility>

SceneMainMenu::SceneMainMenu()
{
    initButtons();
}

SceneMainMenu::SceneMainMenu(std::string title) {
    initButtons();
    this -> title = std::move(title);
}

void SceneMainMenu::initButtons() {
    int screenWidth = Options::GetScreenWidth();
    int screenHeight = Options::GetScreenHeight();

    Quit    = new Button("Quit", screenWidth / 2 - 150, screenHeight - 100);
    Credit  = new Button("Credits", screenWidth / 2 - 150, screenHeight - 225);
    Option  = new Button("Options", screenWidth / 2 - 150, screenHeight - 350);
    Play    = new Button("Play", screenWidth / 2 - 150, screenHeight - 475);
}

void SceneMainMenu::updateButtonPositions() {
    int screenWidth = Options::GetScreenWidth();
    int screenHeight = Options::GetScreenHeight();

    Quit->SetPosition(screenWidth / 2 - 150, screenHeight - 100);
    Credit->SetPosition(screenWidth / 2 - 150, screenHeight - 225);
    Option->SetPosition(screenWidth / 2 - 150, screenHeight - 350);
    Play->SetPosition(screenWidth / 2 - 150, screenHeight - 475);
}

void SceneMainMenu::ButtonQuit()
{
    std::cout << "Button QUIT was pressed" << endl;

    GUIManager::ShouldClose = true;
}

void SceneMainMenu::BacktoMenu()
{
    GUIManager::ShouldClose = true;
}

void SceneMainMenu::EmptyFunctionTMP() {
}

void SceneMainMenu::_LoadScene()
{
    Level *level;
    level = new Level(ASSETS_PATH"level1");
    SceneManager::LoadScene(level);
}

void SceneMainMenu::_LoadOption() {
    Options *Config;
    Config = new Options();
    SceneManager::LoadScene(Config);
}

void SceneMainMenu::render() {
    GUIManager::WriteText(title, 0, 40, 45, 1);

    DrawText("", 2, Options::GetScreenHeight() - 22, 20, WHITE);
    DrawRectangle(Options::GetScreenWidth() / 3, 90, Options::GetScreenWidth() / 3, 2, BLACK);

    Quit->render(ButtonQuit);
    Credit->render(EmptyFunctionTMP);
    Option->render(_LoadOption);
    Play->render(_LoadScene);
}