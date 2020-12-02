//
// Created by Bruce Tieu on 11/16/20.
// Implement the function declarations in Game.h.
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

// Static variable initialization.
const int Game::TOTAL_NUM_SHIPS = 17;

/**
 * Inline implementation of default constructor.
 */
Game::Game() {}

/**
 * Initialize required game objects and vectors.
 * @param humanBoard The human's board of ships (visible)
 * @param trackerBoard The tracker grid to keep track of locations hit and missed (visible)
 * @param computerBoard The computer's board (not visible).
 * @param humanPossibleShipLocs The possible locations of each ship the human has placed.
 * @param computerPossibleShipLocs The possible locations of each ship computer has placed (randomly).
 */
Game::Game(Grid &humanBoard, Grid &trackerBoard, Grid &computerBoard, std::vector <Ship> &humanPossibleShipLocs,
           std::vector <Ship> &computerPossibleShipLocs) {
    this->humanBoard = humanBoard;
    this->trackerBoard = trackerBoard;
    this->computerBoard = computerBoard;
    this->humanPossibleShipLocs = humanPossibleShipLocs;
    this->computerPossibleShipLocs = computerPossibleShipLocs;
}

/**
 * Build the game and return a Game object with all the necessary components.
 * @return A Game instance.
 */
Game Game::buildGame(std::string filename) {

    std::vector <Ship> humanPossibleShipLocs;
    std::vector <Ship> computerPossibleShipLocs;

    // Computer instance.
    Computer computer;

    // Store all possible locations computer has placed.
    computerPossibleShipLocs = computer.generateCorrectPlacements();

    // Create the computer's board, but hide it from the player.
    Grid computerBoard = computer.placeShipsOnBoard();

    // Human instance.
    Human human;

    vector<Ship> vecOfShips;

    // Original locations of ships.
    vecOfShips = human.readShipsFromFile(filename);

    // All possible locations human has placed via reading in from a file.
    humanPossibleShipLocs = human.getPossibleShipLocations(vecOfShips);

    // Construct the board for the player.
    Grid humanBoard = human.placeShipsOnBoard(vecOfShips, humanPossibleShipLocs);
    cout << "Here is your ship configuration: " << endl;
    humanBoard.printGrid();

    cout << endl;

    // Create the tracking grid.
    cout << "Here is your tracking grid of shots you have fired: " << endl;
    Grid trackerBoard;
    trackerBoard.printGrid();

    // Return new game instance.
    return Game(humanBoard, trackerBoard, computerBoard, humanPossibleShipLocs, computerPossibleShipLocs);

}

/**
 * Play the game.
 * @param newGame The new Game instance.
 */
void Game::playGame(Game &newGame) {

    // Create temporary Game instance.
    Game game;

    // Human instance.
    Human human;

    // Computer instance.
    Computer computer;

    string choice;

    while (true) {
        cout << "Choose where to fire (A - J) and a number (1-10). Type 'q' to quit: ";
        getline(cin, choice);

        // Convert choice to all uppercase.
        string upperCaseChoice = helpers.toUpper(choice);

        // Quit game if user types 'q' exactly.
        if (choice == "q") {
            cout << "Quitting Game... " << endl << endl;
            game.printResults(newGame);  // Reveal what the computer's config was.
            exit(1);
        }

        // Fire only if user input is validated.
        if (!helpers.isEmpty(upperCaseChoice) && !helpers.isSpace(upperCaseChoice) &&
            helpers.isRightLength(upperCaseChoice) &&
            helpers.isAlphabet(upperCaseChoice) && helpers.isInBound(upperCaseChoice)) {

            cout << "Firing..." << endl;
            int count1 = human.humanFires(upperCaseChoice, newGame);  // How many locations human has hit.
            cout << "Computer fires..." << endl;
            int count2 = computer.computerFires(newGame);  // How many locations computer has hit.

            cout << "First to hit 17 ships wins! Score - You: " << count1 << " Computer: " << count2 << endl;

            // End game if Human wins or Computer wins.
            if (count1 == Game::TOTAL_NUM_SHIPS) {
                cout << "You Win! Game Over" << endl;
                break;
            } else if (count2 == Game::TOTAL_NUM_SHIPS) {
                cout << "Computer Wins! Game Over." << endl;
                break;
            }

        } else {
            cout << "Invalid target" << endl << endl;
        }
    }

}

/**
 * Print the final board results if the game has been quit.
 * @param newGame The current game state / instance.
 */
void Game::printResults(Game &newGame) {
    cout << "The computer's ship configuration: " << endl;
    newGame.computerBoard.printGrid();

    cout << "Your board: " << endl;
    newGame.humanBoard.printGrid();

    cout << "Your tracking board: " << endl;
    newGame.trackerBoard.printGrid();
}




