#include <iostream>
#include <string>
#include "Grid.h"
#include "Game.h"
#include "Ship.h"
#include "Helpers.h"
#include "Computer.h"
#include "Human.h"

using namespace std;

/**
 * Main driver for playing the game.
 * @return 0 to indicate a successful program.
 */
int main()
{
    // Create a game instance and play it.
    Game game;

    // Specify the ship arrangement file you want to pass in.
    Game newGame = game.buildGame("ship_placement1_good.csv");
    game.playGame(newGame);  // Play the game.

    return 0;
}