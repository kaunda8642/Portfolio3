#include "GameOfLife.h"
#include <iostream>

int main() {
    int rows = 5;  // Number of rows
    int cols = 5;  // Number of columns

    // Get custom thresholds from user
    int birth, death, maintain;
    std::cout << "Enter the number of neighbors required to birth a cell: ";
    std::cin >> birth;
    std::cout << "Enter the number of neighbors required to kill a cell: ";
    std::cin >> death;
    std::cout << "Enter the number of neighbors required to maintain a cell: ";
    std::cin >> maintain;

    GameOfLife game(rows, cols, birth, death, maintain);

    // Ask the user to choose a pattern
    int choice;
    std::cout << "Select a pattern to start with:\n";
    std::cout << "1. Blinker\n";
    std::cout << "2. Block\n";
    std::cout << "3. Toad\n";
    std::cout << "4. Glider\n";
    std::cout << "Enter the number corresponding to your choice: ";
    std::cin >> choice;

    // Initialize grid based on user input
    switch (choice) {
    case 1:
        game.initializeBlinker();
        break;
    case 2:
        game.initializeBlock();
        break;
    case 3:
        game.initializeToad();
        break;
    case 4:
        game.initializeGlider();
        break;
    default:
        std::cout << "Invalid choice, using default (blinker).\n";
        game.initializeBlinker();
        break;
    }

    // Display the initial grid
    game.displayGrid();
    std::cout << "Next generation? (y/n): ";
    char cont;
    std::cin >> cont;

    // Run the game loop
    while (cont == 'y' || cont == 'Y') {
        game.nextGeneration();  // Compute the next generation
        game.displayGrid();     // Display the new grid
        std::cout << "Next generation? (y/n): ";
        std::cin >> cont;
    }

    return 0;
}