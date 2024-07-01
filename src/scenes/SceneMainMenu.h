//
// Created by if23b269 on 30.04.24.
//

#ifndef SCENEMAINMENU_H
#define SCENEMAINMENU_H

#include <iostream>
#include "raylib.h"
#include "Scene.h"
#include "Level.h"
#include "SimpleScene.h"
#include "../gui/Button.h"
#include "../util/GUIManager.h"
#include "../util/SceneManager.h"

class SceneMainMenu : public Scene {
public:
    SceneMainMenu();
    SceneMainMenu(std::string title);
    ~SceneMainMenu();

    void render();
    void updateButtonPositions();

private:
    static Texture2D LoadBackgroundImage(const std::string& assetsPath);
    std::string title;
    Button* Quit;
    Button* Credit;
    Button* Option;
    Button* Play;
    Texture _backgroundTexture;

    void initButtons();
    static void ButtonQuit();
    static void BacktoMenu();
    static void EmptyFunctionTMP();
    static void _LoadScene();
    static void _LoadOption();
};

#endif // SCENEMAINMENU_H