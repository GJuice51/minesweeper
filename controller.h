#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <string>

class Controller {
    class Board;
    Board *b;
    
    void display();

    public:
    Controller(std::string diff);
    ~Controller();
    void readInput();

};

#endif