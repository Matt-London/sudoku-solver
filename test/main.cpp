//
// Created by mattl on 11/6/2021.
//

#include <iostream>
#include <optional>

#include "../include/Sudoku.h"
#include "../include/SudokuConfig.h"
#include "../include/Backtracker.h"
#include "../include/constants.h"

using namespace std;

int main() {
    Sudoku sudoku(false);

    /* Four by Four
    sudoku.setLocked(3, 0, 1);
    sudoku.setLocked(4, 0, 3);
    sudoku.setLocked(1, 1, 2);
    sudoku.setLocked(2, 2, 1);
    sudoku.setLocked(3, 3, 0);
    sudoku.setLocked(4, 3, 2);
    */

    /* Nine by nine */
    // Line 0
    sudoku.setLocked(1, 0, 1);
    sudoku.setLocked(6, 0, 4);
    sudoku.setLocked(8, 0, 5);
    // Line 1
    sudoku.setLocked(3, 1, 1);
    sudoku.setLocked(4, 1, 6);
    // Line 2
    sudoku.setLocked(9, 2, 1);
    sudoku.setLocked(1, 2, 3);
    sudoku.setLocked(6, 2, 6);
    sudoku.setLocked(5, 2, 8);
    // Line 3
    sudoku.setLocked(3, 3, 0);
    sudoku.setLocked(5, 3, 5);
    sudoku.setLocked(7, 3, 7);
    // Line 4
    sudoku.setLocked(2, 4, 0);
    sudoku.setLocked(1, 4, 8);
    // Line 5
    sudoku.setLocked(8, 5, 1);
    sudoku.setLocked(9, 5, 3);
    sudoku.setLocked(3, 5, 8);
    // Line 6
    sudoku.setLocked(5, 6, 0);
    sudoku.setLocked(3, 6, 2);
    sudoku.setLocked(6, 6, 5);
    sudoku.setLocked(8, 6, 7);
    // Line 7
    sudoku.setLocked(4, 7, 2);
    sudoku.setLocked(5, 7, 7);
    // Line 8
    sudoku.setLocked(8, 8, 3);
    sudoku.setLocked(5, 8, 4);
    sudoku.setLocked(6, 8, 7);


    SudokuConfig config(0, -1, sudoku);

    Backtracker backtracker(false);

    optional solution = backtracker.solve(config);

    if (solution.has_value()) {
        cout << solution.value().printable() << endl;
    }
    else {
        cout << "No solution!" << endl;
    }

    return 0;

}