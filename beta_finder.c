#include "libs/matrix.h"
#include <stdio.h>

int main() {
  int X[] = {1, 2, 3, 4, 5};
  int x_n = sizeof(X) / sizeof(X[0]);
  int Y[] = {1, 1, 1, 1, 1};

  int Xa[x_n][COLS];
  make_augmented(X, Y, x_n, Xa);

  int XaT[COLS][x_n];
  transpose(Xa, x_n, XaT);

  int mulXaT[COLS][COLS];
  multiply(XaT, Xa, COLS, COLS, mulXaT);

  int det = determinant(mulXaT);

  float inv[COLS][COLS];
  inverse(mulXaT, inv);

  float XaTY[COLS];
  mat_vec_multiply((float (*)[COLS])XaT, (float *)Y, x_n, XaTY);

  float beta[COLS];
  mat_vec_multiply(inv, XaTY, COLS, beta);

  return 0;
}
