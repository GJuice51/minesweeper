#ifndef BOARD_H
#define BOARD_H

#include "controller.h"
#include <vector>

class Cell;
class Controller::Board {
    int height, width;
    std::vector<std::vector<Cell *>> cells;
    int bombsLeft;

    public:
    Board(int h, int w);
    ~Board();
    friend class Controller;
};

#endif