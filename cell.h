#ifndef CELL_H
#define CELL_H

// The interface for a cell of a minesweeper grid

class Cell {
    int bombsNear;
    bool isBomb, isOpen, isMarked;

    public:
    Cell();
    char getElement();
    void open();
    bool isAnOpen();
    void mark();
    bool isAMark();
    
    void setBomb();
    bool isABomb();
    void incrNear();
};
#endif