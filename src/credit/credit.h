// Created by erber on 02.07.2024.
//

#ifndef WAREHOUSEMANAGER_CREDIT_H
#define WAREHOUSEMANAGER_CREDIT_H

#include "raylib.h"
#include "../gui/Button.h"
#include "../option/option.h"
#include "../scenes/Scene.h"
#include <memory>
#include <vector>

class Credits : public Scene {
private:
    struct Developer {
        std::string name;
        std::string task;
        std::shared_ptr<Button> button;
    };

    std::unique_ptr<Button> backButton;
    inline static std::vector<Developer> developers;
    inline static int selectedDeveloper = -1;

    // Timing variables for the pop-up
    bool _popupVisible;
    float _popupStartTime;
    const float POPUP_DURATION = 2.0f; // 2 seconds

    void InitializeDevelopers();
    static void ShowDeveloperDetails(); // Changed from static to non-static

    static Texture2D LoadBackgroundImage(const std::string& assetsPath);
    Texture _backgroundImage;
    inline static int _reloadImage;

public:
    Credits();
    ~Credits();

    void render() override;

    void TriggerPopup(); // Method to trigger the pop-up
    static void Back();
};

#endif // WAREHOUSEMANAGER_CREDIT_H
