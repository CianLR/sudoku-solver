#include <iostream>
#include <chrono>
#include <string>

#include "grid.h"
#include "input.h"
#include "solver.h"

int main(int argc, char **argv) {
    bool animate = false;
    if (argc > 1 && std::string(argv[1]) == "--animate") {
        animate = true;
    }
    auto g = ReadGridStdin();
    if (!g.has_value()) {
        return 1;
    }
    std::cout << "\nSolving\n";
    g->Print();
    auto start = std::chrono::high_resolution_clock::now();
    bool solved = Solve(*g, animate);
    auto stop = std::chrono::high_resolution_clock::now();
    if (solved) {
        std::cout << "\nSolved\n";
        if (!animate) g->Print();
    } else {
        std::cout << "\nCould not solve\n";
    }
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    if (!animate) {
        std::cout << "\nSolver time " << duration.count() << "usec\n";
    }
}
