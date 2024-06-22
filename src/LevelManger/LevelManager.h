//
// Created by melvi on 2024-05-06.
//

#ifndef WAREHOUSEMANAGER_LEVELMANAGER_H
#define WAREHOUSEMANAGER_LEVELMANAGER_H
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

#include "raylib.h"


class LevelManager {
public:
    LevelManager();
    ~LevelManager();
    void drawtest(const std::string& filename);
    std::vector<std::vector<int>> readDataFromFile(const std::string& filename);
    void processDataFromVector(const std::vector<std::vector<int>>& data);
    void processDataFromVector(const std::vector<std::vector<int>> &data, int box_size, Vector2* playerCoordinates);

    void processDataFromVector(const std::vector<std::vector<int>> & data, int box_size, std::vector<Vector2 *> & playersCoordinates);

private:
    int collumcounter;
    int rowcounter;

};


#endif //WAREHOUSEMANAGER_LEVELMANAGER_H
