//
// Created by Bruce Tieu on 11/16/20.
//

#ifndef BATTLESHIP_WORKING_GAME_H
#define BATTLESHIP_WORKING_GAME_H

#include "Ship.h"
//#include "Computer.h"
#include "Helpers.h"


/**
 * Class which checks if the game is ready to go. So checks placements, etc.
 */
class Game {
private:
//    Grid humanBoard;
//    Grid computerBoard;
//    Grid trackerBoard;
//    std::vector <Ship> humanPossibleShipLocs;
//    std::vector <Ship> computerPossibleShipLocs;

    Helpers helpers;
//    int hitCountHuman;
//    int hitCountComputer;




public:
    static const int TOTAL_NUM_SHIPS;

    Grid humanBoard;
    Grid computerBoard;
    Grid trackerBoard;
    std::vector <Ship> humanPossibleShipLocs;
    std::vector <Ship> computerPossibleShipLocs;
//    Grid getHumanBoard();
//    Grid getComputerBoard();
//    Grid getTrackerBoard();
//    std::vector<Ship> getHumanPossibleShipLocs();
//    std::vector<Ship> getComputerPossibleShipLocs();

    Game();
    Game(Grid &humanBoard, Grid &trackerBoard, Grid &computerBoard, std::vector <Ship> &humanPossibleShipLocs,
         std::vector <Ship> &computerPossibleShipLocs);

    Game buildGame();
//    int playGame(std::string &choice, Game &newGame);
//    int playGame2(Game &newGame);


    void playGame(Game &newGame);
//    void printResults(Game &newGame);


};


#endif //BATTLESHIP_WORKING_GAME_H
