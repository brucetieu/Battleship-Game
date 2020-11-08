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

}

void Player::readShipsFromFile(string filename) {
    ifstream infile;
    Ship ship;
    Helpers helpers;

    try {
        infile.open(filename);

        while (infile.peek() != EOF) {
            getline(infile, ship.shipType, ',');
            getline(infile, ship.shipLocation, ',');
            getline(infile, ship.shipOrientation, '\n');

            addSizeToShips(ship);

            GridIndex gridIndex = helpers.parseShipLocation(ship.shipLocation);

            if (helpers.checkLocationOfShip(gridIndex)) {
                shipVector.push_back(ship);
            }
        }
    } catch (const ifstream::failure& e) {
        cout << "Error reading file" << endl;
    }
}

/**
 * Add sizes to each type of ship.
 * @param shipData
 */
void Player::addSizeToShips(Ship &ship) {
    if (ship.shipType == "Carrier") {
        ship.shipSize = "5";
    } else if (ship.shipSize == "Battleship") {
        ship.shipSize = "4";
    } else if (ship.shipSize == "Cruiser") {
        ship.shipSize = "3";
    } else if (ship.shipSize == "Submarine") {
        ship.shipSize = "2";
    } else if (ship.shipSize == "Destroyer") {
        ship.shipSize = "2";
    }
}

void Player::placeShipOnGrid(Ship &ship) {

}

