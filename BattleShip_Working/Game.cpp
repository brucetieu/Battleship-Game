//
// Created by Bruce Tieu on 11/16/20.
//

#include "Game.h"
#include "Ship.h"
#include "Helpers.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

/**
 * Check if ships are in bounds. The locations are converted to row and columns.
 * @param vecOfShips
 * @return
 */
bool Game::shipsAreInBounds(vector <Ship> &vecOfShips) {
    for (int i = 0; i < vecOfShips.size(); i++) {
        for (int j = 0; j < vecOfShips[i].possibleShipLocations.size(); j++) {
            if (vecOfShips[i].possibleShipLocations[j].length() > 2) return false;
        }
    }
    return true;
}

/**
 * Check if all ships are included.
 * @param vecOfShips The vector of ship location (what was read in from the file).
 * @return True, if all ships are included, false otherwise.
 */
bool Game::allShipsAreIncluded(std::vector <Ship> &vecOfShips) {
    if (vecOfShips.size() < 5) {
        cout << "Not all ships are included." << endl;
        return false;
    }
    return true;
}

/**
 *
 * @param vecOfShips The original vector of ships which was populated from ships in the file.
 * @return
 */
vector<Ship> Game::getPossibleShipLocations(std::vector <Ship> &vecOfShips) {
    Helpers helpers;
    vector<Ship> newVecOfShips;

    for (int i = 0; i < vecOfShips.size(); i++) {
        vector<string> tempVector;
        GridIndex indices = helpers.parseShipLocation(vecOfShips[i].shipLocation);

        // Fix rows, update columns.
        if (vecOfShips[i].shipOrientation.find("H") != std::string::npos) {
            for (int row = indices.row; row <= indices.row; row++) {
                for (int col = indices.column; col < vecOfShips[i].shipSize + indices.column; col++) {
                    string x = to_string(row);
                    string y = to_string(col);
                    string result = x + y;
                    tempVector.push_back(result);
                }
                newVecOfShips.push_back(Ship(vecOfShips[i].shipType, vecOfShips[i].shipSize, tempVector));
            }
        }

        // Fix columns, update rows.
        else if (vecOfShips[i].shipOrientation.find("V") != std::string::npos) {
            for (int col = indices.column; col <= indices.column; col++) {
                for (int row = indices.row; row < vecOfShips[i].shipSize + indices.row; row++) {
                    string x = to_string(row);
                    string y = to_string(col);
                    string result = x + y;
                    tempVector.push_back(result);
                }
                newVecOfShips.push_back(Ship(vecOfShips[i].shipType, vecOfShips[i].shipSize, tempVector));
            }
        }
    }
    return newVecOfShips;
}

/**
 *
 * @param newVecOfShips The new vector of ships with all possible coordinates of each ship. The coords are in row/col.
 * @return
 */
bool Game::shipsDontOverlap(vector<Ship> &newVecOfShips) {
    vector<string> uniques;

    for (int i = 0; i < newVecOfShips.size(); i++) {
        for (int j = 0; j < newVecOfShips[i].possibleShipLocations.size(); j++) {
            if (find(uniques.begin(), uniques.end(), newVecOfShips[i].possibleShipLocations[j]) == uniques.end()) {
                uniques.push_back(newVecOfShips[i].possibleShipLocations[j]);
            }
            else {
                cout << "Ships overlap" << endl;
                return false;
            }
        }
    }
    return true;
}

/**
 * Print out the vector of ships.
 * @param vecOfShips The vector of ships load from file.
 */
void Game::printShipVector(std::vector <Ship> &vecOfShips) {
    for (int i = 0; i < vecOfShips.size(); i++) {
        cout << vecOfShips[i].shipType << endl;
        cout << vecOfShips[i].shipSize << endl;
        cout << vecOfShips[i].shipLocation << endl;
        cout << vecOfShips[i].shipOrientation << endl;
    }
}




