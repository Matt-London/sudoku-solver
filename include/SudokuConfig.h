//
// Created by mattl on 11/6/2021.
//

#ifndef SUDOKU_SOLVER_SUDOKUCONFIG_H
#define SUDOKU_SOLVER_SUDOKUCONFIG_H

#include <vector>

#include "Sudoku.h"

class SudokuConfig {
    private:
        int row;
        int col;
        Sudoku sudoku;

    public:
        /**
         * Get a list of the possible successors available by changing the next box
         *
         * @return List of valid successors (calls isValid)
         */
        std::vector<Sudoku> getSuccessors();

        /**
         * Determines if this config with its changes is valid
         *
         * @return whether it is valid or not
         */
        bool isValid();

        /**
         * Determines if the puzzle is complete and it is the goal
         *
         * @return whether it is the goal
         */
        bool isGoal();


};


#endif //SUDOKU_SOLVER_SUDOKUCONFIG_H
