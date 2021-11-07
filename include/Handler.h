//
// Created by mattl on 11/7/2021.
//

#ifndef SUDOKU_SOLVER_HANDLER_H
#define SUDOKU_SOLVER_HANDLER_H


#include "Sudoku.h"
#include "SudokuConfig.h"
#include "Reader.h"
#include "Backtracker.h"

#include <iostream>
#include <string>

class Handler {
    private:
        Sudoku unsolved;
        Sudoku solved;
        bool hasSolution;

        std::string path;

        /**
         * General printer for the array
         *
         * @param grid Sudoku grid
         */
        void prettyPrint(int grid[BOARD_LENGTH][BOARD_LENGTH]);

    public:
        /**
         * Constructor that takes path
         *
         * @param path path to puzzle file
         */
        Handler(std::string path);

        /**
         * Prints out the unsolved puzzle with delimiters
         */
        void prettyPrintBase();

        /**
         * Prints out the solved puzzle with the delimiters
         */
        void prettyPrintSol();

};


#endif //SUDOKU_SOLVER_HANDLER_H
