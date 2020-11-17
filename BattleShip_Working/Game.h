//
// Created by Bruce Tieu on 11/16/20.
//

#ifndef BATTLESHIP_WORKING_GAME_H
#define BATTLESHIP_WORKING_GAME_H
#include "Ship.h"

/**
 * Class which checks if the game is ready to go. So checks placements, etc.
 */
class Game {
private:

public:
    bool shipsAreInBounds(std::vector<Ship> &vecOfShips);
    std::vector<Ship> getPossibleShipLocations(std::vector<Ship> &vecOfShips);
    bool shipsDontOverlap(std::vector<Ship> &newVector);

};


#endif //BATTLESHIP_WORKING_GAME_H
