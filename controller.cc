#include "controller.h"
#include "board.h"
#include <iostream>

using namespace std;

// Constructor
Controller::Controller(string diff) {
    if (diff == "-easy") {
        board = make_unique<Board>(8,10);
    } else if (diff == "-medium") {

    } else if (diff == "-hard") {

    } else {
        throw runtime_error("Usage: ./minesweeper (-easy | -medium | -hard )");
    }

} 

void Controller::readInput() {
    cout << "hi!" << endl;
}