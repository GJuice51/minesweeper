#ifndef CELL_H
#define CELL_H

class Cell {
    char element;
    int bombsNear;
    bool isBomb;

    public:
    Cell();
    char getElement();
    void setBomb();
    void incrNear();
};
#endif