//
// Created by Bruce Tieu on 11/6/20.
//

#ifndef BATTLESHIP_WORKING_PLAYER_H
#define BATTLESHIP_WORKING_PLAYER_H
#include "Ship.h"
#include "Grid.h"
#include <vector>
#include "Helpers.h"
#include "Game.h"


class Player {
private:
    Ship *ship;
    Game *game;
    std::vector<Ship> shipVector; // Hold ship info e.g [ {ship: , size: , location: , orientation} ]
//    std::vector<Ship> shipLocations; // Hold the ship locations: 00, 01, 02, ...

    void _addSizeToShips();

public:
    Player();
    void fire();

    Ship getShip();
    Game getGame();

    std::vector<Ship> readShipsFromFile(std::string filename);
    Grid placeShipsOnBoard(std::vector<Ship> &vecOfShips, std::vector<Ship> &newVecOfShips);
};


#endif //BATTLESHIP_WORKING_PLAYER_H
