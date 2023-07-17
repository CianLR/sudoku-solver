#pragma once

class Grid {
 public:
  Grid();

  bool SetCell(int x, int y, int n);
  void ClearCell(int x, int y);
  int GetCell(int x, int y) const;
  bool IsValidMove(int x, int y, int n) const;

  void Print() const;

 private:
  int cells[81];
};
