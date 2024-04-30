//
// Created by if23b269 on 30.04.24.
//

#ifndef GUIMANAGER_H
#define GUIMANAGER_H

#include <iostream>
#include "raylib.h"

using namespace std;

class GUIManager {
    public:
    /// @brief Write text to screen
    /// @param text text to print out
    /// @param x position, if centered, put it at anything
    /// @param y y position
    /// @param font size of the font
    /// @param center boolean
    static void WriteText(string text, int x, int y, int font, int center);
    inline static bool ShouldClose = false;
};

#endif //GUIMANAGER_H
