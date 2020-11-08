//
// Created by Bruce Tieu on 11/6/20.
//

#ifndef BATTLESHIP_WORKING_PLAYER_H
#define BATTLESHIP_WORKING_PLAYER_H
#include "Ship.h"
#include <vector>


class Player {
private:
    std::vector<Ship> shipVector;

public:
    Player();
    void readShipsFromFile(std::string filename);
    void addSizeToShips(Ship &ship);
    void placeShipOnGrid(Ship &ship);
};


#endif //BATTLESHIP_WORKING_PLAYER_H
