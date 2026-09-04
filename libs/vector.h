#ifndef VECTOR_H
#define VECTOR_H

typedef struct {
    int size;
    double *data;
} Vector;

Vector *vector_create(int size);
void    vector_destroy(Vector *v);

double  vector_get(const Vector *v, int index);
void    vector_set(Vector *v, int index, double value);

int     vector_length(const Vector *v);

Vector *vector_add(const Vector *a, const Vector *b);
Vector *vector_subtract(const Vector *a, const Vector *b);
Vector *vector_scale(const Vector *v, double scalar);

double  vector_dot(const Vector *a, const Vector *b);

void    vector_print(const Vector *v);

#endif
