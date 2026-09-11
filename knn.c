#include <math.h>
#include <stdio.h>

struct Point {
  int x1;
  int x2;
  int x3;
  char result;
  double distance;
};

int main() {
  int obs = 6;
  int predics = 3;
  int k = 3;

  struct Point data[obs];
  struct Point sorted[obs];

  // Read training data
  for (int i = 0; i < obs; i++) {
    scanf("%d %d %d %c", &data[i].x1, &data[i].x2, &data[i].x3,
          &data[i].result);
  }

  int test[predics];

  // Read the point we want to classify
  for (int i = 0; i < predics; i++) {
    scanf("%d", &test[i]);
  }

  for (int i = 0; i < obs; i++) {
    sorted[i] = data[i];
  }

  // Calculate distance from test point to every observation
  for (int i = 0; i < obs; i++) {
    double sum = 0;

    sum += (test[0] - sorted[i].x1) * (test[0] - sorted[i].x1);

    sum += (test[1] - sorted[i].x2) * (test[1] - sorted[i].x2);

    sum += (test[2] - sorted[i].x3) * (test[2] - sorted[i].x3);

    sorted[i].distance = sqrt(sum);
  }

  // Sort observations from smallest distance to largest
  for (int i = 0; i < obs - 1; i++) {
    for (int j = 0; j < obs - i - 1; j++) {
      if (sorted[j].distance > sorted[j + 1].distance) {
        struct Point temp = sorted[j];
        sorted[j] = sorted[j + 1];
        sorted[j + 1] = temp;
      }
    }
  }

  int countA = 0;
  int countB = 0;

  // Look at the k closest observations
  for (int i = 0; i < k; i++) {
    if (sorted[i].result == 'A') {
      countA++;
    } else if (sorted[i].result == 'B') {
      countB++;
    }
  }

  char prediction;

  if (countA > countB) {
    prediction = 'A';
  } else {
    prediction = 'B';
  }

  printf("Prediction: %c\n", prediction);

  return 0;
}
