#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

#include <vector>

class GameOfLife {
public:
    GameOfLife(int rows, int cols, int birth, int death, int maintain);

    // Functions to set cell states
    void setCellState(int row, int col, bool state);
    void displayGrid() const;
    void nextGeneration();

    // Pattern initialization functions
    void initializeBlinker();
    void initializeBlock();
    void initializeToad();
    void initializeGlider();

private:
    int rows;
    int cols;
    int birthThreshold;
    int deathThreshold;
    int maintainThreshold;
    std::vector<std::vector<bool>> grid;
    std::vector<std::vector<bool>> nextGrid;

    int countNeighbors(int row, int col) const;
    void updateGrid();
};

#endif
#pragma once
