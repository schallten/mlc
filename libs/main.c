#include "distance.h"
#include "vector.h"
#include <stdio.h>

int main(void) {
  Vector *a = vector_create(3);
  vector_set(a, 0, 10);
  vector_set(a, 1, 20);
  vector_set(a, 2, 30);

  printf("a = ");
  vector_print(a);

  Vector *b = vector_create(3);
  vector_set(b, 0, 1);
  vector_set(b, 1, 2);
  vector_set(b, 2, 3);

  printf("b = ");
  vector_print(b);

  Vector *sum = vector_add(a, b);
  printf("a + b = ");
  vector_print(sum);

  Vector *diff = vector_subtract(a, b);
  printf("a - b = ");
  vector_print(diff);

  Vector *scaled = vector_scale(a, 0.5);
  printf("a * 0.5 = ");
  vector_print(scaled);

  printf("a . b = %g\n", vector_dot(a, b));
  printf("dist(a, b) = %g\n", distance_euclidean(a, b));

  vector_destroy(a);
  vector_destroy(b);
  vector_destroy(sum);
  vector_destroy(diff);
  vector_destroy(scaled);

  return 0;
}
