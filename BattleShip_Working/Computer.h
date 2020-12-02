//
// Created by Bruce Tieu on 11/14/20.
// Declare all functions which can be performed by the Computer.
//

#ifndef BATTLESHIP_WORKING_COMPUTER_H
#define BATTLESHIP_WORKING_COMPUTER_H

#include "Ship.h"
#include "Player.h"
#include "Game.h"

class Computer : public Player {

private:
    Helpers helpers;  // Instantiate helper methods to be used throughout class
    std::vector<Ship> computerShips;  // Store computer ships randomly generated.

    std::string shipTypes[5]; // Hold Carrier, Battleship, Cruiser, Submarine, Destroyer
    std::string letters[10];  // Hold A - J
    int shipSizes[5];  // 5, 4, 3, 3, 2
    std::string shipOrientations[2]; // H or V
    std::vector<Ship> shipLocations; // Hold the ship locations: 00, 01, 02, ...

    int hitCountHuman;

    int _numHumanShipsHit(Game &newGame, GridIndex &index, int &i, std::string &choice);
    int _numHumanShipsMissed(Game &newGame, GridIndex &index, std::string &choice);

public:

    Computer();
    void randShipPlacement(); // Randomize ship placement.
    void printRandShips();
    std::string randShipLocation(); // Randomize ship location.
    std::string randShipOrientation();  // Randomize ship orientation.
    std::vector<Ship> getComputerShips();


    std::vector<Ship> generateCorrectPlacements();
    Grid placeShipsOnBoard();

    int computerFires(Game &newGame);

};


#endif //BATTLESHIP_WORKING_COMPUTER_H
