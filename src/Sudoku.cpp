//
// Created by mattl on 11/6/2021.
//

#include "Sudoku.h"

/**
 * Constructor for debug that decides whether to fill or not
 *
 * @param fill
 */
Sudoku::Sudoku(bool fill) {

}

/**
 * Copy constructor
 *
 * @param other other sudoku to copy from
 */
Sudoku::Sudoku(Sudoku const &other) {
    for (int i = 0; i < BOARD_LENGTH; i++) {
        for (int j = 0; j < BOARD_LENGTH; j++) {
            // Copy over grid
            this->grid[i][j] = other.grid[i][j];

            // Copy lock status
            this->locked[i][j] = other.locked[i][j];
        }
    }
}

/**
 * Default constructor that will be called by the program to fill
 */
Sudoku::Sudoku() : Sudoku(true) {}

/**
 * Constructor to be used when a puzzle is generated externally
 *
 * @param board Board with numbers and -1 representing blank
 */
Sudoku::Sudoku(int board[BOARD_LENGTH][BOARD_LENGTH]) {
    // Copy over
    for (int i = 0; i < BOARD_LENGTH; i++) {
        for (int j = 0; j < BOARD_LENGTH; j++) {
            if (board[i][j] == -1) {
                grid[i][j] = BLANK;
                locked[i][j] = false;

            }
            else {
                grid[i][j] = board[i][j];
                locked[i][j] = true;

            }
        }
    }
}

/**
 * Accessor for a specific space
 *
 * @param i row number
 * @param j col number
 * @return number at the space
 */
int Sudoku::getSpace(int i, int j) const {
    return grid[i][j];

}

/**
 * Accessor for status of space
 *
 * @param i row number
 * @param j col number
 * @return status of space
 */
bool Sudoku::isLocked(int i , int j) const {
    return locked[i][j];
}

/**
 * Set a space to a number
 *
 * @param val number to set
 * @param i row
 * @param j col
 * @return whether it was successful
 */
bool Sudoku::setSpace(int val, int i, int j) {
    // Check if it's locked
    if (locked[i][j]) {
        return false;
    }

    grid[i][j] = val;
    return true;
}

/**
 * Gets all the numbers in the sub box minus current
 *
 * @param row Row of square in desired box
 * @param col Col of square in desired box
 * @return Vector of the integers in the box minus current
 */
std::vector<int> Sudoku::getSub(int row, int col) {
    std::vector<int> neighbors;
    int subLength = (int) sqrt(BOARD_LENGTH);

    // Find location within sub
    int subRow = row % subLength;
    int subCol = col % subLength;

    // Find top left of sub in terms of whole grid
    int topLeftRow = row - subRow;
    int topLeftCol = col - subCol;

    // Loop through and add the numbers, but avoid the actual space
    for (int i = topLeftRow; i < topLeftRow + subLength; i++) {
        for (int j = topLeftCol; j < topLeftCol + subLength; j++) {
            // Make sure it isn't the current
            if (i == row && j == col) {
                continue;
            }

            // Add value to vector
            neighbors.push_back(grid[i][j]);

        }
    }

    // Return results
    return neighbors;


}