#ifndef CELL_H
#define CELL_H

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