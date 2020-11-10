//
// Created by Bruce Tieu on 11/6/20.
//

#include "Player.h"
#include "Ship.h"
#include <string>
#include <fstream>
#include "GridIndex.h"
#include <iostream>
#include "Helpers.h"

using namespace std;

Player::Player() {
    ship = Ship();
//    helpers = Helpers();
}

/**
 * Read in Ship type, location, and orientation into a vector of Ship objects.
 * @param filename The name of the file.
 */
void Player::readShipsFromFile(string filename) {
    ifstream infile;

    try {
        infile.open(filename);

        while (infile.peek() != EOF) {
            getline(infile, ship.shipType, ',');
            getline(infile, ship.shipLocation, ',');
            getline(infile, ship.shipOrientation, '\n');

            shipVector.push_back(ship);
        }
    } catch (const ifstream::failure& e) {
        cout << "Error reading file" << endl;
    }
}

/**
 * Add sizes to each type of ship.
 * @param shipData
 */
void Player::addSizeToShips() {
    for (int i = 0; i < shipVector.size(); i++) {
        if (shipVector[i].shipType.find("Carrier") != string::npos) {
            shipVector[i].shipSize = "5";
        } else if (shipVector[i].shipType == "Battleship") {
            shipVector[i].shipSize = "4";
        } else if (shipVector[i].shipType == "Cruiser") {
            shipVector[i].shipSize = "3";
        } else if (shipVector[i].shipType == "Submarine") {
            shipVector[i].shipSize = "2";
        } else if (shipVector[i].shipType.find("Destroyer") != string::npos) {
            shipVector[i].shipSize = "2";
        }
    }
}


/**
 * Replace ship location; ie, change A1 -> 11, B2 -> 22, etc.
 */
vector<Ship> Player::replaceShipLocations() {
    Helpers helpers;

    for (int i = 0; i < shipVector.size(); i++) {
        GridIndex gridIndex = helpers.parseShipLocation(shipVector[i].shipLocation);
        string row = to_string(gridIndex.row);
        string column = to_string(gridIndex.column);
        shipVector[i].shipLocation = row + column;
    }

    return shipVector;
}

/**
 * Check that all ships are included.
 * @return True, if all ships are included, otherwise false.
 */
bool Player::checkAllShipsAreIncluded() {
//    cout << shipVector.size() << endl;
    if (shipVector.size() < 5) {
        return false;
    }
    return true;
}

/**
 * Check that the location of ships do not violate bounds of the grid.
 * @return True, if no violation, else false.
 */
bool Player::checkBoundsOfShipLocation() {
    for (int i = 0; i < shipVector.size(); i++) {
        char row = shipVector[i].shipLocation[0];
        string column = shipVector[i].shipLocation.substr(1);

        if (row > 'J' || stoi(column) > 10 || row < 'A' || stoi(column) < 0) {
            return false;
        }
    }
    return true;
}

void Player::getPossibleShipLocations() {
    Helpers helpers;

    for (int i = 0; i < shipVector.size(); i++) {
        vector<string> tempVector;
        GridIndex indices = helpers.parseShipLocation(shipVector[i].shipLocation);

        // Fix rows, update columns.
        if (shipVector[i].shipOrientation.find("H") != std::string::npos) {
            for (int row = indices.row; row <= indices.row; row++) {
                for (int col = indices.column; col < stoi(shipVector[i].shipSize) + indices.column; col++) {
                    string x = to_string(row);
                    string y = to_string(col);
                    string result = x + y;
                    tempVector.push_back(result);
                }
                shipLocations.push_back(Ship(shipVector[i].shipType, shipVector[i].shipSize, tempVector));
            }
        }

        // Fix columns, update rows.
        else if (shipVector[i].shipOrientation.find("V") != std::string::npos) {
            for (int col = indices.column; col <= indices.column; col++) {
                for (int row = indices.row; row < stoi(shipVector[i].shipSize) + indices.row; row++) {
                    string x = to_string(row);
                    string y = to_string(col);
                    string result = x + y;
                    tempVector.push_back(result);
                }
                shipLocations.push_back(Ship(shipVector[i].shipType, shipVector[i].shipSize, tempVector));
            }
        }
    }
}

/**
 * Print out vector of Ships.
 */
void Player::printShipVector() {
    for (int i = 0; i < shipVector.size(); i++) {
        cout << shipVector[i].shipType << endl;
        cout << shipVector[i].shipSize << endl;
        cout << shipVector[i].shipLocation << endl;
        cout << shipVector[i].shipOrientation << endl;
    }

//    for (int i = 0; i < possibleShipLocations.size(); i++) {
//        for (int j = 0; j < possibleShipLocations[i].possibleShipLocations.size(); j++) {
//            cout << possibleShipLocations[i].possibleShipLocations[j] << endl;
//        }
//    }
    cout << shipLocations[3].possibleShipLocations[0] << endl;
    cout << shipLocations[3].possibleShipLocations[1] << endl;
    cout << shipLocations[3].possibleShipLocations[2] << endl;
//    cout << shipLocations[1].possibleShipLocations[3] << endl;

//    cout << shipLocations[2].possibleShipLocations[1]<< endl;
//    cout << shipLocations[2].possibleShipLocations[2]<< endl;
//    cout << shipLocations[2].possibleShipLocations[3]<< endl;
}





