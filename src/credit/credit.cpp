//
// Created by erber on 02.07.2024.
//

#include "credit.h"

Credits::Credits()
{
    InitializeDevelopers();
    _backgroundImage = LoadBackgroundImage(ASSETS_PATH);
    ResetPopup();
}

Credits::~Credits()
{
    UnloadTexture(_backgroundImage);
}

void Credits::InitializeDevelopers()
{
    int screenWidth = Options::GetScreenWidth();
    int screenHeight = Options::GetScreenHeight();
    int buttonWidth = screenWidth * 0.4;
    int buttonHeight = screenHeight * 0.1;
    int startY = screenHeight * 0.3;

    developers = {
            {"Alexander Kurz", "Lead Programmer: Implemented core game mechanics",
                    std::make_shared<Button>("Alexander Kurz", screenWidth/2 - buttonWidth/2, startY, buttonWidth, buttonHeight)},
            {"Melvin Douglas Boening", "Programmer: Implemented GraphicsLoader, LevelManager, helped on Level.Cpp",
                    std::make_shared<Button>("Melvin Douglas Boenin", screenWidth/2 - buttonWidth/2, startY + buttonHeight * 1.5, buttonWidth, buttonHeight)},
            {"Berkant Er", "Programmer: Implemented Option and Keybinding Logic",
                    std::make_shared<Button>("Berkant Er", screenWidth/2 - buttonWidth/2, startY + buttonHeight * 3, buttonWidth, buttonHeight)},
            {"Lisa Mayrhofer", "Level Designer: Designed and balanced all game levels",
                    std::make_shared<Button>("Lisa Mayrhofer", screenWidth/2 - buttonWidth/2, startY + buttonHeight * 4.5, buttonWidth, buttonHeight)},
            {"Johanna Nasr", "Level Designer: Designed and balanced all game levels",
                    std::make_shared<Button>("Johanna Nasr", screenWidth/2 - buttonWidth/2, startY + buttonHeight * 6, buttonWidth, buttonHeight)}
    };

    backButton = std::make_unique<Button>(
            "Back",
            screenWidth/2 - buttonWidth/2,
            startY + buttonHeight * 6,
            buttonWidth,
            buttonHeight
    );
}

void Credits::ResetPopup() {
    showDetails = false;
    selectedDeveloper = -1;
    popupStartTime = std::chrono::steady_clock::now() - popupDuration;
}

void Credits::Update()
{
    if (IsKeyPressed(KEY_ESCAPE)) {
        ResetPopup();
    }

    for (int i = 0; i < developers.size(); i++) {
        if (developers[i].button->isHovered(GetMouseX(), GetMouseY()) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            showDetails = true;
            selectedDeveloper = i;
            popupStartTime = std::chrono::steady_clock::now();
        }
    }

    if (showDetails) {
        auto currentTime = std::chrono::steady_clock::now();
        if (currentTime - popupStartTime >= popupDuration) {
            ResetPopup();
        }
    }
}

void Credits::render()
{
    ClearBackground(BLUE);
    DrawTexture(_backgroundImage, 0, 0, WHITE);

    DrawText("Credits", GetScreenWidth()/2 - MeasureText("Credits", 40)/2, 50, 40, BLACK);

    if (_reloadImage == 1) {
        UnloadTexture(_backgroundImage);
        _backgroundImage = LoadBackgroundImage(ASSETS_PATH);
        _reloadImage = 0;
    }

    for (int i = 0; i < developers.size(); i++) {
        developers[i].button->render(ShowDeveloperDetails);
    }
    backButton->render(Back);

    if (showDetails && selectedDeveloper >= 0 && selectedDeveloper < developers.size()) {
        ShowDeveloperDetails();
    }
}

void Credits::ShowDeveloperDetails()
{
    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Fade(BLACK, 0.7f));
    Rectangle detailsBox = {
            static_cast<float>(GetScreenWidth()/2 - 300),
            static_cast<float>(GetScreenHeight()/2 - 100),
            600, 200
    };
    DrawRectangleRec(detailsBox, WHITE);
    DrawRectangleLinesEx(detailsBox, 2, BLACK);

    DrawText(developers[selectedDeveloper].name.c_str(),
             detailsBox.x + 10, detailsBox.y + 10,
             30, BLACK);

    DrawText(developers[selectedDeveloper].task.c_str(),
             detailsBox.x + 10, detailsBox.y + 50,
             20, DARKGRAY);
}

Texture2D Credits::LoadBackgroundImage(const std::string& assetsPath)
{
    Image background = LoadImage((assetsPath + "background.png").c_str());
    ImageResize(&background, Options::GetScreenWidth(), Options::GetScreenHeight());
    Texture2D backgroundImage = LoadTextureFromImage(background);
    UnloadImage(background);
    return backgroundImage;
}

void Credits::Back()
{
    SceneManager::LoadScene(new SceneMainMenu ("Warehouse Manager"));
}
