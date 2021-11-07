//
// Created by mattl on 11/6/2021.
//

#ifndef SUDOKU_SOLVER_SUDOKUCONFIG_H
#define SUDOKU_SOLVER_SUDOKUCONFIG_H

#include <vector>
#include <string>

#include "Sudoku.h"

class SudokuConfig {
    private:
        // Last spot to be changed
        int row;
        int col;
        static int configsTried;

        Sudoku sudoku;

    public:
        /**
         * Constructor for config
         *
         * @param row row that was changed
         * @param col col that was changed
         * @param sudoku sudoku grid that is referenced
         */
        SudokuConfig(int row, int col, Sudoku sudoku);

        /**
         * Copy constructor
         *
         * @param other old sudokuconfig to copy from
         */
        SudokuConfig(SudokuConfig const &other);

        /**
         * Get a list of the possible successors available by changing the next box
         *
         * @return List of valid successors (calls isValid)
         */
        std::vector<SudokuConfig> getSuccessors();

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

        /**
         * Builds a printable sudoku
         *
         * @return A string version of puzzle
         */
        std::string printable();

        /**
         * Returns copy of sudoku
         *
         * @return sudoku
         */
        Sudoku getSudoku();

        /**
         * Accessor for number of configsTried to solve
         *
         * @return configsTried
         */
        static int getConfigsTried();


};


#endif //SUDOKU_SOLVER_SUDOKUCONFIG_H
