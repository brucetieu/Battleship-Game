//
// Created by Bruce Tieu on 11/14/20.
//

#ifndef BATTLESHIP_WORKING_COMPUTER_H
#define BATTLESHIP_WORKING_COMPUTER_H

#include "Ship.h"
#include "Player.h"
#include "Game.h"

class Computer : public Player {

private:
    std::vector<Ship> computerShips;

    std::string shipTypes[5];
    std::string letters[10];
    int shipSizes[5];
    std::string shipOrientations[2];
    std::vector<Ship> shipLocations; // Hold the ship locations: 00, 01, 02, ...

    int hitCountHuman;

    int _numHumanShipsHit(Game &newGame, GridIndex &index, int i, std::string &choice);
    int _numHumanShipsMissed(Game &newGame, GridIndex &index, std::string &choice);

public:

    Computer();
    void randShipPlacement();
    void printRandShips();
    std::string randShipLocation();
    std::string randShipOrientation();
    std::vector<Ship> getComputerShips();


    std::vector<Ship> generateCorrectPlacements();
    Grid placeShipsOnBoard();

    int computerFires(Game &newGame);


};


#endif //BATTLESHIP_WORKING_COMPUTER_H
