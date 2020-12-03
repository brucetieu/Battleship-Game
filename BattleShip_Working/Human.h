//
// Created by Bruce Tieu on 11/21/20.
// Declare methods which a human can do.
//

#ifndef BATTLESHIP_WORKING_HUMAN_H
#define BATTLESHIP_WORKING_HUMAN_H

#include "Ship.h"
#include "Grid.h"
#include <vector>
#include "Helpers.h"
#include "Player.h"
#include "Game.h"

/**
 * A human is a type of Player.
 */
class Human : public Player {
private:
    Ship *ship;
    Helpers helpers;  // Use Helper class throughout.
    std::vector<Ship> shipVector; // Hold ship info e.g [ {ship: , size: , location: , orientation} ]

    void _addSizeToShips();  // Private utility method to add sizes to the ships.

    int hitCountComputer;  // Hold number of computer ships which were hit.

    int _numComputerShipsHit(Game &newGame, GridIndex &index, int &i, std::string &choice);
    int _numComputerShipsMissed(Game &newGame, GridIndex &index, std::string &choice);

public:
    Human(); // Default constructor

    Ship getShip(); // Get the Ship instance.

    // Functionality for human to fire.
    int humanFires(std::string &choice, Game &newGame);

    // Read ships from file into vector of Ship objects.
    std::vector<Ship> readShipsFromFile(std::string filename);

    // Place the ships on the board.
    Grid placeShipsOnBoard(std::vector<Ship> &vecOfShips, std::vector<Ship> &newVecOfShips);
};


#endif //BATTLESHIP_WORKING_HUMAN_H
