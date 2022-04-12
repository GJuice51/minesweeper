#include "controller.h"
#include "board.h"
#include "cell.h"
#include <iostream>

using namespace std;

// Constructor
Controller::Controller(string diff) {
    if (diff == "-easy") {
        b = new Board(8,10);
    } else if (diff == "-medium") {

    } else if (diff == "-hard") {

    } else {
        throw runtime_error("Usage: ./minesweeper (-easy | -medium | -hard )");
    }

} 

Controller::~Controller() { delete b; }

void Controller::display() {
    cout << "  ";
    char c = 'a';
    for (int i = 0; i < b->width; ++i, ++c) cout << c;
    cout << endl;
    for (int i = 0; i < b->height; ++i) {
        cout << (i+1) << ' ';
        for (int j = 0; j < b->width; ++j) {
            cout << b->cells[i][j]->getElement();
        }
        cout << endl;
    }
} 

// Read in input from player
void Controller::readInput() {
    display();
    cout << "hi!" << endl;
}