//
// Created by Bruce Tieu on 11/6/20.
//

#ifndef BATTLESHIP_WORKING_PLAYER_H
#define BATTLESHIP_WORKING_PLAYER_H
#include "Ship.h"
#include "Grid.h"
#include <vector>


class Player {
private:
    Ship ship;
    std::vector<Ship> shipVector;

public:
    Player();
    void readShipsFromFile(std::string filename);
    void addSizeToShips();
    void printShipVector();
    void replaceShipLocations();
    Grid placeShipOnGrid();
    bool checkAllShipsAreIncluded();
    bool checkBoundsOfShipLocation();
};


#endif //BATTLESHIP_WORKING_PLAYER_H
