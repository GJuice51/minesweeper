#include <iostream>
#include "controller.h"

int main(int argc, char *argv[]) {
    Controller con(argv[1]); 
    con.readInput();
}