//
// Created by Bruce Tieu on 11/7/20.
//

#ifndef BATTLESHIP_WORKING_HELPERS_H
#define BATTLESHIP_WORKING_HELPERS_H
#include "GridIndex.h"
#include "Grid.h"

/**
 * Helper class to check if ships can be arranged.
 */
class Helpers {

private:
    Grid grid;
public:

    // TODO: Change funciton name to commented out one below.

    GridIndex parseLocationToIndex(std::string &location);
    std::string parseLocationToString(std::string &location);

    bool isAlphabet(std::string &choice);
    bool isInBound(std::string &choice);
    bool isRightLength(std::string &choice);
    bool isSpace(std::string &choice);
    bool isEmpty(std::string &choice);

    std::string toUpper(std::string &str);

//    bool checkLocationOfShip(GridIndex &gridIndex);

};


#endif //BATTLESHIP_WORKING_HELPERS_H
