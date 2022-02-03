#include <stdio.h>
#include "libs/data_structures/vector/vector.h"

int main() {
    vector v = createVector(9);
    v.size = 3;
    printf("%d %d \n", v.size, v.capacity);
    reserve(&v, 2);
    printf("%d %d %d\n", v.size, v.capacity, v.data);
    clear(&v);
    printf("%d %d \n", v.size, v.capacity);
    v.size = 2;
    v.capacity = 4;
    shrinkToFit(&v);
    printf("%d %d \n", v.size, v.capacity);
    deleteVector(&v);


    return 0;
}

