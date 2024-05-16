//
// Created by if23b269 on 30.04.24.
//

#include "GUIManager.h"

void GUIManager::WriteText(string text, int x, int y, int font, int center) {
    {
        if(center)
        {
            DrawText(text.c_str() , (GetScreenWidth() / 2) - (MeasureText(text.c_str(), font) / 2), y, font, BLACK);
        }else{
            DrawText(text.c_str(), x, y, font, BLACK);
        }
    };
}
