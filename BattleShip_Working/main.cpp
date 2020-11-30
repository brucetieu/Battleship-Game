#include <iostream>
#include <string>
#include "Grid.h"
#include "Game.h"
#include "Ship.h"
#include "Helpers.h"
#include "Computer.h"
#include "Human.h"

using namespace std;

int main()
{
    Game game;
    Game newGame = game.buildGame("ship_placement1_good.csv");
    game.playGame(newGame);

    return 0;
}