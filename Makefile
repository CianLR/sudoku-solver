CXX = g++

CXXFLAGS = -g -Wall -std=c++2a

sudoku: main.o grid.o input.o solver.o
	$(CXX) $(CXXFLAGS) -o sudoku main.o grid.o input.o solver.o

main.o: main.cc grid.h input.h
grid.o: grid.cc grid.h
input.o: input.cc input.h grid.h
solver.o: solver.cc solver.h grid.h

clean:
	rm *.o sudoku
