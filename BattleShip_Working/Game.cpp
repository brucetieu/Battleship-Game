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

const int Game::TOTAL_NUM_SHIPS = 17;

Game::Game() {
//    hitCountComputer = 0;
//    hitCountHuman = 0;
}

//Grid Game::getHumanBoard() {
//    return humanBoard;
//}

//Grid Game::getComputerBoard() {
//    return computerBoard;
//}

//Grid Game::getTrackerBoard() {
//    return trackerBoard;
//}

//vector<Ship> Game::getComputerPossibleShipLocs() {
//    return computerPossibleShipLocs;
//}

//vector<Ship> Game::getHumanPossibleShipLocs() {
//    return humanPossibleShipLocs;
//}

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
Game Game::buildGame() {

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
    vector<Ship> newVecOfShips;

    // Original locations of ships.
    vecOfShips = human.readShipsFromFile("ship_placement1_good.csv");

    // All possible locations human has placed via reading in from a file.
    humanPossibleShipLocs = human.getPossibleShipLocations(vecOfShips);

    // Construct the board for the player.
    Grid humanBoard = human.placeShipsOnBoard(vecOfShips, newVecOfShips);
    cout << "Here is your ship configuration: " << endl;
    humanBoard.printGrid();

    cout << endl;

    // Create the tracking grid.
    cout << "Here is your tracking grid of shots you have fired: " << endl;
    Grid trackerBoard;
    trackerBoard.createGrid();
    trackerBoard.printGrid();

    // Return new game instance.
    return Game(humanBoard, trackerBoard, computerBoard, humanPossibleShipLocs, computerPossibleShipLocs);

}

/**
 * Play the game.
 * @param choice
 * @param newGame
 */
//int Game::playGame(string &choice, Game &newGame) {
//
//    Helpers helpers;
//
//    string parsedChoice = helpers.parseLocationToString(choice);
//    GridIndex index = helpers.parseLocationToIndex(choice);
//
//    // Human fires
//    for (int i = 0; i < newGame.computerPossibleShipLocs.size(); i++) {
//        for (int j = 0; j < newGame.computerPossibleShipLocs[i].possibleShipLocations.size(); j++) {
//            if (parsedChoice == newGame.computerPossibleShipLocs[i].possibleShipLocations[j]) {
////                newGame.computerPossibleShipLocs[i].possibleShipLocations.erase(newGame.computerPossibleShipLocs[i].possibleShipLocations.begin() + j);
//
//                if (newGame.trackerBoard.GRID[index.row][index.column] != 'O')  {
//                    newGame.computerPossibleShipLocs[i].shipSize--;
//                    if (newGame.computerPossibleShipLocs[i].shipSize == 0) {
//                        cout << newGame.computerPossibleShipLocs[i].shipType << " is sunk!" << endl;
//                    }
//                    else {
//                        cout << "Hit " << newGame.computerPossibleShipLocs[i].shipType << " at " << choice << "!" << endl;
//                        hitCountComputer += 1;
//                        cout << "Computer ships hit: " << hitCountComputer << endl;
//                    }
//                } else {
//                    cout << newGame.computerPossibleShipLocs[i].shipType << " is already hit!" << endl;
//                }
//
//                newGame.trackerBoard.GRID[index.row][index.column] = 'O';
//                cout << "Your board: " << endl;
//                newGame.humanBoard.printGrid();
//                cout << "Your tracking grid: " << endl;
//                newGame.trackerBoard.printGrid();
//                return 0;
//            }
//        }
//    }
//
//    cout << choice << " is a miss! "<< endl << endl;
//    newGame.trackerBoard.GRID[index.row][index.column] = 'X';
//
//    cout << "Your board:" << endl;
//    newGame.humanBoard.printGrid();
//    cout << endl;
//    cout << "Your tracker board: " << endl;
//    newGame.trackerBoard.printGrid();
//
//    return hitCountComputer;
//}
//
//int Game::playGame2(Game &newGame) {
//
//    // Computer fires.
//    Helpers helpers;
//    Computer computer;
//
//    // Generate random target.
//    string randChoice = computer.randShipLocation(); // e.g A1.
//
//    // E.g change A1 -> 00.
//    string computerChoice = helpers.parseLocationToString(randChoice);
//
//    // Change A1 -> (0,0).
//    GridIndex index = helpers.parseLocationToIndex(randChoice);
//
//
//    for (int i = 0; i < newGame.humanPossibleShipLocs.size(); i++) {
//        for (int j = 0; j < newGame.humanPossibleShipLocs[i].possibleShipLocations.size(); j++) {
//            if (computerChoice == newGame.humanPossibleShipLocs[i].possibleShipLocations[j]) {
////                newGame.humanPossibleShipLocs[i].possibleShipLocations.erase(newGame.humanPossibleShipLocs[i].possibleShipLocations.begin() + j);
//
//                if (newGame.humanBoard.GRID[index.row][index.column] != 'O') {
//                    newGame.humanPossibleShipLocs[i].shipSize--;
//                    if (newGame.humanPossibleShipLocs[i].shipSize == 0) {
//                        cout << newGame.humanPossibleShipLocs[i].shipType << " is sunk!" << endl;
//                    } else {
//                        cout << "Hit " << newGame.humanPossibleShipLocs[i].shipType << " at " << randChoice << "!" << endl;
//                        hitCountHuman += 1;
//                        cout << "Human ships hit: " << hitCountHuman << endl;
//                    }
//                } else {
//                    cout << newGame.humanPossibleShipLocs[i].shipType << " is already hit!" << endl;
//                }
//
//                newGame.humanBoard.GRID[index.row][index.column] = 'O';
//                cout << "Human board: " << endl;
//                newGame.humanBoard.printGrid();
//                cout << endl;
//                return 0;
//            }
//        }
//    }
//
//    cout << randChoice << " is a miss!" << endl << endl;
//
//    newGame.humanBoard.GRID[index.row][index.column] = 'X';
//
//    cout << "Your board: " << endl;
//    newGame.humanBoard.printGrid();
//    cout << endl;
//
//    return hitCountHuman;
//
//}
//
//void Game::printResults(Game &newGame) {
//    cout << "The computer's ship configuration: " << endl;
//    newGame.computerBoard.printGrid();
//
//    cout << "Your board: " << endl;
//    newGame.humanBoard.printGrid();
//
//    cout << "Your tracking board: " << endl;
//    newGame.trackerBoard.printGrid();
//
//
//}

void Game::playGame(Game &newGame) {
    Game game;
    Human human;
    Computer computer;

    string choice;

    while (true) {
        cout << "Choose where to fire (A - J) and a number (1-10). Type 'q' to quit: ";
        getline(cin, choice);

        // Convert input to all uppercase.
        string upperCaseChoice = helpers.toUpper(choice);

        if (choice == "q") {
//            game.printResults(newGame);
            exit(1);
        }

        // Fire only if user input is validated.
        if (!helpers.isEmpty(upperCaseChoice) && !helpers.isSpace(upperCaseChoice) &&
            helpers.isRightLength(upperCaseChoice) &&
            helpers.isAlphabet(upperCaseChoice) && helpers.isInBound(upperCaseChoice)) {

            // TODO: User input is validated => pass this choice into some function and see if it hits any ship.
            cout << "Firing..." << endl;
            int count1 = human.humanFires(upperCaseChoice, newGame);
            cout << "Computer fires..." << endl;
            int count2 = computer.computerFires(newGame);

            cout << "First to hit 17 ships wins! Score - You: " << count1 << " Computer: " << count2 << endl;

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


    string ParsedString = helpers.parseLocationToString(choice);


}




