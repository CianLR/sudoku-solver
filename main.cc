#include <iostream>
#include <chrono>
#include <string>

#include "grid.h"
#include "input.h"
#include "solver.h"

using hrclock = std::chrono::high_resolution_clock;

int main(int argc, char **argv) {
  bool animate = false;
  if (argc > 1 && std::string(argv[1]) == "--animate") {
    animate = true;
  }
  auto g = ReadGridStdin();
  if (!g.has_value()) {
    std::cout << "Unable to parse input.\n";
    return 1;
  }
  std::cout << "\nSolving...\n";
  g->Print();
  auto start = hrclock::now();
  bool solved = Solve(*g, animate);
  auto stop = hrclock::now();
  if (solved) {
    std::cout << "\nSolved.\n";
    if (!animate) g->Print();
  } else {
    std::cout << "\nCould not solve.\n";
  }
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
  if (!animate) {
    std::cout << "\nSolver time " << duration.count() << "usec.\n";
  }
}
