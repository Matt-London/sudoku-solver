//
// Created by mattl on 11/7/2021.
//

#ifndef SUDOKU_SOLVER_READER_H
#define SUDOKU_SOLVER_READER_H

#include <string>
#include <fstream>

#include "Sudoku.h"

class Reader {
    public:
        /**
         * Constructor for reader
         *
         * @param path path to containing puzzle file
         */
        static void read_sudoku(Sudoku &sudoku, std::string path);

        /**
         * Processes the input file and builds the puzzle
         *
         */
        static void process_input(Sudoku &sudoku, std::string path);
};


#endif //SUDOKU_SOLVER_READER_H
