//
// Created by Bruce Tieu on 11/16/20.
//

#include "Game.h"
#include "Ship.h"
#include "Human.h"
#include "Computer.h"
#include "Helpers.h"
#include "GridIndex.h"
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

Game::Game() {

}

Game::Game(Grid &humanBoard, Grid &trackerBoard, Grid &computerBoard, std::vector <Ship> &humanPossibleShipLocs,
           std::vector <Ship> &computerPossibleShipLocs) {
    this->humanBoard = humanBoard;
    this->trackerBoard = trackerBoard;
    this->computerBoard = computerBoard;
    this->humanPossibleShipLocs = humanPossibleShipLocs;
    this->computerPossibleShipLocs = computerPossibleShipLocs;
}

Game Game::buildGame() {

    std::vector <Ship> humanPossibleShipLocs;
    std::vector <Ship> computerPossibleShipLocs;

    Computer computer;

    computerPossibleShipLocs = computer.generateCorrectPlacements();
    Grid computerBoard = computer.placeShipsOnBoard();

    // Human.
    Human human;

    vector<Ship> vecOfShips;
    vector<Ship> newVecOfShips;

    vecOfShips = human.readShipsFromFile("ship_placement1_good.csv");
    humanPossibleShipLocs = human.getPossibleShipLocations(vecOfShips);

    Grid humanBoard = human.placeShipsOnBoard(vecOfShips, newVecOfShips);
    cout << "Here is your ship configuration: " << endl;
    humanBoard.printGrid();

    cout << endl;

    cout << "Here is your tracking grid of shots you have fired: " << endl;
    Grid trackerBoard;
    trackerBoard.createGrid();
    trackerBoard.printGrid();

    return Game(humanBoard, trackerBoard, computerBoard, humanPossibleShipLocs, computerPossibleShipLocs);

}

void Game::playGame(string &choice, Game &newGame) {
    Helpers helpers;

    string parsedChoice = helpers.parseLocationToString(choice);
    GridIndex index = helpers.parseLocationToIndex(choice);

    // Human fires
    for (int i = 0; i < newGame.computerPossibleShipLocs.size(); i++) {
        for (int j = 0; j < newGame.computerPossibleShipLocs[i].possibleShipLocations.size(); j++) {
            if (parsedChoice == newGame.computerPossibleShipLocs[i].possibleShipLocations[j]) {
                cout << "Hit " << newGame.computerPossibleShipLocs[i].shipType << "!" << endl;
                newGame.trackerBoard.GRID[index.row][index.column] = 'O';
                newGame.humanBoard.printGrid();
                cout << endl;
                newGame.trackerBoard.printGrid();
                return;
            }

        }
    }

    cout << "Missed!" << endl;
    newGame.trackerBoard.GRID[index.row][index.column] = 'X';

    newGame.humanBoard.printGrid();
    cout << endl;
    newGame.trackerBoard.printGrid();

}

void Game::playGame2(Game &newGame) {
    // Computer fires.
    Helpers helpers;
    Computer computer;
    string computerChoice = computer.randShipLocation();
    GridIndex index = helpers.parseLocationToIndex(computerChoice);
//    cout << computerChoice << endl;
//    int row = computerChoice[0] - '0';
//    int col = stoi(computerChoice.substr(1));

//    cout << "row: " << row << " " << "col: " << col << endl;

    for (int i = 0; i < newGame.humanPossibleShipLocs.size(); i++) {
        for (int j = 0; j < newGame.humanPossibleShipLocs[i].possibleShipLocations.size(); j++) {
            if (computerChoice == newGame.humanPossibleShipLocs[i].possibleShipLocations[j]) {
                cout << "Hit " << newGame.computerPossibleShipLocs[i].shipType << "!" << endl;
                newGame.humanBoard.GRID[index.row][index.column] = 'O';
                newGame.humanBoard.printGrid();
                cout << endl;
//                newGame.trackerBoard.printGrid();
                return;
            }

        }
    }

    cout << "Missed!" << endl;
    newGame.humanBoard.GRID[index.row][index.column] = 'X';

    newGame.humanBoard.printGrid();
    cout << endl;
//    newGame.trackerBoard.printGrid();

}




