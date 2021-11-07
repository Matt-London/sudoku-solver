//
// Created by mattl on 11/6/2021.
//

//
// Structure of Backtracker borrowed and implemented from https://github.com/CSCI-140-242-CSAPX by RIT CS
//

#ifndef SUDOKU_SOLVER_BACKTRACKER_H
#define SUDOKU_SOLVER_BACKTRACKER_H

#include <iostream>
#include <string>
#include <optional>

#include "SudokuConfig.h"

class Backtracker {
    private:
        bool debug;

    public:
        /**
         * Constructor for backtracker
         *
         * @param debug whether debug should be enabled
         */
        Backtracker(bool debug);

        /**
         * If debug is on will print the config
         *
         * @param msg Status of the config
         * @param config Printed version of config
         */
        void debugPrint(std::string msg, SudokuConfig &config);

        /**
         * Recursively look for solution
         *
         * @param config configuration to look at
         * @return Possibly a solution or possibly empty
         */
        std::optional<SudokuConfig> solve(SudokuConfig config);

};


#endif //SUDOKU_SOLVER_BACKTRACKER_H
