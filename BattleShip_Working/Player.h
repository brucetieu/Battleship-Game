//
// Created by Bruce Tieu on 11/6/20.
//

#ifndef BATTLESHIP_WORKING_PLAYER_H
#define BATTLESHIP_WORKING_PLAYER_H


#include "Ship.h"

/**
 * Class which checks if the game is ready to go. So checks placements, etc.
 */
class Player {
private:

public:
    bool shipsAreInBounds(std::vector<Ship> &vecOfShips);
    std::vector<Ship> getPossibleShipLocations(std::vector<Ship> &vecOfShips);
    bool shipsDontOverlap(std::vector<Ship> &newVecOfShips);
    bool allShipsAreIncluded(std::vector<Ship> &vecOfShips);
    void printShipVector(std::vector<Ship> &vecOfShips);

    void fire();

};



#endif //BATTLESHIP_WORKING_PLAYER_H
