//
// Created by Bruce Tieu on 11/14/20.
//

#include "Computer.h"
#include "GridIndex.h"
#include <string>
#include <iostream>
#include "Ship.h"

using namespace std;

Computer::Computer() : shipTypes{"Carrier", "Battleship", "Cruiser", "Submarine", "Destroyer"},
                       shipSizes{5, 4, 3, 2, 1},
                       shipOrientations{"H", "V"} {}

/**
 * Randomize ship locations for computer;
 * @return A random string like "00" representing row 0, column 0".
 */
string Computer::randShipLocation() {
    GridIndex randIndices;
    randIndices.row = rand() % 11;
    randIndices.column = rand() % 11;
    string rowStr = to_string(randIndices.row);
    string colStr = to_string(randIndices.column);
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
        cout << computerShips[i].shipLocation << endl;
    }
}

