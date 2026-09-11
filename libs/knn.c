#include "knn.h"
#include <math.h>

struct Neighbor {
  float x1;
  float x2;
  float x3;
  char label;
  double distance;
};

char knn_predict(float training_features[][3], char training_labels[], int n_obs,
                 float test_point[], int k) {
  struct Neighbor neighbors[n_obs];

  for (int i = 0; i < n_obs; i++) {
    double sum = 0;
    sum += (test_point[0] - training_features[i][0]) * (test_point[0] - training_features[i][0]);
    sum += (test_point[1] - training_features[i][1]) * (test_point[1] - training_features[i][1]);
    sum += (test_point[2] - training_features[i][2]) * (test_point[2] - training_features[i][2]);
    neighbors[i].distance = sqrt(sum);
    neighbors[i].label = training_labels[i];
  }

  for (int i = 0; i < n_obs - 1; i++) {
    for (int j = 0; j < n_obs - i - 1; j++) {
      if (neighbors[j].distance > neighbors[j + 1].distance) {
        struct Neighbor temp = neighbors[j];
        neighbors[j] = neighbors[j + 1];
        neighbors[j + 1] = temp;
      }
    }
  }

  int countA = 0;
  int countB = 0;

  for (int i = 0; i < k; i++) {
    if (neighbors[i].label == 'A') {
      countA++;
    } else if (neighbors[i].label == 'B') {
      countB++;
    }
  }

  return countA > countB ? 'A' : 'B';
}
