#ifndef KNN_H
#define KNN_H

char knn_predict(float training_features[][3], char training_labels[], int n_obs,
                 float test_point[], int k);

#endif
