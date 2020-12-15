//
// Created by Bruce Tieu on 11/6/20.
//

#ifndef BATTLESHIP_WORKING_PLAYER_H
#define BATTLESHIP_WORKING_PLAYER_H

#include "Ship.h"
#include "Helpers.h"

/**
 * Class which checks if the game is ready to go. So checks placements, etc. This is the base class - Human and Computer inherit from this class.
 */
class Player {
private:
    Helpers helpers; // Use helpers throughout the class.
    const int MAX_SHIP_SIZE = 5;
    const int MAX_LEN_SHIP_LOCATION = 2;
public:
    bool shipsAreInBounds(std::vector<Ship> &vecOfShips);
    std::vector<Ship> getPossibleShipLocations(std::vector<Ship> &vecOfShips);
    bool shipsDontOverlap(std::vector<Ship> &newVecOfShips);
    bool allShipsAreIncluded(std::vector<Ship> &vecOfShips);
    void printShipVector(std::vector<Ship> &vecOfShips);

};



#endif //BATTLESHIP_WORKING_PLAYER_H
