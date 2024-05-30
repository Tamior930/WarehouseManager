//
// Created by erber on 26.05.2024.
//

#ifndef WAREHOUSEMANAGER_KEYBINDING_SCREEN_H
#define WAREHOUSEMANAGER_KEYBINDING_SCREEN_H

#include <raylib.h>
#include "../../gui/Button.h"
#include "../../scenes/Scene.h"
#include "../../scenes/SceneMainMenu.h"


class KeybindingScreen : public Scene {
public:
    KeybindingScreen();
    ~KeybindingScreen();
    void render() override;
    static void ButtonBack();
    static void StartKeyBinding(int bindingIndex);
    static void UpdateKeyBindings();

private:
    static Button* backButton;
    static Button* upButton;
    static Button* leftButton;
    static Button* downButton;
    static Button* rightButton;
    static bool waitingForKeyBinding;
    static int selectedBinding;
    static int keyBindings[4];
};

#endif //WAREHOUSEMANAGER_KEYBINDING_SCREEN_H
