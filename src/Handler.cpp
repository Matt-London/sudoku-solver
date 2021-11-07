//
// Created by mattl on 11/7/2021.
//

#include "Handler.h"

/**
 * Constructor that takes path
 *
 * @param path path to puzzle file
 */
Handler::Handler(std::string path) {
    Reader::read_sudoku(unsolved, path);

    SudokuConfig config(0, -1, unsolved);

    Backtracker backtracker(false);
    std::optional solution = backtracker.solve(config);

    if (solution.has_value()) {
        hasSolution = true;
        solved = Sudoku(solution.value().getSudoku());
    }
    else {
        hasSolution = false;
    }


}

/**
 * General printer for the array
 *
 * @param grid Sudoku grid
 */
void Handler::prettyPrint(int grid[BOARD_LENGTH][BOARD_LENGTH]) {
    int subLen = sqrt(BOARD_LENGTH);

    for (int i = 0; i < BOARD_LENGTH; i++) {
        for (int j = 0; j < BOARD_LENGTH; j++) {
            if (grid[i][j] == BLANK) {
                std::cout << ". ";
            }
            else {
                std::cout << grid[i][j] << " ";
            }

            if (j + 1 != BOARD_LENGTH && (j + 1) % subLen == 0) {
                std::cout << "| ";
            }

        }
        std::cout << std::endl;
        if (i + 1 != BOARD_LENGTH && (i + 1) % subLen == 0) {
            int dashLen = BOARD_LENGTH * 2 + subLen;
            for (int j = 0; j < dashLen; j++) {
                std::cout << "-";

            }
            std::cout << std::endl;
        }

    }
}

/**
 * Prints out the unsolved puzzle with delimiters
 */
void Handler::prettyPrintBase() {
    prettyPrint(unsolved.grid);
}

/**
 * Prints out the solved puzzle with the delimiters
 */
void Handler::prettyPrintSol() {
    if (hasSolution) {
        prettyPrint(solved.grid);
    }
    else {
        std::cout << "No solution!" << std::endl;
    }
}