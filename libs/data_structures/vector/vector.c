
//
// Created by Akelk on 02.02.2022.
//

#include <stdio.h>
#include "vector.h"
#include <malloc.h>

void sizeError(size_t v) {
    if (v == NULL) {
        fprintf(stderr, "bad alloc ");
        exit(1);
    }
}

vector createVector(size_t n) {
    int *p = malloc(sizeof(int) * n);
    sizeError(p);
    return (vector) {p, 0, n};
}

void reserve(vector *v, size_t newCapacity) {
    if (newCapacity == 0) {
        v->data = NULL;
    } else {
        if (newCapacity < v->size)
            v->size = newCapacity;
        else {
            int *vector = realloc(v->data, sizeof(int) * newCapacity);
            sizeError(vector);
        }
        v->capacity = newCapacity;
    }
}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    v->capacity = v->size;
}

void deleteVector(vector *v) {
    free(v);
}
