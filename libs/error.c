#include "error.h"
#include "matrix.h"

float compute_error(int x[], int y[], int n) {
  float beta[COLS];
  find_beta(x, y, n, beta);

  float A[n][COLS];
  make_augmented(x, y, n, A);

  float predicted[n];
  for (int i = 0; i < n; i++) {
    predicted[i] = 0;
    for (int j = 0; j < COLS; j++)
      predicted[i] += A[i][j] * beta[j];
  }

  float error = 0.0f;
  for (int i = 0; i < n; i++) {
    float diff = y[i] - predicted[i];
    error += diff * diff;
  }

  return error;
}
