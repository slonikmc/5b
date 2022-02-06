#include <stdio.h>
#include "libs/data_structures/vector/vector.h"
#include <assert.h>

void test_pushBack_emptyVector() {
vector v = createVector(5);
    pushBack(&v, 42);
    assert(v.data[0] == 42);
    assert(v.size == 1);
    assert(v.capacity == 5);
    deleteVector(&v);
}

void test_pushBack_fullVector() {
    vector v = createVector(5);
    v.size = 5;
    pushBack(&v, 42);
    assert(v.data[5] == 42);
    assert(v.size == 6);
    assert(v.capacity == 10);
    deleteVector(&v);
}

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);
    assert(v.size == 1);
    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);
    deleteVector(&v);
}

void test() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
}

int main() {

    test();
//    vector v = createVector(9);
//    v.size = 3;
//    printf("%d %d \n", v.size, v.capacity);
//    reserve(&v, 2);
//    printf("%d %d %d\n", v.size, v.capacity, v.data);
//    clear(&v);
//    printf("%d %d \n", v.size, v.capacity);
//    v.size = 2;
//    v.capacity = 4;
//    shrinkToFit(&v);
//    printf("%d %d \n", v.size, v.capacity);
//    printf("%d\n", isEmpty(&v));
//    printf("%d\n", isFull(&v));
//
//    deleteVector(&v);

    printf(":)");

    return 0;
}

