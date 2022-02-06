
//
// Created by Akelk on 02.02.2022.
//

#include <stdio.h>
#include "vector.h"
#include <malloc.h>

void sizeError(size_t v) {
    if (v == 0) {
        fprintf(stderr, "bad alloc ");
        exit(1);
    }
}

vector createVector(size_t n) {
    int *p = malloc(sizeof(int) * n);
    sizeError((size_t)p);
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
            sizeError((size_t)vector);
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

bool isEmpty(vector *v) {
    return v->size == 0;
}

bool isFull(vector *v) {
    return v->size == v->capacity;
}

int getVectorValue(vector *v, size_t i) {
    return v->data[i];
}

void pushBack(vector *v, int x) {
    if (isFull(v)) {
        reserve(v, v->capacity * 2);
    } else if (v->capacity == 0) {
        reserve(v, 1);
    }
    v->data[v->size] = x;
    v->size++;
}

void popBack(vector *v) {
    if (isEmpty(v)) {
        fprintf(stderr, "vector is empty ");
        exit(1);
    } else {
        v->size--;
    }
}
