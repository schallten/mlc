#include "matrix.h"

void make_augmented(int X[], int Y[], int n, float out[][COLS]) {
  for (int i = 0; i < n; i++) {
    out[i][0] = 1.0f;
    out[i][1] = (float)X[i];
  }
}

void transpose(int in[][COLS], int n, int out[][n]) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < COLS; j++) {
      out[j][i] = in[i][j];
    }
  }
}

int determinant(int A[][COLS]) {
  return A[0][0] * A[1][1] - A[0][1] * A[1][0];
}

void inverse(int A[][COLS], float out[][COLS]) {
  int det = determinant(A);
  float inv_det = 1.0f / det;
  out[0][0] =  A[1][1] * inv_det;
  out[0][1] = -A[0][1] * inv_det;
  out[1][0] = -A[1][0] * inv_det;
  out[1][1] =  A[0][0] * inv_det;
}

void multiply(int A[][COLS], int B[][COLS], int rA, int cA, int cB, int out[][cB]) {
  for (int i = 0; i < rA; i++)
    for (int j = 0; j < cB; j++)
      out[i][j] = 0;

  for (int i = 0; i < rA; i++)
    for (int j = 0; j < cB; j++)
      for (int k = 0; k < cA; k++)
        out[i][j] += A[i][k] * B[k][j];
}

void mat_vec_multiply(float A[][COLS], float B[], int n, float out[]) {
  for (int i = 0; i < COLS; i++) {
    out[i] = 0;
    for (int k = 0; k < n; k++)
      out[i] += A[i][k] * B[k];
  }
}

void find_beta(int X[], int Y[], int n, float beta[]) {
  float Xa[n][COLS];
  for (int i = 0; i < n; i++) {
    Xa[i][0] = 1.0f;
    Xa[i][1] = (float)X[i];
  }

  float XaT[COLS][n];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < COLS; j++)
      XaT[j][i] = Xa[i][j];

  float mulXaT[COLS][COLS];
  for (int i = 0; i < COLS; i++)
    for (int j = 0; j < COLS; j++) {
      mulXaT[i][j] = 0;
      for (int k = 0; k < n; k++)
        mulXaT[i][j] += XaT[i][k] * Xa[k][j];
    }

  float det = mulXaT[0][0] * mulXaT[1][1] - mulXaT[0][1] * mulXaT[1][0];
  float inv[COLS][COLS];
  float inv_det = 1.0f / det;
  inv[0][0] =  mulXaT[1][1] * inv_det;
  inv[0][1] = -mulXaT[0][1] * inv_det;
  inv[1][0] = -mulXaT[1][0] * inv_det;
  inv[1][1] =  mulXaT[0][0] * inv_det;

  float XaTY[COLS];
  for (int i = 0; i < COLS; i++) {
    XaTY[i] = 0;
    for (int k = 0; k < n; k++)
      XaTY[i] += XaT[i][k] * Y[k];
  }

  for (int i = 0; i < COLS; i++) {
    beta[i] = 0;
    for (int k = 0; k < COLS; k++)
      beta[i] += inv[i][k] * XaTY[k];
  }
}
