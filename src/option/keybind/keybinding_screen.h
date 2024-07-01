#ifndef WAREHOUSEMANAGER_KEYBINDING_SCREEN_H
#define WAREHOUSEMANAGER_KEYBINDING_SCREEN_H

#include "../../gui/Button.h"
#include "../../scenes/Scene.h"
#include "../../scenes/SceneMainMenu.h"
#include "raylib.h"
#include <map>
#include <string>
#include <vector>

class KeybindingScreen : public Scene {
public:
    KeybindingScreen();
    ~KeybindingScreen();

    void render() override;
    static void Back();

private:
    inline static std::map<KeyboardKey, Button*> keyButtons;
    inline static Button* backButton;
    inline static KeyboardKey waitingForKey = KEY_NULL;

    inline static std::map<KeyboardKey, KeyboardKey> currentKeybindings = {
            {KEY_W, KEY_W}, {KEY_A, KEY_A}, {KEY_S, KEY_S}, {KEY_D, KEY_D},
            {KEY_UP, KEY_UP}, {KEY_LEFT, KEY_LEFT}, {KEY_DOWN, KEY_DOWN}, {KEY_RIGHT, KEY_RIGHT},
            {KEY_T, KEY_T}, {KEY_F, KEY_F}, {KEY_G, KEY_G}, {KEY_H, KEY_H},
            {KEY_I, KEY_I}, {KEY_J, KEY_J}, {KEY_K, KEY_K}, {KEY_L, KEY_L}
    };

    static void initializeKeybindings();
    static void renderButtons();
    static void handleInput();
    static void updateKeyBinding(KeyboardKey key, int newKey);
    static string getKeyName(KeyboardKey key);
    static void onButtonClick();
};

#endif // WAREHOUSEMANAGER_KEYBINDING_SCREEN_H
