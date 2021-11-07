cmake_minimum_required(VERSION 3.20)
project(sudoku_solver)

set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_STANDARD 14)

include_directories(include)
include_directories(src)
include_directories(test)

add_executable(sudoku_solver
        test/main.cpp src/Sudoku.cpp include/Sudoku.h include/constants.h src/SudokuConfig.cpp include/SudokuConfig.h src/Backtracker.cpp include/Backtracker.h)
