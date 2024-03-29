//
// Created by mattl on 11/6/2021.
//

#include "SudokuConfig.h"

int SudokuConfig::configsTried = 1;

/**
 * Constructor for config
 *
 * @param row row that was changed
 * @param col col that was changed
 * @param sudoku sudoku grid that is referenced
 */
SudokuConfig::SudokuConfig(int row, int col, Sudoku sudoku) {
    this->row = row;
    this->col = col;

    this->sudoku = Sudoku(sudoku);

}

/**
 * Copy constructor
 *
 * @param other old sudokuconfig to copy from
 */
SudokuConfig::SudokuConfig(SudokuConfig const &other) {
    // Copy primitives
    this->row = other.row;
    this->col = other.col;

    // Copy sudoku
    this->sudoku = Sudoku(other.sudoku);

}

/**
 * Get a list of the possible successors available by changing the next box
 *
 * @return List of valid successors (calls isValid)
 */
std::vector<SudokuConfig> SudokuConfig::getSuccessors() {
    std::vector<SudokuConfig> successors;

    // Get next spot to change
    int newRow = row;
    int newCol = col;
    if (newCol + 1 < BOARD_LENGTH) {
        newCol++;
    }
    else {
        newRow++;
        newCol = 0;
    }

    // Look for one that is not locked
    int destRow = -1;
    int destCol = -1;
    bool complete = false;

    for (int i = newRow; i < BOARD_LENGTH; i++) {
        for (int j = 0; j < BOARD_LENGTH; j++) {
            if (sudoku.getSpace(i, j) == BLANK) {
                destRow = i;
                destCol = j;
                complete = true;
                break;
            }
        }
        if (complete) {
            break;
        }
    }
    // Make sure it actually changed
    if (newRow >= BOARD_LENGTH || (destRow == -1 || destCol == -1)) {
        return successors;
    }

    // Now we have an operable square, so generate all possible combinations and add the valid ones
    for (int i = 0; i < BOARD_LENGTH; i++) {
        // Create the new successor
        SudokuConfig successor(*this);

        // Change to new number
        successor.sudoku.setSpace(i + 1, destRow, destCol);
        successor.row = destRow;
        successor.col = destCol;

        // If it's valid then return it
        if (successor.isValid()) {
            successors.push_back(successor);
        }
    }

    configsTried += BOARD_LENGTH;

    return successors;


}

/**
 * Determines if this config with its changes is valid
 *
 * @return whether it is valid or not
 */
bool SudokuConfig::isValid() {
    int currentVal = sudoku.getSpace(row, col);

    // Check left right up down
    for (int i = 0; i < BOARD_LENGTH; i++) {
        // Check left and right of square
        if (i != col && sudoku.getSpace(row, i) == currentVal) {
            return false;
        }

        // Check up and down of square
        if (i != row && sudoku.getSpace(i, col) == currentVal) {
            return false;
        }
    }

    // Now check the containing box
    std::vector<int> subVals;
    sudoku.getSub(subVals, row, col);
    if (std::find(subVals.begin(), subVals.end(), currentVal) != subVals.end()) {
        // Then it contains
        return false;
    }

    // If none are false then it is a legal combination
    return true;


}

/**
 * Determines if the puzzle is complete and it is the goal
 *
 * @return whether it is the goal
 */
bool SudokuConfig::isGoal() {
    // Check that every square is filled in, otherwise isValid procedurally checks all combinations
    for (int i = 0; i < BOARD_LENGTH; i++) {
        for (int j = 0; j < BOARD_LENGTH; j++) {
            if (sudoku.getSpace(i, j) == BLANK) {
                return false;
            }

        }
    }

    return true;

}

/**
 * Builds a printable sudoku
 *
 * @return A string version of puzzle
 */
std::string SudokuConfig::printable() {
    std::string str = "";

    // Loop through and append
    for (int i = 0; i < BOARD_LENGTH; i++) {
        for (int j = 0; j < BOARD_LENGTH; j++) {
            str.append(std::to_string(sudoku.getSpace(i, j)));
            str.append(" ");
        }
        str.append("\n");
    }

    return str;

}

/**
 * Returns copy of sudoku
 *
 * @return sudoku
 */
Sudoku SudokuConfig::getSudoku() {
    return sudoku;
}

/**
 * Accessor for number of configsTried to solve
 *
 * @return configsTried
 */
int SudokuConfig::getConfigsTried() {
    return configsTried;
}