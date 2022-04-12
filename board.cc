#include "board.h"
#include "cell.h"
#include <cstdlib>
#include <utility>

using namespace std;

// Constructor
Controller::Board::Board(int h, int w): height{h}, width{w} {
    for (int i = 0; i < height; ++i) {
        vector<Cell *> row;
        for (int j = 0; j < width; ++j) {
            row.emplace_back(new Cell);
        }
        cells.emplace_back(row);
    }
}

// Destructor
Controller::Board::~Board() {
    for (auto &row: cells){
        for(auto &cl: row)
            delete cl;
    }
}
