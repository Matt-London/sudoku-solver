//
// Created by mattl on 11/7/2021.
//

#include "Reader.h"

/**
 * Constructor for reader
 *
 * @param path path to containing puzzle file
 */
 void Reader::read_sudoku(Sudoku &sudoku, std::string path) {
    process_input(sudoku, path);

}

/**
 * Processes the input file and builds the puzzle
 *
 */
 void Reader::process_input(Sudoku &sudoku, std::string path) {
    int row = 0;
    int col = 0;

    // Adapted from https://www.systutorials.com/how-to-process-a-file-line-by-line-in-c/
    std::ifstream puzzleFile(path);
    std::string line;
    while (std::getline(puzzleFile, line)) {
        if (row >= BOARD_LENGTH) {
            break;
        }

        col = 0;
        // Loop through line
        for (int i = 0; i < (BOARD_LENGTH * 2) - 1; i += 2) {
            if (line[i] != '.') {
                sudoku.setLocked(line[i] - '0', row, col);

            }
            col++;
        }
        row++;
    }

}
