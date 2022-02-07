#include "libs/data_structures/vector/vector.h"
#include <assert.h>

void test_pushBack_emptyVector() {
    vector v = createVector(5);
    pushBack(&v, 42);
    assert(v.data[0] == 42);
    assert(v.size == 1);
    assert(v.capacity == 5);
}

void test_pushBack_fullVector() {
    vector v = createVector(5);
    v.size = 5;
    pushBack(&v, 42);
    assert(v.data[5] == 42);
    assert(v.size == 6);
    assert(v.capacity == 10);
}

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);
    assert(v.size == 1);
    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);
}

void test_atVector_notEmptyVector() {
    vector v = createVector(5);
    v.size = 4;
    assert(atVector(&v, 2) == &v.data[2]);
}

void test_atVector_requestToLastElement() {
    vector v = createVector(5);
    v.size = 5;
    assert(atVector(&v, 4) == &v.data[4]);
}

void test_back_oneElementInVector() {
    vector v = createVector(1);
    v.size = 1;
    assert(back(&v) == &v.data[0]);
}

void test_front_oneElementInVector() {
    vector v = createVector(1);
    v.size = 1;
    assert(front(&v) == &v.data[0]);
}

void test() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
    test_back_oneElementInVector();
    test_front_oneElementInVector();
}

int main() {
    test();

    return 0;
}

