#include "cell.h"

// Constructor
Cell::Cell(): element{'_'}, bombsNear{0}, isBomb{false} {}

// get element
char Cell::getElement() { return element; }

// Set cell as bomb
void Cell::setBomb() { isBomb = true; }

// Increment count of bombs near
void Cell::incrNear() { if(!isBomb) ++bombsNear; }