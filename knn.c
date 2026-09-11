#include "libs/knn.h"
#include <stdio.h>

int main(void) {
  int n_obs, n_features, k;

  printf("Number of observations: ");
  scanf("%d", &n_obs);

  printf("Number of features: ");
  scanf("%d", &n_features);

  printf("k: ");
  scanf("%d", &k);

  float training_features[n_obs][3];
  char training_labels[n_obs];

  printf("Enter training data (x1 x2 x3 label):\n");
  for (int i = 0; i < n_obs; i++) {
    scanf("%f %f %f %c", &training_features[i][0], &training_features[i][1],
          &training_features[i][2], &training_labels[i]);
  }

  float test_point[3];
  printf("Enter test point (x1 x2 x3): ");
  scanf("%f %f %f", &test_point[0], &test_point[1], &test_point[2]);

  char prediction = knn_predict(training_features, training_labels, n_obs,
                                test_point, k);

  printf("Prediction: %c\n", prediction);

  return 0;
}
