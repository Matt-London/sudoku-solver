//
// Created by mattl on 11/6/2021.
//

#include <iostream>
#include <string>

#include "Sudoku.h"
#include "SudokuHandler.h"

using namespace std;

int main(int argc, char *argv[]) {
    string partialPath;
    if (argc >= 2) {
        partialPath = string(argv[1]);
    }

    SudokuHandler handler("../" + partialPath);

    cout << "Entered Board: " << endl;
    handler.prettyPrintBase();
    cout << endl;

    cout << "Solution: " << endl;
    handler.prettyPrintSol();

    return 0;

}