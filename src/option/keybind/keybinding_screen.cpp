#include "keybinding_screen.h"

KeybindingScreen::KeybindingScreen()
{
    initializeKeybindings();
}

KeybindingScreen::~KeybindingScreen()
{
    for (auto& pair : keyButtons) {
        delete pair.second;
    }
    delete backButton;
}

// Funktion zur Umwandlung eines KeyboardKey in einen String
std::string KeybindingScreen::getKeyName(KeyboardKey key) {
    switch (key) {
        case KEY_W: return "W";
        case KEY_A: return "A";
        case KEY_S: return "S";
        case KEY_D: return "D";
        case KEY_UP: return "Up";
        case KEY_LEFT: return "Left";
        case KEY_DOWN: return "Down";
        case KEY_RIGHT: return "Right";
        case KEY_T: return "T";
        case KEY_F: return "F";
        case KEY_G: return "G";
        case KEY_H: return "H";
        case KEY_I: return "I";
        case KEY_J: return "J";
        case KEY_K: return "K";
        case KEY_L: return "L";
        default: return "?"; // Standardfall für nicht erkannte Tasten
    }
}

void KeybindingScreen::initializeKeybindings()
{
    int buttonWidth = Options::GetScreenWidth() * 0.2;
    int buttonHeight = Options::GetScreenHeight() * 0.1;
    int buttonXStart = Options::GetScreenWidth() / 2 - (buttonWidth * 2);
    int buttonYStart = Options::GetScreenHeight() / 2 - (buttonHeight * 2);

    int buttonXIncrement = buttonWidth + 10;
    int buttonYIncrement = buttonHeight + 10;

    std::vector<std::vector<KeyboardKey>> buttonsInOrder ={
            {KEY_W, KEY_A, KEY_S, KEY_D},
            {KEY_UP, KEY_LEFT, KEY_DOWN, KEY_RIGHT},
            {KEY_T, KEY_F, KEY_G, KEY_H},
            {KEY_I, KEY_J, KEY_K, KEY_L}
    };

    for (auto row = 0; row < buttonsInOrder.size(); ++row) {
        for (auto col = 0; col < buttonsInOrder[row].size(); ++col) {
            int currentX = buttonXStart + col * buttonXIncrement;
            int currentY = buttonYStart + row * buttonYIncrement;

            KeyboardKey key = buttonsInOrder[row][col];
            std::string keyName = getKeyName(currentKeybindings[key]);

            keyButtons[key] = new Button(keyName, currentX, currentY, buttonWidth, buttonHeight);
        }
    }

    backButton = new Button("Back", Options::GetScreenWidth() / 2 - 125, Options::GetScreenHeight() - 100, 250, 75);
}

void KeybindingScreen::render()
{
    DrawText("Keybindings", Options::GetScreenWidth() / 2 - MeasureText("Keybindings", 40) / 2, 50, 40, BLACK);
    renderButtons();
    handleInput();
}

void KeybindingScreen::renderButtons()
{
    for (auto& keyButton : keyButtons)
    {
        keyButton.second->render(onButtonClick);
    }
    backButton->render(Back);
}

void KeybindingScreen::handleInput()
{
    if (waitingForKey != 0)
    {
        int newKey = GetKeyPressed();
        if (newKey != 0)
        {
            updateKeyBinding(waitingForKey, newKey);
            waitingForKey = KEY_NULL;
        }
    }
}

void KeybindingScreen::updateKeyBinding(KeyboardKey key, int newKey)
{
    if (keyButtons.find(key) != keyButtons.end())
    {
        keyButtons[key]->setText(getKeyName(static_cast<KeyboardKey>(newKey)));
        currentKeybindings[key] = KeyboardKey(newKey);
    }
}

void KeybindingScreen::onButtonClick()
{
    for (const auto& pair : keyButtons)
    {
        if (pair.second->isHovered(GetMouseX(), GetMouseY()) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            waitingForKey = pair.first;
            break;
        }
    }
}

void KeybindingScreen::Back()
{
    SceneManager::LoadScene(new Options());
}