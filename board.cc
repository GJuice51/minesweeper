#include "board.h"
#include "cell.h"
#include <cstdlib>
#include <time.h>
#include <iostream>

using namespace std;

// Constructor
Controller::Board::Board(int h, int w): height{h}, width{w} {

    // Create the grid
    for (int i = 0; i < height; ++i) {
        vector<Cell *> row;
        for (int j = 0; j < width; ++j) 
            row.emplace_back(new Cell);       
        cells.emplace_back(row);
    }

    // Get number of mines
    srand(time(NULL));
    if (height == 8) minesLeft = 8;
    else if (height == 14) minesLeft = 30;
    else minesLeft = 70;
    int leftToAdd = minesLeft;

    // Randomly place mines
    while(leftToAdd > 0) {
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j ) {
                int rd = rand() % 100;
                if (rd <= 8 && !cells[i][j]->isABomb() && leftToAdd > 0) {
                    cells[i][j]->setBomb();
                    countBombs(i, j);
                    mines.emplace_back(cells[i][j]);
                    --leftToAdd;
                }           
                //cells[i][j]->open();      // delete later
            }
        }
    }
}

// Destructor
Controller::Board::~Board() {
    for (auto &row: cells){
        for(auto &cl: row) delete cl;
    }
}

// Increment the bomb counter around the cell
void Controller::Board::countBombs(int y, int x) {
    for (int i = y - 1; i < y + 2; ++i) {
        for (int j = x - 1; j < x + 2; ++j ) {
            if (i < 0 || i >= height || j < 0 || j >= width) 
                continue;
            cells[i][j]->incrNear();
        }
    }
}

// Open the cells nearby
void Controller::Board::openNearby(int y, int x) {
    for (int i = y - 1; i < y + 2; ++i) {
        for (int j = x - 1; j < x + 2; ++j ) {
            if (i < 0 || i >= height || j < 0 || j >= width || cells[i][j]->isAnOpen()) 
                continue;
            cells[i][j]->open();
            if (cells[i][j]->getElement() == '.')
                openNearby(i, j);
        }
    }
}