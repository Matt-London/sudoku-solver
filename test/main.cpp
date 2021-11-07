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

    sudoku.setLocked(3, 0, 0);
    sudoku.setLocked(4, 0, 1);
    sudoku.setLocked(1, 0, 2);
    sudoku.setLocked(2, 1, 1);
    sudoku.setLocked(2, 2, 2);
    sudoku.setLocked(1, 3, 1);
    sudoku.setLocked(4, 3, 2);
    sudoku.setLocked(3, 3, 3);


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