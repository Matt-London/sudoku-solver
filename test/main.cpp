//
// Created by mattl on 11/6/2021.
//

#include "../include/Sudoku.h"
#include "../include/Handler.h"

using namespace std;

int main() {
    Handler handler("../input/input01.txt");
//    handler.prettyPrintBase();

    handler.prettyPrintSol();


    return 0;

}