//
// Created by if23b269 on 30.04.24.
//

#include "SimpleScene.h"

SimpleScene::SimpleScene()
{
    text = new TextZone();
}

void SimpleScene::render()
{
    if(TextZone::isInstanced)
    {
        text->render();
    }
};