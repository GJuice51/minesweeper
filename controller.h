#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <string>
#include <memory>

class Board;
class Controller {
    unique_ptr<Board> board;
    int bombs;

    public:
    Controller(std::string diff);
    ~Controller();
    void readInput();


};

#endif