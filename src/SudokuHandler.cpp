//
// Created by mattl on 11/7/2021.
//

#include "SudokuHandler.h"

/**
 * Constructor that takes path
 *
 * @param path path to puzzle file
 */
SudokuHandler::SudokuHandler(std::string path) {
    Reader::read_sudoku(unsolved, path);

    SudokuConfig config(0, -1, unsolved);

    Backtracker backtracker(false);

    auto start = std::chrono::high_resolution_clock::now();
    std::optional solution = backtracker.solve(config);
    auto stop = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

    elapsedTime = std::chrono::duration<double>(duration).count();

    if (solution.has_value()) {
        hasSolution = true;
        solved = Sudoku(solution.value().getSudoku());
    }
    else {
        hasSolution = false;
    }

    configsTried = config.getConfigsTried();

}

/**
 * General printer for the array
 *
 * @param grid Sudoku grid
 */
void SudokuHandler::prettyPrint(int grid[BOARD_LENGTH][BOARD_LENGTH]) {
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
void SudokuHandler::prettyPrintBase() {
    prettyPrint(unsolved.grid);
}

/**
 * Prints out the solved puzzle with the delimiters
 */
void SudokuHandler::prettyPrintSol() {
    std::cout << "Elapsed time: " << elapsedTime << " seconds" << std::endl;
    std::cout << "Configurations tried: " << configsTried << " configurations" << std::endl;

    if (hasSolution) {
        prettyPrint(solved.grid);
    }
    else {
        std::cout << "No solution!" << std::endl;
    }
}