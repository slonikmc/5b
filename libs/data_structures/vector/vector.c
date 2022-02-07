
//
// Created by Akelk on 02.02.2022.
//

#include <stdio.h>
#include "vector.h"
#include <malloc.h>

void sizeError(vector *v) {
    if (v->data == NULL) {
        fprintf(stderr, "bad alloc ");
        exit(1);
    }
}

vector createVector(size_t n) {
    vector v = {malloc(sizeof(int) * n), 0, n};
    sizeError(&v);
    return v;
}

void reserve(vector *v, size_t newCapacity) {
    if (newCapacity == 0) {
        v->data = NULL;
    } else {
        if (newCapacity < v->size)
            v->size = newCapacity;
        else {
            realloc(v->data, sizeof(int) * newCapacity);
            sizeError(v);
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
    return v->size == v->capacity && v->capacity != 0;
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

void errorEmptyVector(vector *v) {
    if (isEmpty(v)) {
        fprintf(stderr, "vector is empty ");
        exit(1);
    }
}

void popBack(vector *v) {
    errorEmptyVector(v);
    v->size--;
}

int *atVector(vector *v, size_t index) {
    if (v->size < index) {
        fprintf(stderr, "IndexError: a[%lld] is not exists", index);
        exit(1);
    }
    errorEmptyVector(v);
    return &v->data[index];
}

int *back(vector *v) {
    return &v->data[v->size - 1];
}

int *front(vector *v) {
    return &v->data[0];
}