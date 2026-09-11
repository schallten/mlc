#include "libs/matrix.h"
#include <stdio.h>

int main(void) {
  // Input data: x = independent variable, y = actual observed values
  int x[] = {1, 2, 3, 4, 5};
  int y[] = {1, 1, 1, 1, 1};
  int n = 5;

  // Compute regression coefficients beta = (A^T A)^-1 A^T y
  // where A is the design matrix [1, x_i] for each observation
  float beta[COLS];
  find_beta(x, y, n, beta);

  // Build design matrix A with n rows and COLS columns
  // Each row is [1, x_i] to model y = b0 + b1*x
  float A[n][COLS];
  make_augmented(x, y, n, A);

  // Compute predicted values: predicted = A * beta
  float predicted[n];
  for (int i = 0; i < n; i++) {
    predicted[i] = 0;
    for (int j = 0; j < COLS; j++)
      predicted[i] += A[i][j] * beta[j];
  }

  // Compute error = (y - A*beta)^T (y - A*beta)
  // This is the sum of squared residuals (SSR)
  float error = 0.0f;
  for (int i = 0; i < n; i++) {
    float diff = y[i] - predicted[i];
    error += diff * diff;
  }

  printf("Beta: [%g, %g]\n", beta[0], beta[1]);
  printf("Error: %g\n", error);

  return 0;
}
