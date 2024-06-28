#include "Button.h"

//Button::Button(const std::string& name, int X, int Y)
//        : X(X), Y(Y), width(250), height(75)
//{
//    const int length = name.length();
//    this->name = new char[length + 1];
//    std::strcpy(this->name, name.c_str());
//}

Button::Button(const std::string& name, int X, int Y, int width, int height)
        : X(X), Y(Y), width(width), height(height)
{
    const int length = name.length();
    this->name = new char[length + 1];
    std::strcpy(this->name, name.c_str());
}

Button::~Button() {
    delete[] name;
}

void Button::SetPosition(int X, int Y) {
    this->X = X;
    this->Y = Y;
}

int Button::isHovered(int X, int Y) const {
    return (X < this->X + width && X > this->X && Y < this->Y + height && Y > this->Y);
}

void Button::render(void (*_setup)())
{
    hovered = isHovered(GetMouseX(), GetMouseY());
    DrawRectangle(X, Y, width, height, hovered ? RED : BLACK);
    DrawRectangle(X + 5, Y + 5, width - 10, height - 10, hovered ? BLACK : WHITE);

    DrawText(name, X + (width / 2 - MeasureText(name, 30) / 2), Y + (height / 2 - 15), 30, (isHovered(GetMouseX(), GetMouseY()) ? RED : BLACK));

    if (hovered && IsMouseButtonPressed(0)) {
        onclick(_setup);
    }
}

//void Button::render(void (*_setup)()) {
//
//    DrawRectangle(X + 25, Y, width, height, (isHovered(GetMouseX(), GetMouseY()) ? RED : BLACK));
//    DrawRectangle(X + 30, Y + 5, width - 10, height - 10, (isHovered(GetMouseX(), GetMouseY()) ? BLACK : WHITE));
//    DrawText(name, X + (width / 2 - MeasureText(name, 30) / 2), Y + (height / 2 - 15), 30, (isHovered(GetMouseX(), GetMouseY()) ? RED : BLACK));
//
//    if(isHovered(GetMouseX(), GetMouseY()))
//    {
//        if(!hovered)
//        {
//
//        }
//        if(IsMouseButtonPressed(0))
//        {
//            onclick(_setup);
//        }
//    }
//    hovered = isHovered(GetMouseX(), GetMouseY());
//}