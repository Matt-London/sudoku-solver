//
// Created by mattl on 11/6/2021.
//

#include "SudokuConfig.h"
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

    for (int i = newRow; i < BOARD_LENGTH; i++) {
        for (int j = newCol; j < BOARD_LENGTH; j++) {
            if (!sudoku.isLocked(i, j)) {
                destRow = i;
                destCol = j;
            }
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

        // If it's valid then return it
        if (successor.isValid()) {
            successors.push_back(successor);
        }
    }


}

/**
 * Determines if this config with its changes is valid
 *
 * @return whether it is valid or not
 */
bool SudokuConfig::isValid() {

}

/**
 * Determines if the puzzle is complete and it is the goal
 *
 * @return whether it is the goal
 */
bool SudokuConfig::isGoal() {

}