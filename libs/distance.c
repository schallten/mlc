#include "distance.h"
#include <math.h>

double distance_euclidean(const Vector *a, const Vector *b) {
    double sum = 0.0;
    for (int i = 0; i < a->size; i++) {
        double diff = a->data[i] - b->data[i];
        sum += diff * diff;
    }
    return sqrt(sum);
}
