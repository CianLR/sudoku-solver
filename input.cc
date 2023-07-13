#include <optional>
#include <stdio.h>

#include "input.h"
#include "grid.h"

std::optional<Grid> ReadGridStdin() {
    Grid g;
    for (int y = 0; y < 9; ++y) {
        char line[10];
        if (scanf("%10c", line) != 1) {
            return std::nullopt;
        }
        for (int x = 0; x < 9; ++x) {
            if (line[x] == 0) return std::nullopt;
            if (line[x] == '.') continue;
            if (!g.SetCell(x, y, line[x] - '0')) {
                return std::nullopt;
            }
        }
    }
    return g;
}