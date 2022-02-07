//
// Created by Akelk on 02.02.2022.
//

#ifndef INC_5B_VECTOR_H
#define INC_5B_VECTOR_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct vector {
    int *data; // указатель на элементы вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
} vector;

// Если операционная система не может предоставить нужный объем памяти
// под размещение динамического массива, функция должна выводить
// сообщение в поток ошибок и заканчиваться с кодом 1
void sizeError(vector *v);

// возвращает структуру-дескриптор вектор из n значений.
vector createVector(size_t n);

// изменяет количество памяти, выделенное под хранение элементов вектора.
void reserve(vector *v, size_t newCapacity);

// удаляет элементы из контейнера, но не освобождает выделенную память.
void clear(vector *v);

// освобождает память, выделенную под неиспользуемые элементы.
void shrinkToFit(vector *v);

// освобождает память, выделенную вектору.
void deleteVector(vector *v);

// выполняет проверку на то, является ли вектор пустым.
bool isEmpty(vector *v);

// выполняет проверку на то, является ли вектор полным.
bool isFull(vector *v);

// возвращает i-ый элемент вектора v.
int getVectorValue(vector *v, size_t i);

// добавляет элемент x в конец вектора v. Если вектор заполнен,
// увеличивает количество выделенной ему памяти в 2 раза, используя reserve.
void pushBack(vector *v, int x);

// удаляет последний элемент из вектора. Функция должна ’выкидывать’ в поток ошибок сообщение,
// если вектор пуст и закончить выполнение с кодом 1.
void popBack(vector *v);

// возвращает указатель на index-ый элемент вектора.
int *atVector(vector *v, size_t index);

// возвращает указатель на последний элемент вектора.
int *back(vector *v);

// возвращает указатель на последний элемент вектора.
int *front(vector *v);

#endif //INC_5B_VECTOR_H
