#include "GameOfLife.h"
#include <iostream>

GameOfLife::GameOfLife(int rows, int cols, int birth, int death, int maintain)
    : rows(rows), cols(cols), birthThreshold(birth), deathThreshold(death), maintainThreshold(maintain) {

    grid.resize(rows, std::vector<bool>(cols, false));
    nextGrid.resize(rows, std::vector<bool>(cols, false));
}

void GameOfLife::setCellState(int row, int col, bool state) {
    if (row >= 0 && row < rows && col >= 0 && col < cols) {
        grid[row][col] = state;
    }
}

void GameOfLife::displayGrid() const {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << (grid[i][j] ? "*" : ".") << " ";
        }
        std::cout << "\n";
    }
}

void GameOfLife::nextGeneration() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int neighbors = countNeighbors(i, j);

            // Determine next state of the cell
            if (grid[i][j]) {  // If cell is alive
                nextGrid[i][j] = (neighbors == maintainThreshold || neighbors == birthThreshold);
            }
            else {  // If cell is dead
                nextGrid[i][j] = (neighbors == birthThreshold);
            }
        }
    }
    updateGrid();
}

int GameOfLife::countNeighbors(int row, int col) const {
    int count = 0;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) continue;  // Skip the center cell
            int r = row + i, c = col + j;
            if (r >= 0 && r < rows && c >= 0 && c < cols && grid[r][c]) {
                count++;
            }
        }
    }
    return count;
}

void GameOfLife::updateGrid() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            grid[i][j] = nextGrid[i][j];
        }
    }
}

// Initialize predefined patterns

void GameOfLife::initializeBlinker() {
    setCellState(1, 1, true);
    setCellState(1, 2, true);
    setCellState(1, 3, true);
}

void GameOfLife::initializeBlock() {
    setCellState(1, 1, true);
    setCellState(1, 2, true);
    setCellState(2, 1, true);
    setCellState(2, 2, true);
}

void GameOfLife::initializeToad() {
    setCellState(1, 1, true);
    setCellState(1, 2, true);
    setCellState(2, 2, true);
    setCellState(2, 3, true);
    setCellState(3, 1, true);
}

void GameOfLife::initializeGlider() {
    setCellState(1, 2, true);
    setCellState(2, 3, true);
    setCellState(3, 1, true);
    setCellState(3, 2, true);
    setCellState(3, 3, true);
}


