#include <stdio.h>

#include "sudoku_grid.h"

SudokuGrid::SudokuGrid() : cells{0} {}

int CalcIndex(int x, int y) {
    if (x < 0 || x >= 9) return false;
    if (y < 0 || y >= 9) return false;
    int index = x + (9 * y);
    if (index < 0 || index >= (9*9)) {
        return -1;
    }
    return index;
}

bool SudokuGrid::SetCell(int x, int y, int n) {
    if (n <= 0 || n > 9) {
        return false;
    }
    int index = CalcIndex(x, y);
    if (index == -1) {
        return false;
    }
    if (!IsValidMove(x, y, n)) {
        return false;
    }
    cells[index] = n;
    return true;
}

void SudokuGrid::ClearCell(int x, int y) {
    int index = CalcIndex(x, y);
    if (index != -1) {
        cells[index] = 0;
    }
}

int SudokuGrid::GetCell(int x, int y) const {
    int index = CalcIndex(x, y);
    return index == -1 ? -1 : cells[index];
}

void SudokuGrid::Print() const {
    for (int y = 0; y < 9; ++y) {
        for (int x = 0; x < 9; ++x) {
            int n = GetCell(x, y);
            if (n != 0) {
                printf(" %d", n);
            } else {
                fputs(" .", stdout);
            }

            if (x == 2 || x == 5) {
                fputs(" |", stdout);
            }
        }
        putchar('\n');
        if (y == 2 || y == 5) {
            puts("----------------------");
        }
    }
}

bool SudokuGrid::IsValidMove(int x, int y, int n) const {
    for (int c = 0; c < 9; ++c) {
        if (c != x && GetCell(c, y) == n) {
            return false;
        }
    }
    for (int r = 0; r < 9; ++r) {
        if (r != y && GetCell(x, r) == n) {
            return false;
        }
    }
    int sq_col_start = (x / 3) * 3;
    int sq_row_start = (y / 3) * 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            int c = sq_col_start + i;
            int r = sq_row_start + j;
            if (c == x && r == y) {
                continue;
            }
            if (GetCell(c, r) == n) {
                return false;
            }
        }
    }
    return true;
}
