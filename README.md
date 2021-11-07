# Sudoku-Solver

A sudoku solver written in C++ that uses a backtracking algorithm to solve any sudoku puzzle of any size

## Executing

This was build and tested in JetBrain's CLion IDE<br>
However, it can be built using CMake

## Input syntax

- The easiest way to provide user input is with a puzzle file<br>
- The puzzle files have the following structure for example:
```
1 . . . . 7 . 9 .
. 3 . . 2 . . . 8
. . 9 6 . . 5 . .
. . 5 3 . . 9 . .
. 1 . . 8 . . . 2
6 . . . . 4 . . .
3 . . . . . . 1 .
. 4 . . . . . . 7
. . 7 . . . 3 . .
```
- The given numbers are written as numbers and the blank spaces are shown using a period (.)
- Notes may be written following the puzzle in the puzzle file, they will be ignored

## Usage

**Give the path to a puzzle file as seen below**
```shell
$ sudokuSolver puzzleFile.txt
```
**NOTE:** If you are using a size other than 9 by 9, that must be specified in include/constants.h<br>
That should take the following format (for example a 4 by 4):
```cpp
#define BOARD_LENGTH 4
```

## Contributing
If you would like to contribute, you may make a pull request. It will be helpful if you first open an issue describing the change that you are interested in contributing.

## License
[MIT](https://choosealicense.com/licenses/mit/)