///////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*--------------------------------****************************************----------------------------------
 |                                *                                      *                                 |
 |  Program Button Class          *       ButtonR Class Declarations     *                                 |
 |                                *                                      *                                 |
 ---------------------------------****************************************----------------------------------*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*

   The ButtonR class creates a responsive button from an image.

   The button size is computed from the font size and length of the text;
   the text is automatically centered on the button.
   See mutators to modify the button’s position, the text’s position in the button, and the button’s size.

   The button's shadows can be turned on and off. It is off by default.
   The sizes of the shadows are computed from the font size and length of the bar with the longest text;
   modifying the bars’ sizes will also modify the shadows’ sizes.
   The default font is raylib font.

   The default font is raylib font.
*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Created by if23b269 on 30.04.24.
//

#ifndef BUTTON_H
#define BUTTON_H

#include <string>
#include <cstring>
#include <raylib.h>

class Button {
public:
    Button(const std::string& name, int X, int Y, int width, int height);
    ~Button();

    void SetPosition(int X, int Y);
    int isHovered(int X, int Y) const;
    void render(void (*_setup)());

private:
    char* name;
    int X, Y;
    int width = 250, height = 75;
    bool hovered = false;

    void onclick(void (*_setup)()) {
        _setup();
    }
};

#endif // BUTTON_H