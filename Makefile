CXX=g++
CXXFLAGS=-std=c++14 -Wall -MMD -g
OBJECTS=main.o controller.o board.o cell.o
DEPENDS=${OBJECTS:.o=.d}
EXEC=minesweeper

${EXEC}: ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC}
-include ${DEPENDS}

.PHONY: clean
clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}

