//
// Created by Bruce Tieu on 11/6/20.
//

#ifndef BATTLESHIP_WORKING_PLAYER_H
#define BATTLESHIP_WORKING_PLAYER_H
#include "Ship.h"
#include "Grid.h"
#include <vector>
#include "Helpers.h"


class Player {
private:
    Ship ship;
    Helpers helpers;
    std::vector<Ship> shipVector; // Hold ship info e.g [ {ship: , size: , location: , orientation} ]
    std::vector<Ship> shipLocations; // Hold the ship locations: 00, 01, 02, ...

public:
    Player();
    void readShipsFromFile(std::string filename);
    void addSizeToShips();
    void printShipVector();
    std::vector<Ship> replaceShipLocations();
//    Grid placeShipOnGrid();
    bool allShipsAreIncluded();
    bool shipsAreInBounds();
    void getPossibleShipLocations();
    bool shipsDontOverlap();
    Grid placeShipsOnBoard();
};


#endif //BATTLESHIP_WORKING_PLAYER_H
