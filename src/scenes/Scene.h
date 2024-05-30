//
// Created by if23b269 on 30.04.24.
//

#ifndef SCENE_H
#define SCENE_H
#include <string>

class Scene {

public:
    virtual ~Scene() {};
    virtual void render() {};

private:
    std::string name;
};

#endif //SCENE_H
