//
// Created by Bruce Tieu on 11/21/20.
//

#include "Human.h"
#include "Game.h"
#include "Ship.h"
#include <string>
#include <fstream>
#include "GridIndex.h"
#include <iostream>
#include <algorithm>
#include "Helpers.h"

using namespace std;

/**
 * Constructor - initialize ship and game objects.
 */
Human::Human() {
    ship = new Ship();
}

Ship Human::getShip() {
    return *ship;
}


/**
 * Read in Ship type, location, and orientation into a vector of Ship objects.
 * @param filename The name of the file.
 * @return A vector of Ship objects.
 */
vector<Ship> Human::readShipsFromFile(string filename) {
    ifstream infile;

    try {
        infile.open(filename);

        while (infile.peek() != EOF) {
            getline(infile, ship->shipType, ',');
            getline(infile, ship->shipLocation, ',');
            getline(infile, ship->shipOrientation, '\n');

            shipVector.push_back(*ship);
        }
    } catch (const ifstream::failure& e) {
        cout << "Error reading file" << endl;
    }
    _addSizeToShips();
    return shipVector;
}

/**
 * Add sizes to each type of ship. Add it to the private vector, shipVector in Player class.
 */
void Human::_addSizeToShips() {
    for (int i = 0; i < shipVector.size(); i++) {
        if (shipVector[i].shipType.find("Carrier") != string::npos) {
            shipVector[i].shipSize = 5;
        } else if (shipVector[i].shipType == "Battleship") {
            shipVector[i].shipSize = 4;
        } else if (shipVector[i].shipType == "Cruiser") {
            shipVector[i].shipSize = 3;
        } else if (shipVector[i].shipType == "Submarine") {
            shipVector[i].shipSize = 3;
        } else if (shipVector[i].shipType.find("Destroyer") != string::npos) {
            shipVector[i].shipSize = 2;
        }
    }
}


/**
 * Place the ships on the Board.
 * @param vecOfShips The vector of ships which were read from the file.
 * @param newVecOfShips The new vector of ships which contains all possible ship placement locations.
 * @return The grid showing the placement of ships, if placement is valid.
 */
Grid Human::placeShipsOnBoard(vector<Ship> &vecOfShips, vector<Ship> &newVecOfShips) {
    Grid grid;
    grid.createGrid();

    // If all ships are included, in bounds, and don't overlap then load the ships onto the board.
    if (allShipsAreIncluded(vecOfShips) & shipsAreInBounds(newVecOfShips) & shipsDontOverlap(newVecOfShips) ) {
        cout << "Ships can be placed on board." << endl;

        for (int i = 0; i < shipVector.size(); i++) {

            GridIndex indices = helpers.parseLocationToIndex(shipVector[i].shipLocation);

            // Fix rows, update columns if ship is horizontal.
            if (shipVector[i].shipOrientation.find("H") != std::string::npos) {
                for (int row = indices.row; row <= indices.row; row++) {
                    for (int col = indices.column; col < shipVector[i].shipSize + indices.column; col++) {
                        grid.GRID[row][col] = shipVector[i].shipType[0];

                    }
                }
            }
                // Fix columns, update rows if ship is vertical.
            else if (shipVector[i].shipOrientation.find("V") != std::string::npos) {
                for (int col = indices.column; col <= indices.column; col++) {
                    for (int row = indices.row; row < shipVector[i].shipSize + indices.row; row++) {
                        grid.GRID[row][col] = shipVector[i].shipType[0];
                    }
                }
            }
        }
    }
    else cout << "Ships can not be placed on board. Try a different configuration." << endl;
    return grid;
}

void Human::fire(Game &newGame) {
    Game game;
    string choice;

    while (true) {
        cout << "Choose where to fire (A - J) and a number (1-10): ";
        getline(cin, choice);

        // Convert input to all uppercase.
        string upperCaseChoice = helpers.toUpper(choice);

        // Fire only if user input is validated.
        if (!helpers.isEmpty(upperCaseChoice) && !helpers.isSpace(upperCaseChoice) && helpers.isRightLength(upperCaseChoice) &&
            helpers.isAlphabet(upperCaseChoice) && helpers.isInBound(upperCaseChoice)) {

            // TODO: User input is validated => pass this choice into some function and see if it hits any ship.
            cout << "Firing..." << endl;
            game.playGame(upperCaseChoice, newGame);
            cout << "Computer fires..." << endl;
            game.playGame2(newGame);
        } else {
            cout << "Invalid target" << endl;
            break;
        }
    }


    string ParsedString = helpers.parseLocationToString(choice);


}
