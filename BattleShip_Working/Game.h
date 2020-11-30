//
// Created by Bruce Tieu on 11/16/20.
//

#ifndef BATTLESHIP_WORKING_GAME_H
#define BATTLESHIP_WORKING_GAME_H

#include "Ship.h"
#include "Helpers.h"


/**
 * Class which checks if the game is ready to go. So checks placements, etc. Builds the game and plays the game.
 */
class Game {
private:

    // Create helper instance to be used throughout the Game class.
    Helpers helpers;

public:

    // Adding up all the ship sizes, we get a total of 17 => first to 17 locations hit wins.
    static const int TOTAL_NUM_SHIPS;

    // The human's board of ships.
    Grid humanBoard;

    // The computer board of ships (not shown).
    Grid computerBoard;

    // The human's board to keep track of where they've fired.
    Grid trackerBoard;

    // Vector of ships holding the possible locations of each ships for the human after checking if they are valid.
    std::vector <Ship> humanPossibleShipLocs;

    // Vector of ships holding the possible locations of each ships for the computer after checking if they are valid.
    std::vector <Ship> computerPossibleShipLocs;

    // Default constructor.
    Game();

    // Parameterized constructor to initialize all of the variables defined previously.
    Game(Grid &humanBoard, Grid &trackerBoard, Grid &computerBoard, std::vector <Ship> &humanPossibleShipLocs,
         std::vector <Ship> &computerPossibleShipLocs);

    // Build each of the components which were defined by the variables.
    Game buildGame(std::string filename);

    // Play the game.
    void playGame(Game &newGame);

    // Print the final results if game is quit.
    void printResults(Game &newGame);

};


#endif //BATTLESHIP_WORKING_GAME_H
