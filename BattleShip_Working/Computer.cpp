//
// Created by Bruce Tieu on 11/14/20.
//

#include "Computer.h"
#include "GridIndex.h"
#include "Game.h"
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

/**
 * Randomize ship locations for computer;
 * @return A random string like "00" representing row 0, column 0".
 */
string Computer::randShipLocation() {
//    GridIndex randIndices;
//    randIndices.row = rand() % 11;
    int column = rand() % 11;
    string rowStr = letters[rand() % 11];
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
void Computer::generateCorrectPlacements() {
    vector<Ship> newVecOfShips;
    do {
        cout << "Generating" << endl;
        newVecOfShips = getPossibleShipLocations(computerShips);
        randShipPlacement();
    } while (shipsDontOverlap(newVecOfShips) && shipsAreInBounds(newVecOfShips));

}
