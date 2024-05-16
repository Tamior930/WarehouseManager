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
    Quit = new Button("Quit", GetScreenWidth() / 2 - 150, GetScreenHeight() - 100);
    Credit = new Button("Credits", GetScreenWidth() / 2 - 150, GetScreenHeight() - 225);
    Option = new Button("Options", GetScreenWidth() / 2 - 150, GetScreenHeight() - 350);
    Play = new Button("Play", GetScreenWidth() / 2 - 150, GetScreenHeight() - 475);
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
    level = new Level();
    SceneManager::LoadScene(level);
}

void SceneMainMenu::render() {
    GUIManager::WriteText(title, 0, 40, 45, 1);

    DrawText("", 2, GetScreenHeight() - 22, 20, WHITE);

    DrawRectangle(GetScreenWidth() / 3, 90, GetScreenWidth() / 3, 2, BLACK);

    Quit->render(ButtonQuit);
    Credit->render(EmptyFunctionTMP);
    Option->render(EmptyFunctionTMP);
    Play->render(_LoadScene);
};