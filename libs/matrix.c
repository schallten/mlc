#include "matrix.h"

void make_augmented(int X[], int Y[], int n, int out[][COLS]) {
  for (int i = 0; i < n; i++) {
    out[i][0] = X[i];
    out[i][1] = Y[i];
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

void multiply(int A[][COLS], int B[][COLS], int rA, int rB, int out[][rB]) {
  for (int i = 0; i < rA; i++)
    for (int j = 0; j < rB; j++)
      out[i][j] = 0;

  for (int i = 0; i < rA; i++)
    for (int j = 0; j < rB; j++)
      for (int k = 0; k < COLS; k++)
        out[i][j] += A[i][k] * B[k][j];
}

void mat_vec_multiply(float A[][COLS], float B[], int n, float out[]) {
  for (int i = 0; i < COLS; i++) {
    out[i] = 0;
    for (int k = 0; k < n; k++)
      out[i] += A[i][k] * B[k];
  }
}
