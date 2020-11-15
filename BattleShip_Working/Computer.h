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
    int shipSizes[5];
    std::string shipOrientations[2];

public:

    Computer();
    void randShipPlacement();
    void printRandShips();
    std::string randShipLocation();
    std::string randShipOrientation();

};


#endif //BATTLESHIP_WORKING_COMPUTER_H
