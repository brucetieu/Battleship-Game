//
// Created by Bruce Tieu on 11/14/20.
//

#include "Computer.h"
#include "Game.h"
#include "GridIndex.h"
#include "Player.h"
#include "Helpers.h"
#include <string>
#include <vector>
#include <iostream>
#include "Ship.h"

using namespace std;

Computer::Computer() : shipTypes{"Carrier", "Battleship", "Cruiser", "Submarine", "Destroyer"},
                       shipSizes{5, 4, 3, 3, 2},
                       shipOrientations{"H", "V"},
                       letters {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J"},
                       hitCountHuman(0) {}



vector<Ship> Computer::getComputerShips() {
    return computerShips;
}
/**
 * Randomize ship locations for computer;
 * @return A random string like "00" representing row 0, column 0".
 */
string Computer::randShipLocation() {

    // Generate random number from 1 - 10.
    int column = rand() % 10 + 1;

    // Select a random index from the letters array (0-9).
    string rowStr = letters[rand() % 10];

    // Convert to a string and return it.
    string colStr = to_string(column);
    return rowStr + colStr;
}

/**
 * Randomize the ship orientation
 * @return H or V.
 */
string Computer::randShipOrientation() {
    string randOrientation = shipOrientations[rand() % 2];
    return randOrientation;
}

/**
 * Randomize the ship placements.
 */
void Computer::randShipPlacement() {

    computerShips.clear();

    for (int i = 0; i < 5; i++) {
        computerShips.push_back(Ship(shipTypes[i], shipSizes[i], randShipLocation(), randShipOrientation()));
    }

}

/**
 * Print out the randomized ship locations.
 */
void Computer::printRandShips() {
    for (int i = 0; i < computerShips.size(); i++) {
        cout << computerShips[i].shipType << endl;
        cout << computerShips[i].shipSize << endl;
        cout << computerShips[i].shipLocation << endl;
        cout << computerShips[i].shipOrientation << endl;
    }
}

/**
 * Continue generating random placements until there's no overlap and all ships are in bounds.
 */
vector<Ship> Computer::generateCorrectPlacements() {
    vector<Ship> newVecOfShips;
    randShipPlacement();
    newVecOfShips = getPossibleShipLocations(computerShips);

    for(;;) {
        if (shipsDontOverlap(newVecOfShips) && shipsAreInBounds(newVecOfShips)) {
            break;
        } else {
//            cout << "Generating..." << endl;
            randShipPlacement();
            newVecOfShips = getPossibleShipLocations(computerShips);
        }
    }
    return newVecOfShips;
}

Grid Computer::placeShipsOnBoard() {
    Grid grid;
    grid.createGrid();

    Helpers helpers;

    for (int i = 0; i < computerShips.size(); i++) {

        GridIndex indices = helpers.parseLocationToIndex(computerShips[i].shipLocation);

        // Fix rows, update columns if ship is horizontal.
        if (computerShips[i].shipOrientation.find("H") != std::string::npos) {
            for (int row = indices.row; row <= indices.row; row++) {
                for (int col = indices.column; col < computerShips[i].shipSize + indices.column; col++) {
                    grid.GRID[row][col] = computerShips[i].shipType[0];
                }
            }
        }
            // Fix columns, update rows if ship is vertical.
        else if (computerShips[i].shipOrientation.find("V") != std::string::npos) {
            for (int col = indices.column; col <= indices.column; col++) {
                for (int row = indices.row; row < computerShips[i].shipSize + indices.row; row++) {
                    grid.GRID[row][col] = computerShips[i].shipType[0];
                }
            }
        }
    }
    return grid;
}

int Computer::computerFires(Game &newGame) {

    // Computer fires.
    Helpers helpers;
    Computer computer;
//    Grid humanBoard = newGame.getHumanBoard();

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

                return _numHumanShipsHit(newGame, index, i, randChoice);
//                if (newGame.humanBoard.GRID[index.row][index.column] != 'O') {
//                    hitCountHuman += 1;
//                    newGame.humanPossibleShipLocs[i].shipSize--;
//                    if (newGame.humanPossibleShipLocs[i].shipSize == 0) {
//                        cout << newGame.humanPossibleShipLocs[i].shipType << " is sunk!" << endl;
//                    } else {
//                        cout << "Hit " << newGame.humanPossibleShipLocs[i].shipType << " at " << randChoice << "!" << endl;
//                    }
//                } else {
//                    cout << newGame.humanPossibleShipLocs[i].shipType << " is already hit!" << endl;
//                }
//
//                cout << "Human ships hit: " << hitCountHuman << endl;
//
//                newGame.humanBoard.GRID[index.row][index.column] = 'O';
//                cout << "Human board: " << endl;
//                newGame.humanBoard.printGrid();
//                cout << endl;
//                return hitCountHuman;
            }
        }
    }

    return _numHumanShipsMissed(newGame, index, randChoice);
//    cout << randChoice << " is a miss!" << endl << endl;
//
//    newGame.humanBoard.GRID[index.row][index.column] = 'X';
//
//    cout << "Your board: " << endl;
//    newGame.humanBoard.printGrid();
//    cout << endl;

//    return 0;
    return hitCountHuman;

}

int Computer::_numHumanShipsHit(Game &newGame, GridIndex &index, int i, std::string &choice) {
    if (newGame.humanBoard.GRID[index.row][index.column] != 'O') {
            hitCountHuman += 1;
            newGame.humanPossibleShipLocs[i].shipSize--;
            if (newGame.humanPossibleShipLocs[i].shipSize == 0) {
                cout << newGame.humanPossibleShipLocs[i].shipType << " is sunk!" << endl;
            } else {
                cout << "Hit " << newGame.humanPossibleShipLocs[i].shipType << " at " << choice << "!" << endl;
            }
        } else {
            cout << newGame.humanPossibleShipLocs[i].shipType << " is already hit!" << endl;
        }

        cout << "Human ships hit: " << hitCountHuman << endl;

        newGame.humanBoard.GRID[index.row][index.column] = 'O';
        cout << "Human board: " << endl;
        newGame.humanBoard.printGrid();
        cout << endl;
        return hitCountHuman;
}

int Computer::_numHumanShipsMissed(Game &newGame, GridIndex &index, std::string &choice) {
    cout << choice << " is a miss!" << endl << endl;

    newGame.humanBoard.GRID[index.row][index.column] = 'X';

    cout << "Your board: " << endl;
    newGame.humanBoard.printGrid();
    cout << endl;

    return hitCountHuman;
}