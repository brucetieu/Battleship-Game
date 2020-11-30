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
    Game newGame = game.buildGame("ship_placement1_good.csv");
    game.playGame(newGame);

    return 0;
}