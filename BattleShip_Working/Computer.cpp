//
// Created by Bruce Tieu on 11/14/20.
// Implement the functions which were declared in Computer.h
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

/**
 * Initialize variables in the Constructor.
 */
Computer::Computer() : shipTypes{"Carrier", "Battleship", "Cruiser", "Submarine", "Destroyer"},
                       shipSizes{5, 4, 3, 3, 2},
                       shipOrientations{"H", "V"},
                       letters {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J"},
                       hitCountHuman(0) {}

/**
 * Get the computerShips vector.
 * @return A vector of Ship objects.
 */
vector<Ship> Computer::getComputerShips() {
    return computerShips;
}

/**
 * Randomize ship locations for computer.
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

    // Clear out any previous Ships.
    computerShips.clear();

    // Create a randomized vector of Ship objects with random location and orientation.
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
 * @return The new vector of Ship objects which have correct ship placements.
 */
vector<Ship> Computer::generateCorrectPlacements() {
    vector<Ship> newVecOfShips;
    randShipPlacement();
    newVecOfShips = getPossibleShipLocations(computerShips);

    for(;;) {

        // If placement is already valid, break out of the loop.
        if (shipsDontOverlap(newVecOfShips) && shipsAreInBounds(newVecOfShips)) {
            break;

            // Otherwise, keep generating placements over and over till we get a valid arrangement.
        } else {
            randShipPlacement();
            newVecOfShips = getPossibleShipLocations(computerShips);
        }
    }
    return newVecOfShips;
}

/**
 * Computer 'places' the ship on the board.
 * @return The Grid of placements.
 */
Grid Computer::placeShipsOnBoard() {
    Grid grid;

    for (int i = 0; i < computerShips.size(); i++) {

        GridIndex indices = helpers.parseLocationToIndex(computerShips[i].shipLocation);

        // Fix rows, update columns if ship is horizontal.
        if (computerShips[i].shipOrientation.find(Ship::HORIZONTAL) != std::string::npos) {
            for (int row = indices.row; row <= indices.row; row++) {
                for (int col = indices.column; col < computerShips[i].shipSize + indices.column; col++) {
                    grid.GRID[row][col] = computerShips[i].shipType[0];
                }
            }
        }
            // Fix columns, update rows if ship is vertical.
        else if (computerShips[i].shipOrientation.find(Ship::VERTICAL) != std::string::npos) {
            for (int col = indices.column; col <= indices.column; col++) {
                for (int row = indices.row; row < computerShips[i].shipSize + indices.row; row++) {
                    grid.GRID[row][col] = computerShips[i].shipType[0];
                }
            }
        }
    }
    return grid;
}

/**
 * Computer 'fires' at a target.
 * @param newGame The current Game instance.
 * @return A tally which keeps track of the score.
 */
int Computer::computerFires(Game &newGame) {

    // Computer fires.
    Helpers helpers;
    Computer computer;

    // Generate random target. e.g A1.
    string randChoice = computer.randShipLocation();

    // E.g change A1 -> 00.
    string computerChoice = helpers.parseLocationToString(randChoice);

    // Change A1 -> (0,0).
    GridIndex index = helpers.parseLocationToIndex(randChoice);

    for (int i = 0; i < newGame.humanPossibleShipLocs.size(); i++) {
        for (int j = 0; j < newGame.humanPossibleShipLocs[i].possibleShipLocations.size(); j++) {
            if (computerChoice == newGame.humanPossibleShipLocs[i].possibleShipLocations[j]) {

                // Private helper method which performs logic for hitting a human ship.
                return _numHumanShipsHit(newGame, index, i, randChoice);
            }
        }
    }
    // Private helper method which performs logic for missing a human ship.
    return _numHumanShipsMissed(newGame, index, randChoice);
}

/**
 * Perform required logic when a human's ship is hit.
 * @param newGame The current game state.
 * @param index The row and column of the target.
 * @param i The current ship which was hit and stored in a vector.
 * @param choice The target the user decided to fire.
 * @return A tally of the number of ships hit.
 */
int Computer::_numHumanShipsHit(Game &newGame, GridIndex &index, int &i, std::string &choice) {

    // If hit.
    if (newGame.humanBoard.GRID[index.row][index.column] != 'O') {
            hitCountHuman += 1;  // Update score.
            newGame.humanPossibleShipLocs[i].shipSize--;  // Decrement size of ship to indicate it was hit.

            // Output message when a ship is sunk.
            if (newGame.humanPossibleShipLocs[i].shipSize == 0) {
                cout << newGame.humanPossibleShipLocs[i].shipType << " is sunk!" << endl;
            } else {
                cout << "Hit " << newGame.humanPossibleShipLocs[i].shipType << " at " << choice << "!" << endl;
            }

            // Handle case when ship is already hit.
        } else {
            cout << newGame.humanPossibleShipLocs[i].shipType << " is already hit!" << endl;
        }

        // Update the human's board and print it out.
        cout << "Human ships hit: " << hitCountHuman << endl;

        newGame.humanBoard.GRID[index.row][index.column] = 'O';
        cout << "Human board: " << endl;
        cout << newGame.humanBoard;
        cout << endl;
        return hitCountHuman;
}

/**
 * Perform required logic when there's a miss.
 * @param newGame The current game instance.
 * @param index The row and column of the ship's location.
 * @param choice The target which was fired.
 * @return A tally of the number of ships hit.
 */
int Computer::_numHumanShipsMissed(Game &newGame, GridIndex &index, std::string &choice) {
    cout << choice << " is a miss!" << endl << endl;

    // Update human board when there's a miss.
    newGame.humanBoard.GRID[index.row][index.column] = 'X';

    cout << "Your board: " << endl;
    cout << newGame.humanBoard;
    cout << endl;

    return hitCountHuman;
}