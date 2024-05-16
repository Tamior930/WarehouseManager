//
// Created by if23b269 on 30.04.24.
//

#ifndef TEXTZONE_H
#define TEXTZONE_H

#include <iostream>
#include <vector>
#include "raylib.h"

class TextZone {
    public:
        TextZone(){}

        static void initLines(std::vector<std::string> lines);
        void render();
        inline static bool isInstanced;
    private:
        inline static std::vector<std::string> lines;
        int index = 0;
        bool canAdvance = true;
};



#endif //TEXTZONE_H
