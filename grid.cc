#include <iostream>

#include "grid.h"

Grid::Grid() : cells{0} {}

int CalcIndex(int x, int y) {
  if (x < 0 || x >= 9) return false;
  if (y < 0 || y >= 9) return false;
  int index = x + (9 * y);
  if (index < 0 || index >= (9*9)) {
    return -1;
  }
  return index;
}

bool Grid::SetCell(int x, int y, int n) {
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

void Grid::ClearCell(int x, int y) {
  int index = CalcIndex(x, y);
  if (index != -1) {
    cells[index] = 0;
  }
}

int Grid::GetCell(int x, int y) const {
  int index = CalcIndex(x, y);
  return index == -1 ? -1 : cells[index];
}

void Grid::Print() const {
  std::cout << "┏━━━┯━━━┯━━━┳━━━┯━━━┯━━━┳━━━┯━━━┯━━━┓\n";
  for (int y = 0; y < 9; ++y) {
    std::cout << "┃";
    for (int x = 0; x < 9; ++x) {
      int n = GetCell(x, y);
      std::cout << " " << (n ? std::to_string(n) : " ");
      if (x == 2 || x == 5 || x == 8) {
        std::cout << " ┃";
      } else {
        std::cout << " │";
      }
    }
    std::cout << '\n';
    if (y == 2 || y == 5) {
      std::cout << "┣━━━┿━━━┿━━━╋━━━┿━━━┿━━━╋━━━┿━━━┿━━━┫\n";
    } else if (y == 8) {
      std::cout << "┗━━━┷━━━┷━━━┻━━━┷━━━┷━━━┻━━━┷━━━┷━━━┛\n";
    } else {
      std::cout << "┠───┼───┼───╂───┼───┼───╂───┼───┼───┨\n";
    }
  }
}

bool Grid::IsValidMove(int x, int y, int n) const {
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
