#pragma once
#include <iostream>
#include <cmath>

template <typename T>
class Array {
    private:
        T* array;
        int size;
    public:
        Array(int size) {
            if (size <= 0)
                throw std::out_of_range("size could not be less than a zero");

            this->size = size;
            this->array = new T[size];
            for (int i = 0; i < size; ++i) array[i] = 0;
        }

        ~Array() {
            delete[] array;
            array = nullptr;
        }

        Array(const intArray& copied) { // задание 2: конструктор копирования
            this->size = copied.size;
            if (copied.size == 0 || copied.array == nullptr) {
                this->array = nullptr;
                return;
            }
            this->array = new int[copied.size];
            for (int i = 0; i < copied.size; ++i) this->array[i] = copied.array[i];   
        }

        void print() const {
            // if (size == 0) {
            //     std::cout << "array is empty" << std::endl;    // здесь exception не нужон, тк есть в конструкторе
            //     return;                                        // вообще вроде не нужны эти строчки
            // }
            for (int i = 0; i < size; ++i) {
                if (i+1 < size) std::cout << array[i] << " ";
                else std::cout << array[i] << std::endl;
            }
        }

        void set(int index, T value) {
            if constexpr (std::is_same_v<T, int>) {    //проверка только для интов
                if (index < 0 || index >= size)
                    throw std::out_of_range("out of array bounds");

                if (value < -100 || value > 100)
                    throw std::invalid_argument("value exceeds the limits (-100 <= value <= 100)");
            }

            array[index] = value;
        }

        T get(int index) const {
            if (index < 0 || index >= size)
                throw std::out_of_range("out of array bounds");

            return array[index];
        }

        void append(T value) { // задание 3: добавление в конец
            if constexpr (std::is_same_v<T, int>)
                if (value < -100 || value > 100)
                    throw std::invalid_argument("value exceeds the limits (-100 <= value <= 100)");
            
            int newSize = size + 1;
            T* newArray = new T[newSize];

            for (int i = 0; i < size; ++i) newArray[i] = array[i];
            newArray[size] = value;

            delete[] array;
            size = newSize;
            array = newArray;
        }

        void add(const Array& added) { // задание 4: сложение и вычитание массивов
            if constexpr (std::is_same_v<T, int>) {
                if (added.size < size) {
                    for (int i = 0; i < added.size; ++i) array[i] += added.array[i];
                    return;
                }
                for (int i = 0; i < size; ++i) array[i] += added.array[i];
            } else throw std::bad_typeid("not an integer");
        }

        void sub(const Array& subtracted) {
            if constexpr (std::is_same_v<T, int>) {
                if (subtracted.size < size) {
                    for (int i = 0; i < subtracted.size; ++i) array[i] -= subtracted.array[i];
                    return;
                }
                for (int i = 0; i < size; ++i) array[i] -= subtracted.array[i];
            } else throw std::bad_typeid("not an integer");
        }

        friend std::ostream& operator<<(std::ostream& out, const Array& array) { // 3 часть, задание 2 
            for (int i = 0; i < size; ++i) {
                if (i+1 < size) out << array[i] << " ";
                else out << array[i] << std::endl;
            }
            return out;
        }

        float dist(Array& a, Array& b) const { //3 часть, задание 3
            if constexpr (!std::is_same_v<T, int>) throw std::bad_typeid("not an integer");
            if (a.size != b.size) throw std::invalid_argument("different sizes");
            float distance = 0;
            for (int i = 0; i < a.size; ++i)
                distance += (a[i] - b[i])*(a[i] - b[i]);
            distance = std.sqrt(distance);
            return distance;
        }
};