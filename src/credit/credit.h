//
// Created by erber on 02.07.2024.
//

#ifndef WAREHOUSEMANAGER_CREDIT_H
#define WAREHOUSEMANAGER_CREDIT_H

#include "raylib.h"
#include "../gui/Button.h"
#include "../option/option.h"
#include "../scenes/Scene.h"
#include <memory>
#include <chrono>

class Credits : public Scene {
private:

    struct Developer {
        std::string name;
        std::string task;
        std::shared_ptr<Button> button;
    };

    std::unique_ptr<Button> backButton;
    inline static std::vector<Developer> developers;
    //Texture2D backgroundTexture;

    inline static bool showDetails = false;
    inline static int selectedDeveloper = -1;

    std::chrono::steady_clock::time_point popupStartTime;
    const std::chrono::seconds popupDuration{2};

    void InitializeDevelopers();
    static void ShowDeveloperDetails();

    static Texture2D LoadBackgroundImage(const std::string& assetsPath);
    Texture _backgroundImage;
    inline static int _reloadImage;

public:
    Credits();
    ~Credits();

    void Update();
    void render() override;

    static void Back();
    void ResetPopup();
};


#endif //WAREHOUSEMANAGER_CREDIT_H
