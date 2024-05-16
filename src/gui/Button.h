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

#ifndef BUTTONR_H
#define BUTTONR_H

#include "raylib.h"

#include <string>
#include <cstring>

using namespace std;

class Button {
    public:
        Button(std::string name, int posX, int posY);
        void render(void (*_setup)());
    private:
        bool hovered;
        int X, Y;
        char* name;
        void onclick(void (*onclick)()) {onclick();};
        int isHovered(int posX, int posY) const;
};



#endif //BUTTONR_H
