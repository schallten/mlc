#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

Vector *vector_create(int size) {
    Vector *v = malloc(sizeof(Vector));
    if (!v) return NULL;
    v->size = size;
    v->data = calloc(size, sizeof(double));
    if (!v->data) {
        free(v);
        return NULL;
    }
    return v;
}

void vector_destroy(Vector *v) {
    if (!v) return;
    free(v->data);
    free(v);
}

double vector_get(const Vector *v, int index) {
    return v->data[index];
}

void vector_set(Vector *v, int index, double value) {
    v->data[index] = value;
}

int vector_length(const Vector *v) {
    return v->size;
}

Vector *vector_add(const Vector *a, const Vector *b) {
    Vector *result = vector_create(a->size);
    for (int i = 0; i < a->size; i++) {
        result->data[i] = a->data[i] + b->data[i];
    }
    return result;
}

Vector *vector_subtract(const Vector *a, const Vector *b) {
    Vector *result = vector_create(a->size);
    for (int i = 0; i < a->size; i++) {
        result->data[i] = a->data[i] - b->data[i];
    }
    return result;
}

Vector *vector_scale(const Vector *v, double scalar) {
    Vector *result = vector_create(v->size);
    for (int i = 0; i < v->size; i++) {
        result->data[i] = v->data[i] * scalar;
    }
    return result;
}

double vector_dot(const Vector *a, const Vector *b) {
    double sum = 0.0;
    for (int i = 0; i < a->size; i++) {
        sum += a->data[i] * b->data[i];
    }
    return sum;
}

void vector_print(const Vector *v) {
    printf("[");
    for (int i = 0; i < v->size; i++) {
        printf("%g", v->data[i]);
        if (i < v->size - 1) printf(", ");
    }
    printf("]\n");
}
