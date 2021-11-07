//
// Created by mattl on 11/6/2021.
//
#ifndef SUDOKU_SOLVER_SUDOKU_H
#define SUDOKU_SOLVER_SUDOKU_H

#include "../include/constants.h"

/**
 * Class to represent the sudoku board
 *
 */
class Sudoku {
    private:
        int grid[BOARD_LENGTH][BOARD_LENGTH];
        bool locked[BOARD_LENGTH][BOARD_LENGTH];

    public:
        /**
         * Constructor for debug that decides whether to fill or not
         *
         * @param fill
         */
        Sudoku(bool fill);

        /**
        * Copy constructor
        *
        * @param other other sudoku to copy from
        */
        Sudoku(Sudoku const &other);

        /**
         * Default constructor that will be called by the program to fill
         */
        Sudoku();

        /**
         * Constructor to be used when a puzzle is generated externally
         *
         * @param board Board with numbers and -1 representing blank
         */
        Sudoku(int board[BOARD_LENGTH][BOARD_LENGTH]);

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

};


#endif //SUDOKU_SOLVER_SUDOKU_H
