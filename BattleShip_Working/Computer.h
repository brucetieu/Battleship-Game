//
// Created by Bruce Tieu on 11/14/20.
//

#ifndef BATTLESHIP_WORKING_COMPUTER_H
#define BATTLESHIP_WORKING_COMPUTER_H

#include "Ship.h"

class Computer {

private:
    std::vector<Ship> computerShips;

    std::string shipTypes[5];
    std::string letters[10];
    int shipSizes[5];
    std::string shipOrientations[2];
    std::vector<Ship> shipLocations; // Hold the ship locations: 00, 01, 02, ...

public:

    Computer();
    void randShipPlacement();
    void printRandShips();
    std::string randShipLocation();
    std::string randShipOrientation();

    bool shipsAreInBounds();
    void getPossibleShipLocations();
    bool shipsDontOverlap();
    void generateCorrectPlacements();
    bool shipOverlapAfterPlacement();

};


#endif //BATTLESHIP_WORKING_COMPUTER_H
