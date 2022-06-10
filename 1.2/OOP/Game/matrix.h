#ifndef MATRIX_H
#define MATRIX_H

#include <randomise.h>
class Matrix
{
public:
  bool checkWin();

  void write(int i, int j, int val);

  void start();

  void solve();

  int read(int i, int j);

  int input(int (*mat)[10]);

  Matrix();

private:
  int obj[10][10];
  int row[10];
  int col[10];
  int block[5][5];
  int memoryMatrix[10][10];

  Randomise randomise;

  int dfs(int ni, int nj);
  void empty();
  void init();
};
#endif // MATRIX_H
