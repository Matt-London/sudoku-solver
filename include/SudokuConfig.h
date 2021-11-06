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
         * @return
         */
        std::vector<Sudoku> getSuccessors();
};


#endif //SUDOKU_SOLVER_SUDOKUCONFIG_H
