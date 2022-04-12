#include "cell.h"

// Constructor
Cell::Cell(): bombsNear{0}, isBomb{false}, isOpen{false}, isMarked{false} {}

// Get element
char Cell::getElement() { 
    if (isMarked) return 'X';
    else if(!isOpen) return 'O'; 
    else if (isBomb) return '@';   
    else if(bombsNear == 0) return '.';
    else return ('0' + bombsNear);
}

// Open the Cell
void Cell::open() { isOpen = true; }

bool Cell::isAnOpen() { return isOpen; }

// Mark the Cell
void Cell::mark() { isMarked = !isMarked; }

// Check if cell is marked
bool Cell::isAMark() { return isMarked; }

// Set cell as bomb
void Cell::setBomb() { isBomb = true; }

// Check if cell is a bomb
bool Cell::isABomb() { return isBomb; }

// Increment count of bombs near
void Cell::incrNear() { ++bombsNear; }