//
// Created by mattl on 11/6/2021.
//
#ifndef SUDOKU_SOLVER_SUDOKU_H
#define SUDOKU_SOLVER_SUDOKU_H

#include <vector>
#include "../include/constants.h"

/**
 * Class to represent the sudoku board
 *
 */
class Sudoku {
    private:
        bool locked[BOARD_LENGTH][BOARD_LENGTH];

    public:
        int grid[BOARD_LENGTH][BOARD_LENGTH];

        /**
         * Constructor for sudoku, fills blank
         *
         */
        Sudoku();

        /**
        * Copy constructor
        *
        * @param other other sudoku to copy from
        */
        Sudoku(Sudoku const &other);

        /**
         * Accessor for a specific space
         *
         * @param i row number
         * @param j col number
         * @return number at the space
         */
        int getSpace(int i, int j) const;

        /**
         * Accessor for status of space
         *
         * @param i row number
         * @param j col number
         * @return status of space
         */
        bool isLocked(int i , int j) const;

        /**
         * Set a space to a number
         *
         * @param val number to set
         * @param i row
         * @param j col
         * @return whether it was successful
         */
        bool setSpace(int val, int i, int j);

        /**
         * Sets the given space then declares it as locked
         *
         * @param val number to set
         * @param i row
         * @param j col
         */
        void setLocked(int val, int i, int j);

        /**
         * Gets all the numbers in the sub box
         *
         * @param row Row of square in desired box
         * @param col Col of square in desired box
         * @return Vector of the integers in the box minus current
         */
        void getSub(std::vector<int> &neighbors, int row, int col);

};


#endif //SUDOKU_SOLVER_SUDOKU_H
