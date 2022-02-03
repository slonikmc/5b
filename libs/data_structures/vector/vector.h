//
// Created by Akelk on 02.02.2022.
//

#ifndef INC_5B_VECTOR_H
#define INC_5B_VECTOR_H

#include <stdlib.h>

typedef struct vector {
    int *data; // указатель на элементы вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
} vector;

// Если операционная система не может предоставить нужный объем памяти
// под размещение динамического массива, функция должна выводить
// сообщение в поток ошибок и заканчиваться с кодом 1
void sizeError(size_t v);

// возвращает структуру-дескриптор вектор из n значений.
vector createVector(size_t n);

// изменяет количество памяти, выделенное под хранение элементов вектора.
void reserve(vector *v, size_t newCapacity);

// удаляет элементы из контейнера, но не освобождает выделенную память.
void clear(vector *v);

//  освобождает память, выделенную под неиспользуемые элементы.
void shrinkToFit(vector *v);

// освобождает память, выделенную вектору.
void deleteVector(vector *v);

#endif //INC_5B_VECTOR_H
