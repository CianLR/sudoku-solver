CXX = g++

CXXFLAGS = -g -Wall -std=c++2a

sudoku: main.o sudoku_grid.o input.o solver.o
	$(CXX) $(CXXFLAGS) -o sudoku main.o sudoku_grid.o input.o solver.o

main.o: main.cc sudoku_grid.h input.h
sudoku_grid.o: sudoku_grid.cc sudoku_grid.h
input.o: input.cc input.h sudoku_grid.h
solver.o: solver.cc solver.h sudoku_grid.h

clean:
	rm *.o sudoku
