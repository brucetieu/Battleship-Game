//
// Created by Bruce Tieu on 11/14/20.
//

#include "Computer.h"
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
                       letters {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J"} {}



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