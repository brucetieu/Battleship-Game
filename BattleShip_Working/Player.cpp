//
// Created by Bruce Tieu on 11/6/20.
// Function implementations for Player.h.
//

#include "Player.h"
#include "Ship.h"
#include "Helpers.h"
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

/**
 * Check if ships are in bounds. The locations are converted to row and columns.
 * @param vecOfShips
 * @return True, if ships are in bounds and False otherwise.
 */
bool Player::shipsAreInBounds(vector <Ship> &newVecOfShips) {
    for (int i = 0; i < newVecOfShips.size(); i++) {
        for (int j = 0; j < newVecOfShips[i].possibleShipLocations.size(); j++) {
            if (newVecOfShips[i].possibleShipLocations[j].length() > MAX_LEN_SHIP_LOCATION) {
                return false;
            }
        }
    }
    return true;
}

/**
 * Check if all ships are included.
 * @param vecOfShips The vector of ship location (what was read in from the file).
 * @return True, if all ships are included, false otherwise.
 */
bool Player::allShipsAreIncluded(std::vector <Ship> &vecOfShips) {
    if (vecOfShips.size() == MAX_SHIP_SIZE) {
        return true;
    }
    cout << "Num of ships: " << vecOfShips.size() << " Not all ships are included." << endl;
    return false;
}

/**
 * Get all possible locations for each ship. For example, [B5, H] -> [B5, B6, B7, B8, B9, B10].
 * @param vecOfShips The original vector of ships which was populated from ships in the file.
 * @return The vector of Ship objects with all placements.
 */
vector<Ship> Player::getPossibleShipLocations(std::vector <Ship> &vecOfShips) {

    vector<Ship> newVecOfShips;  // This holds all possible ship locations.

    for (int i = 0; i < vecOfShips.size(); i++) {
        vector<string> tempVector;  // Temp vector to store locations in, will be pushed into newVecOfShips.

        // Parse location of A1 -> 00, A2 -> 01, etc.
        GridIndex indices = helpers.parseLocationToIndex(vecOfShips[i].shipLocation);

        // Fix rows, update columns.
        if (vecOfShips[i].shipOrientation.find("H") != std::string::npos) {
            for (int row = indices.row; row <= indices.row; row++) {
                for (int col = indices.column; col < vecOfShips[i].shipSize + indices.column; col++) {
                    // Get row, col representation of each ship location.
                    string x = to_string(row);
                    string y = to_string(col);
                    string result = x + y;
                    tempVector.push_back(result); // This holds all the possible locs for each ship.
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
 * Check if there is overlap in ship placements or not.
 * @param newVecOfShips The new vector of ships with all possible coordinates of each ship. The coords are in row/col.
 * @return True, if no overlap, false otherwise.
 */
bool Player::shipsDontOverlap(vector<Ship> &newVecOfShips) {

    // Temp vector to hold unique locations.
    vector<string> uniques;

    for (int i = 0; i < newVecOfShips.size(); i++) {
        for (int j = 0; j < newVecOfShips[i].possibleShipLocations.size(); j++) {
            if (find(uniques.begin(), uniques.end(), newVecOfShips[i].possibleShipLocations[j]) == uniques.end()) {
                uniques.push_back(newVecOfShips[i].possibleShipLocations[j]);
            }

                // If we see an element twice => overlap!
            else {
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
void Player::printShipVector(std::vector <Ship> &vecOfShips) {
    for (int i = 0; i < vecOfShips.size(); i++) {
        cout << vecOfShips[i].shipType << endl;
        cout << vecOfShips[i].shipSize << endl;
        cout << vecOfShips[i].shipLocation << endl;
        cout << vecOfShips[i].shipOrientation << endl;
    }
}
