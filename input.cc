#include <optional>
#include <iostream>
#include <string>

#include "input.h"
#include "grid.h"

std::optional<Grid> ReadGridStdin() {
    Grid g;
    for (int y = 0; y < 9; ++y) {
        std::string line;
        std::getline(std::cin, line);
        if (line.length() != 9) {
            return std::nullopt;
        }
        for (int x = 0; x < 9; ++x) {
            if (line[x] == '.') continue;
            if (!g.SetCell(x, y, line[x] - '0')) {
                return std::nullopt;
            }
        }
    }
    return g;
}
