#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <string>
#include <utility>

// The interface for the I/O controller of the game

class Controller {
    class Board;
    Board *b;
    
    bool display();
    std::pair<int,int> parseCoordinates(const std::string &cmd);

    public:
    Controller(std::string diff);
    ~Controller();
    void readInput();

};

#endif