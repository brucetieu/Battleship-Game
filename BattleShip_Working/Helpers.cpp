//
// Created by Bruce Tieu on 11/7/20.
// Implement function declarations in Helpers.h.
//

#include "Helpers.h"
#include "GridIndex.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

/**
 * Parse ship location into (row, column). eg A1 -> "11"
 * @param location The location in the file.
 * @return A GridIndex struct.
 */
GridIndex Helpers::parseLocationToIndex(string &location) {

    GridIndex gridIndex;
    vector<char> map = grid.getMAP();

    // Loop through map, assign first character of location to be the index of the map.
    for (int i = 0; i <= map.size(); i++) {
        if (location[0] == map[i]) {
            gridIndex.row = i;
        }
    }
    // Convert second character to be an integer. Subtract 1 because Grid goes from 1 - 10, and we want 0 - 9.
    gridIndex.column = stoi(location.substr(1)) - 1;

    // Return the struct.
    return gridIndex;
}

/**
 * Parse A1 -> 00 as a string.
 * @param location
 * @return The string, e.g "00", "01", ..., "99".
 */
string Helpers::parseLocationToString(std::string &location) {
    vector<char> map = grid.getMAP();

    string row, col;

    // Loop through map, assign first character of location to be the index of the map.
    for (int i = 0; i <= map.size(); i++) {
        if (location[0] == map[i]) {
            row = to_string(i);
        }
    }
    // Convert second character to be an integer. Subtract 1 because Grid goes from 1 - 10, and we want 0 - 9.
    col = to_string(stoi(location.substr(1)) - 1);
    return row + col;
}

/**
 * Check if first character of choice is alphabetical and the characters after it are numbers.
 * @param choice The target choice.
 * @return True if first character is alphabetical and characters after it are numbers.
 */
bool Helpers::isAlphabet(std::string &choice) {
    if (isalpha(choice.at(0)) && stoi(choice.substr(1)))
        return true;
    cout << "First character of your target must be an alphabet between 'A' - 'J'. " << endl;
    return false;
}

/**
 * Check if the string is in bounds.
 * @param choice The target.
 * @return True, if in bounds, false if not in bounds.
 */
bool Helpers::isInBound(std::string &choice) {
    if (stoi(choice.substr(1)) <= 10 && stoi(choice.substr(1)) >= 0 && choice.at(0) <= 'J' && choice.at(0) >= 'A') {
        return true;
    }
    cout << "Your target is outside the Board, select again." << endl;
    return false;
}

/**
 * Check that the length of the input is a 3 characters large at the maximum.
 * @param choice The target.
 * @return True, if the target is correct length, false otherwise.
 */
bool Helpers::isRightLength(std::string &choice) {
    if (choice.length() <= 3 && choice.length() > 1) {
        return true;
    }
    cout << "Target must be between 2 or 3 characters max." << endl;
    return false;
}

/**
 * Check that the choice has no spaces.
 * @param choice The target choice.
 * @return True, if there's a space, false otherwise.
 */
bool Helpers::isSpace(std::string &choice) {
    for (int i = 0; i < choice.length(); i++) {
        if (isspace(choice[i])) {
            cout << "Target cannot have spaces." << endl;
            return true;
        }
    }
    return false;
}

/**
 * Check that the user did not supply empty output.
 * @param choice The target choice.
 * @return True, if no input was supplied and false otherwise.
 */
bool Helpers::isEmpty(std::string &choice) {
    if (choice.length() == 0) {
        cout << "Target cannot be empty." << endl;
        return true;
    }
    return false;
}

/**
 * Convert the input to be uppercase.
 * @param str The target.
 * @return The string which is capitalized.
 */
string Helpers::toUpper(std::string &str) {
    string temp = "";
    for (int i = 0; i < str.length(); i++) {
        temp += toupper(str[i]);
    }
    return temp;
}


