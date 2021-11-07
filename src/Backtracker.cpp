//
// Created by mattl on 11/6/2021.
//

#include "Backtracker.h"

/**
 * Constructor for backtracker
 *
 * @param debug whether debug should be enabled
 */
Backtracker::Backtracker(bool debug) {
    this->debug = debug;

}

/**
 * If debug is on will print the config
 *
 * @param msg Status of the config
 * @param config Printed version of config
 */
void Backtracker::debugPrint(std::string msg, SudokuConfig &config) {
    if (debug) {
        std::cout << msg << ":\n" << config.printable() << std::endl;
    }
}

/**
 * Recursively look for solution
 *
 * @param config configuration to look at
 * @return Possibly a solution or possibly empty
 */
std::optional<SudokuConfig> Backtracker::solve(SudokuConfig config) {
    debugPrint("Current config", config);

    // Check if complete
    if (config.isGoal()) {
        return std::optional(config);
    }
    else {
        // Check each successor which are already known to be valid
        for (SudokuConfig successor: config.getSuccessors()) {
            debugPrint("\tValid successor", successor);
            std::optional possibleSol = solve(successor);
            if (possibleSol.has_value()) {
                return possibleSol;
            }

        }

    }

    // If none of that runs that means there is no solution
    return {};

}