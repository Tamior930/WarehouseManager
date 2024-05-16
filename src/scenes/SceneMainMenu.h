//
// Created by if23b269 on 30.04.24.
//

#ifndef SCENEMAINMENU_H
#define SCENEMAINMENU_H

#include <iostream>
#include "raylib.h"
#include "Scene.h"
#include "SimpleScene.h"
#include "../gui/Button.h"
#include "../util/GUIManager.h"
#include "../util/SceneManager.h"

class SceneMainMenu : public Scene {
public:
    SceneMainMenu();
    SceneMainMenu(std::string title);
    void initButtons();
    static void ButtonQuit();
    static void EmptyFunctionTMP();
    static void _LoadScene();
    void render() override;
private:
    Button *Quit, *Play, *Option, *Credit;
    std::string title;
};



#endif //SCENEMAINMENU_H
