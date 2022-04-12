#ifndef BOARD_H
#define BOARD_H

#include "controller.h"
#include <vector>

class Cell;
class Controller::Board {
    int height, width, minesLeft;
    std::vector<std::vector<Cell *>> cells;
    std::vector<Cell *> mines;

    void countBombs(int y, int x);

    public:
    Board(int h, int w);
    ~Board();
    void openNearby(int y, int x);
    friend class Controller;
};

#endif