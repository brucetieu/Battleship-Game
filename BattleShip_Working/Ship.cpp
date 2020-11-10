#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Ship.h"

using namespace std;

Ship::Ship() {

}

Ship::Ship(std::string shipType, int shipSize, std::string shipLocation, std::string shipOrientation) {
    this->shipType = shipType;
    this->shipSize = shipSize;
    this->shipLocation = shipLocation;
    this->shipOrientation = shipOrientation;
}

Ship::Ship(std::string shipType, int shipSize, std::vector <string> possibleShipLocations) {
    this->shipType = shipType;
    this->shipSize = shipSize;
    this->possibleShipLocations = possibleShipLocations;
}


