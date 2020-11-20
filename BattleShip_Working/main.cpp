#include <iostream>
#include <string>
#include "Grid.h"
#include "Game.h"
#include "Ship.h"
#include "Helpers.h"
#include "Player.h"
#include "Computer.h"

using namespace std;

//char Grid::GRID[Grid::MAX_COLUMN][Grid::MAX_COLUMN] = {{'0'}};
int main()
{

    Computer computer;
    computer.generateCorrectPlacements();
    computer.printRandShips();

    Player player;
    Game game;

    vector<Ship> vecOfShips;
    vector<Ship> newVecOfShips;

    vecOfShips = player.readShipsFromFile("ship_placement1_good.csv");
    newVecOfShips = game.getPossibleShipLocations(vecOfShips);

    Grid grid = player.placeShipsOnBoard(vecOfShips, newVecOfShips);
    grid.printGrid();


    return 0;
}