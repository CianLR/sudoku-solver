#include <chrono>
#include <thread>
#include <stdio.h>

#include "solver.h"
#include "grid.h"

void Animate(const Grid &g) {
    puts("\033[20F");
    g.Print();
    std::this_thread::sleep_for(std::chrono::milliseconds(20));
}

bool RecursiveBacktracking(Grid &g, bool animate, int r, int c) {
    if (r == 9) return true;
    if (g.GetCell(c, r) != 0) {
        return RecursiveBacktracking(g, animate, r + (c == 8), (c + 1) % 9);
    }
    for (int n = 1; n < 10; ++n) {
        if (g.SetCell(c, r, n)) {
            if (animate) Animate(g);
            if (RecursiveBacktracking(g, animate, r + (c == 8), (c + 1) % 9)) {
                return true;
            }
            g.ClearCell(c, r);
        }
    }
    return false;
}

bool Solve(Grid &g, bool animate) {
    return RecursiveBacktracking(g, animate, 0, 0);
}
