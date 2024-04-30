//
// Created by if23b269 on 30.04.24.
//

#ifndef SCENE_H
#define SCENE_H

class Scene
{
public:
    virtual ~Scene(){};
    virtual void Render(){};
private:
    std::string name;
};

#endif //SCENE_H
