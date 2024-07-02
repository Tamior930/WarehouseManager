#ifndef WAREHOUSEMANAGER_KEYBINDING_SCREEN_H
#define WAREHOUSEMANAGER_KEYBINDING_SCREEN_H

#include "../../gui/Button.h"
#include "../../scenes/Scene.h"
#include "../../scenes/SceneMainMenu.h"
#include "raylib.h"
#include <memory>
#include <map>
#include <string>
#include <vector>
#include <functional>

#define MAX_KEY_CODE 255

class KeybindingScreen : public Scene {
public:
    KeybindingScreen();
    ~KeybindingScreen();

    void render() override;
    static void Back();
    static std::map<KeyboardKey, KeyboardKey> getCurrentKeybindings();

private:
    inline static std::map<KeyboardKey, std::unique_ptr<Button>> keyButtons;
    inline static std::unique_ptr<Button> backButton;
    inline static KeyboardKey waitingForKey = KEY_NULL;

    inline static std::map<KeyboardKey, KeyboardKey> currentKeybindings = {
            {KEY_W, KEY_W}, {KEY_A, KEY_A}, {KEY_S, KEY_S}, {KEY_D, KEY_D},
            {KEY_UP, KEY_UP}, {KEY_LEFT, KEY_LEFT}, {KEY_DOWN, KEY_DOWN}, {KEY_RIGHT, KEY_RIGHT},
            {KEY_T, KEY_T}, {KEY_F, KEY_F}, {KEY_G, KEY_G}, {KEY_H, KEY_H},
            {KEY_I, KEY_I}, {KEY_J, KEY_J}, {KEY_K, KEY_K}, {KEY_L, KEY_L}
    };

    inline static std::string alertMessage;
    inline static bool showAlertFlag = false;
    inline static float alertStartTime = 0.0f;
    inline static const float ALERT_DURATION = 2.0f;
    inline static bool isInitialized = false;

    static void initializeKeybindings();
    static void renderButtons();
    static void handleInput();
    static void updateKeyBinding(KeyboardKey key, int newKey);
    static std::string getKeyName(KeyboardKey key);
    static void onButtonClick();
    static void setAlertMessage(const std::string& message);
    static Texture2D LoadBackgroundImage(const std::string& assetsPath);
    Texture _backgroundImage;
};

#endif // WAREHOUSEMANAGER_KEYBINDING_SCREEN_H
