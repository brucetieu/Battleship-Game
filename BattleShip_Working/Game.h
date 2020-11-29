//
// Created by Bruce Tieu on 11/16/20.
//

#ifndef BATTLESHIP_WORKING_GAME_H
#define BATTLESHIP_WORKING_GAME_H

#include "Ship.h"
#include "Computer.h"


/**
 * Class which checks if the game is ready to go. So checks placements, etc.
 */
class Game {
private:
    Grid humanBoard;
    Grid computerBoard;
    Grid trackerBoard;
    std::vector <Ship> humanPossibleShipLocs;
    std::vector <Ship> computerPossibleShipLocs;

    int hitCountHuman;
    int hitCountComputer;


public:
    Game();
    Game(Grid &humanBoard, Grid &trackerBoard, Grid &computerBoard, std::vector <Ship> &humanPossibleShipLocs,
         std::vector <Ship> &computerPossibleShipLocs);

    Game buildGame();
    int playGame(std::string &choice, Game &newGame);
    int playGame2(Game &newGame);


};


#endif //BATTLESHIP_WORKING_GAME_H
