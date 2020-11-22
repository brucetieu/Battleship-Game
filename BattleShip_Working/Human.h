//
// Created by Bruce Tieu on 11/21/20.
//

#ifndef BATTLESHIP_WORKING_HUMAN_H
#define BATTLESHIP_WORKING_HUMAN_H


#include "Ship.h"
#include "Grid.h"
#include <vector>
#include "Helpers.h"
#include "Player.h"


class Human : public Player {
private:
    Ship *ship;
    std::vector<Ship> shipVector; // Hold ship info e.g [ {ship: , size: , location: , orientation} ]

    void _addSizeToShips();

public:
    Human();
    void fire();

    Ship getShip();

    std::vector<Ship> readShipsFromFile(std::string filename);
    Grid placeShipsOnBoard(std::vector<Ship> &vecOfShips, std::vector<Ship> &newVecOfShips);
};



#endif //BATTLESHIP_WORKING_HUMAN_H
