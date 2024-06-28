//
// Created by melvi on 2024-05-06.
//

#include "LevelManager.h"
#include "raylib.h"
#include "../util/GUIManager.h"
#include <iostream>
#include <fstream>
#include <vector>

LevelManager::LevelManager() {

}

LevelManager::~LevelManager() {

}

std::vector<std::vector<int>> LevelManager::readDataFromFile(const std::string& filename) {
    // Open the file for reading
    std::ifstream inputFile(filename);

    // Check if the file is opened successfully
    if (!inputFile.is_open()) {
        {
            std::cerr << "Either unable to open file or no more levels" << filename << '\n';
            GUIManager::ShouldClose = true;
            return {};
        }
    }

    // 2D vector to store integers from the file
    std::vector<std::vector<int>> data;

    std::string line;
    // Read each line from the file
    while (std::getline(inputFile, line)) {
        // Vector to store integers from the current line
        std::vector<int> row;

        // Iterate over each character in the line
        for (char ch : line) {
            // Check if the character is a digit
            if (std::isdigit(ch)) {
                // Convert the character to an integer and add it to the row vector
                row.push_back(ch - '0');
            }
            else {
                std::cerr << "Not a digit at" << line << std::endl;
            }
        }

        // Add the row vector to the 2D vector
        data.push_back(row);
    }

    // Close the file
    inputFile.close();
    std::cout << "Contents of the 2D vector:\n";
    for (const auto& row : data) {
        for (int num : row) {
            std::cout << num << " ";
        }
        std::cout << '\n';
    }

    return data;
}

// Function to process data from the 2D vector
//ToDo: Parameter verändern um vector mit Vector2 Pointern zu erhalten
/*
0...Boden
1...Spieler
2...Wand
3...Boxen
4...final
5...BoxonFinal

für jedes Objekt -> case umschreiben
für jedes Objekt neuen Vector2(); erstellen und x und y Position setzen.
 */
void LevelManager::processDataFromVector(const std::vector<std::vector<int>> & data, int box_size, std::vector<Vector2 *>& playersCoordinates,
        std::vector<Vector2 *>& boxesCoordinates, std::vector<Vector2 *>& wallsCoordinates, std::vector<Vector2 *>& flooringCoordinates, std::vector<Vector2 *>& finalPositionsCoordinates) {
    // Iterate through the 2D vector
    Vector2* v;
    double x,y;
    this->maxrowcounter = 0;
    this->maxcollumcounter = 0;
    this -> rowcounter = 0;
    for (const auto& row : data) {
        this -> collumcounter = 0;
        for (int num : row) {
            std::cout << "processing row" << std::endl;


            // Use switch-case statement to call different functions based on integer value
            switch (num) {


                case 0:
                    std::cout << "case0 playerCoordinates at" << collumcounter << "and" << rowcounter << std::endl;

                    v = new Vector2();
                    v -> x = collumcounter * box_size;
                    v -> y = rowcounter * box_size;
                    flooringCoordinates.push_back(v);
                    //functionA();
                    break;
                case 1:
                    std::cout << "case1 playerCoordinates at" << collumcounter << "and" << rowcounter << std::endl;

                    v = new Vector2();
                    v -> x = collumcounter * box_size;
                    v -> y = rowcounter * box_size;
                    playersCoordinates.push_back(v);
                    v = new Vector2();
                    v -> x = collumcounter * box_size;
                    v -> y = rowcounter * box_size;
                    flooringCoordinates.push_back(v);//functionA();
                    break;
                case 2:
                    std::cout << "case2 blue square at"  << collumcounter << "and" << rowcounter  << std::endl;

                    v = new Vector2();
                    v -> x = collumcounter * box_size;
                    v -> y = rowcounter * box_size;
                    wallsCoordinates.push_back(v);
                    //functionB();
                    break;
                case 3:
                    std::cout << "case3 yellow square at"  << collumcounter << "and" << rowcounter  << std::endl;

                    v = new Vector2();
                    v -> x = collumcounter * box_size;
                    v -> y = rowcounter * box_size;
                    boxesCoordinates.push_back(v);
                    v = new Vector2();
                    v -> x = collumcounter * box_size;
                    v -> y = rowcounter * box_size;
                    flooringCoordinates.push_back(v);
                    //functionC();
                    break;
                case 4:
                    std::cout << "case4 red square at"  << collumcounter << "and" << rowcounter << std::endl;

                    v = new Vector2();
                    v -> x = collumcounter * box_size;
                    v -> y = rowcounter * box_size;
                    finalPositionsCoordinates.push_back(v);

                    //functionC();
                    break;
                case 5:
                    std::cout << "case5" << std::endl;

                    //v = new Vector2();
                    //v -> x = collumcounter * box_size;
                    //v -> y = rowcounter * box_size;
                    //functionC();
                    break;
                case 6:
                    std::cout << "case6" << std::endl;
                    //DrawRectangle(collumcounter * CELL_SIZE, rowcounter * CELL_SIZE, CELL_SIZE-10, CELL_SIZE-10, BLACK);
                    //functionC();
                    break;
                default:
                    std::cout << "Unknown number: " << num << "\n";
            }
            std::cout << "collumcounter increase" << std::endl;
            collumcounter++;
            if (maxcollumcounter < collumcounter)
            {maxcollumcounter=collumcounter;}
        }
        std::cout << "rowcounter increase" << std::endl;
        rowcounter++;
        if (maxrowcounter < rowcounter)
        {maxrowcounter=rowcounter;}
    }
    //optional screensizechange based on levelsize
    /*
    int screenWidth = maxcollumcounter*40;
    int screenHeight = maxrowcounter*40;
    SetWindowSize(screenWidth, screenHeight);
     */
}