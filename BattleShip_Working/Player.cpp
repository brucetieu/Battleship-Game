//
// Created by Bruce Tieu on 11/6/20.
//

#include "Player.h"
#include "Ship.h"
#include <string>
#include <fstream>
#include <iostream>
#include "Helpers.h"

using namespace std;

Player::Player() {
    ship = Ship();
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
 * Print out vector of Ships.
 */
void Player::printShipVector() {
    for (int i = 0; i < shipVector.size(); i++) {
        cout << shipVector[i].shipType << endl;
        cout << shipVector[i].shipSize << endl;
        cout << shipVector[i].shipLocation << endl;
        cout << shipVector[i].shipOrientation << endl;
    }
}

/**
 * Replace ship location; ie, change A1 -> 11, B2 -> 22, etc.
 */
void Player::replaceShipLocations() {
    Helpers helpers;

    for (int i = 0; i < shipVector.size(); i++) {
        GridIndex gridIndex = helpers.parseShipLocation(shipVector[i].shipLocation);
        string row = to_string(gridIndex.row);
        string column = to_string(gridIndex.column);
        shipVector[i].shipLocation = row + column;
    }
}

/**
 * Check that all ships are included.
 * @return True, if all ships are included, otherwise false.
 */
bool Player::checkAllShipsAreIncluded() {
    cout << shipVector.size() << endl;
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

        if (row > 'J' || stoi(column) > 10) {
            return false;
        }
    }
    return true;
}






