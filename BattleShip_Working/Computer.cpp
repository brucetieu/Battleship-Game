//
// Created by Bruce Tieu on 11/14/20.
//

#include "Computer.h"
#include "GridIndex.h"
#include "Helpers.h"
#include <string>
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

bool Computer::shipsAreInBounds() {
    for (int i = 0; i < computerShips.size(); i++) {
        char row = computerShips[i].shipLocation[0];
        string column = computerShips[i].shipLocation.substr(1);

        if (row > 'J' || stoi(column) > 10 || row < 'A' || stoi(column) < 0) {
            cout << "Ships are out of bounds" << endl;
            return false;
        }
    }
    return true;
}

void Computer::getPossibleShipLocations() {
    Helpers helpers;

    for (int i = 0; i < computerShips.size(); i++) {
        vector<string> tempVector;
        GridIndex indices = helpers.parseShipLocation(computerShips[i].shipLocation);

        // Fix rows, update columns.
        if (computerShips[i].shipOrientation.find("H") != std::string::npos) {
            for (int row = indices.row; row <= indices.row; row++) {
                for (int col = indices.column; col < computerShips[i].shipSize + indices.column; col++) {
                    string x = to_string(row);
                    string y = to_string(col);
                    string result = x + y;
                    tempVector.push_back(result);
                }
                shipLocations.push_back(Ship(computerShips[i].shipType, computerShips[i].shipSize, tempVector));
            }
        }

            // Fix columns, update rows.
        else if (computerShips[i].shipOrientation.find("V") != std::string::npos) {
            for (int col = indices.column; col <= indices.column; col++) {
                for (int row = indices.row; row < computerShips[i].shipSize + indices.row; row++) {
                    string x = to_string(row);
                    string y = to_string(col);
                    string result = x + y;
                    tempVector.push_back(result);
                }
                shipLocations.push_back(Ship(computerShips[i].shipType, computerShips[i].shipSize, tempVector));
            }
        }
    }
}

bool Computer::shipsDontOverlap() {
    vector<string> uniques;
    for (int i = 0; i < shipLocations.size(); i++) {
        for (int j = 0; j < shipLocations[i].possibleShipLocations.size(); j++) {
            if (find(uniques.begin(), uniques.end(), shipLocations[i].possibleShipLocations[j]) == uniques.end()) {
                uniques.push_back(shipLocations[i].possibleShipLocations[j]);
            }
            else {
                cout << "Ships overlap" << endl;
                return false;
            }
        }
    }
//    for (int i = 0; i < uniques.size(); i++) {
//        cout << uniques[i] << endl;
//    }
    return true;
}

void Computer::generateCorrectPlacements() {

    do {
        cout << "Generating" << endl;
        getPossibleShipLocations();
        randShipPlacement();
    } while (!shipsDontOverlap());

//    while (!shipsAreInBounds() & !shipsDontOverlap() ) {
//        cout << "Generating..." << endl;
//        randShipPlacement();
//    }
}

//bool Computer::shipOverlapAfterPlacement() {
//    for (int i = 0; i < shipLocations.size(); i++) {
//        for (int j = 0; j < shipLocations[i].size(); j++) {
//            if (stoi(shipLocations[i].shipLocation[j]) > 10 || stoi)
//        }
//    }
//}