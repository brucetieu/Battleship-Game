#include <iostream>
#include <string>
#include "Grid.h"
#include "Game.h"
#include "Ship.h"
#include "Helpers.h"
#include "Computer.h"
#include "Human.h"

using namespace std;

//char Grid::GRID[Grid::MAX_COLUMN][Grid::MAX_COLUMN] = {{'0'}};
int main()
{
    Game game;
    Game newGame = game.buildGame();


    game.playGame(newGame);
//    Human human;

//    human.fire(newGame);
//    Game game;
//    game.playGame();

    // Computer
//    Computer computer;
//    vector<Ship> computerPossibleShipLocs = computer.generateCorrectPlacements();
//    Grid computerBoard = computer.placeShipsOnBoard();

//    grid1.printGrid();
//    computer.printRandShips();

    // Human.
//    Human human;
//
//    vector<Ship> vecOfShips;
//    vector<Ship> newVecOfShips;
//
//    vecOfShips = human.readShipsFromFile("ship_placement1_good.csv");
//    newVecOfShips = human.getPossibleShipLocations(vecOfShips);
//
//    Grid humanBoard = human.placeShipsOnBoard(vecOfShips, newVecOfShips);
//    cout << "Here is your ship configuration: " << endl;
//    humanBoard.printGrid();
//
//    cout << endl;

//    cout << "Here is your tracking grid of shots you have fired: " << endl;
//    Grid trackerBoard;
//    trackerBoard.createGrid();
//    trackerBoard.printGrid();
//
//    human.fire();


    return 0;
}