#include "Button.h"

//Button::Button(const std::string& name, int X, int Y)
//        : X(X), Y(Y), width(250), height(75)
//{
//    const int length = name.length();
//    this->name = new char[length + 1];
//    std::strcpy(this->name, name.c_str());
//}

Button::Button(const std::string& name, int posX, int posY, int width, int height)
        : X(posX), Y(posY), width(width), height(height)
{
    const int length = name.length();
    this->name = new char[length + 1];
    std::strcpy(this->name, name.c_str());
}

Button::~Button() {
    delete[] name;
}

void Button::SetPosition(int posX, int posY) {
    this->X = posX;
    this->Y = posY;
}

int Button::isHovered(int posX, int posY) const {
    return (posX < this->X + width && posX > this->X && posY < this->Y + height && posY > this->Y);
}

void Button::render(void (*_setup)())
{
    hovered = isHovered(GetMouseX(), GetMouseY());
    DrawRectangle(X, Y, width, height, hovered ? RED : BLACK);
    DrawRectangle(X + 5, Y + 5, width - 10, height - 10, hovered ? BLACK : WHITE);

    DrawText(name, X + (width / 2 - MeasureText(name, 30) / 2), Y + (height / 2 - 15), 30, (isHovered(GetMouseX(), GetMouseY()) ? RED : BLACK));

    if (hovered) {
        if(IsMouseButtonPressed(0))
        {
            _setup();
        }
    }
}

void Button::setText(const std::string& newText) {
    delete[] name;
    name = new char[newText.length() + 1];
    std::strcpy(name, newText.c_str());
}