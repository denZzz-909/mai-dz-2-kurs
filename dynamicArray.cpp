#include "dynamicArray.h"
#include <iostream>

intArray::intArray(int size) {
    if (size <= 0) {
        this->size = 0;
        this->array = nullptr;
        return;
    }

    this->size = size;
    this->array = new int[size];
    for (int i = 0; i < size; ++i) array[i] = 0;
}

intArray::~intArray() {
    delete[] array;
    array = nullptr;
}

intArray::intArray(const intArray& copied /*копируемый объект*/) { // конструктор копирования
    this->size = copied.size;
    if (copied.size == 0 || copied.array == nullptr) {
        this->array = nullptr;
        return;
    }
    this->array = new int[copied.size];
    for (int i = 0; i < copied.size; ++i) this->array[i] = copied.array[i];   
}

void intArray::print() const {
    if (size == 0) {
        std::cout << "array is empty" << std::endl;
        return;
    }
    for (int i = 0; i < size; ++i) {
        if (i+1 < size) std::cout << array[i] << " ";
        std::cout << array[i] << std::endl;
    }
}

void intArray::set(int index, int value) {
    if (index < 0 || index >= size) {
        std::cout << "out of array bounds" << std::endl;
        return;
    }
    if (value < -100 || value > 100) {
        std::cout << "value exceeds the limits (-100 <= value <= 100)"
        return;
    }
    array[index] = value;
}

int intArray::get(int index) {
    if (index < 0 || index >= size) {
        std::cout << "out of array bounds" << std::endl;
        throw std::out_of_range;
    }

    return array[index];
}

void append(int value) { // добавление
    return;
}
