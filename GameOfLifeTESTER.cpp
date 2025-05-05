#include "GameOfLife.h"
#include <cassert>
#include <iostream>

void testDynamicThresholds() {
    GameOfLife game(5, 5, 3, 2, 2);  // Use default thresholds for simplicity
    game.initializeBlinker();
    game.nextGeneration();
    assert(game.countNeighbors(1, 1) == 1);  // Check the state of the grid after the first generation
    std::cout << "testDynamicThresholds passed!" << std::endl;
}

int main() {
    testDynamicThresholds();
    return 0;
}
