//////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*--------------------------------****************************************----------------------------------
|                                *                                      *                                 |
|  Program Buttons               *       BottonP Class Definitions      *                                 |
|                                *                                      *                                 |
---------------------------------****************************************----------------------------------*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*



*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Created by if23b269 on 30.04.24.
//

#include "Button.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//--------------------------------------------- Class ButtonR ---------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Button::Button(std::string name, int posX, int posY)
{
    this->X = posX;
    this->Y = posY;

    const int length = name.length();
    char* char_array = new char[length + 1];

    std::strcpy(char_array, name.c_str());
    this->name = char_array;
};

Button::~Button() {
    delete[] name;
}

void Button::SetPosition(int posX, int posY) {
    this->X = posX;
    this->Y = posY;
}

int Button::isHovered(int posX, int posY) const {
    return (posX < X + 250 && posX > X && posY < Y + 75 && posY > Y);
};

void Button::render(void (*_setup)())
{

    DrawRectangle(X + 25, Y, 250, 75, (isHovered(GetMouseX(), GetMouseY()) ? RED : BLACK));

    DrawRectangle(X + 30, Y + 5, 240, 65, (isHovered(GetMouseX(), GetMouseY()) ? BLACK : WHITE));
    //Texture2D texture = LoadTexture(ASSETS_PATH"test2.png");
    //DrawTexturePro(texture, { 0.0f, 0.0f, texture.width, texture.height },
    //  { screenWidth / 2.0f, screenHeight / 2.0f, texture.width, texture.height }, {texture.width / 2, texture.height / 2}, 0.0f, WHITE);
    //DrawTexture(texture, X + 30, Y + 5, WHITE);

    DrawText(name, X + (150 - MeasureText(name, 30) / 2), Y + 25, 30, (isHovered(GetMouseX(), GetMouseY()) ? RED : BLACK));

    if(isHovered(GetMouseX(), GetMouseY()))
    {
        if(!hovered)
        {

        }
        if(IsMouseButtonPressed(0))
        {

            onclick(_setup);
        }
    }
    hovered = isHovered(GetMouseX(), GetMouseY());
}