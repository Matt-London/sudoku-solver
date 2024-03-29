//
// Created by mattl on 11/6/2021.
//

#include "Sudoku.h"

/**
 * Constructor for sudoku, fills blank
 *
 */
Sudoku::Sudoku() {
    for (int i = 0; i < BOARD_LENGTH; i++) {
        for (int j = 0; j < BOARD_LENGTH; j++) {
            grid[i][j] = BLANK;
            locked[i][j] = false;

        }
    }

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
 * Sets the given space then declares it as locked
 *
 * @param val number to set
 * @param i row
 * @param j col
 */
void Sudoku::setLocked(int val, int i, int j) {
    setSpace(val, i, j);
    locked[i][j] = true;
}

/**
 * Gets all the numbers in the sub box minus current
 *
 * @param row Row of square in desired box
 * @param col Col of square in desired box
 * @return Vector of the integers in the box minus current
 */
void Sudoku::getSub(std::vector<int> &neighbors, int row, int col) {
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

}