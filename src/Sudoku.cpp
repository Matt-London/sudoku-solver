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