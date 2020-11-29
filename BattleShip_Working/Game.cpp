//
// Created by Bruce Tieu on 11/16/20.
//

#include "Game.h"
#include "Ship.h"
#include "Human.h"
#include "Computer.h"
#include "Helpers.h"
#include "GridIndex.h"
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

Game::Game() {
    hitCountComputer = 0;
    hitCountHuman = 0;
}

Game::Game(Grid &humanBoard, Grid &trackerBoard, Grid &computerBoard, std::vector <Ship> &humanPossibleShipLocs,
           std::vector <Ship> &computerPossibleShipLocs) {
    this->humanBoard = humanBoard;
    this->trackerBoard = trackerBoard;
    this->computerBoard = computerBoard;
    this->humanPossibleShipLocs = humanPossibleShipLocs;
    this->computerPossibleShipLocs = computerPossibleShipLocs;
}

/**
 * Build the game and return a Game object with all the necessary components.
 * @return A Game instance.
 */
Game Game::buildGame() {

    std::vector <Ship> humanPossibleShipLocs;
    std::vector <Ship> computerPossibleShipLocs;

    // Computer instance.
    Computer computer;

    // Store all possible locations computer has placed.
    computerPossibleShipLocs = computer.generateCorrectPlacements();

    // Create the computer's board, but hide it from the player.
    Grid computerBoard = computer.placeShipsOnBoard();

    // Human instance.
    Human human;

    vector<Ship> vecOfShips;
    vector<Ship> newVecOfShips;

    // Original locations of ships.
    vecOfShips = human.readShipsFromFile("ship_placement1_good.csv");

    // All possible locations human has placed via reading in from a file.
    humanPossibleShipLocs = human.getPossibleShipLocations(vecOfShips);

    // Construct the board for the player.
    Grid humanBoard = human.placeShipsOnBoard(vecOfShips, newVecOfShips);
    cout << "Here is your ship configuration: " << endl;
    humanBoard.printGrid();

    cout << endl;

    // Create the tracking grid.
    cout << "Here is your tracking grid of shots you have fired: " << endl;
    Grid trackerBoard;
    trackerBoard.createGrid();
    trackerBoard.printGrid();

    // Return new game instance.
    return Game(humanBoard, trackerBoard, computerBoard, humanPossibleShipLocs, computerPossibleShipLocs);

}

/**
 * Play the game.
 * @param choice
 * @param newGame
 */
int Game::playGame(string &choice, Game &newGame) {

    Helpers helpers;

    string parsedChoice = helpers.parseLocationToString(choice);
    GridIndex index = helpers.parseLocationToIndex(choice);


    // Human fires
    for (int i = 0; i < newGame.computerPossibleShipLocs.size(); i++) {
        for (int j = 0; j < newGame.computerPossibleShipLocs[i].possibleShipLocations.size(); j++) {
            if (parsedChoice == newGame.computerPossibleShipLocs[i].possibleShipLocations[j]) {
//                newGame.computerPossibleShipLocs[i].possibleShipLocations.erase(newGame.computerPossibleShipLocs[i].possibleShipLocations.begin() + j);

                if (newGame.trackerBoard.GRID[index.row][index.column] != 'O')  {
                    cout << "Hit " << newGame.computerPossibleShipLocs[i].shipType << "!" << endl;
                    hitCountComputer += 1;
                    cout << "Computer ships hit: " << hitCountComputer << endl;
                } else {
                    cout << newGame.computerPossibleShipLocs[i].shipType << " is already hit!" << endl;
                }

                newGame.trackerBoard.GRID[index.row][index.column] = 'O';
                cout << "Your board: " << endl;
                newGame.humanBoard.printGrid();
                cout << "Your tracking grid: " << endl;
                newGame.trackerBoard.printGrid();
                return 0;
            }
        }
    }

    cout << "Missed!" << endl << endl;
    newGame.trackerBoard.GRID[index.row][index.column] = 'X';

    cout << "Your board:" << endl << endl;
    newGame.humanBoard.printGrid();
    cout << endl;
    cout << "Your tracker board: " << endl;
    newGame.trackerBoard.printGrid();

    return hitCountComputer;
}

int Game::playGame2(Game &newGame) {

    // Computer fires.
    Helpers helpers;
    Computer computer;

    // Generate random target.
    string randChoice = computer.randShipLocation(); // e.g A1.

    // E.g change A1 -> 00.
    string computerChoice = helpers.parseLocationToString(randChoice);

    // Change A1 -> (0,0).
    GridIndex index = helpers.parseLocationToIndex(randChoice);


    for (int i = 0; i < newGame.humanPossibleShipLocs.size(); i++) {
        for (int j = 0; j < newGame.humanPossibleShipLocs[i].possibleShipLocations.size(); j++) {
            if (computerChoice == newGame.humanPossibleShipLocs[i].possibleShipLocations[j]) {
//                newGame.humanPossibleShipLocs[i].possibleShipLocations.erase(newGame.humanPossibleShipLocs[i].possibleShipLocations.begin() + j);

                if (newGame.humanBoard.GRID[index.row][index.column] != 'O') {
                    cout << "Hit " << newGame.humanPossibleShipLocs[i].shipType << "!" << endl;
                    hitCountHuman += 1;
                    cout << "Human ships hit: " << hitCountHuman << endl;
                } else {
                    cout << newGame.humanPossibleShipLocs[i].shipType << " is already hit!" << endl;
                }

                newGame.humanBoard.GRID[index.row][index.column] = 'O';
                cout << "Human board: " << endl;
                newGame.humanBoard.printGrid();
                cout << endl;
                return 0;
            }
        }
    }



    cout << "Missed!" << endl << endl;

    newGame.humanBoard.GRID[index.row][index.column] = 'X';

    cout << "Your board: " << endl;
    newGame.humanBoard.printGrid();
    cout << endl;

    return hitCountHuman;

}




