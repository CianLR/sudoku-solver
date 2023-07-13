#include "solver.h"
#include "grid.h"

bool RecurBack(Grid &g, int r, int c) {
    if (r == 9) return true;
    if (g.GetCell(c, r) != 0) {
        return RecurBack(g, r + (c == 8), (c + 1) % 9);
    }
    for (int n = 1; n < 10; ++n) {
        if (g.SetCell(c, r, n)) {
            if (RecurBack(g, r + (c == 8), (c + 1) % 9)) {
                return true;
            }
            g.ClearCell(c, r);
        }
    }
    return false;
}

bool RecursiveBacktracking(Grid &g) {
    return RecurBack(g, 0, 0);
}

bool Solve(Grid &g) {
    return RecursiveBacktracking(g);
}
