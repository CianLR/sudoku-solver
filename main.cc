#include <iostream>
#include <chrono>

#include "sudoku_grid.h"
#include "input.h"
#include "solver.h"

int main() {
    auto g = ReadGridStdin();
    if (!g.has_value()) {
        return 1;
    }
    std::cout << "\nGrid before solving:\n";
    g->Print();
    auto start = std::chrono::high_resolution_clock::now();
    bool solved = Solve(*g);
    auto stop = std::chrono::high_resolution_clock::now();
    if (solved) {
        std::cout << "\nGrid after solving:\n";
        g->Print();
    } else {
        std::cout << "\nCould not solve\n";
    }
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "\nSolver time " << duration.count() << "usec\n";
}
