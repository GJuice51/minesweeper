#include "controller.h"
#include "board.h"
#include "cell.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Constructor
Controller::Controller(string diff) {
    if (diff == "-easy") {
        b = new Board(8, 10);
    } else if (diff == "-medium") {
        b = new Board(14, 18);
    } else if (diff == "-hard") {
        b = new Board(20, 24);
    } else {
        throw runtime_error("Usage: ./minesweeper (-easy | -medium | -hard )");
    }
    display();
} 

Controller::~Controller() { delete b; }

bool Controller::display() {
    bool isWin = true;
    cout << "\nMines Left: " << b->minesLeft << "\n   ";
    char c = 'a';
    for (int i = 0; i < b->width; ++i, ++c) cout << c;
    cout << endl;
    for (int i = 0; i < b->height; ++i) {
        cout << setw(2) <<(i+1) << ' ';
        for (int j = 0; j < b->width; ++j) {
            char ele = b->cells[i][j]->getElement();
            cout << ele;
            if (ele == 'O') isWin = false;
        }
        cout << endl;
    }
    cout << endl;
    return isWin;
} 

// Parse through cmd and return coordinates
pair<int,int> Controller::parseCoordinates(const string &cmd) {
    int y, x;
    try {
        int cutoff = ('0' <= cmd[1] && cmd[1] <= '9')? 2 : 1;
        y = stoi(cmd.substr(0, cutoff)) - 1;
        string s = cmd.substr(cutoff);
        x = s[0] - 'a';
        if (y < 0 || y >= b->height || x < 0 || x >= b->width || s.length() != 1) 
            throw runtime_error("Invalid coordinates.");
    } catch (...) {
        return {-1,-1};
    }
    return {y, x};
}

// Read in input from player
void Controller::readInput() {

    while(true) {
        // Get next command
        cout << "Command: ";
        string cmd;
        cin >> cmd;
        if(cin.fail()) break;

        // Parse input
        bool markCell = false;
        if (cmd == "mark") {
            if (b->minesLeft == 0) {
                cout << "No more mines to mark!" << endl;
                continue;
            }
            markCell  = true;
            cin >> cmd;         
        }       
        pair<int, int> cell = parseCoordinates(cmd);
        // Repeat if invalid coordinates
        while (cell.first == -1) { 
            cout << "Invalid coordinates, try again." << endl;
            cout << "Command: ";
            cin >> cmd;
            if (cin.fail()) break;
            cell = parseCoordinates(cmd);
        }
        
        // Execute commands
        Cell *c = b->cells[cell.first][cell.second];
        if (markCell) { 
            // Mark a cell with an X
            b->minesLeft += (c->isAMark())? 1 : -1;
            c->mark();
        } else {
            // Open a cell
            c->open();
            if(c->isAMark()) {
                ++b->minesLeft;
                c->mark();
            }

            // Lose if a mine is opened
            if(c->isABomb()) {
                for (auto cl: b->mines) 
                    cl->open();        
                display();
                cout << "You lose!" << endl;
                break;       
            }
            
            // Open nearby cells if no mines
            if (c->getElement() == '.')
                b->openNearby(cell.first, cell.second);
        }

        // Display the Grid
        if(display()) {
            cout << "*******************\n"
                 << "      YOU WIN!     \n"
                 << "*******************" << endl;
            break;
        }
    }
}