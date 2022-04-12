#include "controller.h"

int main(int argc, char *argv[]) {
    Controller con(argc == 1?  "-easy" : argv[1]); 
    con.readInput();
}