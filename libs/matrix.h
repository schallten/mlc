#ifndef MATRIX_H
#define MATRIX_H

#define COLS 2

void make_augmented(int X[], int Y[], int n, int out[][COLS]);
void transpose(int in[][COLS], int n, int out[][n]);
int determinant(int A[][COLS]);
void inverse(int A[][COLS], float out[][COLS]);
void multiply(int A[][COLS], int B[][COLS], int rA, int rB, int out[][rB]);
void mat_vec_multiply(float A[][COLS], float B[], int n, float out[]);

#endif
