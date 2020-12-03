// Initialize Ship constructors.

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Ship.h"

using namespace std;

Ship::Ship() {}

/**
 * Parameterized Ship constructor to create new Ship objects.
 * @param shipType The type of Ship.
 * @param shipSize The Ship size.
 * @param shipLocation The Ship location.
 * @param shipOrientation The Ship orientation.
 */
Ship::Ship(std::string shipType, int shipSize, std::string shipLocation, std::string shipOrientation) {
    this->shipType = shipType;
    this->shipSize = shipSize;
    this->shipLocation = shipLocation;
    this->shipOrientation = shipOrientation;
}

/**
 * Second parameterized constructor for initializing a vector to store possible ship locations.
 * @param shipType The ship type.
 * @param shipSize The size of the ship.
 * @param possibleShipLocations The possible ship locations.
 */
Ship::Ship(std::string shipType, int shipSize, std::vector <string> possibleShipLocations) {
    this->shipType = shipType;
    this->shipSize = shipSize;
    this->possibleShipLocations = possibleShipLocations;
}


