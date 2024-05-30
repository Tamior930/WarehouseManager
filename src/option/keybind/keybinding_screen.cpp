//
// Created by erber on 26.05.2024.
//

#include "keybinding_screen.h"

Button* KeybindingScreen::backButton = nullptr;
Button* KeybindingScreen::upButton = nullptr;
Button* KeybindingScreen::leftButton = nullptr;
Button* KeybindingScreen::downButton = nullptr;
Button* KeybindingScreen::rightButton = nullptr;
bool KeybindingScreen::waitingForKeyBinding = false;
int KeybindingScreen::selectedBinding = -1;
int KeybindingScreen::keyBindings[4] = {KEY_W, KEY_A, KEY_S, KEY_D};

const char* GetKeyName(int key) {
    switch (key) {
        case KEY_W: return "W";
        case KEY_A: return "A";
        case KEY_S: return "S";
        case KEY_D: return "D";
        case KEY_SPACE: return "SPACE";
        case KEY_ESCAPE: return "ESCAPE";
        default: return "UNKNOWN";
    }
}

KeybindingScreen::KeybindingScreen() {
    backButton = new Button("Back", GetScreenWidth() / 2 - 150, GetScreenHeight() - 100);
    upButton = new Button("Up", GetScreenWidth() / 2 + 150, GetScreenHeight() - 275);
    leftButton = new Button("Left", GetScreenWidth() / 2 + 150, GetScreenHeight() - 250);
    downButton = new Button("Down", GetScreenWidth() / 2 + 150, GetScreenHeight() - 225);
    rightButton = new Button("Right", GetScreenWidth() / 2 + 150, GetScreenHeight() - 200);
}

KeybindingScreen::~KeybindingScreen() {
    delete backButton;
    delete upButton;
    delete leftButton;
    delete downButton;
    delete rightButton;
}

void KeybindingScreen::render() {
    ClearBackground(DARKGRAY);

    DrawText("Keybindings", GetScreenWidth() / 2 - MeasureText("Keybindings", 40) / 2, 50, 40, BLACK);

    backButton->render(ButtonBack);
    upButton->render([](){ StartKeyBinding(0); });
    leftButton->render([](){ StartKeyBinding(1); });
    downButton->render([](){ StartKeyBinding(2); });
    rightButton->render([](){ StartKeyBinding(3); });

    if (waitingForKeyBinding && selectedBinding >= 0 && selectedBinding < 4) {
        DrawText("Press any key to set binding...",
                 GetScreenWidth() / 2 - MeasureText("Press any key to set binding...", 20) / 2, GetScreenHeight() - 50, 20, RED);
    } else {
        DrawText(TextFormat("Move Up: %s", GetKeyName(keyBindings[0])),
                 GetScreenWidth() / 2 + 150, GetScreenHeight() - 275, 20, WHITE);
        DrawText(TextFormat("Move Left: %s", GetKeyName(keyBindings[1])),
                 GetScreenWidth() / 2 + 150, GetScreenHeight() - 250, 20, WHITE);
        DrawText(TextFormat("Move Down: %s", GetKeyName(keyBindings[2])),
                 GetScreenWidth() / 2 + 150, GetScreenHeight() - 225, 20, WHITE);
        DrawText(TextFormat("Move Right: %s", GetKeyName(keyBindings[3])),
                 GetScreenWidth() / 2 + 150, GetScreenHeight() - 200, 20, WHITE);
    }

    if (waitingForKeyBinding) {
        UpdateKeyBindings();
    }
}

void KeybindingScreen::ButtonBack() {
    SceneManager::LoadScene(new Options());
}

void KeybindingScreen::StartKeyBinding(int bindingIndex) {
    selectedBinding = bindingIndex;
    waitingForKeyBinding = true;
}

void KeybindingScreen::UpdateKeyBindings() {
    if (IsKeyPressed(KEY_ESCAPE)) {
        waitingForKeyBinding = false;
        selectedBinding = -1;
        return;
    }

    for (int key = KEY_SPACE; key <= KEY_KP_EQUAL; key++) {
        if (IsKeyPressed(key)) {
            keyBindings[selectedBinding] = key;
            waitingForKeyBinding = false;
            selectedBinding = -1;
            break;
        }
    }
}
